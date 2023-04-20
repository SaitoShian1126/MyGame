//********************************************
//
//	player.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "player.h"
#include "renderer.h"
#include "application.h"
#include "bullet.h"
#include "effect.h"
#include "sound.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CPlayer::m_pTexturePlayer = nullptr;
int CPlayer::m_nLife = 0;
bool CPlayer::BulletFlag = false;

//プレイヤーのコンストラクタ
CPlayer::CPlayer()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_PlayerPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//プレイヤーの位置をクリア
	m_nTime = 0;
	BulletFlag = false;
}

//プレイヤーのデストラクタ
CPlayer::~CPlayer()
{
	//何も書かない
}

//プレイヤーの初期化処理
HRESULT CPlayer::Init(void)
{
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************BulletFlag
	m_PlayerPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//プレイヤーの位置を初期化
	m_nTime = BULLET_TIME;
	BulletFlag = false;

	//テクスチャ反映
	BindTexture(m_pTexturePlayer);

	return S_OK;
}

//プレイヤーの終了処理
void CPlayer::Uninit(void)
{
	//サウンドの停止
	StopSound();
	CObject2D::Uninit();
}

//プレイヤーの更新処理
void CPlayer::Update(void)
{
	//インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();
	D3DXVECTOR3 PlayerPos = GetPos();

	//****************************************************
	//	プレイヤーの攻撃処理
	//****************************************************
	//spaceキーが押された
	if (pInput->GetKeyboardPress(DIK_SPACE) == true && BulletFlag == false || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_RBUTTON5) == true && BulletFlag == false)
	{//弾の生成
		m_nTime--;
		if (m_nTime <= 0)
		{
			//サウンドの再生
			PlaySound(SOUND_LABEL_SE_SHOT);
			CBullet::Create(D3DXVECTOR3(PlayerPos.x, PlayerPos.y, PlayerPos.z), D3DXVECTOR3(15.0f,0.0f, 0.0f), D3DXVECTOR3(5.0f, 0.0f, 0.0f),0, 0,CBullet::BULLETTYPE_NOMAL);
		}
		if (m_nTime <= 0)
		{
			m_nTime = BULLET_TIME;
		}
	}
	//*******************************************************
	//	弾の切り替え
	//*******************************************************
	if (pInput->GetKeyboardTrigger(DIK_C) == true && BulletFlag == false || pInputJoyKey->GetJoypadTrigger(CJoyPad::JOYKEY_B) == true && BulletFlag == false)
	{
		BulletFlag = true;
		//サウンドの再生
		PlaySound(SOUND_LABEL_SE_BULLET);
	}
	else if (pInput->GetKeyboardTrigger(DIK_C) == true && BulletFlag == true || pInputJoyKey->GetJoypadTrigger(CJoyPad::JOYKEY_B) == true && BulletFlag == true)
	{
		BulletFlag = false;
		//サウンドの再生
		PlaySound(SOUND_LABEL_SE_BULLET);
	}
	else if (pInput->GetKeyboardPress(DIK_SPACE) == true && BulletFlag == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_RBUTTON5) == true && BulletFlag == true)
	{//弾の生成
		m_nTime--;
		if (m_nTime <= 0)
		{
			//サウンドの再生
			PlaySound(SOUND_LABEL_SE_SHOT);
			CBullet::Create(D3DXVECTOR3(PlayerPos.x, PlayerPos.y + 15.0f, PlayerPos.z), D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f),0, 0,CBullet::BULLETTYPE_NOMAL);
			CBullet::Create(D3DXVECTOR3(PlayerPos.x, PlayerPos.y - 15.0f, PlayerPos.z), D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f),0, 0, CBullet::BULLETTYPE_NOMAL);
		}
		if (m_nTime <= 0)
		{
			m_nTime = BULLET_TIME;
		}
	}

	//*****************************************************
	//	プレイヤーの移動処理
	//****************************************************
	//Aキーが押された
	if (pInput->GetKeyboardPress(DIK_A) == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_LEFT) == true)
	{
		//エフェクトの生成
		CEffect::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 0.5f, 0.25f), 7);
		m_PlayerPos.x += sinf(-D3DX_PI * 0.5f) * 1.0f;
	}

	//Dキーが押された
	if (pInput->GetKeyboardPress(DIK_D) == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_RIGHT) == true)
	{
		//エフェクトの生成
		CEffect::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 0.5f, 0.25f), 7);
		m_PlayerPos.x -= sinf(-D3DX_PI * 0.5f) * 1.0f;
	}

	//wキーが押された
	if (pInput->GetKeyboardPress(DIK_W) == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_UP) == true)
	{
		//エフェクトの生成
		CEffect::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 0.5f, 0.25f), 7);
		m_PlayerPos.y += sinf(-D3DX_PI * 0.5f) * 1.0f;
	}

	//sキーが押された
	if (pInput->GetKeyboardPress(DIK_S) == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_DOWN) == true)
	{
		//エフェクトの生成
		CEffect::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 0.5f, 0.25f), 7);
		m_PlayerPos.y -= sinf(-D3DX_PI * 0.5f) * 1.0f;
	}

	//*********************************************
	//	プレイヤーの移動範囲制限
	//*********************************************
	//左の範囲
	if (PlayerPos.x < 0.0f + PLAYER_SIZE_X)
	{
		PlayerPos.x = 0.0f + PLAYER_SIZE_X;
	}
	//右の範囲
	if (PlayerPos.x > SCREEN_WIDTH - PLAYER_SIZE_X)
	{
		PlayerPos.x = SCREEN_WIDTH - PLAYER_SIZE_X;
	}
	//上の範囲
	if (PlayerPos.y < 0.0f + PLAYER_SIZE_X / 2)
	{
		PlayerPos.y = 0.0f + PLAYER_SIZE_X / 2;
	}
	//下の範囲
	if (PlayerPos.y > SCREEN_HEIGHT - PLAYER_SIZE_X / 2)
	{
		PlayerPos.y = SCREEN_HEIGHT - PLAYER_SIZE_X / 2;
	}

	//位置を更新
	PlayerPos.x += m_PlayerPos.x;
	PlayerPos.y += m_PlayerPos.y;
	PlayerPos.z += m_PlayerPos.z;

	//移動量減衰
	m_PlayerPos.x += (0.0f - m_PlayerPos.x) * 0.1f;
	m_PlayerPos.y += (0.0f - m_PlayerPos.y) * 0.1f;
	m_PlayerPos.z += (0.0f - m_PlayerPos.z) * 0.1f;

	SetPosition(PlayerPos);
	CObject2D::Update();
}

//プレイヤーの描画処理
void CPlayer::Draw(void)
{
	CObject2D::Draw();
}

//生成
CPlayer *CPlayer::Create(int nLife)
{
	CPlayer *pPlayer = nullptr;

	//クラスの生成
	pPlayer = new CPlayer;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pPlayer != nullptr)
	{
		//初期化処理
		pPlayer->Init();
		//設定処理
		pPlayer->SetPosition(D3DXVECTOR3(200.0f,360.0f,0.0f));
		pPlayer->SetSize(D3DXVECTOR3(50.0f, 35.0f, 0.0f));
		pPlayer->SetType(TYPE_PLAYER);
		pPlayer->SetLife(nLife);
	}
	else
	{
		assert(false);
	}
	return pPlayer;
}

//テクスチャの読み込み
HRESULT CPlayer::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/player.png",
		&m_pTexturePlayer);

	return S_OK;
}

//テクスチャの破棄
void CPlayer::Unload(void)
{
	//テクスチャの破棄
	if (m_pTexturePlayer != nullptr)
	{
		m_pTexturePlayer->Release();
		m_pTexturePlayer = nullptr;
	}
}

//プレイヤーの体力の設定処理
void CPlayer::SetLife(int nLife)
{
	m_nLife = nLife;
}