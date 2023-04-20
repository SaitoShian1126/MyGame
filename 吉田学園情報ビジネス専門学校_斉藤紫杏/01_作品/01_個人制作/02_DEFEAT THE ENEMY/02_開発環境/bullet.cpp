//********************************************
//
//	bullet.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
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

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CBullet::m_apTextureBullet[2] = {};
D3DXVECTOR3 CBullet::m_BulletMove = {};
int CBullet::m_nCntDeath = 0;
bool CBullet::PlayerGameClear = false;

//�e�̃R���X�g���N�^
CBullet::CBullet()
{
	//********************************
	//�����o�ϐ��̃N���A
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

//�e�̃f�X�g���N�^
CBullet::~CBullet()
{
	//���������Ȃ�
}

//�e�̏���������
HRESULT CBullet::Init(void)
{
	//object2D�����������֐��Ăяo��
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
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
		//�e�N�X�`�����f
		BindTexture(m_apTextureBullet[0]);
		break;
	case BULLETTYPE_SITA:
		//�e�N�X�`�����f
		BindTexture(m_apTextureBullet[0]);
		break;
	default:
		break;
	}

	return S_OK;
}

//�e�̏I������
void CBullet::Uninit(void)
{
	//object2D�I�������֐��Ăяo��
	CObject2D::Uninit();
}

