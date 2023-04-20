//********************************************
//
//	hp.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "hp.h"
#include "application.h"
#include "renderer.h"
#include "explosion.h"
#include "fade.h"
#include "input.h"
#include "player.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CHp::m_pTexturehp = {};

//敵のコンストラクタ
CHp::CHp() : CObject(4)
{
	//********************************
	//メンバ変数のクリア
	//********************************
}

//敵のデストラクタ
CHp::~CHp()
{
	//何も書かない
}

//敵の初期化処理
HRESULT CHp::Init(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//********************************
	//メンバ変数の初期化
	//********************************
	m_nPlayreLife = 0;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(1280.0f, 720.0f - 50.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f - LIFE_WIDTH * m_nPlayreLife, 720.0f - 50.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f - LIFE_WIDTH * m_nPlayreLife, 720.0f, 0.0f);

	// rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// 頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//敵の終了処理
void CHp::Uninit(void)
{
	//頂点バッファの破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//破棄処理
	CObject::Release();
}

//敵の更新処理
void CHp::Update()
{
	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//オブジェクトのポインタ
		CObject *pObject;
		//どのタイプかの情報をポインタに代入
		pObject = GetObjects(3, nCntType);

		//nullチェック
		if (pObject != nullptr)
		{
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//プレイヤーの体力
				m_nPlayreLife = pObject->GetLife();
			}
		}
	}
	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(275.0f - LIFE_WIDTH * m_nPlayreLife, 75.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(275.0f, 75.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(275.0f - LIFE_WIDTH * m_nPlayreLife, 100.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(275.0f, 100.0f, 0.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	if (m_nPlayreLife <= 5)
	{
		SetColor(1.0f, 1.0f, 0.0f, 1.0f);
	}
	if (m_nPlayreLife <= 3)
	{
		SetColor(1.0f, 0.0f, 0.0f, 1.0f);
	}
	if (m_nPlayreLife <= 10 && m_nPlayreLife > 5)
	{
		SetColor(0.0f, 1.0f, 0.0f, 1.0f);
	}
	if (m_nPlayreLife > 10)
	{
		SetColor(0.0f, 0.5f, 1.0f, 1.0f);
		//頂点バッファをロックし、頂点情報へのポインタを取得
		m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(275.0f - LIFE_WIDTH * 10, 75.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(275.0f, 75.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(275.0f - LIFE_WIDTH * 10, 100.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(275.0f, 100.0f, 0.0f);

		//頂点バッファをアンロックする
		m_pVtxBuff->Unlock();
	}
}

//敵の描画処理
void CHp::Draw()
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,									//頂点情報の先頭アドレス
		2);									//プリミティブの数
}

//スポーンの生成
CHp *CHp::Create()
{
	CHp *php = nullptr;

	//クラスの生成
	php = new CHp;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (php != nullptr)
	{
		//初期化処理
		php->Init();
	}
	else
	{
		assert(false);
	}

	return php;
}

//色の設定
void CHp::SetColor(float Red, float Green, float Blue, float α)
{
	VERTEX_2D*pVtx;				//頂点情報へのポインタ

	LPDIRECT3DVERTEXBUFFER9 Buffer = GetBuffer();

	//頂点バッファをロックし、頂点情報へのポインタを取得
	Buffer->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[1].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[2].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[3].col = D3DXCOLOR(Red, Green, Blue, α);

	//頂点バッファをアンロックする
	Buffer->Unlock();
}

//********************************************
//
//	bosshp.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "hp.h"
#include "application.h"
#include "renderer.h"
#include "explosion.h"
#include "fade.h"
#include "input.h"
#include "player.h"

//敵のコンストラクタ
CBossHp::CBossHp() : CObject(3)
{
	//********************************
	//メンバ変数のクリア
	//********************************
}

//敵のデストラクタ
CBossHp::~CBossHp()
{
	//何も書かない
}

//敵の初期化処理
HRESULT CBossHp::Init(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//********************************
	//メンバ変数の初期化
	//********************************
	m_nBossLife = 0;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(1280.0f, 720.0f - 50.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f - BOSSLIFE_WIDTH * m_nBossLife, 720.0f - 50.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f - BOSSLIFE_WIDTH * m_nBossLife, 720.0f, 0.0f);

	// rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// 頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//敵の終了処理
void CBossHp::Uninit(void)
{
	//頂点バッファの破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//破棄処理
	CObject::Release();
}

//敵の更新処理
void CBossHp::Update()
{
	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//オブジェクトのポインタ
		CObject *pObject;
		//どのタイプかの情報をポインタに代入
		pObject = GetObjects(3, nCntType);

		//nullチェック
		if (pObject != nullptr)
		{
			if (pObject->GetType() == TYPE_ENEMY && CEnemy::ENEMYTYPE_BOSS)
			{
				//ボスの体力
				m_nBossLife = pObject->GetLife();
			}
		}
	}
	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(915.0f - BOSSLIFE_WIDTH * m_nBossLife, 676.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(915.0f, 676.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(915.0f - BOSSLIFE_WIDTH * m_nBossLife, 702.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(915.0f, 702.0f, 0.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	SetColor(1.0f, 0.0f, 0.0f, 1.0f);
}

//敵の描画処理
void CBossHp::Draw()
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,									//頂点情報の先頭アドレス
		2);									//プリミティブの数
}

//スポーンの生成
CBossHp *CBossHp::Create()
{
	CBossHp *php = nullptr;

	//クラスの生成
	php = new CBossHp;				//2Dオブジェクトのインスタンス生成

								//nullチェック
	if (php != nullptr)
	{
		//初期化処理
		php->Init();
	}
	else
	{
		assert(false);
	}

	return php;
}

//色の設定
void CBossHp::SetColor(float Red, float Green, float Blue, float α)
{
	VERTEX_2D*pVtx;				//頂点情報へのポインタ

	LPDIRECT3DVERTEXBUFFER9 Buffer = GetBuffer();

	//頂点バッファをロックし、頂点情報へのポインタを取得
	Buffer->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[1].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[2].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[3].col = D3DXCOLOR(Red, Green, Blue, α);

	//頂点バッファをアンロックする
	Buffer->Unlock();
}