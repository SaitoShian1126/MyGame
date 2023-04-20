//********************************************
//
//	game.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
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
#include "scene.h"
#include "sound.h"
#include "ui.h"
#include "hp.h"

//静的メンバ変数宣言
CScore *CGame::m_pScore = nullptr;

//数字のコンストラクタ
CGame::CGame()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	EnemyMoveTime = 150;
	nCntdeath = 0;
	m_CountTime = 0;
}

//数字のデストラクタ
CGame::~CGame()
{
	//何も書かない
}

//数字の初期化処理
HRESULT CGame::Init(void)
{
	//乱数
	srand((unsigned int)time(NULL));	//起動時に一回だけ行うため初期化に書く	

	//********************************
	//メンバ変数の初期化
	//********************************
	m_flag = false;
	m_flag2 = false;
	m_flag3 = false;
	nCntdeath = 0;
	m_CountTime = 550;

	//**********************************************
	//	テクスチャ読み込み
	//**********************************************
	//サウンドの再生
	PlaySound(SOUND_LABEL_SOUND0);
	//プレイヤーのテクスチャ読み込み
	CPlayer::Load();
	//敵のテクスチャ読み込み
	CEnemy::Load();
	//弾のテクスチャ読み込み
	CBullet::Load();
	//爆発のテクスチャ読み込み
	CExplosion::Load();
	//エフェクトのテクスチャ読み込み
	CEffect::Load();
	//パーティクルのテクスチャ読み込み
	CParticle::Load();
	//スポーンのテクスチャ読み込み
	CSpawn::Load();
	//背景のテクスチャ読み込み
	CBg::Load();
	//数字のテクスチャ読み込み
	CNumber::Load();
	//アイテムのテクスチャ読み込み
	CItem::Load();
	//アイテムスポナーのテクスチャ読み込み
	CSponer::Load();
	//攻撃のテクスチャ読み込み
	CAttack::Load();
	//攻撃2のテクスチャ読み込み
	CAttack2::Load();
	//軌道のテクスチャ読み込み
	CTrajectory::Load();
	//シーンのテクスチャ読み込み
	CScene::Load();
	//UIのテクスチャ読み込み
	CUi::Load();

	//**********************************************
	//	オブジェクトの生成
	//**********************************************
	//背景の生成
	CBg::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1280.0f, 720.0f, 0.0f));
	//UIの生成
	CUi::Create(D3DXVECTOR3(450.0f, 40.0f, 0.0f), D3DXVECTOR3(35.0f, 35.0f,0.0f),CUi::UITYPE_BULLET);
	//プレイヤーの体力生成
	CHp::Create();
	//スコアの生成
	m_pScore = CScore::Create();
	//アイテムスポナーの生成
	CSponer::Create(D3DXVECTOR3(640.0f, -50.0f, 0.0f), D3DXVECTOR3(100.0f, 100.0f, 0.0f));
	//スポーンの生成
	CSpawn::Create(D3DXVECTOR3(200.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(150.0f, 150.0f, 0.0f), CSpawn::SPAWNTYPE_MAGICCIRCLE1, 100);
	//プレイヤー生成
	CPlayer::Create(10);
	//シーン生成
	CScene::Create(D3DXVECTOR3(640.0f, 1080.0f, 0.0f), D3DXVECTOR3(640.0f, 360.0f, 0.0f), CScene::SCENETYPE_START);

	return S_OK;
}

//数字の終了処理
void CGame::Uninit(void)
{
	//**********************************************
	//	テクスチャ破棄
	//**********************************************
	//プレイヤーのテクスチャ破棄
	CPlayer::Unload();
	//敵のテクスチャ破棄
	CEnemy::Unload();
	//弾のテクスチャ破棄
	CBullet::Unload();
	//爆発のテクスチャ破棄
	CExplosion::Unload();
	//エフェクトのテクスチャ破棄
	CEffect::Unload();
	//パーティクルのテクスチャ破棄
	CParticle::Unload();
	//スポーンのテクスチャ破棄
	CSpawn::Unload();
	//背景のテクスチャ破棄
	CBg::Unload();
	//数字のテクスチャ破棄
	CNumber::Unload();
	//アイテムのテクスチャ破棄
	CItem::Unload();
	//アイテムスポナーのテクスチャ破棄
	CSponer::Unload();
	//攻撃のテクスチャ破棄
	CAttack::Unload();
	//攻撃2のテクスチャ破棄
	CAttack2::Unload();
	//軌道のテクスチャ破棄
	CTrajectory::Unload();
	//シーンのテクスチャ破棄
	CScene::Unload();
	//UIのテクスチャ破棄
	CUi::Unload();

	CObject::Release();
}

//数字の更新処理
void CGame::Update()
{
	if (EnemyMoveTime <= 150)
	{
		EnemyMoveTime--;

		if (EnemyMoveTime <= 0)
		{
			EnemyMoveTime = 151;
			for (int nCnt = 0; nCnt < 5; nCnt++)
			{
				CEnemy::Create(D3DXVECTOR3(1300.0f + 200.0f * nCnt, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X, ENEMY_SIZE_Y, 0.0f), CEnemy::ENEMYTYPE_MEDAMA, 5);
			}

			CEnemy::Create(D3DXVECTOR3(1200.0f, 670.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(100.0f, 100.0f, 0.0f), CEnemy::ENEMYTYPE_SOGEKI, ENEMY_LIFE_SOGEKI);
		}
	}

	nCntdeath = CBullet::GetBullet();
	//*********************************************
	//	BGM切り替え
	//*********************************************
	if (nCntdeath == 27 && m_flag2 == false)
	{
		//サウンドの停止
		StopSound();
		m_flag = true;
		m_flag2 = true;
	}
	if (m_flag == true && m_flag2 == true)
	{
		//サウンドの再生
		PlaySound(SOUND_LABEL_SOUND5);
		m_flag3 = true;
	}
	if (m_flag3 == true)
	{
		m_CountTime--;
		if (m_CountTime <= 0)
		{
			//サウンドの再生
			PlaySound(SOUND_LABEL_SOUND4);
			m_flag = false;
			m_flag3 = false;
		}
	}

	if (m_flag == true)
	{
		m_flag = false;
	}
}

//数字の描画処理
void CGame::Draw()
{

}

//数字の生成
CGame *CGame::Create()
{
	CGame *pgame = nullptr;

	//クラスの生成
	pgame = new CGame;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pgame != nullptr)
	{
		//初期化処理
		pgame->Init();
	}
	else
	{
		assert(false);
	}

	return pgame;
}