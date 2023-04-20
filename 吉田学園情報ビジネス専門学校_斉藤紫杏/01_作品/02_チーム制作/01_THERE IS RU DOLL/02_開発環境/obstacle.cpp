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
#include "obstacle.h"
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
CObstacle::CObstacle(int nPriority)
{
	m_PosOld = {};
	m_nTriggerCount1 = 0;
	m_nTriggerCount2 = 0;
	m_ArrowRand = 0;
	m_AreaFlag1P = false;
	m_AreaFlag2P = false;
	m_ArrowRandFlag = false;
	m_nAlternateFlag = false;
	PlayerGoalFlag = false;
	m_bIsLanding = false;
	m_bIsLandingUp = false;
	m_Completion = false;
	m_StopObstacle = false;

	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_GIMMICK);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CObstacle::~CObstacle()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CObstacle::Init()
{
	// �M�~�b�N�̏�����
	CGimmick::Init();

	//����
	srand((unsigned int)time(NULL));	//�N�����Ɉ�񂾂��s�����ߏ������ɏ���

	m_PosOld = CObjectX::GetPos();

	//���f���̃��[�h
	LoadModel("BOX");

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CObstacle::Uninit()
{
	CGimmick::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CObstacle::Update()
{
	//// �v���C���[���̎擾
	//CPlayer * pPlayer1P = CGame::GetPlayer1P();
	//CPlayer * pPlayer2P = CGame::GetPlayer2P();

	//// �M�~�b�N���̎擾
	//CObstacle * pObstacle1P = CGame::GetObstacle1P();
	//CObstacle * pObstacle2P = CGame::GetObstacle2P();

	//// �M�~�b�N1P�̍��W,�ړ��ʎ擾
	//D3DXVECTOR3 pos1P = pObstacle1P->GetPos();
	//D3DXVECTOR3 move1P = pObstacle1P->GetMove();

	//// �M�~�b�N2P�̍��W,�ړ��ʎ擾
	//D3DXVECTOR3 pos2P = pObstacle2P->GetPos();
	//D3DXVECTOR3 move2P = pObstacle2P->GetMove();

	//// �v���C���[�̍��W�擾
	//D3DXVECTOR3 PlayerPos1 = CGame::GetPlayer1P()->GetPos();
	//D3DXVECTOR3 PlayerPos2 = CGame::GetPlayer2P()->GetPos();

	//// �A�łœ����ǂ̏����֐��Ăяo��
	//bool bFlag1P = pObstacle1P->BarrageMoveWall(pObstacle1P, pos1P, PlayerPos1);
	//bool bFlag2P = pObstacle2P->BarrageMoveWall(pObstacle2P, pos2P, PlayerPos2);

	//// �������瓮���ǂ̏����֐��Ăяo��
	///*bFlag1P = pObstacle1P->PushMoveObject(pObstacle1P, pos1P, PlayerPos1);
	//bFlag2P = pObstacle2P->PushMoveObject(pObstacle2P, pos2P, PlayerPos2);*/

	//if (bFlag1P)
	//{
	//	move1P = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//	if (pObstacle1P->GetStopFlag())
	//	{
	//		move1P = D3DXVECTOR3(0.0f, 2.5f, 0.0f);
	//	}
	//}
	//else
	//{
	//	pPlayer1P->SetSpeed(0.0f);
	//}

	//if (bFlag2P)
	//{
	//	move2P = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//	if (pObstacle2P->GetStopFlag())
	//	{
	//		move2P = D3DXVECTOR3(0.0f, 2.5f, 0.0f);
	//	}
	//}
	//else
	//{
	//	pPlayer2P->SetSpeed(0.0f);
	//}

	//if (pObstacle1P->GetCompletion() == true)
	//{// ���삪�����������Ɏ��s
	//	// �v���C���[�̃X�s�[�h�����ɖ߂�
	//	CGame::GetPlayer1P()->SetSpeed(5.0f);
	//}
	//if (pObstacle2P->GetCompletion() == true)
	//{// ���삪�����������Ɏ��s
	// // �v���C���[�̃X�s�[�h�����ɖ߂�
	//	CGame::GetPlayer2P()->SetSpeed(5.0f);
	//}

	//// �ʒu�X�V
	//pos1P += move1P;
	//pos2P += move2P;

	//// �ړ��ʌ���
	//pos1P.x += (0.0f - move1P.x) * 0.1f;
	//pos1P.y += (0.0f - move1P.y) * 0.1f;
	//pos1P.z += (0.0f - move1P.z) * 0.1f;

	//pos2P.x += (0.0f - move2P.x) * 0.1f;
	//pos2P.y += (0.0f - move2P.y) * 0.1f;
	//pos2P.z += (0.0f - move2P.z) * 0.1f;

	//// ���W�̐ݒ�
	//pObstacle1P->SetPos(pos1P);
	//pObstacle2P->SetPos(pos2P);

	//// �ړ��ʂ̐ݒ�
	//pObstacle1P->SetMove(move1P);
	//pObstacle2P->SetMove(move2P);

	//// �M�~�b�N�̍X�V
	//CGimmick::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CObstacle::Draw()
{
	CGimmick::Draw();
}

//=============================================================================
// ��������
//=============================================================================
void CObstacle::ConstOperate()
{
}

//=============================================================================
// �L�[���J�E���g����֐�
//=============================================================================
void CObstacle::KeyCount()
{
	m_nTriggerCount1++;
}

//=============================================================================
// ���쏈��
//=============================================================================
CObstacle * CObstacle::Create(const D3DXVECTOR3 pos, GIMMICKTYPE gimmicktype,int nPriority)
{
	CObstacle *pObstacle = new CObstacle(nPriority);
	if (pObstacle != nullptr)
	{
		pObstacle->SetGimmickType(gimmicktype);
		pObstacle->Init();
		pObstacle->SetPos(pos);
	}
	else
	{
		assert(false);
	}

	return pObstacle;
}

////=============================================================================
//// �A�łœ����ǂ̏���
////=============================================================================
//D3DXVECTOR3 CObstacle::BarrageMoveWall(D3DXVECTOR3 ObstaclePos, D3DXVECTOR3 P1Pos, D3DXVECTOR3 P2Pos, D3DXVECTOR3 ObstacleMove, D3DXVECTOR3 ObstacleMove2P)
//{
//	// �L�[�{�[�h�̏��擾
//	CInput *pInputKeyboard = CApplication::GetInput();
//
//	if (CGimmick::GetCompletion() == false)
//	{// ������������Ă��Ȃ������s
//		if (CGame::GetPlayer1P()->GetPlayerType() == CPlayer::EPLAYER_1P
//			&&ObstaclePos.x + 150.0f >= P1Pos.x && ObstaclePos.z + 150.0f >= P1Pos.z
//			&&ObstaclePos.x - 150.0f <= P1Pos.x && ObstaclePos.z - 150.0f <= P1Pos.z)
//		{// �v���C���[�^�C�v��1P�������� && �M�~�b�N�͈͓̔��ɂ�����
//			//�v���C���[1�𓮂����Ȃ��悤�ɂ���
//			CGame::GetPlayer1P()->SetSpeed(0.0f);
//		}
//		if (CGimmick::GetGimmickType() == GIMMICKTYPE_BARRAGEMOVEWALL)
//		{// �M�~�b�N�̃^�C�v���A�łœ����ǂ����������s
//			if (CGame::GetPlayer1P()->GetPlayerType() == CPlayer::EPLAYER_1P
//				&&pInputKeyboard->Trigger(DIK_SPACE))
//			{// �v���C���[�^�C�v��1P�������� && SPACE�L�[����������
//				//�L�[���������ƂɃJ�E���g�������Ă���
//				m_nTriggerCount1++;
//				if (m_nTriggerCount1 >= 20)
//				{// �J�E���g��20��ȏ�s��������s
//					 // �M�~�b�N(��)����Ɉړ�
// 					ObstacleMove = D3DXVECTOR3(0.0f, 2.5f,0.0f);
//					// ���삪��������
//					CGimmick::SetCompletion(true);
//				}
//			}
//		}
//	}
//
//	if (CGimmick::GetCompletion() == false)
//	{// ������������Ă��Ȃ������s
//		if (CGame::GetPlayer2P()->GetPlayerType() == CPlayer::EPLAYER_2P
//			&&ObstaclePos.x + 150.0f >= P2Pos.x && ObstaclePos.z + 150.0f >= P2Pos.z
//			&&ObstaclePos.x - 150.0f <= P2Pos.x && ObstaclePos.z - 150.0f <= P2Pos.z)
//		{// �v���C���[�^�C�v��2P�������� && �M�~�b�N�͈͓̔��ɂ�����
//		 //�v���C���[2�𓮂����Ȃ��悤�ɂ���
//			CGame::GetPlayer2P()->SetSpeed(0.0f);
//		}
//		if (CGimmick::GetGimmickType() == GIMMICKTYPE_BARRAGEMOVEWALL)
//		{// �M�~�b�N�̃^�C�v���A�łœ����ǂ����������s
//			if (CGame::GetPlayer2P()->GetPlayerType() == CPlayer::EPLAYER_2P
//				&&pInputKeyboard->Trigger(DIK_LSHIFT))
//			{// �v���C���[�^�C�v��2P�������� && SPACE�L�[����������
//				//�L�[���������ƂɃJ�E���g�������Ă���
//				m_nTriggerCount2++;
//				if (m_nTriggerCount2 >= 20)
//				{// �J�E���g��20��ȏ�s��������s
//				 // �M�~�b�N(��)����Ɉړ�
//					ObstacleMove2P = D3DXVECTOR3(0.0f, 2.5f, 0.0f);
//					// ���삪��������
//					CGimmick::SetCompletion(true);
//				}
//			}
//		}
//	}
//
//	return ObstacleMove2P;
//}


//=============================================================================
// �A�łœ����ǂ̏���
//=============================================================================
bool CObstacle::BarrageMoveWall(CObstacle * pCObstacle, D3DXVECTOR3 ObstaclePos, D3DXVECTOR3 PlayerPos)
{
	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::GetInput();

	// �ϐ��錾
	bool bFlag = true;

	if (pCObstacle->GetCompletion())
	{
		// ���삪�������Ă���
		return bFlag;
	}

	/* �����삪�������Ă��Ȃ��� */

	if (((ObstaclePos.x + 150.0f) >= PlayerPos.x) && ((ObstaclePos.z + 150.0f) >= PlayerPos.z)
		&& ((ObstaclePos.x - 150.0f) <= PlayerPos.x) && ((ObstaclePos.z - 150.0f) <= PlayerPos.z))
	{// �v���C���[�𓮂����Ȃ��悤�ɂ���t���O��L���ɂ���
		bFlag = false;
	}

	if (pCObstacle->GetGimmickType() == GIMMICKTYPE_BARRAGEMOVEWALL)
	{// �M�~�b�N�̃^�C�v���A�łœ����ǂ����������s
		if (!bFlag)
		{
			if (pInputKeyboard->Trigger(DIK_SPACE))
			{// SPACE�L�[����������J�E���g�𑝂₷
				m_nTriggerCount1++;
				if (m_nTriggerCount1 >= 20)
				{// �J�E���g��20��ȏ�s��������s
				 // �M�~�b�N(��)����Ɉړ�
					bFlag = true;
					// ���삪��������
					pCObstacle->SetCompletion(true);
					pCObstacle->SetStopFlag(true);
				}
			}
		}
	}

	// �l��Ԃ�
	return bFlag;
}

////=============================================================================
//// ���ݘA�łœ����ǂ̏���
////=============================================================================
//D3DXVECTOR3 CObstacle::AlternateMoveWal(D3DXVECTOR3 ObstaclePos, D3DXVECTOR3 P1Pos, D3DXVECTOR3 P2Pos, D3DXVECTOR3 ObstacleMove)
//{
//	// �L�[�{�[�h�̏��擾
//	CInput *pInputKeyboard = CApplication::GetInput();
//
//	if (CGimmick::GetCompletion() == false || CGimmick::GetCompletion() == false)
//	{// ������������Ă��Ȃ������s
//		if (CGame::GetPlayer1P()->GetPlayerType() == CPlayer::EPLAYER_1P
//			&&ObstaclePos.x + 150.0f >= P1Pos.x && ObstaclePos.z + 150.0f >= P1Pos.z
//			&&ObstaclePos.x - 150.0f <= P1Pos.x && ObstaclePos.z - 150.0f <= P1Pos.z)
//		{// �v���C���[�^�C�v��1P�������� && �M�~�b�N�͈͓̔��ɂ�����
//		 //�v���C���[1�𓮂����Ȃ��悤�ɂ���
//			CGame::GetPlayer1P()->SetSpeed(0.0f);
//		}
//		if (CGame::GetPlayer2P()->GetPlayerType() == CPlayer::EPLAYER_2P
//			&&ObstaclePos.x + 150.0f >= P2Pos.x && ObstaclePos.z + 150.0f >= P2Pos.z
//			&&ObstaclePos.x - 150.0f <= P2Pos.x && ObstaclePos.z - 150.0f <= P2Pos.z)
//		{// �v���C���[�^�C�v��2P�������� && �M�~�b�N�͈͓̔��ɂ�����
//		 //�v���C���[2�𓮂����Ȃ��悤�ɂ���
//			CGame::GetPlayer2P()->SetSpeed(0.0f);
//		}
//		if (CGimmick::GetGimmickType() == GIMMICKTYPE_ALTERNATEMOVEWALL)
//		{// �M�~�b�N�̃^�C�v�����݂ɘA�łœ����ǂ����������s
//			if (CGame::GetPlayer1P()->GetPlayerType() == CPlayer::EPLAYER_1P)
//			{
//				if (pInputKeyboard->Trigger(DIK_Z) && m_nAlternateFlag == false)
//				{// Z�L�[������������s
//					m_nTriggerCount1++;
//					m_nAlternateFlag = true;
//				}
//				if (pInputKeyboard->Trigger(DIK_C) && m_nAlternateFlag == true)
//				{// C�L�[������������s
//					m_nTriggerCount1++;
//					m_nAlternateFlag = false;
//				}
//				if (m_nTriggerCount1 >= 10)
//				{
//					// �M�~�b�N(��)����Ɉړ�
//					ObstacleMove = D3DXVECTOR3(0.0f, 2.5f, 0.0f);
//
//					// ���삪��������
//					CGimmick::SetCompletion(true);
//				}
//			}
//			if (CGame::GetPlayer2P()->GetPlayerType() == CPlayer::EPLAYER_2P)
//			{
//				if (pInputKeyboard->Trigger(DIK_N) && m_nAlternateFlag == false)
//				{// Z�L�[������������s
//					m_nTriggerCount2++;
//					m_nAlternateFlag = true;
//				}
//				if (pInputKeyboard->Trigger(DIK_M) && m_nAlternateFlag == true)
//				{// C�L�[������������s
//					m_nTriggerCount2++;
//					m_nAlternateFlag = false;
//				}
//				if (m_nTriggerCount2 >= 10)
//				{
//					// �M�~�b�N(��)����Ɉړ�
//					ObstacleMove = D3DXVECTOR3(0.0f, 2.5f, 0.0f);
//
//					// ���삪��������
//					CGimmick::SetCompletion(true);
//				}
//			}
//		}
//	}
//	return ObstacleMove;
//}

////=============================================================================
//// �v���C���[�������ē����ǂ̏���
////=============================================================================
//bool CObstacle::PushMoveObject(CObstacle * pCObstacle, D3DXVECTOR3 ObstaclePos, D3DXVECTOR3 PlayerPos)
//{
//	// �ϐ��錾
//	bool bFlag = true;
//
//	if (pCObstacle->GetCompletion())
//	{
//		// ���삪�������Ă���
//		return bFlag;
//	}
//
//	if (pCObstacle->GetGimmickType() == GIMMICKTYPE_PUSHMOVEWALL)
//	{
//		if (((ObstaclePos.x + 50.0f) >= PlayerPos.x) && ((ObstaclePos.z + 75.0f) >= PlayerPos.z)
//			&& ((ObstaclePos.x - 50.0f) <= PlayerPos.x) && ((ObstaclePos.z - 75.0f) <= PlayerPos.z))
//		{// �M�~�b�N�͈͓̔��ɂ�����
//			bFlag = false;
//		}
//	}
//	return bFlag;
//}

//=============================================================================
// �v���C���[���S�[���������̏���
//=============================================================================
bool CObstacle::PlayerGoal(D3DXVECTOR3 ObstaclePos, D3DXVECTOR3 P1Pos, D3DXVECTOR3 P2Pos, D3DXVECTOR3 ObstacleMove)
{
	if (CGimmick::GetGimmickType() == GIMMICKTYPE_GOAL)
	{
		if (ObstaclePos.x + 150.0f >= P1Pos.x && ObstaclePos.z + 50.0f >= P1Pos.z
			&&ObstaclePos.x - 150.0f <= P1Pos.x && ObstaclePos.z - 50.0f <= P1Pos.z
			&&CGimmick::GetCompletion() == false && PlayerGoalFlag == false
			|| ObstaclePos.x + 150.0f >= P2Pos.x && ObstaclePos.z + 50.0f >= P2Pos.z
			&&ObstaclePos.x - 150.0f <= P2Pos.x && ObstaclePos.z - 50.0f <= P2Pos.z
			&&CGimmick::GetCompletion() == false && PlayerGoalFlag == false)
		{// �M�~�b�N�͈̔� && ������������Ă��Ȃ������s
		 //�Q�[���N���A
			PlayerGoalFlag = true;
			if (PlayerGoalFlag == true)
			{
				// �J��
				CFade::SetFade(CApplication::MODE_TITLE);
			}
		}
	}

	return false;
}
