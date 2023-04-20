//********************************************
//
//	application.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <time.h>
#include "application.h"
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "input.h"
#include "player.h"
#include "explosion.h"
#include "enemy.h"
#include "effect.h"
#include "bg.h"
#include "spawn.h"
#include "number.h"
#include "score.h"
#include "item.h"
#include "sponer.h"
#include "attack.h"
#include "particle.h"
#include "trajectory.h"
#include "game.h"
#include "result.h"
#include "fade.h"
#include "mode.h"
#include "ranking.h"
#include "tutorial.h"

//静的メンバ変数宣言
CRenderer *CApplication::m_pRenderer = nullptr;
CInput *CApplication::m_pInput = nullptr;
CJoyPad *CApplication::m_pInputJoyKey = nullptr;
CMode *CApplication::m_pMode = nullptr;
CApplication::MODE CApplication::m_mode = MODE_TITLE;

//アプリケーションのコンストラクタ
CApplication::CApplication()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_pRenderer = nullptr;
}

//アプリケーションのデストラクタ
CApplication::~CApplication()
{
	//何も書かない
}

//アプリケーションの初期化処理
HRESULT CApplication::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
	//********************************
	//メンバ変数の初期化
	//********************************
	m_pRenderer = nullptr;
	m_pInput = nullptr;
	m_pInputJoyKey = nullptr;
	m_pMode = nullptr;
	m_mode = MODE_TITLE;

	//レンダリングクラスの生成
	m_pRenderer = new CRenderer;

	// 初期化処理
	if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
	{//初期化処理が失敗した場合
		return -1;
	}

	//インプットのインスタンス生成
	m_pInput = new CInput;
	m_pInputJoyKey = new CJoyPad;

	//キーボードの初期化処理
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//ジョイパッドの初期化処理
	if (FAILED(m_pInputJoyKey->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	CFade::Create(MODE_TITLE);

	return S_OK;
}

//アプリケーションの終了処理
void CApplication::Uninit(void)
{
	//キーボードの破棄
	if (m_pInput != nullptr)
	{
		//キーボードの終了処理
		m_pInput->Uninit();

		delete m_pInput;
		m_pInput = nullptr;
	}

	//ジョイパッドの破棄
	if (m_pInputJoyKey != nullptr)
	{
		//ジョイパッドの終了処理
		m_pInputJoyKey->Uninit();

		delete m_pInputJoyKey;
		m_pInputJoyKey = nullptr;
	}

	//レンダリングの破棄
	if (m_pRenderer != nullptr)
	{
		//レンダリングの終了処理
		m_pRenderer->Uninit();

		delete m_pRenderer;
		m_pRenderer = nullptr;
	}
	//オブジェクトの破棄処理
	CObject::ReleaseAll();
}

//アプリケーションの更新処理
void CApplication::Update(void)
{
	//**********************************************
	//	更新処理
	//**********************************************
	if (m_pInput != nullptr)
	{
		//キーボードの更新処理
		m_pInput->Update();
	}

	if (m_pInputJoyKey != nullptr)
	{
		//ジョイパッドの更新処理
		m_pInputJoyKey->Update();
	}

	if (m_pRenderer != nullptr)
	{
		//レンダリングの更新処理
		m_pRenderer->Update();
	}

	if (m_pMode != nullptr)
	{
		m_pMode->Update();
	}
}

//アプリケーションの描画処理
void CApplication::Draw(void)
{
	if (m_pRenderer != nullptr)
	{
		//レンダリングの描画処理
		m_pRenderer->Draw();
	}
}

//レンダリングのインスタンス取得処理
CRenderer *CApplication::GetRenderer (void)
{
	return m_pRenderer;
}

//モードの設定処理
void CApplication::SetMode(MODE mode)
{
	if (m_pMode != nullptr)
	{
		m_pMode->Uninit();
		m_pMode = nullptr;
	}
	
	CObject::ModeRelease();

	m_mode = mode;

	switch (m_mode)
	{
	case CApplication::MODE_TITLE:
		m_pMode = CTitle::Create();
		break;
	case CApplication::MODE_TUTORIAL:
		m_pMode = CTutorial::Create();
		break;
	case CApplication::MODE_GAME:
		m_pMode = CGame::Create();
		break;
	case CApplication::MODE_RESULT:
		m_pMode = CResult::Create();
		CResult::SetScore();
		break;
	case CApplication::MODE_RANKING:
		m_pMode = CRanking::Create();
		CRanking::SetRankingScore();
		break;
	case CApplication::MODE_MAX:
		break;
	default:
		break;
	}
}


