//********************************************
//
//	game.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
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

//�ÓI�����o�ϐ��錾
CScore *CGame::m_pScore = nullptr;

//�����̃R���X�g���N�^
CGame::CGame()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	EnemyMoveTime = 150;
	nCntdeath = 0;
	m_CountTime = 0;
}

//�����̃f�X�g���N�^
CGame::~CGame()
{
	//���������Ȃ�
}

//�����̏���������
HRESULT CGame::Init(void)
{
	//����
	srand((unsigned int)time(NULL));	//�N�����Ɉ�񂾂��s�����ߏ������ɏ���	

	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_flag = false;
	m_flag2 = false;
	m_flag3 = false;
	nCntdeath = 0;
	m_CountTime = 550;

	//**********************************************
	//	�e�N�X�`���ǂݍ���
	//**********************************************
	//�T�E���h�̍Đ�
	PlaySound(SOUND_LABEL_SOUND0);
	//�v���C���[�̃e�N�X�`���ǂݍ���
	CPlayer::Load();
	//�G�̃e�N�X�`���ǂݍ���
	CEnemy::Load();
	//�e�̃e�N�X�`���ǂݍ���
	CBullet::Load();
	//�����̃e�N�X�`���ǂݍ���
	CExplosion::Load();
	//�G�t�F�N�g�̃e�N�X�`���ǂݍ���
	CEffect::Load();
	//�p�[�e�B�N���̃e�N�X�`���ǂݍ���
	CParticle::Load();
	//�X�|�[���̃e�N�X�`���ǂݍ���
	CSpawn::Load();
	//�w�i�̃e�N�X�`���ǂݍ���
	CBg::Load();
	//�����̃e�N�X�`���ǂݍ���
	CNumber::Load();
	//�A�C�e���̃e�N�X�`���ǂݍ���
	CItem::Load();
	//�A�C�e���X�|�i�[�̃e�N�X�`���ǂݍ���
	CSponer::Load();
	//�U���̃e�N�X�`���ǂݍ���
	CAttack::Load();
	//�U��2�̃e�N�X�`���ǂݍ���
	CAttack2::Load();
	//�O���̃e�N�X�`���ǂݍ���
	CTrajectory::Load();
	//�V�[���̃e�N�X�`���ǂݍ���
	CScene::Load();
	//UI�̃e�N�X�`���ǂݍ���
	CUi::Load();

	//**********************************************
	//	�I�u�W�F�N�g�̐���
	//**********************************************
	//�w�i�̐���
	CBg::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1280.0f, 720.0f, 0.0f));
	//UI�̐���
	CUi::Create(D3DXVECTOR3(450.0f, 40.0f, 0.0f), D3DXVECTOR3(35.0f, 35.0f,0.0f),CUi::UITYPE_BULLET);
	//�v���C���[�̗̑͐���
	CHp::Create();
	//�X�R�A�̐���
	m_pScore = CScore::Create();
	//�A�C�e���X�|�i�[�̐���
	CSponer::Create(D3DXVECTOR3(640.0f, -50.0f, 0.0f), D3DXVECTOR3(100.0f, 100.0f, 0.0f));
	//�X�|�[���̐���
	CSpawn::Create(D3DXVECTOR3(200.0f, 360.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(150.0f, 150.0f, 0.0f), CSpawn::SPAWNTYPE_MAGICCIRCLE1, 100);
	//�v���C���[����
	CPlayer::Create(10);
	//�V�[������
	CScene::Create(D3DXVECTOR3(640.0f, 1080.0f, 0.0f), D3DXVECTOR3(640.0f, 360.0f, 0.0f), CScene::SCENETYPE_START);

	return S_OK;
}

//�����̏I������
void CGame::Uninit(void)
{
	//**********************************************
	//	�e�N�X�`���j��
	//**********************************************
	//�v���C���[�̃e�N�X�`���j��
	CPlayer::Unload();
	//�G�̃e�N�X�`���j��
	CEnemy::Unload();
	//�e�̃e�N�X�`���j��
	CBullet::Unload();
	//�����̃e�N�X�`���j��
	CExplosion::Unload();
	//�G�t�F�N�g�̃e�N�X�`���j��
	CEffect::Unload();
	//�p�[�e�B�N���̃e�N�X�`���j��
	CParticle::Unload();
	//�X�|�[���̃e�N�X�`���j��
	CSpawn::Unload();
	//�w�i�̃e�N�X�`���j��
	CBg::Unload();
	//�����̃e�N�X�`���j��
	CNumber::Unload();
	//�A�C�e���̃e�N�X�`���j��
	CItem::Unload();
	//�A�C�e���X�|�i�[�̃e�N�X�`���j��
	CSponer::Unload();
	//�U���̃e�N�X�`���j��
	CAttack::Unload();
	//�U��2�̃e�N�X�`���j��
	CAttack2::Unload();
	//�O���̃e�N�X�`���j��
	CTrajectory::Unload();
	//�V�[���̃e�N�X�`���j��
	CScene::Unload();
	//UI�̃e�N�X�`���j��
	CUi::Unload();

	CObject::Release();
}

//�����̍X�V����
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
	//	BGM�؂�ւ�
	//*********************************************
	if (nCntdeath == 27 && m_flag2 == false)
	{
		//�T�E���h�̒�~
		StopSound();
		m_flag = true;
		m_flag2 = true;
	}
	if (m_flag == true && m_flag2 == true)
	{
		//�T�E���h�̍Đ�
		PlaySound(SOUND_LABEL_SOUND5);
		m_flag3 = true;
	}
	if (m_flag3 == true)
	{
		m_CountTime--;
		if (m_CountTime <= 0)
		{
			//�T�E���h�̍Đ�
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

//�����̕`�揈��
void CGame::Draw()
{

}

//�����̐���
CGame *CGame::Create()
{
	CGame *pgame = nullptr;

	//�N���X�̐���
	pgame = new CGame;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pgame != nullptr)
	{
		//����������
		pgame->Init();
	}
	else
	{
		assert(false);
	}

	return pgame;
}