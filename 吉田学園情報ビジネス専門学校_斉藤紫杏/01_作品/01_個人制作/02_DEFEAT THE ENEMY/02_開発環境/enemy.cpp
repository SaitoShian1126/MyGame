//********************************************
//
//	enemy.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
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

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CEnemy::m_pTextureEnemy[7] = {}; 
bool CEnemy::m_PlayerGameOver = false;

//�G�̃R���X�g���N�^
CEnemy::CEnemy()
{
	//********************************
	//�����o�ϐ��̃N���A
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

//�G�̃f�X�g���N�^
CEnemy::~CEnemy()
{
	//���������Ȃ�
}

//�G�̏���������
HRESULT CEnemy::Init(void)
{	
	CObject2D::Init();
	//����
	srand((unsigned int)time(NULL));	//�N�����Ɉ�񂾂��s�����ߏ������ɏ���	

	//********************************
	//�����o�ϐ��̏�����
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
		//�e�N�X�`�����f
		BindTexture(m_pTextureEnemy[0]);
		//�e�N�X�`���̐ݒ�
		SetTexture(3.0f, 0.0f, 1.0f, 0.0f);
		break;
	case ENEMYTYPE_KYODAIMEDAMA:
		//�e�N�X�`�����f
		BindTexture(m_pTextureEnemy[0]);
		break;
	case ENEMYTYPE_BOMB:
		//�e�N�X�`�����f
		BindTexture(m_pTextureEnemy[1]);
		break;
	case ENEMYTYPE_ZIGUZAGU:
		//�e�N�X�`�����f
		BindTexture(m_pTextureEnemy[2]);
		break;
	case ENEMYTYPE_ENN:
		//�e�N�X�`�����f
		BindTexture(m_pTextureEnemy[3]);
		break;
	case ENEMYTYPE_HEBI:
		//�e�N�X�`�����f
		BindTexture(m_pTextureEnemy[4]);
		break;
	case ENEMYTYPE_BOSS:
		//�e�N�X�`�����f
		BindTexture(m_pTextureEnemy[5]);
		//�e�N�X�`���̐ݒ�
		SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 0.0f);
		break;
	case ENEMYTYPE_SOGEKI:
		//�e�N�X�`�����f
		BindTexture(m_pTextureEnemy[6]);
		break;
	default:
		break;
	}

	return S_OK;
}

//�G�̏I������
void CEnemy::Uninit(void)
{
	CObject2D::Uninit();
}

