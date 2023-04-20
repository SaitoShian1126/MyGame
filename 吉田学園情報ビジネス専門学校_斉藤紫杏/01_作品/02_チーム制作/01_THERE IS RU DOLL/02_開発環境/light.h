//=============================================================================
//
// ライト処理 [light.cpp]
// Author : KADO TAKUMA
//
//=============================================================================
#ifndef _LIGHT_H_
#define _LIGHT_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"

//=============================================================================
//マクロ定義
//=============================================================================
#define MAX_LIGHT	(5)		//ライトの最大数 

//=============================================================================
// クラスの定義
//=============================================================================
class CLight
{
public:
	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	CLight();
	~CLight();

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init(void);					// 初期化処理
	void Uninit(void);					// 終了処理
	void Update(void);					// 更新処理
	static CLight *Create(void);		// 生成処理

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	D3DLIGHT9 m_aLight[MAX_LIGHT];		//ライト情報
};

#endif