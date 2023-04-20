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
#include "barrage_move_wall.h"
#include "player.h"
#include "input.h"
#include "application.h"
#include "renderer.h"
#include "game.h"
#include "fade.h"
#include "model.h"
#include "billboard.h"
#include "icon.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CBarrageMoveWall::CBarrageMoveWall(int nPriority)
{
	m_PosOld = {};
	m_nTriggerCount = 0;
	m_Completion = false;

	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_GIMMICK);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CBarrageMoveWall::~CBarrageMoveWall()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CBarrageMoveWall::Init()
{
	// �M�~�b�N�̏�����
	CGimmick::Init();

	m_PosOld = CObjectX::GetPos();

	//���f���̃��[�h
	LoadModel("BOOK04");
	SetRot(D3DXVECTOR3(D3DX_PI * 0.5f, 0.0f, 0.0f));
	SetPos(GetPos() + D3DXVECTOR3(0.0f, GetMaxVtx().z, 0.0f));

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CBarrageMoveWall::Uninit()
{
	CGimmick::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CBarrageMoveWall::Update()
{
	if (GetCompletion())
	{
		/* ��Gimmick�N���A���Ă��遫 */

		// �M�~�b�N�̍��W,�ړ��ʎ擾
		D3DXVECTOR3 pos = GetPos();
		D3DXVECTOR3 move = GetMove();

		move = D3DXVECTOR3(0.0f, 2.5f, 0.0f);

		// �ʒu�X�V
		pos += move;

		// �ړ��ʌ���
		pos.x += (0.0f - move.x) * 0.1f;
		pos.y += (0.0f - move.y) * 0.1f;
		pos.z += (0.0f - move.z) * 0.1f;

		SetPos(pos);	// ���W�̐ݒ�
		SetMove(move);	// �ړ��ʂ̐ݒ�
	}
	else
	{
		/* ��Gimmick�N���A���Ă��Ȃ��� */

		// �����蔻��̃`�F�b�N
		Collision(CGame::GetPlayer1P());
		Collision(CGame::GetPlayer2P());

		if (GetHitPlayer() == nullptr)
		{
			return;
		}

		// �M�~�b�N����
		ConstOperate();

		CPlayer* hitPlayer = GetHitPlayer();

		hitPlayer->SetSpeed(0.0f);
		if (GetCompletion())
		{// ���삪�����������Ɏ��s
		 // �v���C���[�̃X�s�[�h�����ɖ߂�
			hitPlayer->SetSpeed(5.0f);
		}

		// �M�~�b�N�̍X�V
		CGimmick::Update();
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CBarrageMoveWall::Draw()
{
	CGimmick::Draw();
}

//=============================================================================
// ��������
//=============================================================================
void CBarrageMoveWall::ConstOperate()
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

	if (m_pIcon[0] == nullptr)
	{
		m_pIcon[0] = CIcon::Create(GetHitPlayer()->GetPos() + D3DXVECTOR3(0.0f, 130.0f, 0.0f), D3DXVECTOR3(30.0f, 30.0f, 0.0f), "SPEECH_BUBBLE", PRIORITY_LEVEL3);
		m_pIcon[0]->SetScaling(true, true);
		m_pIcon[0]->SetAnimation(1, 1, 12, 1, true);
	}

	if (GetHitPlayer()->GetKeyIndex() == -1)
	{
		if (m_pIcon[1] == nullptr)
		{
			m_pIcon[1] = CIcon::Create(GetHitPlayer()->GetPos() + D3DXVECTOR3(0.0f, 130.0f, 0.0f), D3DXVECTOR3(12.0f, 12.0f, 0.0f), "BUTTON_ENTER", PRIORITY_LEVEL3);
			m_pIcon[1]->SetAnimation(2, 1, 12, 1, true);
		}
	}
	else
	{
		if (m_pIcon[1] == nullptr)
		{
			m_pIcon[1] = CIcon::Create(GetHitPlayer()->GetPos() + D3DXVECTOR3(0.0f, 130.0f, 0.0f), D3DXVECTOR3(12.0f, 12.0f, 0.0f), "BUTTON_B", PRIORITY_LEVEL3);
			m_pIcon[1]->SetAnimation(2, 1, 12, 1, true);
		}
	}

	/* �����삪�������Ă��Ȃ��� */

	if (pInputKeyboard->Trigger(KEY_DECISION))
	{// SPACE�L�[����������J�E���g�𑝂₷
		m_nTriggerCount++;
		if (m_nTriggerCount >= 20)
		{// �J�E���g��20��ȏ�s��������s
		 // �M�~�b�N(��)����Ɉړ�
			m_pIcon[0]->Uninit();
			m_pIcon[1]->Uninit();
			// ���삪��������
			SetCompletion(true);
		}
	}
}

//=============================================================================
// �L�[���J�E���g����֐�
//=============================================================================
void CBarrageMoveWall::KeyCount()
{
	m_nTriggerCount++;
}

//=============================================================================
// ���쏈��
//=============================================================================
CBarrageMoveWall* CBarrageMoveWall::Create(const D3DXVECTOR3& pos)
{
	CBarrageMoveWall *pObstacle = new CBarrageMoveWall();

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
