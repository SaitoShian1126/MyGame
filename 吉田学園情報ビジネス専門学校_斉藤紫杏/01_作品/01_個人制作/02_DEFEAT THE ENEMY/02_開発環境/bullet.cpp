//********************************************
//
//	bullet.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "bullet.h"
#include "application.h"
#include "renderer.h"
#include "player.h"
#include "object2D.h"
#include "explosion.h"
#include "enemy.h"
#include "effect.h"
#include "spawn.h"
#include "score.h"
#include "item.h"
#include "game.h"
#include "fade.h"
#include "result.h"
#include "particle.h"
#include "scene.h"
#include "sound.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CBullet::m_apTextureBullet[2] = {};
D3DXVECTOR3 CBullet::m_BulletMove = {};
int CBullet::m_nCntDeath = 0;
bool CBullet::PlayerGameClear = false;

//弾のコンストラクタ
CBullet::CBullet()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_BulletPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_BulletMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 0;
	m_nRand = 0;
	m_nItemRand = 0;
	m_nBossUninitTime = 0;
	PlayerGameClear = false;
	m_PlayerDeath = false;
	m_flag = false;
}

//弾のデストラクタ
CBullet::~CBullet()
{
	//何も書かない
}

//弾の初期化処理
HRESULT CBullet::Init(void)
{
	//object2D初期化処理関数呼び出し
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************
	m_BulletPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_BulletMove = D3DXVECTOR3(10.0f, 0.0f, 0.0f);
	m_nLife = 50;
	m_nBossUninitTime = 500;
	m_nRand = 0;
	m_nItemRand = 0;
	PlayerGameClear = false;
	m_PlayerDeath = false;
	m_flag = false;

	switch (m_nType)
	{
	case BULLETTYPE_NOMAL:
		//テクスチャ反映
		BindTexture(m_apTextureBullet[0]);
		break;
	case BULLETTYPE_SITA:
		//テクスチャ反映
		BindTexture(m_apTextureBullet[0]);
		break;
	default:
		break;
	}

	return S_OK;
}

//弾の終了処理
void CBullet::Uninit(void)
{
	//object2D終了処理関数呼び出し
	CObject2D::Uninit();
}

