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
#include "stop_gimmick.h"
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
CStopGimmick::CStopGimmick(int nPriority)
{
	m_StopCount = 100;
	m_StopFlag = false;

	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_GIMMICK);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CStopGimmick::~CStopGimmick()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CStopGimmick::Init()
{
	// �M�~�b�N�̏�����
	CGimmick::Init();

	//���f���̃��[�h
	LoadModel("BOX");

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CStopGimmick::Uninit()
{
	CGimmick::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CStopGimmick::Update()
{
	// �M�~�b�N�̍��W,�ړ��ʎ擾
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 move = GetMove();

	// �����蔻��̃`�F�b�N
	CollisionGimmick(CGame::GetPlayer1P());
	//CollisionGimmick(CGame::GetPlayer2P());

	if (GetHitPlayer() == nullptr)
	{
		return;
	}

	// �M�~�b�N����
	ConstOperate();

	CPlayer* hitPlayer = GetHitPlayer();

	if (CollisionGimmick(CGame::GetPlayer1P()) == true)
	{
		hitPlayer->SetSpeed(0.0f);
		m_StopCount--;
		if (m_StopCount <= 0)
		{
			hitPlayer->SetSpeed(5.0f);
			m_StopCount = 100;
		}
	}
	else
	{
		hitPlayer->SetSpeed(5.0f);
		m_StopCount = 100;
	}

	// �ʒu�X�V
	pos += move;

	// �ړ��ʌ���
	pos.x += (0.0f - move.x) * 0.1f;
	pos.y += (0.0f - move.y) * 0.1f;
	pos.z += (0.0f - move.z) * 0.1f;

	SetPos(pos);	// ���W�̐ݒ�
	SetMove(move);	// �ړ��ʂ̐ݒ�

					// �M�~�b�N�̍X�V
	CGimmick::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CStopGimmick::Draw()
{
	CGimmick::Draw();
}

//=============================================================================
// ��������
//=============================================================================
void CStopGimmick::ConstOperate()
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
CStopGimmick* CStopGimmick::Create(const D3DXVECTOR3& pos)
{
	CStopGimmick *pObstacle = new CStopGimmick();

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
