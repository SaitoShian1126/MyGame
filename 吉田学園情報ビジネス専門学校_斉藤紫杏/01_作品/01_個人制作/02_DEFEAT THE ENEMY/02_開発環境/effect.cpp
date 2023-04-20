//********************************************
//
//	effect.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "effect.h"
#include "application.h"
#include "renderer.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CEffect::m_pTextureEffect = nullptr;

//エフェクトのコンストラクタ
CEffect::CEffect() : CObject2D(2)
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_nLife = 0;
	m_nCol = {};
}

//エフェクトのデストラクタ
CEffect::~CEffect()
{
	//何も書かない
}

//エフェクトの初期化処理
HRESULT CEffect::Init(void)
{
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************
	m_nLife = 0;
	m_nCol = {};

	//テクスチャ反映
	BindTexture(m_pTextureEffect);

	return S_OK;
}

//エフェクトの終了処理
void CEffect::Uninit(void)
{
	CObject2D::Uninit();
}

//エフェクトの更新処理
void CEffect::Update(void)
{
	D3DXVECTOR3 EffectSize = GetSize();
	EffectSize.x -= 1.5f;
	EffectSize.y -= 1.5f;
	SetSize(EffectSize);

	m_nLife--;
	if (m_nLife <= 0)
	{
		Uninit();
	}
}

//エフェクトの描画処理
void CEffect::Draw(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//**********************************
	// αブレンディングを加算合成に設定
	//**********************************
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CObject2D::Draw();

	//***************************
	//αブレンディングを元に戻す
	//***************************
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//エフェクトの生成
CEffect *CEffect::Create(D3DXVECTOR3 pos,D3DXVECTOR3 size,D3DXCOLOR col,int nLife)
{
	CEffect *pEffect= nullptr;

	//クラスの生成
	pEffect = new CEffect;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pEffect != nullptr)
	{
		//初期化処理
		pEffect->Init();
		//設定処理
		pEffect->SetPosition(pos);
		pEffect->SetSize(size);
		pEffect->SetLife(nLife);
		pEffect->SetColor(col.r, col.g, col.b, col.a);
	}
	else
	{
		assert(false);
	}

	return pEffect;
}

//テクスチャの読み込み
HRESULT CEffect::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/effect000.jpg",
		&m_pTextureEffect);

	return S_OK;
}

//テクスチャの破棄
void CEffect::Unload(void)
{
	//テクスチャの破棄
	if (m_pTextureEffect != nullptr)
	{
		m_pTextureEffect->Release();
		m_pTextureEffect = nullptr;
	}
}

//ライフの設定
void CEffect::SetLife(int nLife)
{
	m_nLife = nLife;
}