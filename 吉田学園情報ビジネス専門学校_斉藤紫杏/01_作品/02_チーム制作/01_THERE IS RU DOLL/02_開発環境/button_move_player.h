//=============================================================================
//
// ボタンを押すとプレイヤーが進むギミック
// Author : saito shian
//
//=============================================================================
#ifndef _BUTTON_MOVE_PLAYER_H_
#define _BUTTON_MOVE_PLAYER_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "gimmick.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_WALK_COUNT (50)		//歩ける時間

//=============================================================================
// クラスの定義
//=============================================================================
class CButtonMovePlayer : public CGimmick
{
public:
	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	explicit CButtonMovePlayer(int nPriority = PRIORITY_LEVEL3);
	~CButtonMovePlayer() override;

	// 生成処理
	static CButtonMovePlayer *Create(const D3DXVECTOR3& pos);

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init() override;		// 初期化処理
	void Uninit() override;			// 終了処理
	void Update() override;			// 更新処理
	void Draw() override;			// 描画処理

	void ConstOperate() override;	// 一定の操作(連打、回転)
	void ButtonPush();				// キーを押す処理

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	int m_RandNumber;	// ランダムの数字
	int m_MoveCount;	// ボタンを押したときに歩く時間
	int m_TimeToMove;	// また動けるまでの時間

	bool m_MoveFlag;	// 歩いているかのフラグ
	bool m_RandFlag;	// ランダムが実行されているか
	bool m_PushFlag;					// Bキーを押しているか
};
#endif
