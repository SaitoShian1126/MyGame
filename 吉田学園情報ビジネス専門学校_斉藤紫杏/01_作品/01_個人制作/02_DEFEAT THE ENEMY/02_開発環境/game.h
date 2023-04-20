//********************************************
//
//	game.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _GAME_H_
#define _GAME_H_

//インクルード
#include "main.h"
#include "mode.h"

//前方宣言
class CObject2D;

//ゲームクラス
class CGame : public CMode
{
public:
	CGame();						//コンストラクタ
	~CGame();					//デストラクタ

	HRESULT Init(void);			//ゲームの初期化処理
	void Uninit(void);			//ゲームの終了処理
	void Update(void);			//ゲームの更新処理
	void Draw(void);			//ゲームの描画処理

	static CScore *GetScore(void) { return m_pScore; }			//スコアの取得処理
	static CGame *Create();										//生成

private:
	static CScore *m_pScore;				//スコアのポインタ	
	int EnemyMoveTime;						//敵が動き始めるまでの時間
	int nCntdeath;							//敵が何体死んだかを保存する
	int m_CountTime;						//サウンドが変化する時間
	bool m_flag;							//フラグ1
	bool m_flag2;							//フラグ2
	bool m_flag3;							//フラグ3
};

#endif