//�e�̍X�V����
void CBullet::Update(void)
{
	D3DXVECTOR3 BulletPos = GetPos();
	D3DXVECTOR3 BulletMove = GetMove();

	//�e�̈ʒu�X�V
	BulletPos += BulletMove;

	//���������炷����
	m_nLife--;

	if (m_nType == BULLETTYPE_SITA)
	{
		BulletMove.y += 0.5f;
		SetMove(BulletMove);
	}

	//�ʒu�̐ݒ�
	SetPosition(BulletPos);
	CObject2D::Update();
	//�v���C���[
	if (m_nUser == 0)
	{
		//�G�t�F�N�g�̐���
		CEffect::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(20.0f, 15.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 1.0f, 1.0f), 5);
	}
	//�G
	if (m_nUser == 1)
	{
		//�G�t�F�N�g�̐���
		CEffect::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(20.0f, 15.0f, 0.0f), D3DXCOLOR(1.0f, 0.1f, 0.1f, 1.0f), 5);
	}
	//�U��
	if (m_nUser == 2)
	{
		//�G�t�F�N�g�̐���
		CEffect::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(20.0f, 15.0f, 0.0f), D3DXCOLOR(0.5f, 0.5f, 0.2f, 1.0f), 5);
	}
	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//�I�u�W�F�N�g�̃|�C���^
		CObject *pObject;
		//�ǂ̃^�C�v���̏����|�C���^�ɑ��
		pObject = GetObjects(3, nCntType);

		//null�`�F�b�N
		if (pObject != nullptr)
		{
			//**********************************************************
			// �G�̓����蔻��
			//**********************************************************
			if (pObject->GetType() == TYPE_ENEMY && m_nUser == 0 || pObject->GetType() == TYPE_ENEMY &&m_nUser == 2)
			{
				//�G�̈ʒu
				D3DXVECTOR3 EnemyPos = pObject->GetPos();
				//�G�̃T�C�Y
				D3DXVECTOR3 EnemySize = pObject->GetSize();
				CEnemy *pEnemy = nullptr;
				pEnemy->GetEnemyType();
				//�G�̗̑�
				int nLife = pObject->GetLife();

				//�G�̓����蔻��
				if (BulletPos.x + 5.0f >= EnemyPos.x - EnemySize.x
					&&BulletPos.x - 5.0f <= EnemyPos.x + EnemySize.x
					&&BulletPos.y + 5.0f >= EnemyPos.y - EnemySize.y
					&&BulletPos.y - 5.0f <= EnemyPos.y + EnemySize.y)
				{
					//����
					CExplosion::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.0f, 0.5f, 1.0f, 1.0f), CExplosion::EXPLOTIONTYPE_KOUGEKI);
					//�G�̗̑͂����炷
					nLife--;
					//�̗͂̕ۑ�
					pObject->SetLife(nLife);
					//�̗͂�0�ɂȂ�����
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
							//�A�C�e���̐���
							CItem::Create(D3DXVECTOR3(640.0f, 50.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), CItem::ITEMTYPE_SCOREUP);
							m_flag = false;
						}
						else if (m_nRand == 1 && m_nItemRand == 3 && m_flag == true || m_nRand == 1 && m_nItemRand == 4 && m_flag == true)
						{
							//�A�C�e���̐���
							CItem::Create(D3DXVECTOR3(640.0f, 50.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), CItem::ITEMTYPE_LIFEUP);
							m_flag = false;
						}
						else if (m_nRand == 1 && m_nItemRand == 5 && m_flag == true && CItem::GetAttackCount() == 0)
						{
							//�A�C�e���̐���
							CItem::Create(D3DXVECTOR3(640.0f, 50.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), CItem::ITEMTYPE_ATTACKUP);
							m_flag = false;
						}
						else if (m_flag == true)
						{
							m_flag = false;
						}
						//�T�E���h�̍Đ�
						PlaySound(SOUND_LABEL_SE_ENEMYEXPLOSION);
             			m_nCntDeath++;
						//�X�R�A�̉��Z
						CGame::GetScore()->AddScore(5000);
						//����
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
								//��莞�Ԃ������甚������G�̐���
								CEnemy::Create(D3DXVECTOR3(200.0f + 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(70.0f, 70.0f, 0.0f), CEnemy::ENEMYTYPE_BOMB, ENEMY_LIFE_BOMB);
							}

							//�W�O�U�O�ɓ����G�̐���
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
						//�G�̍폜
						pObject->Uninit();
						return;
					}
					//�e�̍폜
					Uninit();
					return;
				}
			}

			//**********************************************************
			// �{�X�̓����蔻��
			//**********************************************************
			if (pObject->GetType() == TYPE_BOSS && m_nUser == 0)
			{
				//�G�̈ʒu
				D3DXVECTOR3 BossPos = pObject->GetPos();
				//�G�̃T�C�Y
				D3DXVECTOR3 BossSize = pObject->GetSize();
				//�G�̗̑�
				int nLife = pObject->GetLife();

				//�G�̓����蔻��
				if (BulletPos.x + 5.0f >= BossPos.x - BossSize.x + 120.0f
					&&BulletPos.x - 5.0f <= BossPos.x + BossSize.x - 120.0f
					&&BulletPos.y + 5.0f >= BossPos.y - BossSize.y + 55.0f
					&&BulletPos.y - 5.0f <= BossPos.y + BossSize.y - 55.0f)
				{
					//�G�̗̑͂����炷
					nLife--;
					//�̗͂̕ۑ�
					pObject->SetLife(nLife);
					//�̗͂�0�ɂȂ�����
					if (nLife == 0)
					{
						m_nCntDeath++;
						//����
						CExplosion::Create(D3DXVECTOR3(BossPos), D3DXVECTOR3(200.0f, 200.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						m_nBossUninitTime--;
						if (m_nBossUninitTime <= 0)
						{
							//�G�̍폜
							pObject->Uninit();
							return;
						}
					}
					//�e�̍폜
					m_nLife = 0;
				}
			}

			//**********************************************************
			// �v���C���[�̓����蔻��
			//**********************************************************
			if (pObject->GetType() == TYPE_PLAYER && m_nUser == 1)
			{
				//�v���C���[�̈ʒu
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				//�v���C���[�̃T�C�Y
				D3DXVECTOR3 PlayerSize = pObject->GetSize();
				//�v���C���[�̗̑�
				int nLife = pObject->GetLife();

				//�v���C���[�̓����蔻��
				if (BulletPos.x + 5.0f >= PlayerPos.x - PlayerSize.x
					&&BulletPos.x - 5.0f <= PlayerPos.x + PlayerSize.x
					&&BulletPos.y + 5.0f >= PlayerPos.y - PlayerSize.y
					&&BulletPos.y - 5.0f <= PlayerPos.y + PlayerSize.y)
				{
					//�T�E���h�̍Đ�
					PlaySound(SOUND_LABEL_SE_DAMAGE);
					//�X�R�A�̉��Z
					CGame::GetScore()->SubScore(1000);
					//�v���C���[�̗̑͂����炷						  
					nLife--;
					//����
					CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_KOUGEKI);
					//�v���C���[�̗̑͂̕ۑ�
					pObject->SetLife(nLife);
					//�v���C���[�̗̑͂�0�ɂȂ�����
					if (nLife <= 0)
					{
						//�T�E���h�̍Đ�
						PlaySound(SOUND_LABEL_SE_ENEMYEXPLOSION);
						//����
						CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						m_PlayerDeath = CEnemy::GetPlayerDeathFlag();
						m_PlayerDeath = true;
						CResult::SetType(CResult::TYPE_GAMEOVER);
						CFade::SetFade(CApplication::MODE_RESULT);
						pObject->Uninit();
						return;
					}
					//�e�̍폜
					m_nLife = 0;
				}
			}

			//**********************************************************
			// �X�|�[���ƒe�̓����蔻��
			//**********************************************************
			if (pObject->GetType() == TYPE_SPAWN && m_nUser == 0)
			{
				//�G�̈ʒu
				D3DXVECTOR3 SpawnPos = pObject->GetPos();
				CSpawn *pSpawn = nullptr;
				pSpawn->GetSpawnType();
				int SpawnLife = pObject->GetLife();

				//�G�̓����蔻��
				if (BulletPos.x + 5.0f >= SpawnPos.x - 60.0f
					&&BulletPos.x - 5.0f <= SpawnPos.x + 60.0f
					&&BulletPos.y + 5.0f >= SpawnPos.y - 60.0f
					&&BulletPos.y - 5.0f <= SpawnPos.y + 60.0f)
				{
					SpawnLife--;
					pObject->SetLife(SpawnLife);

					//����
					CExplosion::Create(D3DXVECTOR3(BulletPos), D3DXVECTOR3(20.0f, 20.0f, 0.0f), D3DXCOLOR(1.0f, 0.8f, 0.5f, 1.0f), CExplosion::EXPLOTIONTYPE_KOUGEKI);

					if (SpawnLife <= 0)
					{
						//����
						CExplosion::Create(D3DXVECTOR3(SpawnPos), D3DXVECTOR3(35.0f, 35.0f, 0.0f), D3DXCOLOR(1.0f, 0.8f, 0.8f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						pObject->Uninit();
						return;
					}
					//�e�̍폜
					m_nLife = 0;
				}
			}

			//**********************************************************
			// �ʎY�G�̓����蔻��
			//**********************************************************
			if (pObject->GetType() == TYPE_MPENEMY && m_nUser == 0)
			{
				//�G�̈ʒu
				D3DXVECTOR3 MPEnemyPos = pObject->GetPos();
				//�G�̃T�C�Y
				D3DXVECTOR3 MPEnemySize = pObject->GetSize();
				//�G�̗̑�
				int MPEnemynLife = pObject->GetLife();

				//�G�̓����蔻��
				if (BulletPos.x + 5.0f >= MPEnemyPos.x - MPEnemySize.x
					&&BulletPos.x - 5.0f <= MPEnemyPos.x + MPEnemySize.x
					&&BulletPos.y + 5.0f >= MPEnemyPos.y - MPEnemySize.y
					&&BulletPos.y - 5.0f <= MPEnemyPos.y + MPEnemySize.y)
				{
					//�G�̗̑͂����炷
					MPEnemynLife--;
					//�̗͂̕ۑ�
					pObject->SetLife(MPEnemynLife);
					//�̗͂�0�ɂȂ�����
					if (MPEnemynLife == 0)
					{
						m_nCntDeath++;
						//����
						CExplosion::Create(D3DXVECTOR3(MPEnemyPos), D3DXVECTOR3(20.0f, 20.0f, 0.0f), D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
						//�G�̍폜
						pObject->Uninit();
						return;
					}
					//�e�̍폜
					m_nLife = 0;
				}
			}
		}
	}

	//�e�̃��C�t��0�ɂȂ�����
	if (m_nLife == 0)
	{
		//�e�̍폜
		Uninit();
		return;
	}

	//�v���C���[�����񂾂�G�̏o���J�E���g������������
	if (CEnemy::GetPlayerDeathFlag() == true || CBullet::GetPlayerGameClear() == true || m_PlayerDeath == true)
	{
		m_nCntDeath = 0;
	}
}

//�e�̕`�揈��
void CBullet::Draw(void)
{
	CObject2D::Draw();
}

//�e�̐���
CBullet *CBullet::Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move,D3DXVECTOR3 size,int nLife,int nUser, BULLETTYPE nType)
{
	CBullet *pBullet = nullptr;

	//�e�̃C���X�^���X�̐���
	pBullet = new CBullet;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pBullet != nullptr)
	{
		//����������
		pBullet->SetBulletType(nType);
		pBullet->SetUser(nUser);
		pBullet->Init();
		//�ݒ菈��
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

//�e�N�X�`���̓ǂݍ���
HRESULT CBullet::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�e.png",
		&m_apTextureBullet[0]);

	return S_OK;
}

//�e�N�X�`���̔j��
void CBullet::Unload(void)
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_apTextureBullet[nCnt] != NULL)
		{					 
			m_apTextureBullet[nCnt]->Release();
			m_apTextureBullet[nCnt] = NULL;
		}
	}
}

//�e�̎�ނ̐ݒ�
void CBullet::SetBulletType(BULLETTYPE type)
{
	m_nType = type;
}

//�e���g�p���Ă���z
void CBullet::SetUser(int nUser)
{
	m_nUser = nUser;
}