//********************************************
//
//	object.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include "object.h"
#include "renderer.h"

//静的メンバ変数宣言
CObject *CObject::m_apObject[MAX_DRAWPRIORITY][MAX_OBJECT] = {};
int CObject::m_nNumAll;

//オブジェクト優先順位
CObject::CObject(int nPriority /* = 3*/)
{
	m_nPriority = nPriority;

	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
	{
		if (m_apObject[nPriority][nCntObject] == nullptr)
		{
			m_apObject[nPriority][nCntObject] = this;	//CObject2DのpObject2Dがthis
			//自分の番号を設定
			m_nID = nCntObject;
			m_nNumAll++;
			break;
		}
	}
}

//オブジェクトのデストラクタ
CObject::~CObject()
{
	//何も書かない
}

//すべての破棄処理
void CObject::ReleaseAll(void)
{
	for (int nCntPriority = 0; nCntPriority < MAX_DRAWPRIORITY; nCntPriority++)
	{
		for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
		{
			//nullチェック
			if (m_apObject[nCntPriority][nCnt] != nullptr)
			{
				//終了処理の関数呼び出し
				m_apObject[nCntPriority][nCnt]->Uninit();

				//メモリの解放
				delete m_apObject[nCntPriority][nCnt];
				m_apObject[nCntPriority][nCnt] = nullptr;
			}
		}
	}
}

//すべての更新処理
void CObject::UpdateAll(void)
{
	for (int nCntPriority = 0; nCntPriority < MAX_DRAWPRIORITY; nCntPriority++)
	{
		for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
		{
			//nullチェック
			if (m_apObject[nCntPriority][nCnt] != nullptr)
			{
				//更新処理の関数呼び出し
				m_apObject[nCntPriority][nCnt]->Update();
			}
		}
	}
}

//すべての描画処理
void CObject::DrawAll(void)
{
	for (int nCntPriority = 0; nCntPriority < MAX_DRAWPRIORITY; nCntPriority++)
	{
		for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
		{
			//nullチェック
			if (m_apObject[nCntPriority][nCnt] != nullptr)
			{
				//描画処理の関数呼び出し
				m_apObject[nCntPriority][nCnt]->Draw();
			}
		}
	}
}

//モードの破棄
void CObject::ModeRelease(void)
{
	for (int nCntPriority = 0; nCntPriority < MAX_DRAWPRIORITY; nCntPriority++)
	{
		for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
		{
			if (m_apObject[nCntPriority][nCnt] != nullptr)
			{
				if (m_apObject[nCntPriority][nCnt]->GetType() != TYPE_MODE)
				{
					m_apObject[nCntPriority][nCnt]->Uninit();
				}
			}
		}
	}
}

//破棄
void CObject::Release(void)
{
	if (m_apObject[m_nPriority][m_nID] != nullptr)
	{
		//番号保存
		const int nID = m_nID;
		const int nPriority = m_nPriority;
		delete m_apObject[nPriority][nID];
		m_apObject[nPriority][nID] = nullptr;
		
	}
	m_nNumAll--;
}

//何番目のオブジェクトを取得
CObject *CObject::GetObjects(int nPriority, int nCntType)
{
	return m_apObject[nPriority][nCntType];
}

//タイプの設定
void CObject::SetType(TYPE type)
{
	m_Type = type;
}