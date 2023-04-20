//=============================================================================
//
// �{�^���������ƃv���C���[���i�ރM�~�b�N
// Author : saito shian
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include <time.h>
#include "button_move_player.h"
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
CButtonMovePlayer::CButtonMovePlayer(int nPriority)
{
	m_MoveCount = MAX_WALK_COUNT;
	m_TimeToMove = 0;
	m_RandNumber = 0;
	m_MoveFlag = false;
	m_RandFlag = false;

	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_GIMMICK);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CButtonMovePlayer::~CButtonMovePlayer()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CButtonMovePlayer::Init()
{
	// �M�~�b�N�̏�����
	CGimmick::Init();

	//����
	srand((unsigned int)time(NULL));	//�N�����Ɉ�񂾂��s�����ߏ������ɏ���

	//���f���̃��[�h
	LoadModel("TABLE04");

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CButtonMovePlayer::Uninit()
{
	CGimmick::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CButtonMovePlayer::Update()
{
	// �M�~�b�N�̍X�V
	CGimmick::Update();

	// �M�~�b�N�̍��W,�ړ��ʎ擾
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 move = GetMove();

	// �����蔻��̃`�F�b�N
	bool bCollision1P = Collision(CGame::GetPlayer1P());
	bool bCollision2P = Collision(CGame::GetPlayer2P());

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
		hitPlayer->SetSpeed(0.0f);
		ButtonPush();
	}
	else
	{
		hitPlayer->SetSpeed(5.0f);
		Uninit();
		return;
	}

	// �ړ��ʌ���
	pos.x += (0.0f - move.x) * 0.1f;
	pos.y += (0.0f - move.y) * 0.1f;
	pos.z += (0.0f - move.z) * 0.1f;

	SetPos(pos);	// ���W�̐ݒ�
	SetMove(move);	// �ړ��ʂ̐ݒ�
}

//=============================================================================
// �`�揈��
//=============================================================================
void CButtonMovePlayer::Draw()
{
	CGimmick::Draw();
}

//=============================================================================
// ���쏈��
//=============================================================================
void CButtonMovePlayer::ConstOperate()
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
// �L�[����������
//=============================================================================
void CButtonMovePlayer::ButtonPush()
{
	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::GetInput();

	// �v���C���[���ڐG�������̃|�C���^
	CPlayer* hitPlayer = GetHitPlayer();

	// �����_���ŉ����L�[�����܂�
	if (m_RandFlag == false)
	{
		m_RandNumber = rand() % 4 + 1;
		m_RandFlag = true;
	}
	else if (m_RandFlag == true && m_RandNumber == 1)
	{
		if (pInputKeyboard->Trigger(KEY_RIGHT_BUTTON))
		{
			m_RandFlag = false;
		}
	}
	else if (m_RandFlag == true && m_RandNumber == 2)
	{
		if (pInputKeyboard->Trigger(KEY_LEFT_BUTTON))
		{
			m_RandFlag = false;
		}
	}
	else if (m_RandFlag == true && m_RandNumber == 3)
	{
		if (pInputKeyboard->Trigger(KEY_DOWN_BUTTON))
		{
			m_RandFlag = false;
		}
	}
	else if (m_RandFlag == true && m_RandNumber == 4)
	{
		if (pInputKeyboard->Trigger(KEY_UP_BUTTON))
		{
			m_RandFlag = false;
		}
	}

	if (m_RandFlag == false && m_MoveFlag == false)
	{// �����_���Ō��܂����L�[���������Ƃ� && �v���C���[���~�܂�Ȃ��Ƃ����Ȃ��Ƃ����s
		m_MoveFlag = true;	
	}
	if (m_MoveFlag == true)
	{// �v���C���[��������悤�ɂȂ�Ƃ����s
		hitPlayer->SetMove(D3DXVECTOR3(0.0f, 0.0f, 2.0f));
		m_MoveCount--;
		if (m_MoveCount <= 0)
		{// �J�E���g��0�ȉ��ɂȂ�������s
			hitPlayer->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			// �ϐ���������
			m_MoveCount = MAX_WALK_COUNT;
			m_MoveFlag = false;
		}
	}
}

//=============================================================================
// ��������
//=============================================================================
CButtonMovePlayer* CButtonMovePlayer::Create(const D3DXVECTOR3& pos)
{
	CButtonMovePlayer *pObstacle = new CButtonMovePlayer();

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
