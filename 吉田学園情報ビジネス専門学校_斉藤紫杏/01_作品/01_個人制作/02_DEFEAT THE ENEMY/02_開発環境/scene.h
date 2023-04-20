//********************************************
//
//	scene.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _SCENE_H_
#define _SCENE_H_

//インクルード
#include "main.h"
#include "object2D.h"

//マクロ定義
#define SCENE_SIZE_X		 (20.0f)	//シーンのxサイズ
#define SCENE_SIZE_Y		 (25.0f)	//シーンのyサイズ

//スポーンクラス
class CScene : public CObject2D
{
public:
	enum SCENETYPE
	{
		SCENETYPE_NONE = 0,
		SCENETYPE_BOSS,
		SCENETYPE_START,
		SCENETYPE_MAX
	};
public:
	CScene();							//コンストラクタ
	~CScene()override;					//デストラクタ

	HRESULT Init(void)override;			//シーンの初期化処理
	void Uninit(void)override;			//シーンの終了処理
	void Update(void)override;			//シーンの更新処理
	void Draw(void)override;			//シーンの描画処理

	static HRESULT Load(void);			//テクスチャの読み込み
	static void Unload(void);			//テクスチャの破棄
	static CScene *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, SCENETYPE type);	//生成

	SCENETYPE GetSceneType(void) { return SCENETYPE(); }	//シーンの種類の取得
	void SetSceneType(SCENETYPE type);						//シーンの種類の設定

private:
	static LPDIRECT3DTEXTURE9 m_pTextureScene[2];	//テクスチャへのポインタ
	SCENETYPE m_nType;								//シーンの種類
	int m_nUninitTimer;								//削除時間	
	bool m_flag;									//フラグ
};

#endif






