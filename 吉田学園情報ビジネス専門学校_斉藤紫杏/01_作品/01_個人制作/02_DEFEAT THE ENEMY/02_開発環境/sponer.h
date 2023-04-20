//********************************************
//
//	sponer.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _SPONER_H_
#define _SPONER_H_

//インクルード
#include "main.h"
#include "object2D.h"

//スポナークラス
class CSponer : public CObject2D
{
public:
	CSponer();							//コンストラクタ
	~CSponer()override;					//デストラクタ

	HRESULT Init(void)override;			//スポナーの初期化処理
	void Uninit(void)override;			//スポナーの終了処理
	void Update(void)override;			//スポナーの更新処理
	void Draw(void)override;			//スポナーの描画処理

	static HRESULT Load(void);			//テクスチャの読み込み
	static void Unload(void);			//テクスチャの破棄
	static CSponer *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureSponer;		//テクスチャへのポインタ
};

#endif






