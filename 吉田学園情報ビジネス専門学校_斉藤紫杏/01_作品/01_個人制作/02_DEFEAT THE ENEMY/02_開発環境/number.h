//********************************************
//
//	number.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _NUMBER_H_
#define _NUMBER_H_

//インクルード
#include "main.h"
#include "object2D.h"

//マクロ定義
#define NUMBER_SIZE_X		 (25.0f)	//数字のxサイズ
#define NUMBER_SIZE_Y		 (250.0f)	//数字のyサイズ

//数字クラス
class CNumber : public CObject2D
{
public:
	CNumber();							//コンストラクタ
	~CNumber()override;					//デストラクタ

	HRESULT Init(void)override;			//数字の初期化処理
	void Uninit(void)override;			//数字の終了処理
	void Update(void)override;			//数字の更新処理
	void Draw(void)override;			//数字の描画処理

	static HRESULT Load(void);			//テクスチャの読み込み
	static void Unload(void);			//テクスチャの破棄
	static CNumber *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureNumber;		//テクスチャへのポインタ
};

#endif





