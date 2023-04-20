//********************************************
//
//	bullet.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _BULLE_H_
#define _BULLE_H_

//インクルード
#include "main.h"
#include "object2D.h"

//前方宣言
class CFade;

//弾のクラス
class CBullet : public CObject2D
{
public:
	enum BULLETTYPE
	{
		BULLETTYPE_NOMAL = 0,			//ノーマル弾
		BULLETTYPE_SITA,				//下に攻撃する弾
	};
public:
	CBullet();					//弾のコンストラクタ
	~CBullet()override;			//弾のデストラクタ

	HRESULT Init(void);			//弾の初期化処理
	void Uninit(void)override;	//弾の終了処理
	void Update(void)override;	//弾の更新処理
	void Draw(void)override;	//弾の描画処理

	void SetUser(int nUser);
	static bool GetPlayerGameClear() { return PlayerGameClear; }
	static CBullet *Create(const D3DXVECTOR3 &pos,const D3DXVECTOR3 &move,D3DXVECTOR3 size,int nLife, int nUser, BULLETTYPE nType);		//生成
	static int GetBullet(void) { return m_nCntDeath; }

	static HRESULT Load(void);							//テクスチャの読み込み
	static void Unload(void);							//テクスチャの破棄

	BULLETTYPE GetBulletType(void) { return BULLETTYPE(); }	//弾の種類の取得
	void SetBulletType(BULLETTYPE type);					//弾の種類の設定

private:
	static LPDIRECT3DTEXTURE9 m_apTextureBullet[2];		//テクスチャへのポインタ
	static D3DXVECTOR3 m_BulletMove;					//移動量
	static int m_nCntDeath;								//死んだ敵の数
	static bool PlayerGameClear;						//ゲームクリアフラグ

	D3DXVECTOR3 m_BulletPos;							//弾の位置
	BULLETTYPE m_nType;									//弾の種類
	CFade *m_pFade;										//フェードのポインタ
	
	int m_nLife;										//弾の寿命	
	int m_nUser;										//どのタイプが使っているか
	int m_nRand;										//ランダム
	int m_nBossUninitTime;								//ボスが消されるまでの時間
	int m_nItemRand;									//アイテムの種類のランダム

	bool m_flag;										//フラグ			
	bool m_PlayerDeath;
};

#endif