//=============================================================================
//
// タイトルメニュー処理 [title_menu.h]
// Author : KADO TAKUMA
//
//=============================================================================
#ifndef _TITLE_MENU_H_ 
#define _TITLE_MENU_H_

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
class CFade;

//=============================================================================
// クラスの定義
//=============================================================================
class CTitleMenu : public CObject2D
{
public:
	//-------------------------------------------------------------------------
	// 列挙型
	//-------------------------------------------------------------------------
	enum EMenu
	{
		MENU_GAME = 0,
		MENU_TUTORIAL,
		MENU_RANKING,
		MENU_MAX
	};

	enum EGameMenu
	{
		MENU_SOLO = 0,
		MENU_VS,
		MENU_MAX2
	};

	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	explicit CTitleMenu(int nPriority = PRIORITY_LEVEL4);
	~CTitleMenu();

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init() override;				// 初期化処理
	void Uninit() override;					// 終了処理
	void Update() override;					// 更新処理
	void Draw() override;					// 描画処理
	void PutoutMenu(void);					// メニュー欄出現処理
	void SelectMenu(void);					// メニュー欄選択処理
	static CTitleMenu *Create(void);		// 生成処理

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	static	CObject2D *m_apObject2D[6];			// ポインタ
	CFade	*m_pFade;							// フェードのポインタ

	D3DXVECTOR3	m_pos[6];						// メニューの座標
	int			m_eMenu;						// メニューのタイプ
	int			m_eGameMenu;					// ゲームメニューのタイプ
	int			m_nTextureMax;					// 使用するテクスチャの最大数
	bool		m_bGame;						// GAMEフラグ
	bool		m_bTutorial;					// TUTORIALフラグ
	bool		m_bRanking;						// RANKINGフラグ
	bool		m_bSelect;						// メニュー選択できるかのフラグ
	bool		m_bGameMenu;					// ゲームメニューフラグ

	static	EMenu	m_eType;					// メニューのタイプ
};
#endif