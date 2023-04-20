//********************************************
//
//	sponer.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include <time.h>
#include "sponer.h"
#include "application.h"
#include "renderer.h" 

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CSponer::m_pTextureSponer = nullptr;

//アイテムのコンストラクタ
CSponer::CSponer() : CObject2D(0)
{
	//********************************
	//メンバ変数のクリア
	//********************************
}

//アイテムのデストラクタ
CSponer::~CSponer()
{
	//何も書かない
}

//アイテムの初期化処理
HRESULT CSponer::Init(void)
{
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************

	//テクスチャの反映
	BindTexture(m_pTextureSponer);

	return S_OK;
}

//アイテムの終了処理
void CSponer::Uninit(void)
{
	CObject2D::Uninit();
}

//アイテムの更新処理
void CSponer::Update()
{
	D3DXVECTOR3 SponerPos = GetPos();

	//位置の設定
	SetPosition(SponerPos);
	CObject2D::Update();
}

//アイテムの描画処理
void CSponer::Draw()
{
	CObject2D::Draw();
}

//アイテムの生成
CSponer *CSponer::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size)
{
	CSponer *pSponer = nullptr;

	//クラスの生成
	pSponer = new CSponer;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pSponer != nullptr)
	{
		//初期化処理
		pSponer->Init();
		//設定処理
		pSponer->SetPosition(pos);
		pSponer->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pSponer;
}

//テクスチャの読み込み
HRESULT CSponer::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/アイテムスポナー.png",
		&m_pTextureSponer);

	return S_OK;
}

//テクスチャの破棄
void CSponer::Unload(void)
{
	//テクスチャの破棄
	if (m_pTextureSponer != nullptr)
	{
		m_pTextureSponer->Release();
		m_pTextureSponer = nullptr;
	}
}