//弾の更新処理
void CBullet::Update(void)
{
	D3DXVECTOR3 BulletPos = GetPos();
	D3DXVECTOR3 BulletMove = GetMove();

	//弾の位置更新
	BulletPos += BulletMove;

	//寿命を減らす処理
	m_nLife--;

	if (m_nType == BULLETTYPE_SITA)
	{
		BulletMove.y += 0.5f;
		SetMove(BulletMove);
	}

	//位置の設定
	SetPosition(BulletPos);
	CObject2D::Update();
	//プレイヤー
	if (m_nUser == 0)
	{
		//エフェクトの生成
		CEffect::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(20.0f, 15.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 1.0f, 1.0f), 5);
	}
	//敵
	if (m_nUser == 1)
	{
		//エフェクトの生成
		CEffect::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(20.0f, 15.0f, 0.0f), D3DXCOLOR(1.0f, 0.1f, 0.1f, 1.0f), 5);
	}
	//攻撃
	if (m_nUser == 2)
	{
		//エフェクトの生成
		CEffect::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(20.0f, 15.0f, 0.0f), D3DXCOLOR(0.5f, 0.5f, 0.2f, 1.0f), 5);
	}
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
			// 敵の当たり判定
			//**********************************************************
			if (pObject->GetType() == TYPE_ENEMY && m_nUser == 0 || pObject->GetType() == TYPE_ENEMY &&m_nUser == 2)
			{
				//敵の位置
				D3DXVECTOR3 EnemyPos = pObject->GetPos();
				//敵のサイズ
				D3DXVECTOR3 EnemySize = pObject->GetSize();
				CEnemy *pEnemy = nullptr;
				pEnemy->GetEnemyType();
				//敵の体力
				int nLife = pObject->GetLife();

				//敵の当たり判定
				if (BulletPos.x + 5.0f >= EnemyPos.x - EnemySize.x
					&&BulletPos.x - 5.0f <= EnemyPos.x + EnemySize.x
					&&BulletPos.y + 5.0f >= EnemyPos.y - EnemySize.y
					&&BulletPos.y - 5.0f <= EnemyPos.y + EnemySize.y)
				{
					//爆発
					CExplosion::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.0f, 0.5f, 1.0f, 1.0f), CExplosion::EXPLOTIONTYPE_KOUGEKI);
					//敵の体力を減らす
					nLife--;
					//体力の保存
					pObject->SetLife(nLife);
					//体力が0になったら
					if (nLife == 0)
					{
						if (m_flag == false)
						{
							m_nRand = rand() % 5 + 1;
							m_nItemRand = rand() % 5 + 1;
							m_flag = true;
						}
						if (m_nRand == 1 && m_nItemRand == 1 && m_flag == true || m_nRand == 1 && m_nItemRand == 2 && m_flag == true)
						{
							//アイテムの生成
							CItem::Create(D3DXVECTOR3(640.0f, 50.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), CItem::ITEMTYPE_SCOREUP);
							m_flag = false;
						}
						else if (m_nRand == 1 && m_nItemRand == 3 && m_flag == true || m_nRand == 1 && m_nItemRand == 4 && m_flag == true)
						{
							//アイテムの生成
							CItem::Create(D3DXVECTOR3(640.0f, 50.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), CItem::ITEMTYPE_LIFEUP);
							m_flag = false;
						}
						else if (m_nRand == 1 && m_nItemRand == 5 && m_flag == true && CItem::GetAttackCount() == 0)
						{
							//アイテムの生成
							CItem::Create(D3DXVECTOR3(640.0f, 50.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), CItem::ITEMTYPE_ATTACKUP);
							m_flag = false;
						}
						else if (m_flag == true)
						{
							m_flag = false;
						}
						//サウンドの再生
						PlaySound(SOUND_LABEL_SE_ENEMYEXPLOSION);
             			m_nCntDeath++;
						//スコアの加算
						CGame::GetScore()->AddScore(5000);
						//爆発
						CExplosion::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);

						if (m_nCntDeath == 6 && pEnemy->ENEMYTYPE_MEDAMA)
						{
							CEnemy::Create(D3DXVECTOR3(1900.0f, 120.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X + 20.0f, ENEMY_SIZE_Y + 20.0f, 0.0f), CEnemy::ENEMYTYPE_HEBI, 10);
							CEnemy::Create(D3DXVECTOR3(1600.0f, 240.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X + 20.0f, ENEMY_SIZE_Y + 20.0f, 0.0f), CEnemy::ENEMYTYPE_HEBI, 10);
							CEnemy::Create(D3DXVECTOR3(1300.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X + 20.0f, ENEMY_SIZE_Y + 20.0f, 0.0f), CEnemy::ENEMYTYPE_HEBI, 10);
							CEnemy::Create(D3DXVECTOR3(1600.0f, 480.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X + 20.0f, ENEMY_SIZE_Y + 20.0f, 0.0f), CEnemy::ENEMYTYPE_HEBI, 10);
							CEnemy::Create(D3DXVECTOR3(1900.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X + 20.0f, ENEMY_SIZE_Y + 20.0f, 0.0f), CEnemy::ENEMYTYPE_HEBI, 10);
							CEnemy::Create(D3DXVECTOR3(2200.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X + 50.0f, ENEMY_SIZE_Y + 50.0f, 0.0f), CEnemy::ENEMYTYPE_HEBI, 10);
							CEnemy::Create(D3DXVECTOR3(1200.0f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(100.0f, 100.0f, 0.0f), CEnemy::ENEMYTYPE_SOGEKI, ENEMY_LIFE_SOGEKI);
						}
						if (m_nCntDeath == 13)
						{
							for (int nCnt = 0; nCnt < 2; nCnt++)
							{
								//一定時間たったら爆発する敵の生成
								CEnemy::Create(D3DXVECTOR3(200.0f + 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(70.0f, 70.0f, 0.0f), CEnemy::ENEMYTYPE_BOMB, ENEMY_LIFE_BOMB);
							}

							//ジグザグに動く敵の生成
							CEnemy::Create(D3DXVECTOR3(1300.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X, ENEMY_SIZE_Y, 0.0f), CEnemy::ENEMYTYPE_ZIGUZAGU, ENEMY_LIFE_ZIGUZAGU);
						}
						if (pEnemy->ENEMYTYPE_ZIGUZAGU && m_nCntDeath == 15)
						{
							for (int nCnt = 0; nCnt < 4; nCnt++)
							{
								CEnemy::Create(D3DXVECTOR3(1300.0, 100.0f + 173.0f * nCnt, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X, ENEMY_SIZE_Y, 0.0f), CEnemy::ENEMYTYPE_MEDAMA, 5);
							}
							CEnemy::Create(D3DXVECTOR3(1200.0f, 670.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(100.0f, 100.0f, 0.0f), CEnemy::ENEMYTYPE_SOGEKI, ENEMY_LIFE_SOGEKI);
							CEnemy::Create(D3DXVECTOR3(1200.0f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(100.0f, 100.0f, 0.0f), CEnemy::ENEMYTYPE_SOGEKI, ENEMY_LIFE_SOGEKI);
						}
						if (m_nCntDeath == 22)
						{
							for (int nCnt = 0; nCnt < 3; nCnt++)
							{
								CEnemy::Create(D3DXVECTOR3(1400.0f, 50.0f + 300.0f * nCnt, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X, ENEMY_SIZE_Y, 0.0f), CEnemy::ENEMYTYPE_ENN, 20);
							}
							CEnemy::Create(D3DXVECTOR3(1800.0f, 160.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X, ENEMY_SIZE_Y, 0.0f), CEnemy::ENEMYTYPE_ENN, 20);
							CEnemy::Create(D3DXVECTOR3(1800.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X, ENEMY_SIZE_Y, 0.0f), CEnemy::ENEMYTYPE_ENN, 20); 
						}
						if (m_nCntDeath == 27)
						{
							CScene::Create(D3DXVECTOR3(1280.0f, 360.0f, 0.0f), D3DXVECTOR3(640.0f, 360.0f, 0.0f), CScene::SCENETYPE_BOSS);
						}
						if (m_nCntDeath == 28)
						{	
							CGame::GetScore()->AddScore(5000000);
							PlayerGameClear = true;
							CResult::SetType(CResult::TYPE_GAMECLEAR);
							CFade::SetFade(CApplication::MODE_RESULT);
						}
						//敵の削除
						pObject->Uninit();
						return;
					}
					//弾の削除
					Uninit();
					return;
				}
			}

			//**********************************************************
			// ボスの当たり判定
			//**********************************************************
			if (pObject->GetType() == TYPE_BOSS && m_nUser == 0)
			{
				//敵の位置
				D3DXVECTOR3 BossPos = pObject->GetPos();
				//敵のサイズ
				D3DXVECTOR3 BossSize = pObject->GetSize();
				//敵の体力
				int nLife = pObject->GetLife();

				//敵の当たり判定
				if (BulletPos.x + 5.0f >= BossPos.x - BossSize.x + 120.0f
					&&BulletPos.x - 5.0f <= BossPos.x + BossSize.x - 120.0f
					&&BulletPos.y + 5.0f >= BossPos.y - BossSize.y + 55.0f
					&&BulletPos.y - 5.0f <= BossPos.y + BossSize.y - 55.0f)
				{
					//敵の体力を減らす
					nLife--;
					//体力の保存
					pObject->SetLife(nLife);
					//体力が0になったら
					if (nLife == 0)
					{
						m_nCntDeath++;
						//爆発
						CExplosion::Create(D3DXVECTOR3(BossPos), D3DXVECTOR3(200.0f, 200.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						m_nBossUninitTime--;
						if (m_nBossUninitTime <= 0)
						{
							//敵の削除
							pObject->Uninit();
							return;
						}
					}
					//弾の削除
					m_nLife = 0;
				}
			}

			//**********************************************************
			// プレイヤーの当たり判定
			//**********************************************************
			if (pObject->GetType() == TYPE_PLAYER && m_nUser == 1)
			{
				//プレイヤーの位置
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				//プレイヤーのサイズ
				D3DXVECTOR3 PlayerSize = pObject->GetSize();
				//プレイヤーの体力
				int nLife = pObject->GetLife();

				//プレイヤーの当たり判定
				if (BulletPos.x + 5.0f >= PlayerPos.x - PlayerSize.x
					&&BulletPos.x - 5.0f <= PlayerPos.x + PlayerSize.x
					&&BulletPos.y + 5.0f >= PlayerPos.y - PlayerSize.y
					&&BulletPos.y - 5.0f <= PlayerPos.y + PlayerSize.y)
				{
					//サウンドの再生
					PlaySound(SOUND_LABEL_SE_DAMAGE);
					//スコアの加算
					CGame::GetScore()->SubScore(1000);
					//プレイヤーの体力を減らす						  
					nLife--;
					//爆発
					CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_KOUGEKI);
					//プレイヤーの体力の保存
					pObject->SetLife(nLife);
					//プレイヤーの体力が0になったら
					if (nLife <= 0)
					{
						//サウンドの再生
						PlaySound(SOUND_LABEL_SE_ENEMYEXPLOSION);
						//爆発
						CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						m_PlayerDeath = CEnemy::GetPlayerDeathFlag();
						m_PlayerDeath = true;
						CResult::SetType(CResult::TYPE_GAMEOVER);
						CFade::SetFade(CApplication::MODE_RESULT);
						pObject->Uninit();
						return;
					}
					//弾の削除
					m_nLife = 0;
				}
			}

			//**********************************************************
			// スポーンと弾の当たり判定
			//**********************************************************
			if (pObject->GetType() == TYPE_SPAWN && m_nUser == 0)
			{
				//敵の位置
				D3DXVECTOR3 SpawnPos = pObject->GetPos();
				CSpawn *pSpawn = nullptr;
				pSpawn->GetSpawnType();
				int SpawnLife = pObject->GetLife();

				//敵の当たり判定
				if (BulletPos.x + 5.0f >= SpawnPos.x - 60.0f
					&&BulletPos.x - 5.0f <= SpawnPos.x + 60.0f
					&&BulletPos.y + 5.0f >= SpawnPos.y - 60.0f
					&&BulletPos.y - 5.0f <= SpawnPos.y + 60.0f)
				{
					SpawnLife--;
					pObject->SetLife(SpawnLife);

					//爆発
					CExplosion::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(20.0f, 20.0f, 0.0f), D3DXCOLOR(1.0f, 0.8f, 0.5f, 1.0f), CExplosion::EXPLOTIONTYPE_KOUGEKI);

					if (SpawnLife <= 0)
					{
						//爆発
						CExplosion::Create(D3DXVECTOR3(SpawnPos), D3DXVECTOR3(35.0f, 35.0f, 0.0f), D3DXCOLOR(1.0f, 0.8f, 0.8f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						pObject->Uninit();
						return;
					}
					//弾の削除
					m_nLife = 0;
				}
			}

			//**********************************************************
			// 量産敵の当たり判定
			//**********************************************************
			if (pObject->GetType() == TYPE_MPENEMY && m_nUser == 0)
			{
				//敵の位置
				D3DXVECTOR3 MPEnemyPos = pObject->GetPos();
				//敵のサイズ
				D3DXVECTOR3 MPEnemySize = pObject->GetSize();
				//敵の体力
				int MPEnemynLife = pObject->GetLife();

				//敵の当たり判定
				if (BulletPos.x + 5.0f >= MPEnemyPos.x - MPEnemySize.x
					&&BulletPos.x - 5.0f <= MPEnemyPos.x + MPEnemySize.x
					&&BulletPos.y + 5.0f >= MPEnemyPos.y - MPEnemySize.y
					&&BulletPos.y - 5.0f <= MPEnemyPos.y + MPEnemySize.y)
				{
					//敵の体力を減らす
					MPEnemynLife--;
					//体力の保存
					pObject->SetLife(MPEnemynLife);
					//体力が0になったら
					if (MPEnemynLife == 0)
					{
						m_nCntDeath++;
						//爆発
						CExplosion::Create(D3DXVECTOR3(MPEnemyPos), D3DXVECTOR3(20.0f, 20.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						//敵の削除
						pObject->Uninit();
						return;
					}
					//弾の削除
					m_nLife = 0;
				}
			}
		}
	}

	//弾のライフが0になったら
	if (m_nLife == 0)
	{
		//弾の削除
		Uninit();
		return;
	}

	//プレイヤーが死んだら敵の出現カウントを初期化する
	if (CEnemy::GetPlayerDeathFlag() == true || CBullet::GetPlayerGameClear() == true || m_PlayerDeath == true)
	{
		m_nCntDeath = 0;
	}
}

//弾の描画処理
void CBullet::Draw(void)
{
	CObject2D::Draw();
}

//弾の生成
CBullet *CBullet::Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move,D3DXVECTOR3 size,int nLife,int nUser, BULLETTYPE nType)
{
	CBullet *pBullet = nullptr;

	//弾のインスタンスの生成
	pBullet = new CBullet;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pBullet != nullptr)
	{
		//初期化処理
		pBullet->SetBulletType(nType);
		pBullet->SetUser(nUser);
		pBullet->Init();
		//設定処理
		pBullet->SetPosition(pos);
		pBullet->SetMove(move);
		pBullet->SetSize(size);
		pBullet->SetLife(nLife);
		pBullet->SetType(TYPE_BULLET);
	}
	else
	{
		assert(false);
	}

	return pBullet;
}

//テクスチャの読み込み
HRESULT CBullet::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/弾.png",
		&m_apTextureBullet[0]);

	return S_OK;
}

//テクスチャの破棄
void CBullet::Unload(void)
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		//テクスチャの破棄
		if (m_apTextureBullet[nCnt] != NULL)
		{					 
			m_apTextureBullet[nCnt]->Release();
			m_apTextureBullet[nCnt] = NULL;
		}
	}
}

//弾の種類の設定
void CBullet::SetBulletType(BULLETTYPE type)
{
	m_nType = type;
}

//弾を使用している奴
void CBullet::SetUser(int nUser)
{
	m_nUser = nUser;
}