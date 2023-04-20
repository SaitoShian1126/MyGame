//********************************************
//
//	title.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "title.h"
#include "application.h"
#include "renderer.h" 
#include "input.h"
#include "object2D.h"
#include "fade.h"
#include "bullet.h"
#include "sound.h"
#include "enter.h"

//数字のコンストラクタ
CTitle::CTitle()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_SoundFlag = false;
}

//数字のデストラクタ
CTitle::~CTitle()
{
	//何も書かない
}

//数字の初期化処理
HRESULT CTitle::Init(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/タイトル画面.png",
		&m_pTextureTitle);

	//********************************
	//メンバ変数の初期化
	//********************************
	m_SoundFlag = false;
	m_flag = false;

	m_pObject = CObject2D::Create(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->SetSize(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->BindTexture(m_pTextureTitle);

	return S_OK;
}

//数字の終了処理
void CTitle::Uninit(void)
{
	//サウンドの停止
	StopSound();
	CObject::Release();
}

//数字の更新処理
void CTitle::Update()
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
		CEnter::Create(D3DXVECTOR3(640.0f, 550.0f, 0.0f), D3DXVECTOR3(250.0f, 75.0f, 0.0f));
		m_flag = true;
	}

	if (pInput->GetKeyboardTrigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE && CApplication::GetModeType() == CApplication::MODE_TITLE
		|| pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_B) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE && CApplication::GetModeType() == CApplication::MODE_TITLE)
	{
		CFade::SetFade(CApplication::MODE_TUTORIAL);
		//サウンドの再生
		PlaySound(SOUND_LABEL_SE_BUTTON);
	}
}

//数字の描画処理
void CTitle::Draw()
{

}

//数字の生成
CTitle *CTitle::Create()
{
	CTitle *pTitle = nullptr;

	//クラスの生成
	pTitle = new CTitle;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pTitle != nullptr)
	{
		//初期化処理
		pTitle->Init();
	}
	else
	{
		assert(false);
	}

	return pTitle;
}

//色の設定
void CTitle::SetColor(float Red, float Green, float Blue, float α)
{
	VERTEX_2D*pVtx;				//頂点情報へのポインタ

	LPDIRECT3DVERTEXBUFFER9 Buffer = GetBuffer();

	//頂点バッファをロックし、頂点情報へのポインタを取得
	Buffer->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[1].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[2].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[3].col = D3DXCOLOR(Red, Green, Blue, α);

	//頂点バッファをアンロックする
	Buffer->Unlock();
}