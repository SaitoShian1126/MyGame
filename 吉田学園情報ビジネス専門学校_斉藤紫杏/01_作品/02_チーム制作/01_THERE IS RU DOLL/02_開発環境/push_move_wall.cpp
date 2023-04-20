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
#include "push_move_wall.h"
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
CPushMoveWall::CPushMoveWall(int nPriority)
{
	m_PosOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nTriggerCount = 0;
	m_Completion = false;
	m_bIsLanding = false;
	m_bIsLandingUp = false;

	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_GIMMICK);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPushMoveWall::~CPushMoveWall()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPushMoveWall::Init()
{
	// �M�~�b�N�̏�����
	CGimmick::Init();

	m_PosOld = CObjectX::GetPos();

	//���f���̃��[�h
	LoadModel("SMALL BOTTLE");

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CPushMoveWall::Uninit()
{
	CGimmick::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CPushMoveWall::Update()
{
	// �M�~�b�N�̍X�V
	CGimmick::Update();

	// �M�~�b�N�̍��W,�ړ��ʎ擾
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 move = GetMove();

	// �d�͐ݒ�
	move.y -= 2.5f;

	// �O��̈ʒu��ۑ�
	m_PosOld = pos;

	// �|�C���^�錾
	CObject *pObject = CObject::GetTop(PRIORITY_LEVEL3);

	// �ʒu�X�V
	pos += move;

	// �M�~�b�N(���f��)�ƃ��f���̓����蔻��
	while (pObject != nullptr)
	{
		if (pObject == this)
		{
			pObject = pObject->GetNext();
			continue;
		}

		/* ��Gimmick�N���A���Ă��Ȃ��� */
		CObject::EObjType objType;

		// �����蔻��̃`�F�b�N
		objType = pObject->GetObjType();

		if (objType == OBJTYPE_MODEL)
		{
			CObjectX *pObjectX = (CObjectX*)pObject;
			m_bIsLanding = pObjectX->Collision(&pos, &m_PosOld, &GetSize());
			m_bIsLandingUp = pObjectX->UpCollision(&pos, &m_PosOld, &GetSize(), &move);
		}

		// �M�~�b�N����
		pObject = pObject->GetNext();
	}

	// �����蔻��̃`�F�b�N
	bool bCollision1P = CollisionGimmick(CGame::GetPlayer1P());
	bool bCollision2P = CollisionGimmick(CGame::GetPlayer2P());

	if (GetHitPlayer() == nullptr)
	{
		return;
	}

	// �M�~�b�N����
	ConstOperate();

	// �v���C���[���ڐG�������̃|�C���^
	CPlayer* hitPlayer = GetHitPlayer();

	// �M�~�b�N�ƃv���C���[���ڐG������
	if (bCollision1P || bCollision2P)
	{
		GetHitPlayer()->SetMotionType(CPlayer::MOTION_PUSH);
		// �ʒu�X�V
		hitPlayer->SetSpeed(1.5f);
		move = D3DXVECTOR3(0.0f, 0.0f, 1.5f);
	}
	// �M�~�b�N�ƃv���C���[�����ꂽ��
	else
	{
		GetHitPlayer()->SetMotionType(CPlayer::MOTION_NONE);
		// �v���C���[�̃X�s�[�h��5.0f�A�M�~�b�N�̃X�s�[�h��0.0f�ɖ߂�
		hitPlayer->SetSpeed(5.0f);
		move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		SetHitPlayer(nullptr);
	}

	// �M�~�b�N�����ɗ�������
	if (pos.y <= -100.0f)
	{
		// �ړ��ʌ���
		hitPlayer->SetSpeed(5.0f);
		// �M�~�b�N�폜
		Uninit();
		return;
	}

	// �ړ��ʌ���
	pos.x += move.x;
	pos.y += move.y;
	pos.z += move.z;

	SetPos(pos);	// ���W�̐ݒ�
	SetMove(move);	// �ړ��ʂ̐ݒ�
}

//=============================================================================
// �`�揈��
//=============================================================================
void CPushMoveWall::Draw()
{
	CGimmick::Draw();
}

//=============================================================================
// ���쏈��
//=============================================================================
void CPushMoveWall::ConstOperate()
{
	if (GetHitPlayer())
	{
		return;
	}

	/* ���v���C���[�ƐڐG������ */

	if (GetCompletion())
	{
		return;
	}
}

//=============================================================================
// ��������
//=============================================================================
CPushMoveWall* CPushMoveWall::Create(const D3DXVECTOR3& pos)
{
	CPushMoveWall *pObstacle = new CPushMoveWall();

	if (pObstacle != nullptr)
	{
		pObstacle->SetGimmickType(GIMMICKTYPE_PUSHMOVEWALL);
		pObstacle->Init();
		pObstacle->SetPos(pos);
	}
	else
	{
		assert(false);
	}

	return pObstacle;
}
