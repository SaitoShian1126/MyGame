//********************************************
//
//	enemy.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include <time.h>
#include "enemy.h"
#include "application.h"
#include "renderer.h" 
#include "bullet.h"
#include "explosion.h"
#include "player.h"
#include "object.h"
#include "effect.h"
#include "fade.h"
#include "result.h"
#include "sound.h"
#include "trajectory.h"
#include "item.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CEnemy::m_pTextureEnemy[7] = {}; 
bool CEnemy::m_PlayerGameOver = false;

//敵のコンストラクタ
CEnemy::CEnemy()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_BulletMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_sLifeTime = 0; 
	m_nTime = 0;
	m_nMoveTime = 0;
	m_nAttackTime = 0;
	m_nBossTime = 0;
	m_nBulletCnt = 0;
	m_AttackCount = 0;
	m_Count = 0;
	m_nCounterAnimEnemy = 0;
	m_nPatternAnimEnemy = 0;
	m_fRotMove = 0.0f;
	m_flag = true;
	m_flag2 = false;		
	m_PlayerGameOver = false;
	m_UseFlag = true;
	m_Bossflag1 = true;
	m_Bossflag2 = true;
	m_Bossflag3 = true;
	m_Bossflag4 = false;
}

//敵のデストラクタ
CEnemy::~CEnemy()
{
	//何も書かない
}

//敵の初期化処理
HRESULT CEnemy::Init(void)
{	
	CObject2D::Init();
	//乱数
	srand((unsigned int)time(NULL));	//起動時に一回だけ行うため初期化に書く	

	//********************************
	//メンバ変数の初期化
	//********************************
	m_BulletMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_sLifeTime = TIME;
	m_nTime = 50; 
	m_Count = 50;
	m_nMoveTime = 10;
	m_nAttackTime = BOSS_BULLET_TIME;
	m_nAttackTime2 = 200;
	m_AttackCount = 0;
	m_nBossTime = TIME;
	m_nBulletCnt = 0;
	m_nCounterAnimEnemy = 0;
	m_nPatternAnimEnemy = 0;
	m_fRotMove = 5.0f;
	m_flag = true;
	m_flag2 = false;
	m_UseFlag = true;
	m_Bossflag1 = true;
	m_Bossflag2 = true;
	m_Bossflag3 = true;
	m_Bossflag4 = false;

	switch (m_nType)
	{
	case ENEMYTYPE_MEDAMA:
		//テクスチャ反映
		BindTexture(m_pTextureEnemy[0]);
		//テクスチャの設定
		SetTexture(3.0f, 0.0f, 1.0f, 0.0f);
		break;
	case ENEMYTYPE_KYODAIMEDAMA:
		//テクスチャ反映
		BindTexture(m_pTextureEnemy[0]);
		break;
	case ENEMYTYPE_BOMB:
		//テクスチャ反映
		BindTexture(m_pTextureEnemy[1]);
		break;
	case ENEMYTYPE_ZIGUZAGU:
		//テクスチャ反映
		BindTexture(m_pTextureEnemy[2]);
		break;
	case ENEMYTYPE_ENN:
		//テクスチャ反映
		BindTexture(m_pTextureEnemy[3]);
		break;
	case ENEMYTYPE_HEBI:
		//テクスチャ反映
		BindTexture(m_pTextureEnemy[4]);
		break;
	case ENEMYTYPE_BOSS:
		//テクスチャ反映
		BindTexture(m_pTextureEnemy[5]);
		//テクスチャの設定
		SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 0.0f);
		break;
	case ENEMYTYPE_SOGEKI:
		//テクスチャ反映
		BindTexture(m_pTextureEnemy[6]);
		break;
	default:
		break;
	}

	return S_OK;
}

//敵の終了処理
void CEnemy::Uninit(void)
{
	CObject2D::Uninit();
}

