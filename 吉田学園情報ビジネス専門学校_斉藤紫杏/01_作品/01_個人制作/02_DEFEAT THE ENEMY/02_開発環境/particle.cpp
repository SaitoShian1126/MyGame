//********************************************
//
//	particle.cpp
//	Author: saito shian
//
//********************************************

//インクルード
//#include <time.h>
#include <assert.h>
#include "particle.h"
#include "application.h"
#include "renderer.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CParticle::m_pTextureParticle = nullptr;
D3DXVECTOR3 CParticle::m_nMove = {};

//パーティクルのコンストラクタ
CParticle::CParticle()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_nLife = 0;
	m_nCol = {};
	m_nMove = {};
}

//パーティクルのデストラクタ
CParticle::~CParticle()
{
	//何も書かない
}

//パーティクルの初期化処理
HRESULT CParticle::Init(void)
{
	//乱数
	//srand((unsigned int)time(NULL));	//起動時に一回だけ行うため初期化に書く	

	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************
	m_nLife = 0;
	m_nCol = {};
	m_nMove = {};

	//テクスチャ反映
	BindTexture(m_pTextureParticle);

	return S_OK;
}

//パーティクルの終了処理
void CParticle::Uninit(void)
{
	CObject2D::Uninit();
}

//パーティクルの更新処理
void CParticle::Update(void)
{
	CObject2D::Update();

	//寿命
	m_nLife--;

	m_nLife = ((rand() % 5));

	D3DXVECTOR3 ParticleSize = GetSize();

	ParticleSize.x = MAX_PARTICLESIZE;
	ParticleSize.y = MAX_PARTICLESIZE;

	ParticleSize.x--;
	ParticleSize.y--;
	ParticleSize.x -= 0.05f;
	ParticleSize.y -= 0.05f;

	if (ParticleSize.x <= 0)
	{
		ParticleSize.x = 0;
	}
	if (ParticleSize.y <= 0)
	{
		ParticleSize.y = 0;
	}
	if (m_nLife <= 0.0f)
	{
		Uninit();
		return;
	}

	//pos代入
	D3DXVECTOR3 ParticlePos = GetPos();
	D3DXVECTOR3 ParticleMove = GetMove();

	//移動方向
	ParticleMove.x = cosf((float)(rand() % 360) / 100) * ((float)(rand() % 10) + 1);
	ParticleMove.y = sinf((float)(rand() % 360) / 100) * ((float)(rand() % 10) + 1);

	SetMove(D3DXVECTOR3(ParticleMove));
	SetPosition(D3DXVECTOR3(ParticlePos));
	SetSize(D3DXVECTOR3(ParticleSize));
}

//パーティクルの描画処理
void CParticle::Draw(void)
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

//パーティクルの生成
CParticle *CParticle::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, int nLife)
{
	CParticle *pParticle = nullptr;

	//クラスの生成
	pParticle = new CParticle;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pParticle != nullptr)
	{
		//初期化処理
		pParticle->Init();
		//設定処理
		pParticle->SetPosition(pos);
		pParticle->SetSize(size);
		pParticle->SetLife(nLife);
		pParticle->SetColor(col.r, col.g, col.b, col.a);
	}
	else
	{
		assert(false);
	}

	return pParticle;
}

//テクスチャの読み込み
HRESULT CParticle::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/effect000.jpg",
		&m_pTextureParticle);

	return S_OK;
}

//テクスチャの破棄
void CParticle::Unload(void)
{
	//テクスチャの破棄
	if (m_pTextureParticle != nullptr)
	{
		m_pTextureParticle->Release();
		m_pTextureParticle = nullptr;
	}
}

//ライフの設定
void CParticle::SetLife(int nLife)
{
	m_nLife = nLife;
}