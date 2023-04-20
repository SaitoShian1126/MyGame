//********************************************
//
//	result.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "result.h"
#include "application.h"
#include "renderer.h" 
#include "input.h"
#include "fade.h"
#include "bullet.h"
#include "sound.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CResult::m_pTextureResult[3] = {};
CResult::TYPE CResult::m_type = TYPE_NONE;
CNumber *CResult::m_pNumber[7] = {};
int CResult::m_nScore = 0;
int CResult::m_aData = 0;

//リザルトのコンストラクタ
CResult::CResult()
{
	//********************************
	//メンバ変数のクリア
	//********************************
}

//リザルトのデストラクタ
CResult::~CResult()
{
	//何も書かない
}

//リザルトの初期化処理
HRESULT CResult::Init(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/result2.png",
		&m_pTextureResult[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/result.png",
		&m_pTextureResult[1]);

	//テクスチャの読み込みm_aRanking
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/number000.png",
		&m_pTextureResult[2]);

	//********************************
	//メンバ変数の初期化
	//********************************

	m_pObject = CObject2D::Create(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->SetSize(D3DXVECTOR3(640.0f, 360.0f, 0.0f));

		for (int nCnt = 0; nCnt < SCORE_DIGIT; nCnt++)
		{
			m_pNumber[nCnt] = CNumber::Create(D3DXVECTOR3(425.0f + 75.0f * nCnt, 200.0f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f));
			m_pNumber[nCnt]->BindTexture(m_pTextureResult[2]);
		}

	switch (m_type)
	{
	case CResult::TYPE_GAMEOVER:
		m_pObject->BindTexture(m_pTextureResult[0]);
		//サウンドの再生
		PlaySound(SOUND_LABEL_SOUND2);
		break;
	case CResult::TYPE_GAMECLEAR:
		m_pObject->BindTexture(m_pTextureResult[1]);
		//サウンドの再生
		PlaySound(SOUND_LABEL_SOUND3);
		break;
	default:
		break;
	}

	return S_OK;
}

//リザルトの終了処理
void CResult::Uninit(void)
{
	//サウンドの停止
	StopSound();
	CObject::Release();
	//メンバ変数の初期化
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		if (m_pNumber[nCnt] != nullptr)
		{
			m_pNumber[nCnt]->Uninit();
		}

		m_pNumber[nCnt] = nullptr;
	}
}

//リザルトの更新処理
void CResult::Update()
{
	//インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();

	if (pInput->GetKeyboardTrigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE && CApplication::GetModeType() == CApplication::MODE_RESULT
		|| pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_B) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE && CApplication::GetModeType() == CApplication::MODE_RESULT)
	{
		CFade::SetFade(CApplication::MODE_RANKING);
		//サウンドの再生
		PlaySound(SOUND_LABEL_SE_BUTTON);
	}
}

//リザルトの描画処理
void CResult::Draw()
{

}

//リザルトの設定処理
void CResult::SetType(TYPE type)
{
	m_type = type;
}

//リザルトの生成
CResult *CResult::Create()
{
	CResult *pResult = nullptr;

	//クラスの生成
	pResult = new CResult;				//2Dオブジェクトのインスタンス生成

										//nullチェック
	if (pResult != nullptr)
	{
		//初期化処理
		pResult->Init();
	}
	else
	{
		assert(false);
	}

	return pResult;
}
void CResult::SetScore(int Score)
{
	m_nScore = Score;
}

void CResult::SetScore(void)
{
	int aPosTexU[SCORE_DIGIT];	//各桁の数字を格納

	m_aData = m_nScore;

	aPosTexU[0] = m_aData % 10000000 / 1000000;
	aPosTexU[1] = m_aData % 1000000 / 100000;
	aPosTexU[2] = m_aData % 100000 / 10000;
	aPosTexU[3] = m_aData % 10000 / 1000;
	aPosTexU[4] = m_aData % 1000 / 100;
	aPosTexU[5] = m_aData % 100 / 10;
	aPosTexU[6] = m_aData % 10 / 1;


	for (int nCnt = 0; nCnt < SCORE_DIGIT; nCnt++)
	{
		//分割数,何番目か
		m_pNumber[nCnt]->SetTexture(10.0f, (float)aPosTexU[nCnt], 1.0f, 0.0f);
	}
}
