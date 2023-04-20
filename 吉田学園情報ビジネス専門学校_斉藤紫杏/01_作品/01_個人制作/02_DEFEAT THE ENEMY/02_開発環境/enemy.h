//********************************************
//
//	enemy.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _ENEMY_H_
#define _ENEMY_H_

//インクルード
#include "main.h"
#include "object2D.h"

//マクロ定義
#define ENEMY_SIZE_X			(35.0f)		//敵のxサイズ
#define ENEMY_SIZE_Y			(35.0f)		//敵のyサイズ
#define ENEMY_MOVE_X			(-3.0f)		//敵のxの移動量
#define ENEMY_MOVE_Y			(6.0f)		//敵のyの移動量
#define RANGE_HIGH_Y			(450.0f)	//yの範囲(高さ)
#define RANGE_DOWN_Y			(650.0f)	//yの範囲(低さ)
#define TIME					(200)		//時間
#define ENEMY_LIFE_MEDAMA		(10)		//目玉の体力
#define ENEMY_LIFE_BOMB			(5)			//爆弾の体力
#define ENEMY_LIFE_ZIGUZAGU		(30)		//ジグザグの体力
#define ENEMY_LIFE_ENN			(25)		//円の体力
#define ENEMY_LIFE_HEBI			(20)		//蛇の体力
#define ENEMY_LIFE_RANDAM		(250)		//ランダム(ボス)の体力
#define ENEMY_LIFE_KYODAIMEDAMA	(15)		//巨大目玉の体力
#define ENEMY_LIFE_SOGEKI		(5)			//狙撃の体力

#define BOSS_SIZE_X				(200.0f)	//敵のxサイズ
#define BOSS_SIZE_Y				(225.0f)	//敵のyサイズ
#define BOSS_BULLET_TIME		(100)		//敵が攻撃してくるまでの時間	
#define BOSS_LIFE				(899)		//ボスの体力

#define MAX_BOSSTEXTURE_X		(2.0f)		//ボスのxのテクスチャ
#define MAX_BOSSTEXTURE_Y		(6.0f)		//ボスのyのテクスチャ

//敵クラス
class CEnemy : public CObject2D
{
public:
	//敵の種類
	enum ENEMYTYPE
	{
		ENEMYTYPE_NONE = 0,
		ENEMYTYPE_MEDAMA,			//目玉の敵
		ENEMYTYPE_BOMB,				//爆発する敵
		ENEMYTYPE_ZIGUZAGU,			//ジグザグに動く敵
		ENEMYTYPE_ENN,				//円を描く敵
		ENEMYTYPE_HEBI,				//蛇の敵
		ENEMYTYPE_BOSS,				//ボス
		ENEMYTYPE_KYODAIMEDAMA,		//巨大目玉
		ENEMYTYPE_SOGEKI,			//狙撃敵
		ENEMYTYPE_BOSSTUKAI,		//ボスが出す敵
		ENEMYTYPE_MAX
	};

public:
	CEnemy();							//コンストラクタ
	~CEnemy()override;					//デストラクタ

	HRESULT Init(void)override;			//敵の初期化処理
	void Uninit(void)override;			//敵の終了処理
	void Update(void)override;			//敵の更新処理
	void Draw(void)override;			//敵の描画処理

	int GetLife(void)override { return m_nLife; }	//体力の取得
	void SetLife(int nLife)override;				//体力の設定

	ENEMYTYPE GetEnemyType(void) { return ENEMYTYPE(); }	//敵の種類の取得
	void SetEnemyType(ENEMYTYPE type);	//敵の種類の設定

	void HitJudgment(D3DXVECTOR3 pos);				//敵の当たり判定
	void HitBossJudgment(D3DXVECTOR3 pos);			//ボスの当たり判定

	static bool GetPlayerDeathFlag() { return m_PlayerGameOver; }
	static HRESULT Load(void);			//テクスチャの読み込み
	static void Unload(void);			//テクスチャの破棄
	static CEnemy *Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move, D3DXVECTOR3 size,ENEMYTYPE nType, int nLife);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureEnemy[7];	//テクスチャへのポインタ
	static bool m_PlayerGameOver;					//プレイヤーが死んだのかフラグ
	D3DXVECTOR3 m_BulletMove;						//弾の移動
	ENEMYTYPE m_nType;								//敵の種類
	float m_fRotMove;								//向きの移動
	int m_nLife;									//敵の体力
	int m_sLifeTime;								//時間で死ぬ敵		
	int m_nTime;									//敵が攻撃してくるまでの時間
	int m_nRand;									//ランダム
	int m_nCounterAnimEnemy;						//アニメーションカウンター
	int m_nPatternAnimEnemy;						//アニメーションパターンNo.
	int m_Count;									//カウント
	int m_nBulletCnt;								//弾のカウント
	int m_nAttackTime;								//敵が攻撃してくるまでの時間
	int m_nAttackTime2;								//敵が攻撃してくるまでの時間
	int m_AttackCount;								//攻撃時間
	int m_nBossTime;								//ボスのカウント
	int m_nMoveTime;								//移動するまでの時間
	bool m_flag;									//敵がいつどの動きをするかのフラグ
	bool m_flag2;									//敵がいつどの動きをするかのフラグ
	bool m_UseFlag;									//使われているかのフラグ
	bool m_Bossflag1;								//ボスのフラグ1
	bool m_Bossflag2;								//ボスのフラグ2
	bool m_Bossflag3;								//ボスのフラグ3
	bool m_Bossflag4;								//ボスのフラグ4
};

#endif