//�G�̍X�V����
void CEnemy::Update()
{
	D3DXVECTOR3 EnemyPos = GetPos();
	D3DXVECTOR3 EnemyMove = GetMove();
	D3DXVECTOR3 EnemySize = GetSize();

	CObject2D::Update();

	//*****************************************************
	//	�^�񒆂ɂ܂��߂鋓��
	//*****************************************************
	//�G�̃^�C�v��0��������
	if (m_nType == ENEMYTYPE_MEDAMA)
	{
		//�����蔻��
		HitJudgment(EnemyPos);
		//�A�j���[�V�����J�E���^�[���C���N�������g
		m_nCounterAnimEnemy++;

		if (m_nCounterAnimEnemy % 15 == 0)
		{
			//�e�N�X�`���̐ݒ�
			SetTexture(3.0f, (float)m_nPatternAnimEnemy, 1.0f, 0.0f);

			//�A�j���[�V�����p�^�[���̃C���N������
			m_nPatternAnimEnemy++;
		}
		//�G��x�ʒu��1280.0f�ȏォ�t���O��true��������
		if (EnemyPos.x >= SCREEN_WIDTH && m_flag == true)
		{
			//�G�����ړ�
			EnemyMove = D3DXVECTOR3(-3.0f, 0.0f, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
			//�t���O��false�ɂ���
			m_flag = false;
		}
		//�G��x�ʒu����ʂ̔����ɗ����炩�t���O��false��������
		if (EnemyPos.x <= SCREEN_WIDTH / 2 && m_flag == false)
		{
			//�G���E�ړ�
			EnemyMove = D3DXVECTOR3(3.0f, 0.0f, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
			m_flag = true;
		}
	}

	//*****************************************************
	//	�ォ�痎���Ă��Ď��Ԍo�߂Ŕ�������
	//*****************************************************
	//�G�̃^�C�v��2��������
	if (m_nType == ENEMYTYPE_BOMB)
	{
		//�����蔻��
		HitJudgment(EnemyPos);
		//�G��y�ʒu��0.0f�ȉ���������
		if (EnemyPos.y <= 0.0f)
		{
			//�G�����ړ�
			EnemyMove = D3DXVECTOR3(0.0f, 3.0f, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
		}
		//�G��y�ʒu��640.0f�ȏゾ������
		m_sLifeTime--;
		if (m_sLifeTime <= 0)
		{
			//����
			CExplosion::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(100.0f, 100.0f, 0.0f),D3DXCOLOR(1.0f,0.0f,0.0f,1.0f),CExplosion::EXPLOTIONTYPE_BAKUHATU);

			//�G�̐���
			CEnemy::Create(D3DXVECTOR3(1300.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(ENEMY_SIZE_X + 15.0f, ENEMY_SIZE_Y + 15.0f, 0.0f), CEnemy::ENEMYTYPE_KYODAIMEDAMA, 50);

			//�G������
			CEnemy::Uninit();
			return;
		}
	}
	//*****************************************************
	//	�W�O�U�O�Ɉړ����鋓��
	//*****************************************************
	//�G�̃^�C�v��2��������
	if (m_nType == ENEMYTYPE_ZIGUZAGU)
	{
		//�����蔻��
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
		//�G�̋���
		if (EnemyPos.y >= RANGE_HIGH_Y && m_flag == true)
		{
			EnemyMove = D3DXVECTOR3(ENEMY_MOVE_X, -ENEMY_MOVE_Y, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
			m_flag = false;
		}
		else if (EnemyPos.y <= RANGE_HIGH_Y && m_flag == false)
		{
			EnemyMove = D3DXVECTOR3(ENEMY_MOVE_X, ENEMY_MOVE_Y, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
		}
		else if (EnemyPos.y <= RANGE_DOWN_Y && m_flag2 == false)
		{
			EnemyMove = D3DXVECTOR3(ENEMY_MOVE_X, ENEMY_MOVE_Y, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
			m_flag2 = true;
		}
		else if (EnemyPos.y >= RANGE_DOWN_Y && m_flag2 == true)
		{
			EnemyMove = D3DXVECTOR3(ENEMY_MOVE_X, -ENEMY_MOVE_Y, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
		}

		//������E�Ƀ��[�v
		if (EnemyPos.x < -ENEMY_SIZE_X / 2 && m_nType == ENEMYTYPE_ZIGUZAGU)
		{
			EnemyPos.x = SCREEN_WIDTH + ENEMY_SIZE_X / 2;
			SetPosition(EnemyPos);
		}
	}

	//*****************************************************
	//	�~��`���Đi�ދ���
	//*****************************************************
	if (m_nType == ENEMYTYPE_ENN)
	{
		if (EnemyMove.x <= -0.0f)
		{
			//�G�t�F�N�g�̐���
			CEffect::Create(D3DXVECTOR3(EnemyPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f), 10);
			//�����蔻��
			HitJudgment(EnemyPos);
		}
		if (EnemyPos.x >= 1400.0f)
		{
			//�e�N�X�`���̐ݒ�
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
			//�e�N�X�`���̐ݒ�
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
			//�e�N�X�`���̐ݒ�
			SetTexture(2.0f, 1.0f, 1.0f, 0.0f);
			EnemyMove.x = 7.5f;
			SetMove(EnemyMove);
			EnemySize = D3DXVECTOR3(20.0f, 20.0f, 0.0f);
			SetSize(EnemySize);
		}
		//�ʒu�X�V
		EnemyPos.x += EnemyMove.x;
		EnemyPos.y += EnemyMove.y;
		EnemyPos.z += EnemyMove.z;

		//�ړ��ʌ���
		EnemyPos.x += (0.0f - EnemyMove.x) * 0.1f;
		EnemyPos.y += (0.0f - EnemyMove.y) * 0.1f;
		EnemyPos.z += (0.0f - EnemyMove.z) * 0.1f;

		//�ʒu�̐ݒ�
		SetPosition(EnemyPos);
		SetMove(EnemyMove);
	}
		
	//*****************************************************
	//	���@�̏����O�ɗ����玩�@�̌��Ɉړ����鋓��
	//*****************************************************
	if (m_nType == ENEMYTYPE_HEBI)
	{
		//�����蔻��
		HitJudgment(EnemyPos);
		EnemyMove = D3DXVECTOR3(-3.0f, 0.0f, 0.0f);
		//�ʒu�ݒ�
		SetMove(EnemyMove);

		//������E�Ƀ��[�v
		if (EnemyPos.x < -ENEMY_SIZE_X / 2 && m_nType == ENEMYTYPE_HEBI)
		{
			EnemyPos.x = SCREEN_WIDTH + ENEMY_SIZE_X / 2;
			SetPosition(EnemyPos);
		}
	}
	//*****************************************************
	//	�����_���œ����G(�{�X�\��)
	//*****************************************************
	if (m_nType == ENEMYTYPE_BOSS)
	{
		//for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
		//{
		//	//�I�u�W�F�N�g�̃|�C���^
		//	CObject *pObject;
		//	//�ǂ̃^�C�v���̏����|�C���^�ɑ��
		//	pObject = GetObjects(3, nCntType);
		//
		//	//null�`�F�b�N
		//	if (pObject != nullptr)
		//	{
		//		//**********************************************************
		//		// �{�X�ƃv���C���[�̓����蔻��
		//		//**********************************************************
		//		if (pObject->GetType() == TYPE_PLAYER)
		//		{
		//			//�G�̈ʒu
		//			D3DXVECTOR3 PlayerPos = pObject->GetPos();
		//			//�G�̃T�C�Y
		//			D3DXVECTOR3 PlayerSize = pObject->GetSize();
		//			//�G�̗̑�
		//			int nLife = pObject->GetLife();
		//
		//			//�G�̓����蔻��
		//			if (EnemyPos.x + 150.0f >= PlayerPos.x - PlayerSize.x
		//				&&EnemyPos.x - 150.0f <= PlayerPos.x + PlayerSize.x
		//				&&EnemyPos.y + 170.0f >= PlayerPos.y - PlayerSize.y
		//				&&EnemyPos.y - 170.0f <= PlayerPos.y + PlayerSize.y)
		//			{
		//				//�G�̗̑͂����炷
		//				nLife = 0;
		//				//�̗͂̕ۑ�
		//				pObject->SetLife(nLife);
		//				//�̗͂�0�ɂȂ�����
		//				if (nLife == 0)
		//				{
		//					//����
		//					CExplosion::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
		//					m_PlayerGameOver = true;
		//					pObject->Uninit();
		//					CResult::SetType(CResult::TYPE_GAMEOVER);
		//					CFade::SetFade(CApplication::MODE_RESULT);
		//					return;
		//				}
		//				if (nLife <= 0 && m_nLife <= 0)
		//				{
		//					//����
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
		//�{�X�̗̑͂�1100�ɂȂ�����
		HitBossJudgment(EnemyPos);
		if (m_nLife <= 1100)
		{
			EnemyMove = D3DXVECTOR3(-2.0f, 0.0f, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
			if (m_nLife >= 800)
			{
				//�A�j���[�V�����J�E���^�[���C���N�������g
				m_nCounterAnimEnemy++;
				if (m_nCounterAnimEnemy % 50 == 0)
				{
					//�e�N�X�`���̐ݒ�
					SetTexture(MAX_BOSSTEXTURE_X, (float)m_nPatternAnimEnemy, MAX_BOSSTEXTURE_Y, 1.0f);
					//�A�j���[�V�����p�^�[���̃C���N�������g
					m_nPatternAnimEnemy++;
				}
				else if (m_nPatternAnimEnemy == 2.0f)
				{
					m_nPatternAnimEnemy = 0;
				}
			}
			else if (m_nLife <= 799)
			{
				//�A�j���[�V�����J�E���^�[���C���N�������g
				m_nCounterAnimEnemy++;
				if (m_nCounterAnimEnemy % 50 == 0)
				{
					//�e�N�X�`���̐ݒ�
					SetTexture(MAX_BOSSTEXTURE_X, (float)m_nPatternAnimEnemy, MAX_BOSSTEXTURE_Y, 4.0f);
					//�A�j���[�V�����p�^�[���̃C���N�������g
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
			//�ʒu�ݒ�
			SetMove(EnemyMove);
			if (m_nLife >= 800)
			{
				//�e�N�X�`���̐ݒ�
				SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 0.0f);
			}
			else if (m_nLife <= 799)
			{
				//�e�N�X�`���̐ݒ�
				SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 3.0f);
			}
			m_nBossTime--;
		}
		if (m_nBossTime <= 0)
		{
			EnemyMove = D3DXVECTOR3(MAX_BOSSTEXTURE_X, 0.0f, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
		}
		if (EnemyPos.x >= 1051.0f)
		{
			EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//�ʒu�ݒ�
			SetMove(EnemyMove);
			m_nAttackTime--;

			if (m_nLife >= 800)
			{
				//�A�j���[�V�����J�E���^�[���C���N�������g
				m_nCounterAnimEnemy++;

				if (m_nCounterAnimEnemy % 100 == 0)
				{
					//�e�N�X�`���̐ݒ�
					SetTexture(MAX_BOSSTEXTURE_X, (float)m_nPatternAnimEnemy, MAX_BOSSTEXTURE_Y, 2.0f);

					//�A�j���[�V�����p�^�[���̃C���N�������g
					m_nPatternAnimEnemy++;
				}
				if (m_nAttackTime <= 0)
				{
					if (m_nBulletCnt <= 4)
					{
						m_nBulletCnt++;
						//�e�̐���
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
				//�A�j���[�V�����J�E���^�[���C���N�������g
				m_nCounterAnimEnemy++;

				if (m_nCounterAnimEnemy % 100 == 0)
				{
					//�e�N�X�`���̐ݒ�
					SetTexture(MAX_BOSSTEXTURE_X, (float)m_nPatternAnimEnemy, MAX_BOSSTEXTURE_Y, 5.0f);

					//�A�j���[�V�����p�^�[���̃C���N�������g
					m_nPatternAnimEnemy++;
				}
				if (m_nAttackTime <= 0)
				{
					if (m_nBulletCnt <= 4)
					{
						m_nBulletCnt++;
						//�e�̐���
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
				//�e�N�X�`���̐ݒ�
				SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 0.0f);
				EnemyMove = D3DXVECTOR3(0.0f, -2.0f, 0.0f);
				//�ʒu�ݒ�
				SetMove(EnemyMove);
			}
			else if (m_nLife <= 799)
			{
				//�e�N�X�`���̐ݒ�
				SetTexture(MAX_BOSSTEXTURE_X, 0.0f, MAX_BOSSTEXTURE_Y, 3.0f);
				EnemyMove = D3DXVECTOR3(0.0f, -3.5f, 0.0f);
				//�ʒu�ݒ�
				SetMove(EnemyMove);
			}
			m_nAttackTime = BOSS_BULLET_TIME;
		}
		if (m_nBulletCnt == 5 && EnemyPos.y <= -400.0f)
		{
			EnemyPos = D3DXVECTOR3(640.0f, -200.0f, 0.0f);
			//�ʒu�̐ݒ�
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
					//����
					CExplosion::Create(D3DXVECTOR3(-100.0f + EnemyPos.x + 50.0f * nCnt, 700.0f, EnemyPos.z), D3DXVECTOR3(100.0f, 100.0f, 0.0f), D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
					m_Bossflag1 = false;
					m_nBossTime = 100;
					m_nAttackTime = 50;
					m_nAttackTime2 = 100;
					m_Bossflag4 = true;
				}
			}
			//*******************************************
			//	�{�X�̗̑͂�800�ȏゾ������
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
							//�e�N�X�`���̐ݒ�
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 2.0f);
						}
					}
				}
				if (m_nRand == 1 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					for (int nCnt = 0; nCnt < 10; nCnt++)
					{
						//�O���̐���
						CTrajectory::Create(D3DXVECTOR3(50.0f + 150.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_DOWN);
					}

					if (m_nLife >= 800)
					{
						//�e�N�X�`���̐ݒ�
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 2.0f);
					}
					if (m_nLife <= 800)
					{
						//�e�N�X�`���̐ݒ�
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					}

					m_nAttackTime--;
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 10; nCnt++)
						{
							//�e�̐���
							CBullet::Create(D3DXVECTOR3(50.0f + 150.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 20.0f, 0.0f), D3DXVECTOR3(10.0f, 10.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}

						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							if (m_nLife >= 800)
							{
								//�e�N�X�`���̐ݒ�
								SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 2.0f);
							}
							if (m_nLife < -800)
							{
								//�e�N�X�`���̐ݒ�
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
						//�e�N�X�`���̐ݒ�
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 2.0f);
					}
					if (m_nLife <= 800)
					{
						//�e�N�X�`���̐ݒ�
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					}

					if (EnemyPos.x - BOSS_SIZE_X / 2 <= 50.0f)
					{
						EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						SetMove(EnemyMove);
						if (m_nLife >= 800)
						{
							//�e�N�X�`���̐ݒ�
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 2.0f);
						}
						if (m_nLife <= 800)
						{
							//�e�N�X�`���̐ݒ�
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
						//�O���̐���
						CTrajectory::Create(D3DXVECTOR3(20.0f, 60.0f + 176.0f * nCnt, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LIGHT);
						//�O���̐���
						CTrajectory::Create(D3DXVECTOR3(1260.0f, 176.0f * nCnt, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LEFT);
					}

					if (m_nLife >= 800)
					{
						//�e�N�X�`���̐ݒ�
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 2.0f);
					}
					if (m_nLife <= 800)
					{
						//�e�N�X�`���̐ݒ�
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					}
					m_nAttackTime--;
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 6; nCnt++)
						{
							//�e�̐���
							CBullet::Create(D3DXVECTOR3(0.0f, 60.0f + 176.0f * nCnt, 0.0f), D3DXVECTOR3(20.0f, 0.0f, 0.0f), D3DXVECTOR3(10.0f, 10.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
							//�e�̐���
							CBullet::Create(D3DXVECTOR3(1280.0f, 176.0f * nCnt, 0.0f), D3DXVECTOR3(-20.0f, 0.0f, 0.0f), D3DXVECTOR3(10.0f, 10.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}
						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							if (m_nLife >= 800)
							{
								//�e�N�X�`���̐ݒ�
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
			//	�{�X�̗̑͂�800�ȉ��ɂȂ�����
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
							//�e�N�X�`���̐ݒ�
							SetTexture(MAX_BOSSTEXTURE_X, 2.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					}
				}
				if (m_nRand == 1 && m_Bossflag2 == false && m_nAttackTime2 <= 0)
				{
					for (int nCnt = 0; nCnt < 10; nCnt++)
					{
						//�O���̐���
						CTrajectory::Create(D3DXVECTOR3(50.0f + 150.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_DOWN);
					}
						//�e�N�X�`���̐ݒ�
						SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					m_nAttackTime--;
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 10; nCnt++)
						{
							//�e�̐���
							CBullet::Create(D3DXVECTOR3(50.0f + 150.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 20.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}

						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							if (m_nLife < -800)
							{
								//�e�N�X�`���̐ݒ�
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
					//�e�N�X�`���̐ݒ�
					SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					if (EnemyPos.x - BOSS_SIZE_X / 2 <= 50.0f)
					{
						EnemyMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						SetMove(EnemyMove);
						//�e�N�X�`���̐ݒ�
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
						//�O���̐���
						CTrajectory::Create(D3DXVECTOR3(20.0f, 60.0f + 176.0f * nCnt, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LIGHT);
						//�O���̐���
						CTrajectory::Create(D3DXVECTOR3(1260.0f, 176.0f * nCnt, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LEFT);
					}
					//�e�N�X�`���̐ݒ�
					SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					m_nAttackTime--;
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 6; nCnt++)
						{
							//�e�̐���
							CBullet::Create(D3DXVECTOR3(0.0f, 60.0f + 176.0f * nCnt, 0.0f), D3DXVECTOR3(20.0f, 0.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
							//�e�̐���
							CBullet::Create(D3DXVECTOR3(1280.0f, 176.0f * nCnt, 0.0f), D3DXVECTOR3(-20.0f, 0.0f, 0.0f), D3DXVECTOR3(20.0f, 20.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}
						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							//�e�N�X�`���̐ݒ�
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
					//�e�N�X�`���̐ݒ�
					SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					m_nAttackTime--;
					for (int nCnt = 0; nCnt < 10; nCnt++)
					{
						//�O���̐���
						CTrajectory::Create(D3DXVECTOR3(-200.0f + 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LIGHTDOWN);
					}
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 20; nCnt++)
						{
							//�e�̐���
							CBullet::Create(D3DXVECTOR3(-200.0f + 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(15.0f, 15.0f, 0.0f), D3DXVECTOR3(15.0f, 15.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}
						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							//�e�N�X�`���̐ݒ�
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
					//�e�N�X�`���̐ݒ�
					SetTexture(MAX_BOSSTEXTURE_X, 1.0f, MAX_BOSSTEXTURE_Y, 5.0f);
					m_nAttackTime--;
					for (int nCnt = 0; nCnt < 10; nCnt++)
					{
						//�O���̐���
						CTrajectory::Create(D3DXVECTOR3(1480.0f - 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 50.0f, 0.0f), CTrajectory::TRAJECTORY_LEFTDOWN);
					}
					if (m_nAttackTime <= 0)
					{
						m_AttackCount++;
						for (int nCnt = 0; nCnt < 20; nCnt++)
						{
							//�e�̐���
							CBullet::Create(D3DXVECTOR3(1480.0f - 200.0f * nCnt, 0.0f, 0.0f), D3DXVECTOR3(-12.5f, 12.5f, 0.0f), D3DXVECTOR3(15.0f, 15.0f, 0.0f), 50, 1, CBullet::BULLETTYPE_NOMAL);
						}
						if (m_AttackCount == 5)
						{
							m_Bossflag2 = true;
							m_nAttackTime2 = 100;
							m_nRand = 0;
							//�e�N�X�`���̐ݒ�
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
	//	�����ڋʂ̋���
	//*****************************************************
	if (m_nType == ENEMYTYPE_KYODAIMEDAMA)
	{
		//�����蔻��
		HitJudgment(EnemyPos);
		//�A�j���[�V�����J�E���^�[���C���N�������g
		m_nCounterAnimEnemy++;

		if (m_nCounterAnimEnemy % 15 == 0)
		{
			//�e�N�X�`���̐ݒ�
			SetTexture(3.0f, (float)m_nPatternAnimEnemy, 1.0f, 0.0f);

			//�A�j���[�V�����p�^�[���̃C���N������
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
		{// �ړ������̐��K��
			m_fRotMove -= D3DX_PI * 2;
		}
		else if (m_fRotMove <= -D3DX_PI)
		{// �ړ������̐��K��
			m_fRotMove += D3DX_PI * 2;
		}

		EnemyPos.x -= sinf(D3DX_PI * 0.5f) * 2.0f;
		EnemyPos.y += sinf(m_fRotMove) * 8.0f;

		//�ʒu�ݒ�
		SetMove(EnemyMove);

		//������E�Ƀ��[�v
		if (EnemyPos.x < -ENEMY_SIZE_X / 2 && m_nType == ENEMYTYPE_KYODAIMEDAMA)
		{
			EnemyPos.x = SCREEN_WIDTH + ENEMY_SIZE_X / 2;
			SetPosition(EnemyPos);
		}
	}

	//*****************************************************
	//	�_���̋���
	//*****************************************************
	if (m_nType == ENEMYTYPE_SOGEKI)
	{
		//�����蔻��
		HitJudgment(EnemyPos);
		m_nMoveTime--;
		if (m_nMoveTime <= 0)
		{
			m_nRand = rand() % 2 + 1;	//0�`9�̃����_���̐������o�������Ƃ���%10������	1�`6���o�������Ƃ���% 6 + 1�ɂȂ�
			m_flag = false;
		}
		if (m_nMoveTime <= 0)
		{
			m_nMoveTime = 100;
		}

		if (m_nRand == 1 && m_flag == false)
		{
			// �e�̏���������
			D3DXVECTOR3 PlayerPos;

			for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
			{
				//�I�u�W�F�N�g�̃|�C���^
				CObject *pObject;
				//�ǂ̃^�C�v���̏����|�C���^�ɑ��
				pObject = GetObjects(3, nCntType);

				//null�`�F�b�N
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

	//�ʒu�X�V
	EnemyPos.x += EnemyMove.x;
	EnemyPos.y += EnemyMove.y;
	EnemyPos.z += EnemyMove.z;

	//�ړ��ʌ���
	EnemyPos.x += (0.0f - EnemyMove.x) * 0.1f;
	EnemyPos.y += (0.0f - EnemyMove.y) * 0.1f;
	EnemyPos.z += (0.0f - EnemyMove.z) * 0.1f;

	//�ʒu�̐ݒ�
	SetPosition(EnemyPos);
	SetMove(EnemyMove);
}

//�G�̕`�揈��
void CEnemy::Draw()
{
	CObject2D::Draw();
}

//�G�̐���
CEnemy *CEnemy::Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move,D3DXVECTOR3 size, ENEMYTYPE nType,int nLife)
{
	CEnemy *pEnemy = nullptr;

	//�N���X�̐���
	pEnemy = new CEnemy;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pEnemy != nullptr)
	{
		//����������
		pEnemy->SetEnemyType(nType);
		pEnemy->Init();
		//�ݒ菈��
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

//�e�N�X�`���̓ǂݍ���
HRESULT CEnemy::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�ڋ�3.png",
		&m_pTextureEnemy[0]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�~�T�C��.png",
		&m_pTextureEnemy[1]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/UFO.png",
		&m_pTextureEnemy[2]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�퓬�@4.png",
		&m_pTextureEnemy[3]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/22199391.png",
		&m_pTextureEnemy[4]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�{�X���.jpg",
		&m_pTextureEnemy[5]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�_��1.png",
		&m_pTextureEnemy[6]);

	return S_OK;
}

//�e�N�X�`���̔j��
void CEnemy::Unload(void)
{
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_pTextureEnemy[nCnt] != NULL)
		{
			m_pTextureEnemy[nCnt]->Release();
			m_pTextureEnemy[nCnt] = NULL;
		}
	}
}

//�̗͂̐ݒ菈��
void CEnemy::SetLife(int nLife)
{
	m_nLife = nLife;
}

//�G�̃^�C�v�̐ݒ�
void CEnemy::SetEnemyType(ENEMYTYPE type)
{
	m_nType = type;
}

//�����蔻��
void CEnemy::HitJudgment(D3DXVECTOR3 pos)
{
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
			// �G�ƃv���C���[�̓����蔻��
			//**********************************************************
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//�G�̈ʒu
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				//�G�̃T�C�Y
				D3DXVECTOR3 PlayerSize = pObject->GetSize();
				//�G�̗̑�
				int nLife = pObject->GetLife();

				//�G�̓����蔻��
				if (pos.x + ENEMY_SIZE_X >= PlayerPos.x - PlayerSize.x
					&&pos.x - ENEMY_SIZE_X <= PlayerPos.x + PlayerSize.x
					&&pos.y + ENEMY_SIZE_Y >= PlayerPos.y - PlayerSize.y
					&&pos.y - ENEMY_SIZE_Y <= PlayerPos.y + PlayerSize.y)
				{
					//�G�̗̑͂����炷
					nLife = 0;
					//�̗͂̕ۑ�
					pObject->SetLife(nLife);
					//�̗͂�0�ɂȂ�����
					if (nLife == 0)
					{
						//����
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

//�{�X�̓����蔻��
void CEnemy::HitBossJudgment(D3DXVECTOR3 pos)
{
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
			// �G�ƃv���C���[�̓����蔻��
			//**********************************************************
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//�G�̈ʒu
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				//�G�̃T�C�Y
				D3DXVECTOR3 PlayerSize = pObject->GetSize();
				//�G�̗̑�
				int nLife = pObject->GetLife();

				//�G�̓����蔻��
				if (pos.x + BOSS_SIZE_X - 50.0f>= PlayerPos.x - PlayerSize.x
					&&pos.x - BOSS_SIZE_X + 50.0f <= PlayerPos.x + PlayerSize.x
					&&pos.y + BOSS_SIZE_Y - 50.0f >= PlayerPos.y - PlayerSize.y
					&&pos.y - BOSS_SIZE_Y + 50.0f <= PlayerPos.y + PlayerSize.y)
				{
					//�G�̗̑͂����炷
					nLife = 0;
					//�̗͂̕ۑ�
					pObject->SetLife(nLife);
					//�̗͂�0�ɂȂ�����
					if (nLife == 0)
					{
						//����
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

