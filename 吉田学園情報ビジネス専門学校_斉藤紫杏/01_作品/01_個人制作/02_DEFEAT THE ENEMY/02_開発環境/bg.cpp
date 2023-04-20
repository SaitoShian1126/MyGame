//********************************************
//
//	bg.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "bg.h"
#include "renderer.h"
#include "object.h"
#include "application.h"
#include "input.h"
#include "bullet.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CBg::m_pTexture = {};

//オブジェクトのコンストラクタ
CBg::CBg() : CObject(0)
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_pVtxBuff = nullptr;						//バッファのクリア
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//位置のクリア
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//移動のクリア
}

//オブジェクトのデストラクタ
CBg::~CBg()
{
	//何も書かない
}

//オブジェクト(ポリゴン)の初期化処理
HRESULT CBg::Init(void)
{
	//********************************
	//メンバ変数の初期化
	//********************************
	m_pVtxBuff = nullptr;											//バッファの初期化
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);							//位置の初期化
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);							//移動の初期化

	m_fPosTexV = 0.0f;												//テクスチャ座標の開始位置(V値)
	
	m_fPosTexV;

	//テクスチャ反映
	BindTexture(m_pTexture);
	
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

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点情報を設定
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0);

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
	pVtx[0].tex = D3DXVECTOR2(m_fPosTexV, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(m_fPosTexV + 1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(m_fPosTexV, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(m_fPosTexV + 1.0f, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//オブジェクト(ポリゴン)の終了処理
void CBg::Uninit(void)
{
	//頂点バッファの破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//破棄処理
	Release();
}

//オブジェクト(ポリゴン)の更新処理
void CBg::Update(void)
{
	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0);

	m_fPosTexV += 0.002f;

	//頂点座標の設定
	pVtx[0].tex = D3DXVECTOR2(m_fPosTexV, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(m_fPosTexV + 1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(m_fPosTexV, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(m_fPosTexV + 1.0f, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//オブジェクト(ポリゴン)の描画処理
void CBg::Draw(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,									//頂点情報の先頭アドレス
		2);											//プリミティブの数
	//テクスチャの解除
	pDevice->SetTexture(0, NULL);
}

//生成
CBg *CBg::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size)
{
	CBg *pBg = nullptr;

	//2Dオブジェクトクラスの生成
	pBg = new CBg;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pBg != nullptr)
	{
		//初期化処理
		pBg->Init();
		//設定処理
		pBg->SetPosition(pos);
		pBg->SetSize(size);
	}
	else
	{
		assert(false);
	}
	return pBg;
}

//テクスチャ読み込み
HRESULT CBg::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/bg108.png",
		&m_pTexture);

	return S_OK;
}

//テクスチャ破棄
void CBg::Unload(void)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}
}

//ポリゴンのサイズの設定処理
void CBg::SetSize(D3DXVECTOR3 size)
{
	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	m_size = size;

	m_fLength = sqrtf(((m_size.x * m_size.x) + (m_size.y * m_size.y))) / 2;	//拡大縮小のスケールの初期化
	m_fAngle = atan2f(m_size.y, m_size.x);									//角度の初期化

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点情報の更新
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//テクスチャ反映
void CBg::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}