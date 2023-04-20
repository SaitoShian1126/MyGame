//=============================================================================
//
// �Q�[������ [game.cpp]
// Author : KADO TAKUMA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include <time.h>
#include "application.h"
#include "renderer.h"
#include "objectX.h"
#include "object3D.h"
#include "object2D.h"
#include "object.h"
#include "input.h"
#include "title.h"
#include "game.h"
#include "fade.h"
#include "player.h"
#include "camera.h"
#include "light.h"
#include "meshfield.h"
#include "model.h"
#include "time.h"
#include "number.h"
#include "obstacle.h"
#include "load_stage.h"
#include "barrage_move_wall.h"
#include "alternate_move_wall.h"
#include "push_move_wall.h"
#include "pause.h"
#include "button_move_player.h"
#include "countdown.h"
#include "stop_gimmick.h"
#include "sound.h"
#include "goal.h"
#include "random_door.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CPlayer *CGame::m_pPlayer1P = nullptr;
CPlayer *CGame::m_pPlayer2P = nullptr;
CCamera *CGame::m_pCamera = nullptr;
CMeshfield *CGame::m_pMeshField = nullptr;
CLight *CGame::m_pLight = nullptr;
CTime *CGame::m_pTime = nullptr;
CPause *CGame::m_pPause = nullptr;
CSound *CGame::m_pSound = nullptr;
CGame::EMode CGame::m_mode = CGame::EMode::SOLO;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CGame::CGame()
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CGame::~CGame()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CGame::Init(void)
{
	CApplication::GetCamera()->SetCameraType(CCamera::CAMERATYPE_ONE);

	////BGM�̐ݒ�
	//CApplication::GetSound()->Play(CSound::LABEL_BGM_GAME);

	// ���C�g�̐���
	m_pLight = CLight::Create();

	// �^�C�}�[�̐���
	m_pTime = CTime::Create(CTime::TYPE_TIMER, D3DXVECTOR3(SCREEN_WIDTH_HALF - 190.0f, 40.0f, 0.0f), D3DXVECTOR3(100.0f, 170.0f, 0.0f), 0, CObject::PRIORITY_LEVEL4);

	// ���b�V���t�B�[���h�̐���
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, -210.0f, 14000.0f), CObject::PRIORITY_LEVEL2);

	// �J�E���g�_�E���̐���
	CCountDown::Create(D3DXVECTOR3(SCREEN_WIDTH_HALF, SCREEN_HEIGHT_HALF, 0.0f));
	m_isCountDownNow = true;

	m_countDown = 0;

	// �X�e�[�W�̃��[�h
	CLoadStage::LoadAll(D3DXVECTOR3(-700.0f, 0.0f, 0.0f));
	//�v���C���[�̐���
	{
		int joyoadCount = CApplication::GetInput()->GetAcceptJoyPadCount();
		m_pPlayer1P = CPlayer::Create(CPlayer::EPLAYER_1P, D3DXVECTOR3(-700.0f, 50.0f, 0.0f), CObject::PRIORITY_LEVEL3);
		m_pPlayer1P->SetKeyIndex(joyoadCount - 1);
		m_pPlayer1P->SetRot(D3DXVECTOR3(0.0f, D3DX_PI , 0.0f));
		m_pPlayer1P->SetMotionType(CPlayer::MOTION_BURABURA);
	}

	if (m_mode == EMode::VS)
	{
		int joyoadCount = CApplication::GetInput()->GetAcceptJoyPadCount();
		m_pPlayer2P = CPlayer::Create(CPlayer::EPLAYER_2P, D3DXVECTOR3(700.0f, 50.0f, 0.0f), CObject::PRIORITY_LEVEL3);
		m_pPlayer2P->SetKeyIndex(joyoadCount - 2);
		m_pPlayer2P->SetRot(D3DXVECTOR3(0.0f, D3DX_PI, 0.0f));
		m_pPlayer2P->SetMotionType(CPlayer::MOTION_BURABURA);
	}

	SetGimmik(-700.0f);

	if (m_mode == EMode::VS)
	{
		SetGimmik(700.0f);
		CLoadStage::LoadAll(D3DXVECTOR3(700.0f, 0.0f, 0.0f));
		CApplication::GetCamera()->SetCameraType(CCamera::CAMERATYPE_TWO);
	}

	// �J�����̐ݒ�
	CApplication::GetCamera()->Init();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CGame::Uninit(void)
{
	// �i���o�[�̍폜
	CNumber::Unload();

	// �J�����̐ݒ�
	CApplication::GetCamera()->SetCameraType(CCamera::CAMERATYPE_NONE);

	////BGM�̐ݒ�
	//CApplication::GetSound()->Stop();

	// ���C�g�̉���E�폜
	if (m_pLight != nullptr)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}

	// �C���X�^���X�̉������
	CObject::Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CGame::Update(void)
{
	if (!m_isCountDownNow)
	{
	}
	else
	{
		m_countDown++;
		if (m_countDown >= 240)
		{
			m_isCountDownNow = true;
		}
	}

	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::GetInput();

	if (m_pFade->GetFade() == CFade::FADE_NONE)
	{
		if (m_pPause == nullptr)
		{
			if (pInputKeyboard->Trigger(KEY_PAUSE))
			{
				m_pPause = CPause::Create();
			}
		}
		else
		{
			if (m_pPause->GetEndFlag())
			{
				static int count = 0;
				count++;

				if (count <= 20)
				{
					count = 0;
					m_pPause = nullptr;
				}
			}
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CGame::Draw(void)
{

}

//=============================================================================
// ��������
//=============================================================================
CGame * CGame::Create()
{
	//�|�C���^�錾
	CGame *pGame = nullptr;

	//�C���X�^���X����
	pGame = new CGame;

	if (pGame != nullptr)
	{//�|�C���^�����݂�������s
		pGame->Init();
	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	//�|�C���^��Ԃ�
	return pGame;
}

void CGame::SetGimmik(float x)
{
	// �M�~�b�N�̐���(�A�ŃM�~�b�N)
	CBarrageMoveWall::Create(D3DXVECTOR3(-700.0f, 0.0f, 3700.0f));
	// �M�~�b�N�̐���(���ݘA�ŃM�~�b�N)
	CAlternateMoveWall::Create(D3DXVECTOR3(-700.0f, 0.0f, 3000.0f));
	// �M�~�b�N�̐���(�����M�~�b�N)
	CPushMoveWall::Create(D3DXVECTOR3(-700.0f, 0.0f, 3900.0f));
	// �M�~�b�N�̐���(�{�^���������班�����i�ރM�~�b�N)
	//CButtonMovePlayer::Create(D3DXVECTOR3(-700.0f, -200.0f, 2500.0f));
	// �M�~�b�N�̐���(����������~�܂�M�~�b�N)
	CStopGimmick::Create(D3DXVECTOR3(-700.0f, 0.0f, 1800.0f));
	// �S�[���̐���
	CGoal::Create(D3DXVECTOR3(-700.0f, 0.0f, 5000.0f));

	// �M�~�b�N�̐ݒu
	CAlternateMoveWall::Create(D3DXVECTOR3(x, 20.0f, 2000.0f));
	CAlternateMoveWall::Create(D3DXVECTOR3(x, 45.0f, 2800.0f));
	CButtonMovePlayer::Create(D3DXVECTOR3(x, -200.0f, 3600.0f));
	CPushMoveWall::Create(D3DXVECTOR3(x, 0.0f, 3900.0f));
	CPushMoveWall::Create(D3DXVECTOR3(x - 70.0f, 0.0f, 3900.0f));
	CPushMoveWall::Create(D3DXVECTOR3(x - 140.0f, 0.0f, 3900.0f));
	CPushMoveWall::Create(D3DXVECTOR3(x + 70.0f, 0.0f, 3900.0f));
	CPushMoveWall::Create(D3DXVECTOR3(x + 140.0f, 0.0f, 3900.0f));
}
