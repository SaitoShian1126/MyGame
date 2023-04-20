//********************************************
//
//	trajectory.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _TRAJECTORY_H_
#define _TRAJECTORY_H_

//インクルード
#include "main.h"
#include "object2D.h"

//マクロ定義
#define TRAJECTORY_SIZE_X		 (40.0f)	//軌道のxサイズ
#define TRAJECTORY_SIZE_Y		 (25.0f)	//軌道のyサイズ

//軌道クラス
class CTrajectory : public CObject2D
{
public:
	enum TRAJECTORY
	{
		TRAJECTORY_NONE = 0,
		TRAJECTORY_DOWN,		//軌道下
		TRAJECTORY_LIGHTDOWN,	//軌道右下
		TRAJECTORY_LEFTDOWN,	//軌道左下
		TRAJECTORY_LIGHT,		//軌道右
		TRAJECTORY_LEFT,		//軌道左
		TRAJECTRY_MAX
	};
public:
	CTrajectory();						//コンストラクタ
	~CTrajectory()override;				//デストラクタ

	HRESULT Init(void)override;			//軌道の初期化処理
	void Uninit(void)override;			//軌道の終了処理
	void Update(void)override;			//軌道の更新処理
	void Draw(void)override;			//軌道の描画処理
	void SetTrajectoryType(TRAJECTORY type);					//軌道の種類の設定
	TRAJECTORY GetTrajectoryType(void) { return TRAJECTORY(); }	//軌道の種類の取得
	
	static HRESULT Load(void);									//テクスチャの読み込み
	static void Unload(void);									//テクスチャの破棄
	static CTrajectory *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, TRAJECTORY nType);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureTrajectory[5];		//テクスチャへのポインタ
	TRAJECTORY m_nType;										//軌道の種類
	int m_UninitCount;										//消えるまでの時間
	bool m_flag;											//フラグ
};

#endif






