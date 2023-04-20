//=============================================================================
//
// ��Q������ [obstacle.cpp]
// Author : saito shian
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include <time.h>
#include "random_door.h"
#include "player.h"
#include "input.h"
#include "application.h"
#include "renderer.h"
#include "game.h"
#include "fade.h"
#include "model.h"
#include "billboard.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CRandomDoor::CRandomDoor(int nPriority)
{
	m_DoorNumber = 1;
	m_RandNumber = 0;
	m_RandFlag = false;
	m_RandNumberFlag = false;

	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_GIMMICK);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CRandomDoor::~CRandomDoor()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CRandomDoor::Init()
{
	// �M�~�b�N�̏�����
	CGimmick::Init();

	//����
	srand((unsigned int)time(NULL));	//�N�����Ɉ�񂾂��s�����ߏ������ɏ���

	//���f���̃��[�h
	LoadModel("BOX");

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CRandomDoor::Uninit()
{
	CGimmick::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CRandomDoor::Update()
{
	// �M�~�b�N�̍��W,�ړ��ʎ擾
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 move = GetMove();

	D3DXVECTOR3 PlayerPos1P = CGame::GetPlayer1P()->GetPos();		//�v���C���[POS���̎擾
	//yD3DXVECTOR3 PlayerPos2P = CGame::GetPlayer2P()->GetPos();		//�v���C���[POS���̎擾

	// �����蔻��̃`�F�b�N
	CollisionGimmick(CGame::GetPlayer1P());
	CollisionGimmick(CGame::GetPlayer2P());

	if (GetHitPlayer() == nullptr)
	{
		return;
	}

	// �M�~�b�N����
	ConstOperate();

	CPlayer* hitPlayer = GetHitPlayer();

	if (CollisionGimmick(CGame::GetPlayer1P()) == true)
	{
		if (m_RandNumberFlag == false)
		{// �܂��ԍ������܂��Ă��Ȃ��Ƃ��Ɏ��s
			m_RandNumber = rand() % 9 + 1;
			// �ԍ������܂���
			m_RandNumberFlag = true;
		}
		if (m_RandNumber == 1 || m_RandNumber == 2 && m_RandNumberFlag == true)
		{
			if (m_RandNumber == m_DoorNumber)
			{
				m_RandFlag = true;
			}
		}
		else
		{
			m_RandFlag = false;
		}

		if (m_RandFlag == true)
		{
			PlayerPos1P = D3DXVECTOR3(-700.0f,0.0f,2100.0f);
		}
		else
		{
			PlayerPos1P = D3DXVECTOR3(-700.0f, 0.0f, 1800.0f);
		}
	}

	CGame::GetPlayer1P()->SetPos(PlayerPos1P);
	// �M�~�b�N�̍X�V
	CGimmick::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CRandomDoor::Draw()
{
	CGimmick::Draw();
}

//=============================================================================
// ��������
//=============================================================================
void CRandomDoor::ConstOperate()
{
	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::GetInput();

	if (GetHitPlayer() == nullptr)
	{
		return;
	}

	/* ���v���C���[�ƐڐG���ĂȂ��� */

	if (GetCompletion())
	{
		return;
	}
}

//=============================================================================
// ���쏈��
//=============================================================================
CRandomDoor* CRandomDoor::Create(const D3DXVECTOR3& pos)
{
	CRandomDoor *pObstacle = new CRandomDoor();

	if (pObstacle != nullptr)
	{
		pObstacle->SetGimmickType(GIMMICKTYPE_BARRAGEMOVEWALL);
		pObstacle->Init();
		pObstacle->SetPos(pos);
	}
	else
	{
		assert(false);
	}

	return pObstacle;
}
