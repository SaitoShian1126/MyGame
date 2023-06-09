//=============================================================================
//
// マネージャ処理 [application.h]
// Author : KADO TAKUMA
//
//=============================================================================
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"

//=============================================================================
// クラスの前方定義
//=============================================================================
class CInput;
class CCamera;
class CLight;
class CObjectX;
class CMeshfield;
class CTime;
class CTexture;
class CObjectXGroup;
class CSound;

//=============================================================================
// クラスの定義
//=============================================================================
class CApplication
{
public:

	//=============================================================================
	// 列挙型
	//=============================================================================
	enum MODE
	{
		MODE_TITLE = 0,
		MODE_GAME_SOLO,
		MODE_GAME_VS,
		MODE_RESULT,
		MODE_RANKING,
		MODE_TUTORIAL,
		MODE_MAX
	};

	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	CApplication();
	~CApplication();

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, bool bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static void SetMode(MODE mode);
	static MODE GetMode();
	static CRenderer *GetRenderer();
	static CInput *GetInput();
	static CCamera *GetCamera() { return m_pCamera; }
	static CTexture *GetTexture() { return m_pTexture; }
	static CObjectXGroup *GetObjectXGroup() { return m_pObjectXGroup; }
	static CSound *GetSound() { return m_pSound; }

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	static CRenderer *m_pRenderer;
	static CInput *m_pInput;
	static MODE m_mode;
	static CObject *m_pMode;
	static CCamera *m_pCamera;
	static CTexture *m_pTexture;
	static CObjectXGroup *m_pObjectXGroup;
	static CSound *m_pSound;
};

#endif