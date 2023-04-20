//********************************************
//
//	item.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _ITEM_H_
#define _ITEM_H_

//インクルード
#include "main.h"
#include "object2D.h"

//アイテムクラス
class CItem : public CObject2D
{
public:
	enum ITEMTYPE
	{
		ITEMTYPE_SCOREUP = 0,			//スコアアップアイテム
		ITEMTYPE_LIFEUP,				//体力アップアイテム
		ITEMTYPE_ATTACKUP				//攻撃力アップアイテム
	};
public:
	CItem();							//コンストラクタ
	~CItem()override;					//デストラクタ

	HRESULT Init(void)override;			//アイテムの初期化処理
	void Uninit(void)override;			//アイテムの終了処理
	void Update(void)override;			//アイテムの更新処理
	void Draw(void)override;			//アイテムの描画処理
	void SetItemType(ITEMTYPE type);	//アイテムの種類の設定

	static int GetAttackCount(void) { return m_AttackCount; }	//攻撃アイテムのカウントの取得
	static HRESULT Load(void);									//テクスチャの読み込み
	static void Unload(void);									//テクスチャの破棄
	static CItem *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, ITEMTYPE nType);	//生成

	ITEMTYPE GetItemType(void) { return ITEMTYPE(); }	//アイテムの種類の取得

private:
	static LPDIRECT3DTEXTURE9 m_pTextureItem[3];	//テクスチャへのポインタ
	static int m_AttackCount;						//攻撃アイテムのカウント
	ITEMTYPE m_nType;								//敵の種類
	int m_nRand;									//ランダム
	int m_ItemMoveTimeCount;						//アイテムが動くまでの時間
	int m_nItemMoveTime;							//移動するまでの時間
	int m_AttackItemUninitCount;					//攻撃アイテム削除までの時間
	bool m_flag;									//アイテムがいつどの動きをするかのフラグ
};

#endif






