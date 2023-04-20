//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : KADO TAKUMA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include <assert.h>
#include "application.h"
#include "camera.h"
#include "input.h"
#include "main.h"
#include "motion_model3D.h"
#include "motion.h"
#include "player.h"
#include "meshfield.h"
#include "game.h"
#include "countdown.h"
#include "sound.h"
#include "particle.h"
#include "icon.h"

//=============================================================================
// �萔��`
//=============================================================================
const float CPlayer::SPEED_POWER = 4.0f;
const float CPlayer::JUMP_POWER = 12.0f;
const float CPlayer::GRAVITY_POWER = 0.775f;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer::CPlayer(int nPriority) :
	CMotionModel3D(nPriority),
	m_rotDest(0.0f, 0.0f, 0.0f),
	m_posOld(0.0f, 0.0f, 0.0f),
	m_move(0.0f, 0.0f, 0.0f),
	m_nType(EPLAYER_NONE),
	m_nSmokeCnt(0),
	m_keyIndex(-1),
	m_nSpeed(5.0f),
	m_bJumpFlag(false),
	m_bIsLanding(false),
	m_bIsLandingUp(false),
	m_pParticle(nullptr),
	m_isMove(true),
	m_HalfWayPointFlag(false)
{
	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_PLAYER);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer::~CPlayer()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayer::Init()
{
	//�I�u�W�F�N�g�̏�����
	CMotionModel3D::Init();

	//���f���̃��[�h
	SetMotion("Data/MODEL/PLAYER/player_new/Motion/motion_new.txt");

	m_bJumpFlag = true;
	return S_OK;
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayer::Update()
{
	CMotionModel3D::Update();

	// �ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	static int count = 0;
	if (m_moutionType == MOTION_BURABURA)
	{
		count++;

		if (m_pRope == nullptr)
		{
			m_pRope = CBillboard::Create(D3DXVECTOR3(pos.x, pos.y + 140.0f, pos.z), PRIORITY_LEVEL3);
			m_pRope->SetSize(D3DXVECTOR3(25.0f, 75.0f, 0.0f));
			m_pRope->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			m_pRope->BindTexture("ROPE");
		}

		m_pRope->SetMove(D3DXVECTOR3(0.0f,0.0f,0.0f));

		if (count >= 240)
		{
			count = 0;
			m_pRope->SetMove(D3DXVECTOR3(0.0f,2.5f,0.0f));
			SetMotionType(MOTION_NONE);
		}
		return;
	}

	// �O��̈ʒu��ۑ�
	m_posOld = pos;

	// �����擾
	D3DXVECTOR3 rot = GetRot();

	Move();

	// �ړ��͎擾
	D3DXVECTOR3 move = GetMove();

	// �d�͐ݒ�
	move.y -= GRAVITY_POWER;

	//�p�x�̐��K��(�ړI�̊p�x)
	if (m_rotDest.y - rot.y > D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y - D3DX_PI * 2;
	}
	else if (m_rotDest.y - rot.y < -D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y + D3DX_PI * 2;
	}

	// ����������
	rot.y += (m_rotDest.y - rot.y) * 0.08f;

	// �p�x�̐��K��(���݂̊p�x)
	if (rot.y > D3DX_PI)
	{
		rot.y = rot.y - D3DX_PI * 2;
	}
	else if (rot.y < -D3DX_PI)
	{
		rot.y = rot.y + D3DX_PI * 2;
	}

	// �ړ��ʉ��Z
	pos += move;
	move.x *= 0.75f;
	move.z *= 0.75f;

	if (pos.x != m_posOld.x && pos.z != m_posOld.z)
	{
		m_nSmokeCnt++;
	}

	if ((m_nSmokeCnt % 10) == 1)
	{
		for (int i = 0; i < 2; i++)
		{
			m_pParticle = CParticle::Create(D3DXVECTOR3(pos.x, pos.y + 5.0f, pos.z),
				CParticle::BEHAVIOR_SMOKE,
				PRIORITY_LEVEL3);
		}

		m_nSmokeCnt++;
	}

	// �|�C���^�錾
	CObject *pObject = CObject::GetTop(PRIORITY_LEVEL3);

	m_bIsLandingUp = false;

	// �v���C���[�ƃ��f���̓����蔻��
	while (pObject != nullptr)
	{
		if (pObject == this)
		{
			pObject = pObject->GetNext();
			continue;
		}

		//�I�u�W�F�N�g�̃^�C�v���擾
		CObject::EObjType objType = pObject->GetObjType();

		if (objType == OBJTYPE_MODEL)
		{
			CObjectX *pObjectX = (CObjectX*)pObject;

			// �����蔻��
			m_bIsLanding = pObjectX->Collision(&pos, &m_posOld, &GetMaxVtx(), &GetMinVtx());

			if (m_bIsLanding)
			{ // ���������ꍇ
				move = D3DXVECTOR3(0.0f, move.y, 0.0f);
			}
			// y���̓����蔻��
			if (m_bIsLandingUp)
			{
				pObjectX->UpCollision(&pos, &m_posOld, &GetMaxVtx(), &GetMinVtx(), &move);
			}
			else
			{
 				m_bIsLandingUp = pObjectX->UpCollision(&pos, &m_posOld, &GetMaxVtx(), &GetMinVtx(), &move);
			}
			if (m_bIsLandingUp)
			{
				m_bJumpFlag = false;
			}
		}
		//�|�C���^�����ɐi�߂�
		pObject = pObject->GetNext();
	}

	// ���b�V���t�B�[���h�̃|�C���^���擾
	//pMeshField->Collision(&pos);
	CMeshfield *pMeshField = CGame::GetMeshfield();

	if (pMeshField != nullptr)
	{
		float i = pMeshField->GetAnswer();

		// �v���C���[��pos��rot�̐ݒ�
		if (pos.y < pMeshField->GetAnswer())
		{
			m_bJumpFlag = false;
		}

		// ���b�V���t�B�[���h�Ƃ̓����蔻��
		//if (m_bJumpFlag == false)
		//{
		//	pMeshField->Collision(&pos);
		//}

		// y�����ړ����ĂȂ������ꍇ
		if (pos.y == m_posOld.y)
		{
			//move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		}
	}

	if (m_moutionType != MOTION_JUMP)
	{
		if (!m_bIsLandingUp)
		{
			SetMotionType(MOTION_JUMP);
		}
		else
		{
			if (move.x == 0.0f && move.z == 0.0f)
			{
				if (m_moutionType != MOTION_NONE && m_moutionType != MOTION_SCREW)
				{
					SetMotionType(MOTION_NONE);
				}
				//BGM�̐ݒ�
				CApplication::GetSound()->Play(CSound::LABEL_SE_HASHIRI);
			}
			else
			{
				if (move.x < 0.25f && move.x > -0.25f)
				{
					move.x = 0.0f;
				}
				if (move.z < 0.25f && move.z > -0.25f)
				{
					move.z = 0.0f;
				}

				if (m_moutionType != MOTION_MOVE)
				{
					SetMotionType(MOTION_MOVE);
				}
			}
		}
	}
	else
	{
		if (m_bIsLandingUp)
		{
			SetMotionType(MOTION_LANDING);
		}
	}

	if (m_HalfWayPointFlag == false)
	{
		// ���X�|�[������
		Respawn(pos);
	}

	// ���Ԓn�_
	HalfWayPoint(pos);

	// �v���C���[��pos��rot��move�̐ݒ�
	SetPos(pos);
	SetRot(rot);
	SetMove(move);
}

//=============================================================================
// ���X�|�[������
//=============================================================================
void CPlayer::Respawn(D3DXVECTOR3 &pos)
{
	// �ʒu�ύX
	if (pos.y <= -100.0f && m_nType == EPLAYER_1P)
	{
		SetMotionType(MOTION_BURABURA);
		pos = D3DXVECTOR3(-700.0f,80.0f,0.0f);
		m_pRope->SetPos(D3DXVECTOR3(pos.x, pos.y + 140.0f, pos.z));

	}
	if (pos.y <= -100.0f && m_nType == EPLAYER_2P)
	{
		SetMotionType(MOTION_BURABURA);
		pos = D3DXVECTOR3(700.0f, 80.0f, 0.0f);
		m_pRope->SetPos(D3DXVECTOR3(pos.x, pos.y + 140.0f, pos.z));
	}
}

//=============================================================================
// ��������
//=============================================================================
void CPlayer::HalfWayPoint(D3DXVECTOR3 & pos)
{
	// �ʒu�ύX
	if (pos.z >= 2800.0f)
	{
		m_HalfWayPointFlag = true;
		if (pos.y <= -100.0f && m_HalfWayPointFlag == true && m_nType == EPLAYER_1P)
		{
			SetMotionType(MOTION_BURABURA);
			pos = D3DXVECTOR3(-700.0f, 80.0f, 2800.0f);
		}
		if (pos.y <= -100.0f && m_HalfWayPointFlag == true && m_nType == EPLAYER_2P)
		{
			SetMotionType(MOTION_BURABURA);
			pos = D3DXVECTOR3(700.0f, 80.0f, 2800.0f);
		}
	}
	else
	{
		if (pos.y <= -100.0f && m_HalfWayPointFlag == true && m_nType == EPLAYER_1P)
		{
			SetMotionType(MOTION_BURABURA);
			pos = D3DXVECTOR3(-700.0f, 80.0f, 2800.0f);
		}
		if (pos.y <= -100.0f && m_HalfWayPointFlag == true && m_nType == EPLAYER_2P)
		{
			SetMotionType(MOTION_BURABURA);
			pos = D3DXVECTOR3(700.0f, 80.0f, 2800.0f);
		}
	}
}

//=============================================================================
// ��������
//=============================================================================
void CPlayer::Move()
{
	if (!m_isMove)
	{
		return;
	}

	/* ���ړ������� */

	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::GetInput();

	// �ړ��͎擾
	D3DXVECTOR3 move = GetMove();

	// �J�����̏��擾
	D3DXVECTOR3 pCameraRot = CCamera::GetRot();

	if (pInputKeyboard->Press(KEY_UP, m_keyIndex))
	{// ��Ɉړ�
		if (pInputKeyboard->Press(KEY_LEFT, m_keyIndex))
		{
			move.x = sinf(D3DX_PI * -0.25f + pCameraRot.y) * m_nSpeed;
			move.z = cosf(D3DX_PI * -0.25f + pCameraRot.y) * m_nSpeed;
			m_rotDest.y = pCameraRot.y + D3DX_PI * 0.75f;
		}
		else if (pInputKeyboard->Press(KEY_RIGHT, m_keyIndex))
		{
			move.x = sinf(D3DX_PI * 0.25f + pCameraRot.y) * m_nSpeed;
			move.z = cosf(D3DX_PI * 0.25f + pCameraRot.y) * m_nSpeed;
			m_rotDest.y = pCameraRot.y + -D3DX_PI * 0.75f;
		}
		else
		{
			move.x = sinf(pCameraRot.y) * m_nSpeed;
			move.z = cosf(pCameraRot.y) * m_nSpeed;
			m_rotDest.y = pCameraRot.y + D3DX_PI;
		}
	}
	else if (pInputKeyboard->Press(KEY_DOWN, m_keyIndex))
	{// ���Ɉړ�
		if (pInputKeyboard->Press(KEY_LEFT, m_keyIndex))
		{
			move.x = sinf(D3DX_PI * -0.75f + pCameraRot.y) * m_nSpeed;
			move.z = cosf(D3DX_PI * -0.75f + pCameraRot.y) * m_nSpeed;
			m_rotDest.y = pCameraRot.y + D3DX_PI * 0.25f;
		}
		else if (pInputKeyboard->Press(KEY_RIGHT, m_keyIndex))
		{
			move.x = sinf(D3DX_PI * 0.75f + pCameraRot.y) * m_nSpeed;
			move.z = cosf(D3DX_PI * 0.75f + pCameraRot.y) * m_nSpeed;
			m_rotDest.y = pCameraRot.y + -D3DX_PI * 0.25f;
		}
		else
		{
			move.x = sinf(pCameraRot.y) * -m_nSpeed;
			move.z = cosf(pCameraRot.y) * -m_nSpeed;
			m_rotDest.y = pCameraRot.y + 0.0f;
		}

	}
	else if (pInputKeyboard->Press(KEY_LEFT, m_keyIndex))
	{// ���Ɉړ�
		move.x = sinf(D3DX_PI * 0.5f + pCameraRot.y) * -m_nSpeed;
		move.z = cosf(D3DX_PI * 0.5f + pCameraRot.y) * -m_nSpeed;
		m_rotDest.y = pCameraRot.y + D3DX_PI * 0.5f;
	}
	else if (pInputKeyboard->Press(KEY_RIGHT, m_keyIndex))
	{// �E�Ɉړ�
		move.x = sinf(D3DX_PI * 0.5f + pCameraRot.y) * m_nSpeed;
		move.z = cosf(D3DX_PI * 0.5f + pCameraRot.y) * m_nSpeed;
		m_rotDest.y = pCameraRot.y + -D3DX_PI * 0.5f;
	}

	if (pInputKeyboard->Trigger(KEY_JUMP, m_keyIndex) && m_bJumpFlag == false)
	{// �W�����v
		m_bJumpFlag = true;
		move.y += JUMP_POWER;
		////BGM�̐ݒ�
		//CApplication::GetSound()->Play(CSound::LABEL_SE_JUMP_01);
	}
	SetMove(move);

	//�e�X�g�p
#ifdef _DEBUG

	D3DXVECTOR3 pos = GetPos();

	if (pInputKeyboard->Trigger(DIK_PERIOD))
	{
		int max = 100;
		for (int i = 0; i < max; i++)
		{
			m_pParticle = CParticle::Create(D3DXVECTOR3(pos.x, pos.y + 180.0f, pos.z),
				D3DXVECTOR3(sinf((rand() % max * ((360 / max) * (D3DX_PI / 180)))), sinf((rand() % max * ((360 / max) * (D3DX_PI / 180)))) * cosf((rand() % max * ((360 / max) * (D3DX_PI / 180)))), cosf((rand() % max * ((360 / max) * (D3DX_PI / 180))))),
				D3DXCOLOR((rand() % 100) * 0.01f, (rand() % 100) * 0.01f, (rand() % 100) * 0.01f, 1.0f),
				"PARTICLE_FLARE",
				PRIORITY_LEVEL3);
			//m_pParticle->SetLower(pos);
		}
	}

	if (pInputKeyboard->Trigger(DIK_BACKSPACE))
	{
	}

#endif // _DEBUG
}


//=============================================================================
// ��������
//=============================================================================
CPlayer * CPlayer::Create(EPLAYER type, const D3DXVECTOR3 pos, int nPriority)
{
	CPlayer *pPlayer = new CPlayer(nPriority);

	if (pPlayer != nullptr)
	{
		pPlayer->Init();
		pPlayer->SetType(type);
		pPlayer->SetPos(pos);
	}
	else
	{
		assert(false);
	}

	return pPlayer;
}

//=============================================================================
// �^�C�v�ݒ菈��
//=============================================================================
void CPlayer::SetType(EPLAYER type)
{
	m_nType = type;
}

//=============================================================================
// �X�s�[�h�̐ݒ�
//=============================================================================
void CPlayer::SetSpeed(float speed)
{
	m_nSpeed = speed;
}

void CPlayer::SetMotionType(EMotion inMotion)
{
	// �������[�V�����ɂ͑J�ڂ��Ȃ��B
	if (m_moutionType == inMotion)
	{
		return;
	}

	m_moutionType = inMotion;
	GetMotion()->SetNumMotion(m_moutionType);
}
