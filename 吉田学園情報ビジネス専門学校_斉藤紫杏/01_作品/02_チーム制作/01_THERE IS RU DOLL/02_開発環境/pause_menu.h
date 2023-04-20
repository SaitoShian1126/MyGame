//=============================================================================
//
// ポーズメニュー処理 [pause_menu.h]
// Author : KADO TAKUMA
// Author : Yuda Kaito
//
//=============================================================================
#ifndef _PAUSE_MENU_H_ 
#define _PAUSE_MENU_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "mode.h"
#include "object2D.h"
#include "application.h"

//=============================================================================
// 前方宣言
//=============================================================================
class CObject2D;

//=============================================================================
// クラスの定義
//=============================================================================
class CPauseMenu : public CObject2D
{
public:
	//-------------------------------------------------------------------------
	// 列挙型
	//-------------------------------------------------------------------------
	enum EMenu
	{
		MENU_QUIT = 0,
		MENU_RETRY,
		MENU_EXIT,
		MENU_MAX
	};

	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	explicit CPauseMenu(int nPriority = PRIORITY_LEVEL4);
	~CPauseMenu();

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init() override;				// 初期化処理
	void Uninit() override;					// 終了処理
	void Update() override;					// 更新処理
	void Draw() override;					// 描画処理
	void PutoutMenu(void);					// メニュー欄出現処理
	void SelectMenu(void);					// メニュー欄選択処理
	static CPauseMenu *Create(void);		// 生成処理

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	static	CObject2D *m_apObject2D[6];		// ポインタ

	D3DXVECTOR3	m_pos[6];					// メニューの座標
	EMenu		m_eMenu;					// メニューのタイプ
	int			m_nTextureMax;				// 使用するテクスチャの最大数
	bool		m_bGame;					// GAMEフラグ
	bool		m_bTutorial;				// TUTORIALフラグ
	bool		m_bRanking;					// RANKINGフラグ
	bool		m_bSelect;					// メニュー選択できるかのフラグ
	bool		m_bGameMenu;				// ゲームメニューフラグ

	static	EMenu	m_eType;				// メニューのタイプ
};
#endif