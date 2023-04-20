//********************************************
//
//	trajectory.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "trajectory.h"
#include "application.h"
#include "renderer.h" 

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CTrajectory::m_pTextureTrajectory[5] = {};

//軌道のコンストラクタ
CTrajectory::CTrajectory()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_UninitCount = 0;
	m_flag = true;
}

//軌道のデストラクタ
CTrajectory::~CTrajectory()
{
	//何も書かない
}

//軌道の初期化処理
HRESULT CTrajectory::Init(void)
{
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************m_UninitCount
	m_UninitCount = 50;
	m_flag = true;
	
	switch (m_nType)
	{
	case TRAJECTORY_DOWN:
		BindTexture(m_pTextureTrajectory[0]);
		break;
	case TRAJECTORY_LIGHT:
		BindTexture(m_pTextureTrajectory[1]);
		break;
	case TRAJECTORY_LEFT:
		BindTexture(m_pTextureTrajectory[2]);
		break;
	case TRAJECTORY_LIGHTDOWN:
		BindTexture(m_pTextureTrajectory[3]);
		break;
	case TRAJECTORY_LEFTDOWN:
		BindTexture(m_pTextureTrajectory[4]);
		break;
	default:
		break;
	}

	return S_OK;
}

//軌道の終了処理
void CTrajectory::Uninit(void)
{
	CObject2D::Uninit();
}

//軌道の更新処理
void CTrajectory::Update()
{
	D3DXVECTOR3 TrajectoryPos = GetPos();

	m_UninitCount--;
	if (m_UninitCount <= 0)
	{
		Uninit();
		return;
	}

	//位置の設定
	SetPosition(TrajectoryPos);
	CObject2D::Update();
}

//軌道の描画処理
void CTrajectory::Draw()
{
	CObject2D::Draw();
}

//軌道の生成
CTrajectory *CTrajectory::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, TRAJECTORY nType)
{
	CTrajectory *pTrajectory = nullptr;

	//クラスの生成
	pTrajectory = new CTrajectory;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pTrajectory != nullptr)
	{
		pTrajectory->SetTrajectoryType(nType);
		//初期化処理
		pTrajectory->Init();
		//設定処理
		pTrajectory->SetPosition(pos);
		pTrajectory->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pTrajectory;
}

//テクスチャの読み込み
HRESULT CTrajectory::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/下方向.jpg",
		&m_pTextureTrajectory[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/右方向.jpg",
		&m_pTextureTrajectory[1]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/左方向.jpg",
		&m_pTextureTrajectory[2]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/右下方向.jpg",
		&m_pTextureTrajectory[3]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/左下方向.jpg",
		&m_pTextureTrajectory[4]);

	return S_OK;
}

//テクスチャの破棄
void CTrajectory::Unload(void)
{
	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		//テクスチャの破棄
		if (m_pTextureTrajectory[nCnt] != nullptr)
		{						
			m_pTextureTrajectory[nCnt]->Release();
			m_pTextureTrajectory[nCnt] = nullptr;
		}
	}
}

//軌道のタイプの設定
void CTrajectory::SetTrajectoryType(TRAJECTORY type)
{
	m_nType = type;
}
