//********************************************
//
//	object.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _OBJECT_H_
#define _OBJECT_H_

//インクルード
#include "main.h"

//マクロ定義
#define MAX_OBJECT	(2048)		//オブジェクトの最大数
#define MAX_DRAWPRIORITY (5)	//プライオリティの最大数

//オブジェクトクラス
class CObject
{
public:
	//オブジェクトの種類
	enum TYPE
	{
		TYPE_NONE = 0,
		TYPE_PLAYER,		//プレイヤー
		TYPE_ENEMY,			//敵
		TYPE_BULLET,		//弾
		TYPE_BOSS,			//ボス
		TYPE_EXPLOSION,		//爆発
		TYPE_SPAWN,			//スポーン
		TYPE_ATTACK,		//攻撃
		TYPE_MODE,			//モード
		TYPE_MPENEMY,		//量産敵
		TYPE_MAX
	};
public:
	explicit CObject(int nPriority = 3);				//オブジェクト優先順位
	virtual ~CObject();									//デストラクタ

	virtual HRESULT Init(void) = 0;						//ポリゴンの初期化処理
	virtual void Uninit(void) = 0;						//ポリゴンの終了処理
	virtual void Update(void) = 0;						//ポリゴンの更新処理
	virtual void Draw(void) = 0;						//ポリゴンの描画処理

	virtual void SetPosition(D3DXVECTOR3 pos) = 0;		//ポリゴンの位置処理
	virtual void SetMove(D3DXVECTOR3 move) = 0;			//ポリゴンの移動処理
	virtual void SetLength(float length) = 0;

	virtual D3DXVECTOR3 GetPos(void) = 0;				//位置の取得処理
	virtual D3DXVECTOR3 GetMove(void) = 0;				//移動量の取得
	virtual D3DXVECTOR3 GetSize(void) = 0;				//サイズの取得処理
	virtual D3DXVECTOR3 GetRot(void) = 0;				//回転の取得
	virtual float GetLength(void) = 0;					//拡大縮小のスケールの取得
	virtual D3DXCOLOR GetCol(void) = 0;					//色の取得処理
	
	virtual int GetLife(void) { return 0; }				//体力の取得
	virtual void SetLife(int nLife) { nLife; }			//体力の設定

	void SetType(TYPE type);							//タイプの設定

	CObject *GetObjects(int nPriority,int nCntType);	//何番目のオブジェクトを取得
	TYPE GetType(void) { return m_Type; }				//タイプの取得処理

	static void ReleaseAll(void);						//すべての破棄処理
	static void UpdateAll(void);						//すべての更新処理
	static void DrawAll(void);							//すべての描画処理
	static void ModeRelease(void);						//モードの破棄

	void Release();										//破棄

private:
	static CObject *m_apObject[MAX_DRAWPRIORITY][MAX_OBJECT];		//オブジェクト2Dのインスタンス
	static int m_nNumAll;											//すべての番号
	TYPE m_Type;													//オブジェクトの種類
	int m_nID;														//格納先の番号
	int m_nPriority;												//描画順
};

#endif


