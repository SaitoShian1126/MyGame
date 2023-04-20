//********************************************
//
//	explosion.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

//インクルード
#include "main.h"
#include "object2D.h"

//マクロ定義
#define MAX_EXPLOSION_PATTERN	(8.0f)	//爆発パターン数の最大値
#define MAX_KOUGEKI_PATTERN		(6.0f)	//攻撃パターン数の最大値
#define EXPLOSION_SIZE			(25.0f)	//爆発の大きさ

//爆発のクラス
class CExplosion : public CObject2D
{
public:
	enum EXPLOTIONTYPE
	{
		EXPLOTIONTYPE_BAKUHATU,	//敵が死んだときの爆発
		EXPLOTIONTYPE_BOSS,	//ボスが死んだときの爆発
		EXPLOTIONTYPE_KOUGEKI	//敵に弾が当たった時の爆発
	};
public:
	CExplosion();											//爆発のコンストラクタ
	~CExplosion()override;									//爆発のデストラクタ
															  
	HRESULT Init(void)override;								//爆発の初期化処理
	void Uninit(void)override;								//爆発の終了処理
	void Update(void)override;								//爆発の更新処理
	void Draw(void)override;								//爆発の描画処理

	static HRESULT Load(void);								//テクスチャの読み込み
	static void Unload(void);								//テクスチャの破棄
	static CExplosion *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, D3DXCOLOR col, EXPLOTIONTYPE nType);	//生成

	EXPLOTIONTYPE GetExplotionType(void) { return EXPLOTIONTYPE(); }	//爆発の種類の取得
	void SetExplotionType(EXPLOTIONTYPE type);							//爆発の種類の設定

private:
	static LPDIRECT3DTEXTURE9 m_pTextureExplosion[2];		//テクスチャへのポインタ
	D3DXVECTOR3 m_ExplosionPos;								//位置
	D3DXCOLOR m_ExplosionCol;								//色
	EXPLOTIONTYPE m_nType;									//爆発のタイプ
	int m_nCounterAnimExplosion;							//アニメーションカウンター
	int m_nPatternAnimExplosion;							//アニメーションXパターンNo.
	int m_nPatternAnimExplosionY;							//アニメーションYパターンNo.
};

#endif