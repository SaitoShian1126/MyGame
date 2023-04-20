//=============================================================================
//
// モデル処理 [model.h]
// Author : saito shian
//
//=============================================================================
#ifndef _MODEL_H_
#define _MODEL_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "objectX.h"

//=============================================================================
// 前方定義
//=============================================================================

//=============================================================================
// クラスの定義
//=============================================================================
class CModel : public CObjectX
{
public:
	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	explicit CModel(int nPriority = PRIORITY_LEVEL3);
	~CModel() override;

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init() override;			// 初期化処理
	void Uninit() override;				// 終了処理
	void Update() override;				// 更新処理		
	void Draw()	override;				// 描画処理

	static CModel *Create(const D3DXVECTOR3 pos, int nPriority);    // 生成処理

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------

};
#endif
