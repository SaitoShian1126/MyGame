//********************************************
//
//	tutorial.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "tutorial.h"
#include "application.h"
#include "renderer.h" 
#include "input.h"
#include "object2D.h"
#include "fade.h"
#include "bullet.h"
#include "sound.h"
#include "enter.h"

//チュートリアルのコンストラクタ
CTutorial::CTutorial()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_SoundFlag = false;
}

//チュートリアルのデストラクタ
CTutorial::~CTutorial()
{
	//何も書かない
}

//チュートリアルの初期化処理
HRESULT CTutorial::Init(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/チュートリアル.png",
		&m_pTextureTutorial);

	//********************************
	//メンバ変数の初期化
	//********************************
	m_SoundFlag = false;
	m_flag = false;

	m_pObject = CObject2D::Create(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->SetSize(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->BindTexture(m_pTextureTutorial);

	return S_OK;
}

//チュートリアルの終了処理
void CTutorial::Uninit(void)
{
	//サウンドの停止
	StopSound();
	CObject::Release();
}

//チュートリアルの更新処理
void CTutorial::Update()
{
	if (m_SoundFlag == false)
	{
		//サウンドの再生
		PlaySound(SOUND_LABEL_SOUND1);
		m_SoundFlag = true;
	}
	//インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();

	if (m_pFade->GetFade() == CFade::FADETYPE_NONE && m_flag == false)
	{
		CEnter::Create(D3DXVECTOR3(1000.0f, 650.0f, 0.0f), D3DXVECTOR3(250.0f, 75.0f, 0.0f));
		m_flag = true;
	}

	if (pInput->GetKeyboardTrigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE && CApplication::GetModeType() == CApplication::MODE_TUTORIAL
		|| pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_B) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE && CApplication::GetModeType() == CApplication::MODE_TUTORIAL)
	{
		CFade::SetFade(CApplication::MODE_GAME);
		//サウンドの再生
		PlaySound(SOUND_LABEL_SE_BUTTON);
	}
}

//チュートリアルの描画処理
void CTutorial::Draw()
{

}

//チュートリアルの生成
CTutorial *CTutorial::Create()
{
	CTutorial *ptutorial = nullptr;

	//クラスの生成
	ptutorial = new CTutorial;				//2Dオブジェクトのインスタンス生成

										//nullチェック
	if (ptutorial != nullptr)
	{
		//初期化処理
		ptutorial->Init();
	}
	else
	{
		assert(false);
	}

	return ptutorial;
}