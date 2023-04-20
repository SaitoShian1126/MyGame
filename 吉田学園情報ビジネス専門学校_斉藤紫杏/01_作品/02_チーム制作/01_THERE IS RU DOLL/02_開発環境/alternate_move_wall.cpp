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
#include "alternate_move_wall.h"
#include "player.h"
#include "input.h"
#include "application.h"
#include "renderer.h"
#include "game.h"
#include "fade.h"
#include "model.h"
#include "billboard.h"
#include "sound.h"
#include "particle.h"
#include "icon.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAlternateMoveWall::CAlternateMoveWall(int nPriority) :
	m_Screw(nullptr),
	m_buttonPushCount(0)
{
	m_PosOld = {};
	m_nTriggerCount = 0;

	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_GIMMICK);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAlternateMoveWall::~CAlternateMoveWall()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CAlternateMoveWall::Init()
{
	// �M�~�b�N�̏�����
	CGimmick::Init();

	m_PosOld = CObjectX::GetPos();

	//���f���̃��[�h
	LoadModel("POCKET_WATCH");

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CAlternateMoveWall::Uninit()
{
	CGimmick::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CAlternateMoveWall::Update()
{
	if (GetCompletion())
	{
		/* ��Gimmick�N���A���Ă��遫 */

		// �M�~�b�N�̍��W,�ړ��ʎ擾
		D3DXVECTOR3 pos = GetPos();

		D3DXVECTOR3 move = D3DXVECTOR3(0.0f, 2.5f, 0.0f);

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

		CPlayer* hitPlayer = GetHitPlayer();

		if (hitPlayer->GetPos().x != 0.0f)
		{
			D3DXVECTOR3 pos = hitPlayer->GetPos();
			pos.x = GetPos().x;
			hitPlayer->SetPos(pos);
		}
		hitPlayer->SetMotionType(CPlayer::MOTION_SCREW);

		// �M�~�b�N����
		ConstOperate();

		m_buttonPushCount++;

		if (m_buttonPushCount >= 10)
		{
			hitPlayer->SetUpdateStop(true);
		}
		else
		{
			D3DXVECTOR3 rot = m_Screw->GetRot();
			rot.y += 0.04f;
			m_Screw->SetRot(rot);
		}

		hitPlayer->SetIsMove(false);
		if (GetCompletion())
		{// ���삪�����������Ɏ��s
		 // �v���C���[�̃X�s�[�h�����ɖ߂�
			hitPlayer->SetIsMove(true);
		}

		// �M�~�b�N�̍X�V
		CGimmick::Update();
		m_Screw->Update();
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CAlternateMoveWall::Draw()
{
	CGimmick::Draw();
	m_Screw->Draw();
}

//=============================================================================
// ��������
//=============================================================================
void CAlternateMoveWall::ConstOperate()
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

	/* �����삪�������Ă��Ȃ��� */

	if (m_pIcon[0] == nullptr)
	{
		m_pIcon[0] = CIcon::Create(m_Screw->GetPos() + D3DXVECTOR3(0.0f, 130.0f, 0.0f), D3DXVECTOR3(50.0f, 30.0f, 0.0f), "SPEECH_BUBBLE", PRIORITY_LEVEL3);
		m_pIcon[0]->SetScaling(true, true);
		m_pIcon[0]->SetAnimation(1, 1, 12, 1, true);
	}

	if (GetHitPlayer()->GetKeyIndex() == -1)
	{
		if (m_pIcon[1] == nullptr)
		{
			m_pIcon[1] = CIcon::Create(m_Screw->GetPos() + D3DXVECTOR3(-15.0f, 130.0f, 0.0f), D3DXVECTOR3(12.0f, 12.0f, 0.0f), "BUTTON_ZKEY", PRIORITY_LEVEL3);
			m_pIcon[1]->SetAnimation(2, 1, 12, 1, true);
			m_pIcon[1]->SetStopAnim(0, 0);
		}

		if (m_pIcon[2] == nullptr)
		{
			m_pIcon[2] = CIcon::Create(m_Screw->GetPos() + D3DXVECTOR3(15.0f, 130.0f, 0.0f), D3DXVECTOR3(12.0f, 12.0f, 0.0f), "BUTTON_CKEY", PRIORITY_LEVEL3);
			m_pIcon[2]->SetAnimation(2, 1, 12, 1, true);
			m_pIcon[2]->SetStopAnim(1, 0);
		}
	}
	else
	{
		if (m_pIcon[1] == nullptr)
		{
			m_pIcon[1] = CIcon::Create(m_Screw->GetPos() + D3DXVECTOR3(-15.0f, 130.0f, 0.0f), D3DXVECTOR3(12.0f, 12.0f, 0.0f), "BUTTON_LB", PRIORITY_LEVEL3);
			m_pIcon[1]->SetAnimation(2, 1, 12, 1, true);
			m_pIcon[1]->SetStopAnim(0, 0);
		}

		if (m_pIcon[2] == nullptr)
		{
			m_pIcon[2] = CIcon::Create(m_Screw->GetPos() + D3DXVECTOR3(15.0f, 130.0f, 0.0f), D3DXVECTOR3(12.0f, 12.0f, 0.0f), "BUTTON_RB", PRIORITY_LEVEL3);
			m_pIcon[2]->SetAnimation(2, 1, 12, 1, true);
			m_pIcon[2]->SetStopAnim(1, 0);
		}
	}

	if (m_pIcon[3] == nullptr)
	{
		m_pIcon[3] = CIcon::Create(m_Screw->GetPos() + D3DXVECTOR3(0.0f, 130.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f), "ARROW", PRIORITY_LEVEL3);
		m_pIcon[3]->SetFlip(CIcon::FLIP_HORIZON);
	}

	if (pInputKeyboard->Trigger(KEY_LEFT_ACTION) && !m_nAlternateFlag)
	{// Z�L�[������������s

		//BGM�̐ݒ�
		CApplication::GetSound()->Play(CSound::LABEL_SE_NEGIMAKI);

		D3DXVECTOR3 pos = GetPos();
		pos.y += 2.5f;
		SetPos(pos);

		m_nTriggerCount++;
		GetHitPlayer()->SetUpdateStop(false);
		m_buttonPushCount = 0;
		m_nAlternateFlag = true;

		for (int i = 0; i < 2; i++)
		{
			// �ړ���
			D3DXVECTOR3 move;
			move.x = sinf(rand() % 50 * ((360 / 50) * (D3DX_PI / 180)));
			move.y = 1.0f;
			move.z = cosf(rand() % 50 * ((360 / 50) * (D3DX_PI / 180)));

			// �F
			D3DXCOLOR color((rand() % 100) * 0.01f, (rand() % 100) * 0.01f, (rand() % 100) * 0.01f, 1.0f);
			D3DXCOLOR destColor(1.0f, 0.2f, 0.0f, 1.0f);

			CParticle* particle = CParticle::Create(GetPos(),move, color,"PARTICLE_FLARE",PRIORITY_LEVEL3);
			particle->SetDestCol(destColor);
			particle->SetGravity(true, 0.1f);
			particle->SetDelay(15);
			particle->SetBounce(true);
			particle->SetLower(GetPos());
		}

		//�A�C�R��
		m_pIconEffect = CIcon::Create(m_Screw->GetPos() + D3DXVECTOR3(-15.0f, 130.0f, 0.0f), D3DXVECTOR3(12.0f, 12.0f, 0.0f), "BUTTON_EFFECT", PRIORITY_LEVEL4);
		m_pIconEffect->SetCol(D3DXCOLOR(1.0f,0.5f,0.0f,1.0f));
		m_pIconEffect->SetFade(true);
		m_pIconEffect->SetScaling(true);

		m_pIcon[1]->SetStopAnim(1, 0);
		m_pIcon[2]->SetStopAnim(0, 0);
		m_pIcon[3]->SetFlip(CIcon::FLIP_HORIZON);
	}

	if (pInputKeyboard->Trigger(KEY_RIGHT_ACTION) && m_nAlternateFlag)
	{// C�L�[������������s

		//BGM�̐ݒ�
		CApplication::GetSound()->Play(CSound::LABEL_SE_NEGIMAKI);

		D3DXVECTOR3 pos = GetPos();
		pos.y += 2.5f;
		SetPos(pos);

		m_nTriggerCount++;
		GetHitPlayer()->SetUpdateStop(false);
		m_buttonPushCount = 0;
		m_nAlternateFlag = false;

		for (int i = 0; i < 2; i++)
		{
			D3DXVECTOR3 move;
			move.x = sinf(rand() % 50 * ((360 / 50) * (D3DX_PI / 180)));
			move.y = 1.0f;
			move.z = cosf(rand() % 50 * ((360 / 50) * (D3DX_PI / 180)));

			D3DXCOLOR color((rand() % 100) * 0.01f, (rand() % 100) * 0.01f, (rand() % 100) * 0.01f, 1.0f);
			D3DXCOLOR destColor(1.0f, 0.2f,0.0f,1.0f);

			CParticle* particle = CParticle::Create(GetPos(), move, color, "PARTICLE_FLARE", PRIORITY_LEVEL3);
			particle->SetDestCol(destColor);
			particle->SetGravity(true, 0.1f);
			particle->SetDelay(15);
			particle->SetBounce(true);
			particle->SetLower(GetPos());
		}

		//�A�C�R��
		m_pIconEffect = CIcon::Create(m_Screw->GetPos() + D3DXVECTOR3(15.0f, 130.0f, 0.0f), D3DXVECTOR3(12.0f, 12.0f, 0.0f), "BUTTON_EFFECT", PRIORITY_LEVEL4);
		m_pIconEffect->SetCol(D3DXCOLOR(1.0f, 0.5f, 0.0f, 1.0f));
		m_pIconEffect->SetFade(true);
		m_pIconEffect->SetScaling(true);

		m_pIcon[1]->SetStopAnim(0, 0);
		m_pIcon[2]->SetStopAnim(1, 0);
		m_pIcon[3]->SetFlip(CIcon::FLIP_HORIZON);
	}

	// �w��񐔂̃{�^�����������ꍇ
	if (m_nTriggerCount >= 40)
	{
		// ���삪��������
		GetHitPlayer()->SetMotionType(CPlayer::MOTION_NONE);
		m_pIcon[0]->Uninit();
		m_pIcon[1]->Uninit();
		m_pIcon[2]->Uninit();
		m_pIcon[3]->Uninit();
		CGimmick::SetCompletion(true);
	}
}

//=============================================================================
// �L�[���J�E���g����֐�
//=============================================================================
void CAlternateMoveWall::KeyCount()
{
	m_nTriggerCount++;
}

//=============================================================================
// ���쏈��
//=============================================================================
CAlternateMoveWall* CAlternateMoveWall::Create(const D3DXVECTOR3& pos)
{
	CAlternateMoveWall *pObstacle = new CAlternateMoveWall();

	if (pObstacle != nullptr)
	{
		pObstacle->SetGimmickType(GIMMICKTYPE_BARRAGEMOVEWALL);
		pObstacle->Init();
		pObstacle->SetPos(pos);
		pObstacle->m_Screw = CObjectX::Create(pos - D3DXVECTOR3(0.0f, 0.0f, 130.0f), CObject::PRIORITY_LEVEL3);
		pObstacle->m_Screw->LoadModel("SCREW WINDING");
	}
	else
	{
		assert(false);
	}

	return pObstacle;
}
