//********************************************
//
//	score.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "score.h"
#include "application.h"
#include "renderer.h" 
#include "ranking.h"
#include "result.h"

//数字のコンストラクタ
CScore::CScore() : CObject(4)
{
	//********************************
	//メンバ変数のクリア
	//********************************
	for (int nCnt = 0; nCnt < SCORE_DIGIT; nCnt++)
	{
		m_apNumber[nCnt] = nullptr;
	}
}

//数字のデストラクタ
CScore::~CScore()
{
	//何も書かない
}

//数字の初期化処理
HRESULT CScore::Init(void)
{
	//********************************
	//メンバ変数の初期化
	//********************************
	for (int nCnt = 0; nCnt < SCORE_DIGIT; nCnt++)
	{
		m_apNumber[nCnt] = nullptr;
	}

	for (int nCnt = 0; nCnt < SCORE_DIGIT; nCnt++)
	{
		//数字の生成
		m_apNumber[nCnt] = CNumber::Create(D3DXVECTOR3(50.0f + 50.0f * nCnt, 50.0f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f));
	}
	m_nScore = 0;
	return S_OK;
}

//数字の終了処理
void CScore::Uninit(void)
{
	//メンバ変数の初期化
	for (int nCnt = 0; nCnt < SCORE_DIGIT; nCnt++)
	{
		if (m_apNumber[nCnt] != nullptr)
		{
			m_apNumber[nCnt]->Uninit();
		}

		m_apNumber[nCnt] = nullptr;
	}

	CObject::Release();
}

//数字の更新処理
void CScore::Update()
{
	
}

//数字の描画処理
void CScore::Draw()
{

}

//スコアの設定処理
void CScore::SetScore(int nScore)
{
	int aPosTexU[7];	//各桁の数字を格納
	m_nScore = nScore;

	aPosTexU[0] = m_nScore % 10000000 / 1000000;
	aPosTexU[1] = m_nScore % 1000000 / 100000;
	aPosTexU[2] = m_nScore % 100000 / 10000;
	aPosTexU[3] = m_nScore % 10000 / 1000;
	aPosTexU[4] = m_nScore % 1000 / 100;
	aPosTexU[5] = m_nScore % 100 / 10;
	aPosTexU[6] = m_nScore % 10 / 1;

	for (int nCnt = 0; nCnt < SCORE_DIGIT; nCnt++)
	{
		//分割数,何番目か
		m_apNumber[nCnt]->SetTexture(10.0f, (float)aPosTexU[nCnt], 1.0f, 0.0f);
	}
	CRanking::SetRanking(m_nScore);
	CResult::SetScore(m_nScore);
}

//スコアの加算処理
void CScore::AddScore(int nValue)
{
	//メンバ変数にスコアを加算
	SetScore(m_nScore + nValue);
}

//スコアの減算処理
void CScore::SubScore(int nSubtract)
{
	//メンバ変数にスコアを減算
	SetScore(m_nScore - nSubtract);
}

//数字の生成
CScore *CScore::Create()
{
	CScore *pScore = nullptr;

	//クラスの生成
	pScore = new CScore;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pScore != nullptr)
	{
		//初期化処理
		pScore->Init();
	}
	else
	{
		assert(false);
	}

	return pScore;
}
