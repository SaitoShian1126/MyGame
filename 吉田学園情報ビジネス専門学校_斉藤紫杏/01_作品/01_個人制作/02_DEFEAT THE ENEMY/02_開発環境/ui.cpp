//********************************************
//
//	ui.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "ui.h"
#include "application.h"
#include "renderer.h"
#include "explosion.h"
#include "fade.h"
#include "input.h"
#include "player.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CUi::m_pTextureUi[2] = {};

//敵のコンストラクタ
CUi::CUi() : CObject2D(4)
{
	//********************************
	//メンバ変数のクリア
	//********************************
}

//敵のデストラクタ
CUi::~CUi()
{
	//何も書かない
}

//敵の初期化処理
HRESULT CUi::Init(void)
{
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************

	switch (m_nType)
	{
	case CUi::UITYPE_NONE:
		break;
	case CUi::UITYPE_BULLET:
		//テクスチャ反映
		BindTexture(m_pTextureUi[0]);
		break;
	case CUi::UITYPE_LIFE:
		//テクスチャ反映
		BindTexture(m_pTextureUi[1]);
		break;
	default:
		break;
	}
	return S_OK;
}

//敵の終了処理
void CUi::Uninit(void)
{
	CObject2D::Uninit();
}

//敵の更新処理
void CUi::Update()
{
	if (m_nType == UITYPE_BULLET)
	{
		if (CPlayer::GetBulletFlag() == true)
		{
			//テクスチャの設定
			SetTexture(2.0f, 1.0f, 1.0f, 0.0f);
		}
		else if (CPlayer::GetBulletFlag() == false)
		{
			//テクスチャの設定
			SetTexture(2.0f, 2.0f, 1.0f, 0.0f);
		}
	}
}

//敵の描画処理
void CUi::Draw()
{
	CObject2D::Draw();
}

//uiの種類の設定
void CUi::SetUiType(UITYPE type)
{
	m_nType = type;
}

//スポーンの生成
CUi *CUi::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, UITYPE type)
{
	CUi *pUi = nullptr;

	//クラスの生成
	pUi = new CUi;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pUi != nullptr)
	{
		pUi->SetUiType(type);
		//初期化処理
		pUi->Init();
		//設定処理
		pUi->SetPosition(pos);
		pUi->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pUi;
}

//テクスチャの読み込み
HRESULT CUi::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/弾切り替え.png",
		&m_pTextureUi[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ゲージカバー.png",
		&m_pTextureUi[1]);

	return S_OK;
}

//テクスチャの破棄
void CUi::Unload(void)
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		//テクスチャの破棄
		if (m_pTextureUi[nCnt] != nullptr)
		{				
			m_pTextureUi[nCnt]->Release();
			m_pTextureUi[nCnt] = nullptr;
		}
	}
}
