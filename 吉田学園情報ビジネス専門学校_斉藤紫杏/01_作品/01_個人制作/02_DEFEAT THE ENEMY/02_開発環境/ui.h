//********************************************
//
//	ui.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _UI_H_
#define _UI_H_

//インクルード
#include "main.h"
#include "object2D.h"

//マクロ定義
#define UI_SIZE_X		 (20.0f)	//uiのxサイズ
#define UI_SIZE_Y		 (25.0f)	//uiのyサイズ

//uiクラス
class CUi : public CObject2D
{
public:
	enum UITYPE
	{
		UITYPE_NONE = 0,
		UITYPE_BULLET,
		UITYPE_LIFE
	};
public:
	CUi();							//コンストラクタ
	~CUi()override;					//デストラクタ

	HRESULT Init(void)override;		//uiの初期化処理
	void Uninit(void)override;		//uiの終了処理
	void Update(void)override;		//uiの更新処理
	void Draw(void)override;		//uiの描画処理
	void SetUiType(UITYPE type);	//uiの種類の設定

	UITYPE GetUiType(void) { return UITYPE(); }	//スポーンの種類の取得

	static HRESULT Load(void);		//テクスチャの読み込み
	static void Unload(void);		//テクスチャの破棄
	static CUi *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size,UITYPE type);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureUi[2];	//テクスチャへのポインタ
	UITYPE m_nType;							//uiの種類
};

#endif







