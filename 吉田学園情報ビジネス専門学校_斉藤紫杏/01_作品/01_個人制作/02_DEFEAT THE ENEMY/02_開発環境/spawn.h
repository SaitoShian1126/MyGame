//********************************************
//
//	spawn.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _SPAWN_H_
#define _SPAWN_H_

//インクルード
#include "main.h"
#include "object2D.h"

//マクロ定義
#define SPAWN_SIZE_X		 (20.0f)	//スポーンのxサイズ
#define SPAWN_SIZE_Y		 (25.0f)	//スポーンのyサイズ

//スポーンクラス
class CSpawn : public CObject2D
{
public:
	enum SPAWNTYPE
	{
		SPAWNTYPE_MAGICCIRCLE1 = 0,
		SPAWNTYPE_MAGICCIRCLE2,
		SPAWNTYPE_MAGICCIRCLE3
	};
public:
	CSpawn();							//コンストラクタ
	~CSpawn()override;					//デストラクタ

	HRESULT Init(void)override;			//スポーンの初期化処理
	void Uninit(void)override;			//スポーンの終了処理
	void Update(void)override;			//スポーンの更新処理
	void Draw(void)override;			//スポーンの描画処理
	void SetSpawnType(SPAWNTYPE type);	//スポーンの種類の設定
	void SetLife(int nLife)override;	//体力の設定

	SPAWNTYPE GetSpawnType(void) { return SPAWNTYPE(); }	//スポーンの種類の取得

	int GetLife(void)override { return m_nLife; }			//体力の取得

	static HRESULT Load(void);								//テクスチャの読み込み
	static void Unload(void);								//テクスチャの破棄
	static CSpawn *Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move, D3DXVECTOR3 size, SPAWNTYPE nType, int nLife);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureSpawn[3];	//テクスチャへのポインタ
	SPAWNTYPE m_nType;								//スポーンの種類
	int m_nUninitTimer;								//削除時間
	int m_nTimer;									//拡大縮小時間
	int m_nLife;
};

#endif





