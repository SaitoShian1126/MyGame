//********************************************
//
//	effect.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _EFFECT_H_
#define _EFFECT_H_

//インクルード
#include "main.h"
#include "object2D.h"

//エフェクトクラス
class CEffect : public CObject2D
{
public:
	CEffect();							//コンストラクタ
	~CEffect()override;					//デストラクタ

	HRESULT Init(void)override;			//プレイヤーの初期化処理
	void Uninit(void)override;			//プレイヤーの終了処理
	void Update(void)override;			//プレイヤーの更新処理
	void Draw(void)override;			//プレイヤーの描画処理

	void SetLife(int nLife);			//ライフの設定

	static HRESULT Load(void);			//テクスチャの読み込み
	static void Unload(void);			//テクスチャの破棄
	static CEffect *Create(D3DXVECTOR3 pos,D3DXVECTOR3 size, D3DXCOLOR col, int nLife);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureEffect;	//テクスチャへのポインタ
	D3DXCOLOR m_nCol;							//色
	int m_nLife;								//エフェクトの体力
};

#endif






