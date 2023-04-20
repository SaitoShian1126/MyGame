//********************************************
//
//	spawn.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "spawn.h"
#include "application.h"
#include "renderer.h"
#include "explosion.h"
#include "fade.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CSpawn::m_pTextureSpawn[3] = {};

//敵のコンストラクタ
CSpawn::CSpawn()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_nUninitTimer = 0;
	m_nTimer = 0;
}

//敵のデストラクタ
CSpawn::~CSpawn()
{
	//何も書かない
}

//敵の初期化処理
HRESULT CSpawn::Init(void)
{
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************m_nLife
	m_nUninitTimer = 500;
	m_nTimer = 0;

	switch (m_nType)
	{
	case SPAWNTYPE_MAGICCIRCLE1:
		//テクスチャ反映
		BindTexture(m_pTextureSpawn[0]);
		break;
	case SPAWNTYPE_MAGICCIRCLE2:
		//テクスチャ反映
		BindTexture(m_pTextureSpawn[1]);
		break;
	case SPAWNTYPE_MAGICCIRCLE3:
		//テクスチャ反映
		BindTexture(m_pTextureSpawn[2]);
		break;
	default:
		break;
	}
	
	return S_OK;
}

//敵の終了処理
void CSpawn::Uninit(void)
{
	CObject2D::Uninit();
}

//敵の更新処理
void CSpawn::Update()
{
	CObject2D::Update();
	D3DXVECTOR3 SpawnRot = GetRot();
	D3DXVECTOR3 SpawnPos = GetPos();
	
	//*************************************
	//	回転
	//*************************************
	if (m_nType == SPAWNTYPE_MAGICCIRCLE2)
	{
		//回転率
		SpawnRot.z += 0.05f;
		SetRot(SpawnRot);
	}
	if (m_nType == SPAWNTYPE_MAGICCIRCLE1)
	{
		//回転率
		SpawnRot.z -= 0.025f;
		SetRot(SpawnRot);
	}

	m_nUninitTimer--;
	if (m_nUninitTimer <= 0)
	{
		//爆発
		CExplosion::Create(D3DXVECTOR3(SpawnPos), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 0.8f, 0.8f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
		Uninit();
		return;
	}
}

//敵の描画処理
void CSpawn::Draw()
{
	CObject2D::Draw();
}

//スポーンの生成
CSpawn *CSpawn::Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move,D3DXVECTOR3 size, SPAWNTYPE nType,int nLife)
{
	CSpawn *pSpawn = nullptr;

	//クラスの生成
	pSpawn = new CSpawn;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pSpawn != nullptr)
	{
		pSpawn->SetSpawnType(nType);
		//初期化処理
		pSpawn->Init();
		//設定処理
		pSpawn->SetPosition(pos);
		pSpawn->SetMove(move);
		pSpawn->SetSize(size);
		pSpawn->SetLife(nLife);
		pSpawn->SetType(TYPE_SPAWN);
	}
	else
	{
		assert(false);
	}

	return pSpawn;
}

//スポーンのタイプ
void CSpawn::SetSpawnType(SPAWNTYPE type)
{
	m_nType = type;
}

//スポーンの設定
void CSpawn::SetLife(int nLife)
{
	m_nLife = nLife;
}

//テクスチャの読み込み
HRESULT CSpawn::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/MagicCircle1.png",
		&m_pTextureSpawn[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/MagicCircle6.png",
		&m_pTextureSpawn[1]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/MagicCircle4.png",
		&m_pTextureSpawn[2]);

	return S_OK;
}

//テクスチャの破棄
void CSpawn::Unload(void)
{
	//テクスチャの破棄
	for (int nCnt = 0; nCnt < 3; nCnt++)
	{
		if (m_pTextureSpawn[nCnt] != nullptr)
		{
			m_pTextureSpawn[nCnt]->Release();
			m_pTextureSpawn[nCnt] = nullptr;
		}
	}
}