//敵の更新処理
void CEnemy::Update()
{
	D3DXVECTOR3 EnemyPos = GetPos();
	D3DXVECTOR3 EnemyMove = GetMove();
	D3DXVECTOR3 EnemySize = GetSize();

	CObject2D::Update();

	//*****************************************************
	//	真ん中にまた戻る挙動
	//*****************************************************
	//敵のタイプが0だったら
	if (m_nType == ENEMYTYPE_MEDAMA)
	{
		//当たり判定
		HitJudgment(EnemyPos);
		//アニメーションカウンターをインクリメント
		m_nCounterAnimEnemy++;

		if (m_nCounterAnimEnemy % 15 == 0)
		{
			//テクスチャの設定
			SetTexture(3.0f, (float)m_nPatternAnimEnemy, 1.0f, 0.0f);

			//アニメーションパターンのインクリメン
			m_nPatternAnimEnemy++;
		}
		//敵のx位置が1280.0f以上かつフラグがtrueだったら
		if (EnemyPos.x >= SCREEN_WIDTH && m_flag == true)
		{
			//敵が左移動
			EnemyMove = D3DXVECTOR3(-3.0f, 0.0f, 0.0f);
			//位置設定
			SetMove(EnemyMove);
			//フラグをfalseにする
			m_flag = false;
		}
		//敵のx位置が画面の半分に来たらかつフラグがfalseだったら
		if (EnemyPos.x <= SCREEN_WIDTH / 2 && m_flag == false)
		{
			//敵が右移動
			EnemyMove = D3DXVECTOR3(3.0f, 0.0f, 0.0f);
			//位置設定
			SetMove(EnemyMove);
			m_flag = true;
		}
	}

	//*****************************************************
	//	上から落ちてきて時間経過で爆発挙動
	//*****************************************************
	//敵のタイプが2だったら
	if (m_nType == ENEMYTYPE_BOMB)
	{
		//当たり判定
		HitJudgment(EnemyPos);
		//敵のy位置が0.0f以下だったら
		if (EnemyPos.y <= 0.0f)
		{
			//敵が下移動
			EnemyMove = D3DXVECTOR3(0.0f, 3.0f, 0.0f);
			//位置設定
			SetMove(EnemyMove);
		}
		//敵のy位置が640.0f以上だったら
		m_sLifeTime--;
		if (m_sLifeTime <= 0)
		{
			//爆発
			CExplosion::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(100.0f, 100.0f, 0.0f),D3DXCOLOR(1.0f,0.0f,0.0f,1.0f),CExplosion::EXPLOTIONTYPE_BAKUHATU);

			//敵の生成
			CEnemy::Create(D3DXVECTOR3(1300.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X + 15.0f, ENEMY_SIZE_Y + 15.0f, 0.0f), CEnemy::ENEMYTYPE_KYODAIMEDAMA, 50);

			//敵を消す
			CEnemy::Uninit();
			return;
		}
	}
	//*****************************************************
	//	ジグザグに移動する挙動
	//*****************************************************
	//敵のタイプが2だったら
	if (m_nType == ENEMYTYPE_ZIGUZAGU)
	{
		//当たり判定
		HitJudgment(EnemyPos);
		if (EnemyPos.x <= SCREEN_WIDTH)
		{
			m_nTime--;

			if (m_nTime <= 0)
			{
				CBullet::Create(D3DXVECTOR3(EnemyPos.x, EnemyPos.y, EnemyPos.z), D3DXVECTOR3(-10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f), 7, 1, CBullet::BULLETTYPE_NOMAL);
			}
			if (m_nTime <= 0)
			{
				m_nTime = 50;
			}
		}
		//敵の挙動
		if (EnemyPos.y >= RANGE_HIGH_Y && m_flag == true)
		{
			EnemyMove = D3DXVECTOR3(ENEMY_MOVE_X, -ENEMY_MOVE_Y, 0.0f);
			//位置設定
			SetMove(EnemyMove);
			m_flag = false;
		}
		else if (EnemyPos.y <= RANGE_HIGH_Y && m_flag == false)
		{
			EnemyMove = D3DXVECTOR3(ENEMY_MOVE_X, ENEMY_MOVE_Y, 0.0f);
			//位置設定
			SetMove(EnemyMove);
		}
		else if (EnemyPos.y <= RANGE_DOWN_Y && m_flag2 == false)
		{
			EnemyMove = D3DXVECTOR3(ENEMY_MOVE_X, ENEMY_MOVE_Y, 0.0f);
			//位置設定
			SetMove(EnemyMove);
			m_flag2 = true;
		}
		else if (EnemyPos.y >= RANGE_DOWN_Y && m_flag2 == true)
		{
			EnemyMove = D3DXVECTOR3(ENEMY_MOVE_X, -ENEMY_MOVE_Y, 0.0f);
			//位置設定
			SetMove(EnemyMove);
		}

		//左から右にループ
		if (EnemyPos.x < -ENEMY_SIZE_X / 2 && m_nType == ENEMYTYPE_ZIGUZAGU)
		{
			EnemyPos.x = SCREEN_WIDTH + ENEMY_SIZE_X / 2;
			SetPosition(EnemyPos);
		}
	}

	//*****************************************************
	//	円を描いて進む挙動
	//*****************************************************
	if (m_nType == ENEMYTYPE_ENN)
	{
		if (EnemyMove.x <= -0.0f)
		{
			//エフェクトの生成
			CEffect::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f), 10);
			//当たり判定
			HitJudgment(EnemyPos);
		}
		if (EnemyPos.x >= 1400.0f)
		{
			//テクスチャの設定
			SetTexture(2.0f, 2.0f, 1.0f, 0.0f);
			EnemyMove.x = -5.0f;
			SetMove(EnemyMove);
			EnemySize = D3DXVECTOR3(ENEMY_SIZE_X, ENEMY_SIZE_Y, 0.0f);
			SetSize(EnemySize);
			m_flag = true;
			m_UseFlag = true;
		}
		if (EnemyPos.x <= 900.0f && m_flag == true)
		{
			//テクスチャの設定
			SetTexture(2.0f, 2.0f, 1.0f, 0.0f);
			EnemyMove.x = -2.5f;
			SetMove(EnemyMove);
			m_Count--;
			if (m_Count <= 0)
			{
				EnemyMove.x = -10.0f;
				SetMove(EnemyMove);
				m_flag = false;
				m_UseFlag = false;
				m_Count = 50;
			}
		}
		if (EnemyPos.x <= -200.0f && m_UseFlag == false)
		{
			//テクスチャの設定
			SetTexture(2.0f, 1.0f, 1.0f, 0.0f);
			EnemyMove.x = 7.5f;
			SetMove(EnemyMove);
			EnemySize = D3DXVECTOR3(20.0f, 20.0f, 0.0f);
			SetSize(EnemySize);
		}
		//位置更新
		EnemyPos.x += EnemyMove.x;
		EnemyPos.y += EnemyMove.y;
		EnemyPos.z += EnemyMove.z;

		//移動量減衰
		EnemyPos.x += (0.0f - EnemyMove.x) * 0.1f;
		EnemyPos.y += (0.0f - EnemyMove.y) * 0.1f;
		EnemyPos.z += (0.0f - EnemyMove.z) * 0.1f;

		//位置の設定
		SetPosition(EnemyPos);
		SetMove(EnemyMove);
	}
		
	//*****************************************************
	//	自機の少し前に来たら自機の後ろに移動する挙動
	//*****************************************************
	if (m_nType == ENEMYTYPE_HEBI)
	{
		//当たり判定
		HitJudgment(EnemyPos);
		EnemyMove = D3DXVECTOR3(-3.0f, 0.0f, 0.0f);
		//位置設定
		SetMove(EnemyMove);

		//左から右にループ
		if (EnemyPos.x < -ENEMY_SIZE_X / 2 && m_nType == ENEMYTYPE_HEBI)
		{
			EnemyPos.x = SCREEN_WIDTH + ENEMY_SIZE_X / 2;
			SetPosition(EnemyPos);
		}
	}
	//*****************************************************
	//	ランダムで動く敵(ボス予定)
	//*****************************************************
	if (m_nType == ENEMYTYPE_BOSS)
	{
		//for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
		//{
		//	//オブジェクトのポインタ
		//	CObject *pObject;
		//	//どのタイプかの情報をポインタに代入
		//	pObject = GetObjects(3, nCntType);
		//
		//	//nullチェック
		//	if (pObject != nullptr)
		//	{
		//		//**********************************************************
		//		// ボスとプレイヤーの当たり判定
		//		//**********************************************************
		//		if (pObject->GetType() == TYPE_PLAYER)
		//		{
		//			//敵の位置
		//			D3DXVECTOR3 PlayerPos = pObject->GetPos();
		//			//敵のサイズ
		//			D3DXVECTOR3 PlayerSize = pObject->GetSize();
		//			//敵の体力
		//			int nLife = pObject->GetLife();
		//
		//			//敵の当たり判定
		//			if (EnemyPos.x + 150.0f >= PlayerPos.x - PlayerSize.x
		//				&&EnemyPos.x - 150.0f <= PlayerPos.x + PlayerSize.x
		//				&&EnemyPos.y + 170.0f >= PlayerPos.y - PlayerSize.y
		//				&&EnemyPos.y - 170.0f <= PlayerPos.y + PlayerSize.y)
		//			{
		//				//敵の体力を減らす
		//				nLife = 0;
		//				//体力の保存
		//				pObject->SetLife(nLife);
		//				//体力が0になったら
		//				if (nLife == 0)
		//				{
		//					//爆発
		//					CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
		//					m_PlayerGameOver = true;
		//					pObject->Uninit();
		//					CResult::SetType(CResult::TYPE_GAMEOVER);
		//					CFade::SetFade(CApplication::MODE_RESULT);
		//					return;
		//				}
		//				if (nLife <= 0 && m_nLife <= 0)
		//				{
		//					//爆発
		//					CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
		//					pObject->Uninit();
		//					CResult::SetType(CResult::TYPE_GAMECLEAR);
		//					CFade::SetFade(CApplication::MODE_RESULT);
		//					return;
		//				}
		//			}
		//		}
		//	}
		//}
		//ボスの体力が1100になったら
		HitBossJudgment(EnemyPos);
		if (m_nLife <= 1100)
		{
			EnemyMove = D3DXVECTOR3(-2.0f, 0.0f, 0.0f);
			//位置設定
			SetMove(EnemyMove);
			if (m_nLife >= 800)
			{
				//アニメーションカウンターをインクリメント
				m_nCounterAnimEnemy++;
				if (m_nCounterAnimEnemy % 50 == 0)
				{
					//テクスチャの設定
					SetTexture(MAX_BOSSTEXTURE_X, (float)m_nPatternAnimEnemy, MAX_BOSSTEXTURE_Y, 1.0f);
					//アニメーションパターンのインクリメント
					m_nPatternAnimEnemy++;
				}
				else if (m_nPatternAnimEnemy == 2.0f)
				{
					m_nPatternAnimEnemy = 0;
				}
			}
			else if (m_nLife <= 799)
			{
				//アニメーションカウンターをインクリメント
				m_nCounterAnimEnemy++;
				if (m_nCounterAnimEnemy % 50 == 0)
				{
					//テクスチャの設定
					SetTexture(MAX_BOSSTEXTURE_X, (float)m_nPatternAnimEnemy, MAX_BOSSTEXTURE_Y, 4.0f);
					//アニメーションパターンのインクリメント
					m_nPatternAnimEnemy++;
				}
				else if (m_nPatternAnimEnemy == 2.0f)
				{
					m_nPatternAnimEnemy = 0;
				}
			}
		}
		if (EnemyPos.x <= 500.0f)
		{
			EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//位置設定
			SetMove(EnemyMove);
			if (m_nLife >= 800)
			{
				//テクスチャの設定
				SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 0.0f);
			}
			else if (m_nLife <= 799)
			{
				//テクスチャの設定
				SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 3.0f);
			}
			m_nBossTime--;
		}
		if (m_nBossTime <= 0)
		{
			EnemyMove = D3DXVECTOR3(MAX_BOSSTEXTURE_X, 0.0f, 0.0f);
			//位置設定
			SetMove(EnemyMove);
		}
		if (EnemyPos.x >= 1051.0f)
		{
			EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//位置設定
			SetMove(EnemyMove);
			m_nAttackTime--;

			if (m_nLife >= 800)
			{
				//アニメーションカウンターをインクリメント
				m_nCounterAnimEnemy++;

				if (m_nCounterAnimEnemy % 100 == 0)
				{
					//テクスチャの設定
					SetTexture(MAX_BOSSTEXTURE_X, (float)m_nPatternAnimEnemy, MAX_BOSSTEXTURE_Y, 2.0f);

					//アニメーションパターンのインクリメント
					m_nPatternAnimEnemy++;
				}
				if (m_nAttackTime <= 0)
				{
					if (m_nBulletCnt <= 4)
					{
						m_nBulletCnt++;
						//弾の生成
						CBullet::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(-20.0f, 5.0f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						CBullet::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(-20.0f, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						CBullet::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(-20.0f, -5.0f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
					}
				}
				if (m_nAttackTime <= 0)
				{
					m_nAttackTime = BOSS_BULLET_TIME;
				}
			}
			else if (m_nLife <= 799)
			{
				//アニメーションカウンターをインクリメント
				m_nCounterAnimEnemy++;

				if (m_nCounterAnimEnemy % 100 == 0)
				{
					//テクスチャの設定
					SetTexture(MAX_BOSSTEXTURE_X, (float)m_nPatternAnimEnemy, MAX_BOSSTEXTURE_Y, 5.0f);

					//アニメーションパターンのインクリメント
					m_nPatternAnimEnemy++;
				}
				if (m_nAttackTime <= 0)
				{
					if (m_nBulletCnt <= 4)
					{
						m_nBulletCnt++;
						//弾の生成
						CBullet::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(-20.0f, 5.0f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						CBullet::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(-20.0f, 2.5f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						CBullet::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(-20.0f, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						CBullet::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(-20.0f, -2.5f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						CBullet::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(-20.0f, -5.0f, 0.0f), D3DXVECTOR3(25.0f, 25.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
					}
				}
				if (m_nAttackTime <= 0)
				{
					m_nAttackTime = BOSS_BULLET_TIME;
				}
			}
		}
		if (m_nBulletCnt == 5 && EnemyPos.x >= 1051.0f)
		{
			if (m_nLife >= 800)
			{
				//テクスチャの設定
				SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 0.0f);
				EnemyMove = D3DXVECTOR3(0.0f, -2.0f, 0.0f);
				//位置設定
				SetMove(EnemyMove);
			}
			else if (m_nLife <= 799)
			{
				//テクスチャの設定
				SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 3.0f);
				EnemyMove = D3DXVECTOR3(0.0f, -3.5f, 0.0f);
				//位置設定
				SetMove(EnemyMove);
			}
			m_nAttackTime = BOSS_BULLET_TIME;
		}
		if (m_nBulletCnt == 5 && EnemyPos.y <= -400.0f)
		{
			EnemyPos = D3DXVECTOR3(640.0f, -200.0f, 0.0f);
			//位置の設定
			SetPosition(EnemyPos);
		}
		if (m_nBulletCnt == 5 && EnemyPos.x == 640.0f)
		{
			EnemyMove.x = 0.0f;
			EnemyMove.y += 7.0f;
			SetMove(EnemyMove);
		}
		if (EnemyPos.y > 500.0f)
		{
			EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			SetMove(EnemyMove);
			if (m_Bossflag1 == true)
			{
				for (int nCnt = 0; nCnt < 5; nCnt++)
				{
					//爆発
					CExplosion::Create(D3DXVECTOR3(-100.0f + EnemyPos.x + 50.0f * nCnt, 700.0f, EnemyPos.z), D3DXVECTOR3(100.0f, 100.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
					m_Bossflag1 = false;
					m_nBossTime = 100;
					m_nAttackTime = 50;
					m_nAttackTime2 = 100;
					m_Bossflag4 = true;
				}
			}
			//*******************************************
			//	ボスの体力が800以上だったら
			//*******************************************
			if (m_nLife >= 800 && m_Bossflag4 == true)
			{
				if (m_Bossflag2 == true)
				{
					m_nRand = rand() % 3 + 1;
					m_Bossflag2 = false;
					m_AttackCount = 0;
					m_nBossTime = 100;
					m_nCounterAnimEnemy = 0;
					m_nPatternAnimEnemy = 0;
				}
				if (m_Bossflag2 == false)
				{
					m_nAttackTime2--;
					if (m_nAttackTime2 > 0)
					{
						if (m_nLife >= 800)
						{
							//テクスチャの設定
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 2.0f);
						}
					}
				}
				if (m_nRand == 1 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					for (int nCnt = 0; nCnt < 10; nCnt++)
					{
						//軌道の生成
						CTrajectory::Create(D3DXVECTOR3(50.0f + 150.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_DOWN);
					}

					if (m_nLife >= 800)
					{
						//テクスチャの設定
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 2.0f);
					}
					if (m_nLife <= 800)
					{
						//テクスチャの設定
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					}

					m_nAttackTime--;
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 10; nCnt++)
						{
							//弾の生成
							CBullet::Create(D3DXVECTOR3(50.0f + 150.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 20.0f, 0.0f), D3DXVECTOR3(10.0f, 10.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}

						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							if (m_nLife >= 800)
							{
								//テクスチャの設定
								SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 2.0f);
							}
							if (m_nLife < -800)
							{
								//テクスチャの設定
								SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
							}
						}
					}
					if (m_nAttackTime <= 0)
					{
						m_nAttackTime = 50;
					}
				}
				else if (m_nRand == 2 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					EnemyMove = D3DXVECTOR3(-5.0f, 0.0f, 0.0f);
					SetMove(EnemyMove);
					if (m_nLife >= 800)
					{
						//テクスチャの設定
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 2.0f);
					}
					if (m_nLife <= 800)
					{
						//テクスチャの設定
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					}

					if (EnemyPos.x - BOSS_SIZE_X / 2 <= 50.0f)
					{
						EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						SetMove(EnemyMove);
						if (m_nLife >= 800)
						{
							//テクスチャの設定
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 2.0f);
						}
						if (m_nLife <= 800)
						{
							//テクスチャの設定
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
						}
						m_nBossTime--;
						m_Bossflag3 = false;
					}
					if (m_nBossTime <= 0 && m_Bossflag3 == false)
					{
						EnemyMove = D3DXVECTOR3(5.0f, 0.0f, 0.0f);
						SetMove(EnemyMove);
						if (EnemyPos.x >= 641.0f)
						{
							EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
							SetMove(EnemyMove);
							m_Bossflag2 = true;
							m_Bossflag3 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
						}
					}
				}
				else if (m_nRand == 3 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					for (int nCnt = 0; nCnt < 6; nCnt++)
					{
						//軌道の生成
						CTrajectory::Create(D3DXVECTOR3(20.0f, 60.0f + 176.0f * nCnt, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LIGHT);
						//軌道の生成
						CTrajectory::Create(D3DXVECTOR3(1260.0f, 176.0f * nCnt, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LEFT);
					}

					if (m_nLife >= 800)
					{
						//テクスチャの設定
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 2.0f);
					}
					if (m_nLife <= 800)
					{
						//テクスチャの設定
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					}
					m_nAttackTime--;
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 6; nCnt++)
						{
							//弾の生成
							CBullet::Create(D3DXVECTOR3(0.0f, 60.0f + 176.0f * nCnt, 0.0f), D3DXVECTOR3(20.0f, 0.0f, 0.0f), D3DXVECTOR3(10.0f, 10.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
							//弾の生成
							CBullet::Create(D3DXVECTOR3(1280.0f, 176.0f * nCnt, 0.0f), D3DXVECTOR3(-20.0f, 0.0f, 0.0f), D3DXVECTOR3(10.0f, 10.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}
						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							if (m_nLife >= 800)
							{
								//テクスチャの設定
								SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 2.0f);
							}
						}
					}
					if (m_nAttackTime <= 0)
					{
						m_nAttackTime = 50;
					}
				}
			}
			//*******************************************
			//	ボスの体力が800以下になったら
			//*******************************************
			else if (m_nLife <= 799 && m_Bossflag4 == true)
			{
				if (m_Bossflag2 == true)
				{
					m_nRand = rand() % 5 + 1;
					m_Bossflag2 = false;
					m_AttackCount = 0;
					m_nBossTime = 100;
					m_nCounterAnimEnemy = 0;
					m_nPatternAnimEnemy = 0;
				}
				if (m_Bossflag2 == false)
				{
					m_nAttackTime2--;
					if (m_nAttackTime2 > 0)
					{
							//テクスチャの設定
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					}
				}
				if (m_nRand == 1 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					for (int nCnt = 0; nCnt < 10; nCnt++)
					{
						//軌道の生成
						CTrajectory::Create(D3DXVECTOR3(50.0f + 150.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_DOWN);
					}
						//テクスチャの設定
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					m_nAttackTime--;
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 10; nCnt++)
						{
							//弾の生成
							CBullet::Create(D3DXVECTOR3(50.0f + 150.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 20.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}

						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							if (m_nLife < -800)
							{
								//テクスチャの設定
								SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
							}
						}
					}
					if (m_nAttackTime <= 0)
					{
						m_nAttackTime = 50;
					}
				}
				else if (m_nRand == 2 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					EnemyMove = D3DXVECTOR3(-8.0f, 0.0f, 0.0f);
					SetMove(EnemyMove);
					//テクスチャの設定
					SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					if (EnemyPos.x - BOSS_SIZE_X / 2 <= 50.0f)
					{
						EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						SetMove(EnemyMove);
						//テクスチャの設定
						SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
						m_nBossTime--;
						m_Bossflag3 = false;
					}
					if (m_nBossTime <= 0 && m_Bossflag3 == false)
					{
						EnemyMove = D3DXVECTOR3(8.0f, 0.0f, 0.0f);
						SetMove(EnemyMove);
						if (EnemyPos.x >= 641.0f)
						{
							EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
							SetMove(EnemyMove);
							m_Bossflag2 = true;
							m_Bossflag3 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
						}
					}
				}
				else if (m_nRand == 3 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					for (int nCnt = 0; nCnt < 6; nCnt++)
					{
						//軌道の生成
						CTrajectory::Create(D3DXVECTOR3(20.0f, 60.0f + 176.0f * nCnt, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LIGHT);
						//軌道の生成
						CTrajectory::Create(D3DXVECTOR3(1260.0f, 176.0f * nCnt, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LEFT);
					}
					//テクスチャの設定
					SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					m_nAttackTime--;
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 6; nCnt++)
						{
							//弾の生成
							CBullet::Create(D3DXVECTOR3(0.0f, 60.0f + 176.0f * nCnt, 0.0f), D3DXVECTOR3(20.0f, 0.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
							//弾の生成
							CBullet::Create(D3DXVECTOR3(1280.0f, 176.0f * nCnt, 0.0f), D3DXVECTOR3(-20.0f, 0.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}
						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							//テクスチャの設定
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
						}
					}
					if (m_nAttackTime <= 0)
					{
						m_nAttackTime = 50;
					}
				}
				else if (m_nRand == 4 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					//テクスチャの設定
					SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					m_nAttackTime--;
					for (int nCnt = 0; nCnt < 10; nCnt++)
					{
						//軌道の生成
						CTrajectory::Create(D3DXVECTOR3(-200.0f + 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LIGHTDOWN);
					}
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 20; nCnt++)
						{
							//弾の生成
							CBullet::Create(D3DXVECTOR3(-200.0f + 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(15.0f, 15.0f, 0.0f), D3DXVECTOR3(15.0f, 15.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}
						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							//テクスチャの設定
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
						}
					}
					if (m_nAttackTime <= 0)
					{
						m_nAttackTime = 50;
					}
				}
				else if (m_nRand == 5 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					//テクスチャの設定
					SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					m_nAttackTime--;
					for (int nCnt = 0; nCnt < 10; nCnt++)
					{
						//軌道の生成
						CTrajectory::Create(D3DXVECTOR3(1480.0f - 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LEFTDOWN);
					}
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 20; nCnt++)
						{
							//弾の生成
							CBullet::Create(D3DXVECTOR3(1480.0f - 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(-12.5f, 12.5f, 0.0f), D3DXVECTOR3(15.0f, 15.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}
						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							//テクスチャの設定
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
						}
					}
					if (m_nAttackTime <= 0)
					{
						m_nAttackTime = 50;
					}
				}
			}
		}
	}

	//*****************************************************
	//	居愛目玉の挙動
	//*****************************************************
	if (m_nType == ENEMYTYPE_KYODAIMEDAMA)
	{
		//当たり判定
		HitJudgment(EnemyPos);
		//アニメーションカウンターをインクリメント
		m_nCounterAnimEnemy++;

		if (m_nCounterAnimEnemy % 15 == 0)
		{
			//テクスチャの設定
			SetTexture(3.0f, (float)m_nPatternAnimEnemy, 1.0f, 0.0f);

			//アニメーションパターンのインクリメン
			m_nPatternAnimEnemy++;
		}

		m_nTime--;

		if (m_nTime <= 0)
		{
			CBullet::Create(EnemyPos, D3DXVECTOR3(-10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 0.0f, 0.0f), 7, 1, CBullet::BULLETTYPE_NOMAL);
		}
		if (m_nTime <= 0)
		{
			m_nTime = 50;
		}

		m_fRotMove += 0.1f;

		if (m_fRotMove >= D3DX_PI)
		{// 移動方向の正規化
			m_fRotMove -= D3DX_PI * 2;
		}
		else if (m_fRotMove <= -D3DX_PI)
		{// 移動方向の正規化
			m_fRotMove += D3DX_PI * 2;
		}

		EnemyPos.x -= sinf(D3DX_PI * 0.5f) * 2.0f;
		EnemyPos.y += sinf(m_fRotMove) * 8.0f;

		//位置設定
		SetMove(EnemyMove);

		//左から右にループ
		if (EnemyPos.x < -ENEMY_SIZE_X / 2 && m_nType == ENEMYTYPE_KYODAIMEDAMA)
		{
			EnemyPos.x = SCREEN_WIDTH + ENEMY_SIZE_X / 2;
			SetPosition(EnemyPos);
		}
	}

	//*****************************************************
	//	狙撃の挙動
	//*****************************************************
	if (m_nType == ENEMYTYPE_SOGEKI)
	{
		//当たり判定
		HitJudgment(EnemyPos);
		m_nMoveTime--;
		if (m_nMoveTime <= 0)
		{
			m_nRand = rand() % 2 + 1;	//0～9のランダムの数字を出したいときは%10を書く	1～6を出したいときは% 6 + 1になる
			m_flag = false;
		}
		if (m_nMoveTime <= 0)
		{
			m_nMoveTime = 100;
		}

		if (m_nRand == 1 && m_flag == false)
		{
			// 弾の初期化処理
			D3DXVECTOR3 PlayerPos;

			for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
			{
				//オブジェクトのポインタ
				CObject *pObject;
				//どのタイプかの情報をポインタに代入
				pObject = GetObjects(3, nCntType);

				//nullチェック
				if (pObject != nullptr)
				{
					if (pObject->GetType() == TYPE_PLAYER)
					{
						D3DXVECTOR3 PlayerPos1 = pObject->GetPos();
						PlayerPos = PlayerPos1;
					}
				}
			}
			m_nTime--;

			if (m_nTime <= 0)
			{
				CBullet::Create(D3DXVECTOR3(EnemyPos.x - 50.0f, EnemyPos.y, EnemyPos.z), -m_BulletMove, D3DXVECTOR3(5.0f, 0.0f, 0.0f), 7, 1, CBullet::BULLETTYPE_NOMAL);
			}
			if (m_nTime <= 0)
			{
				m_nTime = 40;
			}

			m_BulletMove = EnemyPos - PlayerPos;
			D3DXVec3Normalize(&m_BulletMove, &m_BulletMove);
			m_BulletMove *= 15.0f;
		}
	}

	//位置更新
	EnemyPos.x += EnemyMove.x;
	EnemyPos.y += EnemyMove.y;
	EnemyPos.z += EnemyMove.z;

	//移動量減衰
	EnemyPos.x += (0.0f - EnemyMove.x) * 0.1f;
	EnemyPos.y += (0.0f - EnemyMove.y) * 0.1f;
	EnemyPos.z += (0.0f - EnemyMove.z) * 0.1f;

	//位置の設定
	SetPosition(EnemyPos);
	SetMove(EnemyMove);
}

//敵の描画処理
void CEnemy::Draw()
{
	CObject2D::Draw();
}

//敵の生成
CEnemy *CEnemy::Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move,D3DXVECTOR3 size, ENEMYTYPE nType,int nLife)
{
	CEnemy *pEnemy = nullptr;

	//クラスの生成
	pEnemy = new CEnemy;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pEnemy != nullptr)
	{
		//初期化処理
		pEnemy->SetEnemyType(nType);
		pEnemy->Init();
		//設定処理
		pEnemy->SetPosition(pos);
		pEnemy->SetMove(move);
		pEnemy->SetSize(size);
		pEnemy->SetType(TYPE_ENEMY);
		pEnemy->SetLife(nLife);
	}
	else
	{
		assert(false);
	}

	return pEnemy;
}

//テクスチャの読み込み
HRESULT CEnemy::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/目玉3.png",
		&m_pTextureEnemy[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ミサイル.png",
		&m_pTextureEnemy[1]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/UFO.png",
		&m_pTextureEnemy[2]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/戦闘機4.png",
		&m_pTextureEnemy[3]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/22199391.png",
		&m_pTextureEnemy[4]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ボス状態.jpg",
		&m_pTextureEnemy[5]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/狙撃1.png",
		&m_pTextureEnemy[6]);

	return S_OK;
}

//テクスチャの破棄
void CEnemy::Unload(void)
{
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		//テクスチャの破棄
		if (m_pTextureEnemy[nCnt] != NULL)
		{
			m_pTextureEnemy[nCnt]->Release();
			m_pTextureEnemy[nCnt] = NULL;
		}
	}
}

//体力の設定処理
void CEnemy::SetLife(int nLife)
{
	m_nLife = nLife;
}

//敵のタイプの設定
void CEnemy::SetEnemyType(ENEMYTYPE type)
{
	m_nType = type;
}

//当たり判定
void CEnemy::HitJudgment(D3DXVECTOR3 pos)
{
	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//オブジェクトのポインタ
		CObject *pObject;
		//どのタイプかの情報をポインタに代入
		pObject = GetObjects(3, nCntType);

		//nullチェック
		if (pObject != nullptr)
		{
			//**********************************************************
			// 敵とプレイヤーの当たり判定
			//**********************************************************
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//敵の位置
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				//敵のサイズ
				D3DXVECTOR3 PlayerSize = pObject->GetSize();
				//敵の体力
				int nLife = pObject->GetLife();

				//敵の当たり判定
				if (pos.x + ENEMY_SIZE_X >= PlayerPos.x - PlayerSize.x
					&&pos.x - ENEMY_SIZE_X <= PlayerPos.x + PlayerSize.x
					&&pos.y + ENEMY_SIZE_Y >= PlayerPos.y - PlayerSize.y
					&&pos.y - ENEMY_SIZE_Y <= PlayerPos.y + PlayerSize.y)
				{
					//敵の体力を減らす
					nLife = 0;
					//体力の保存
					pObject->SetLife(nLife);
					//体力が0になったら
					if (nLife == 0)
					{
						//爆発
						CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						pObject->Uninit();
						m_PlayerGameOver = true;
						CResult::SetType(CResult::TYPE_GAMEOVER);
						CFade::SetFade(CApplication::MODE_RESULT);
						return;
					}
				}
			}
		}
	}
}

//ボスの当たり判定
void CEnemy::HitBossJudgment(D3DXVECTOR3 pos)
{
	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//オブジェクトのポインタ
		CObject *pObject;
		//どのタイプかの情報をポインタに代入
		pObject = GetObjects(3, nCntType);

		//nullチェック
		if (pObject != nullptr)
		{
			//**********************************************************
			// 敵とプレイヤーの当たり判定
			//**********************************************************
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//敵の位置
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				//敵のサイズ
				D3DXVECTOR3 PlayerSize = pObject->GetSize();
				//敵の体力
				int nLife = pObject->GetLife();

				//敵の当たり判定
				if (pos.x + BOSS_SIZE_X - 50.0f>= PlayerPos.x - PlayerSize.x
					&&pos.x - BOSS_SIZE_X + 50.0f <= PlayerPos.x + PlayerSize.x
					&&pos.y + BOSS_SIZE_Y - 50.0f >= PlayerPos.y - PlayerSize.y
					&&pos.y - BOSS_SIZE_Y + 50.0f <= PlayerPos.y + PlayerSize.y)
				{
					//敵の体力を減らす
					nLife = 0;
					//体力の保存
					pObject->SetLife(nLife);
					//体力が0になったら
					if (nLife == 0)
					{
						//爆発
						CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						pObject->Uninit();
						m_PlayerGameOver = true;
						CResult::SetType(CResult::TYPE_GAMEOVER);
						CFade::SetFade(CApplication::MODE_RESULT);
						return;
					}
				}
			}
		}
	}
}

