//********************************************
//
//	particle.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _particle_H_
#define _particle_H_

//インクルード
#include "main.h"
#include "object2D.h"

//マクロ定義
#define MAX_PARTICLESIZE (10.0f);	//パーティクルサイズ

//パーティクルクラス
class CParticle : public CObject2D
{
public:
	CParticle();						//コンストラクタ
	~CParticle()override;				//デストラクタ

	HRESULT Init(void)override;			//パーティクルの初期化処理
	void Uninit(void)override;			//パーティクルの終了処理
	void Update(void)override;			//パーティクルの更新処理
	void Draw(void)override;			//パーティクルの描画処理

	void SetLife(int nLife);			//ライフの設定

	static HRESULT Load(void);			//テクスチャの読み込み
	static void Unload(void);			//テクスチャの破棄
	static CParticle *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, int nLife);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureParticle;	//テクスチャへのポインタ
	static D3DXVECTOR3 m_nMove;						//移動
	D3DXCOLOR m_nCol;								//色
	int m_nLife;									//パーティクルの体力
};

#endif







