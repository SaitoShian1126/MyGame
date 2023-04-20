//********************************************
//
//	player.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _PLAYER_H_
#define _PLAYER_H_

//インクルード
#include "main.h"
#include "object2D.h"
#include "bullet.h"

//マクロ定義
#define PLAYER_SIZE_X	(50.0f)	//プレイヤーのxサイズ
#define PLAYER_SIZE_Y	(35.0f)	//プレイヤーのyサイズ
#define BULLET_TIME		(6)		//弾が出る時間

//プレイヤークラス
class CPlayer : public CObject2D
{
public:
	CPlayer();							//コンストラクタ
	~CPlayer()override;					//デストラクタ

	HRESULT Init(void)override;			//プレイヤーの初期化処理
	void Uninit(void)override;			//プレイヤーの終了処理
	void Update(void)override;			//プレイヤーの更新処理
	void Draw(void)override;			//プレイヤーの描画処理
	void SetLife(int nLife)override;					//体力の設定
	int GetLife(void)override { return m_nLife; }		//体力の取得

	static bool GetBulletFlag() { return BulletFlag; }	//弾のフラグの取得処理
	static HRESULT Load(void);							//テクスチャの読み込み
	static void Unload(void);							//テクスチャの破棄
	static CPlayer *Create(int nLife);					//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTexturePlayer;	//テクスチャへのポインタ
	static 	int m_nLife;						//プレイヤーの体力
	static bool BulletFlag;						//弾のフラグ	
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;			//頂点バッファのポインタ
	D3DXVECTOR3	m_PlayerPos;					//位置
	int m_nTime;								//弾発射までの時間
};

#endif





