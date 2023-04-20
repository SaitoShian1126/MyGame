//********************************************
//
//	attack.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _ATTACK_H_
#define _ATTACK_H_

//インクルード
#include "main.h"
#include "object2D.h"

//スポナークラス
class CAttack : public CObject2D
{
public:
	CAttack();							//コンストラクタ
	~CAttack()override;					//デストラクタ

	HRESULT Init(void)override;			//攻撃の初期化処理
	void Uninit(void)override;			//攻撃の終了処理
	void Update(void)override;			//攻撃の更新処理
	void Draw(void)override;			//攻撃の描画処理

	static HRESULT Load(void);			//テクスチャの読み込み
	static void Unload(void);			//テクスチャの破棄
	static CAttack *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 move,D3DXVECTOR3 size);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureAttack;		//テクスチャへのポインタ
	int m_nTime;									//攻撃するまでの時間
};

//********************************************
//
//	attack2.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _ATTACK2_H_
#define _ATTACK2_H_

//インクルード
#include "main.h"
#include "object2D.h"

//攻撃2クラス
class CAttack2 : public CAttack
{
public:
	CAttack2();							//コンストラクタ
	~CAttack2()override;				//デストラクタ

	HRESULT Init(void)override;			//攻撃2の初期化処理
	void Uninit(void)override;			//攻撃2の終了処理
	void Update(void)override;			//攻撃2の更新処理
	void Draw(void)override;			//攻撃2の描画処理

	static HRESULT Load(void);			//テクスチャの読み込み
	static void Unload(void);			//テクスチャの破棄
	static CAttack2 *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 move, D3DXVECTOR3 size);	//生成

private:
	static LPDIRECT3DTEXTURE9 m_pTextureAttack2;		//テクスチャへのポインタ
	int m_nTime;									//攻撃2するまでの時間
};

#endif









#endif







