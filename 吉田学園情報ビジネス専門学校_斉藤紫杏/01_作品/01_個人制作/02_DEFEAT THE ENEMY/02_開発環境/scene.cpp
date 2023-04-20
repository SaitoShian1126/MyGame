//********************************************
//
//	scene.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "scene.h"
#include "application.h"
#include "renderer.h"
#include "explosion.h"
#include "fade.h"
#include "bullet.h"
#include "hp.h"
#include "ui.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CScene::m_pTextureScene[2] = {};

//敵のコンストラクタ
CScene::CScene() : CObject2D(4)
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_nUninitTimer = 0;
	m_flag = false;
}

//敵のデストラクタ
CScene::~CScene()
{
	//何も書かない
}

//敵の初期化処理
HRESULT CScene::Init(void)
{
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************
	m_nUninitTimer = 0;
	m_flag = false;

	switch (m_nType)
	{
	case SCENETYPE_BOSS:
		//テクスチャ反映
		BindTexture(m_pTextureScene[0]);
		break;
	case SCENETYPE_START:
		//テクスチャ反映
		BindTexture(m_pTextureScene[1]);
		break;
	default:
		break;
	}

	return S_OK;
}

//敵の終了処理
void CScene::Uninit(void)
{
	CObject2D::Uninit();
}

//敵の更新処理
void CScene::Update()
{
	D3DXVECTOR3 ScenePos = GetPos();
	D3DXVECTOR3 SceneMove = GetMove();

	//位置更新
	ScenePos.x += SceneMove.x;
	ScenePos.y += SceneMove.y;
	ScenePos.z += SceneMove.z;

	CObject2D::Update();

	if (m_nType == SCENETYPE_BOSS)
	{
		if (m_flag == false)
		{
			m_nUninitTimer = 400;
			m_flag = true;
		}
		SceneMove.x = -5.0f;
		SetMove(SceneMove);

		if (ScenePos.x <= 640.0f)
		{
			SceneMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			SetMove(SceneMove);
		}

		m_nUninitTimer--;
		if (m_nUninitTimer <= 0)
		{
			Uninit();
			//ボスの生成
			CEnemy::Create(D3DXVECTOR3(1050.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(BOSS_SIZE_X, BOSS_SIZE_Y, 0.0f), CEnemy::ENEMYTYPE_BOSS, 1100);
			//UIの生成
			CUi::Create(D3DXVECTOR3(645.0f, 685.0f, 0.0f), D3DXVECTOR3(310.0f, 20.0f, 0.0f), CUi::UITYPE_LIFE);
			CBossHp::Create();
			return;
		}
	}
	if (m_nType == SCENETYPE_START)
	{
		if (m_flag == false)
		{
			m_nUninitTimer = 200;
			m_flag = true;
		}
		SceneMove.y = -5.0f;
		SetMove(SceneMove);
		if (ScenePos.y <= 360.0f)
		{
			SceneMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			SetMove(SceneMove);
		}
		m_nUninitTimer--;
		if (m_nUninitTimer <= 0)
		{
			SceneMove.y = -5.0f;
			SetMove(SceneMove);
			if (ScenePos.y <= -360.0f)
			{
				Uninit();
				return;
			}
		}
	}

	SetMove(SceneMove);
	SetPosition(ScenePos);
}

//敵の描画処理
void CScene::Draw()
{
	CObject2D::Draw();
}

//スポーンの生成
CScene *CScene::Create(const D3DXVECTOR3 &pos,D3DXVECTOR3 size, SCENETYPE type)
{
	CScene *pScene = nullptr;

	//クラスの生成
	pScene = new CScene;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pScene != nullptr)
	{
		pScene->SetSceneType(type);
		//初期化処理
		pScene->Init();
		//設定処理
		pScene->SetPosition(pos);
		pScene->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pScene;
}

//テクスチャの読み込み
HRESULT CScene::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ボス出現.png",
		&m_pTextureScene[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/start1.png",
		&m_pTextureScene[1]);

	return S_OK;
}

//テクスチャの破棄
void CScene::Unload(void)
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		//テクスチャの破棄
		if (m_pTextureScene[nCnt] != nullptr)
		{
			m_pTextureScene[nCnt]->Release();
			m_pTextureScene[nCnt] = nullptr;
		}
	}
}

//シーンの設定
void CScene::SetSceneType(SCENETYPE type)
{
	m_nType = type;
}
