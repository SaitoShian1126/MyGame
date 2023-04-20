//********************************************
//
//	application.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
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
#include "result.h"
#include "fade.h"
#include "mode.h"
#include "ranking.h"
#include "tutorial.h"

//�ÓI�����o�ϐ��錾
CRenderer *CApplication::m_pRenderer = nullptr;
CInput *CApplication::m_pInput = nullptr;
CJoyPad *CApplication::m_pInputJoyKey = nullptr;
CMode *CApplication::m_pMode = nullptr;
CApplication::MODE CApplication::m_mode = MODE_TITLE;

//�A�v���P�[�V�����̃R���X�g���N�^
CApplication::CApplication()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_pRenderer = nullptr;
}

//�A�v���P�[�V�����̃f�X�g���N�^
CApplication::~CApplication()
{
	//���������Ȃ�
}

//�A�v���P�[�V�����̏���������
HRESULT CApplication::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_pRenderer = nullptr;
	m_pInput = nullptr;
	m_pInputJoyKey = nullptr;
	m_pMode = nullptr;
	m_mode = MODE_TITLE;

	//�����_�����O�N���X�̐���
	m_pRenderer = new CRenderer;

	// ����������
	if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
	{//���������������s�����ꍇ
		return -1;
	}

	//�C���v�b�g�̃C���X�^���X����
	m_pInput = new CInput;
	m_pInputJoyKey = new CJoyPad;

	//�L�[�{�[�h�̏���������
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//�W���C�p�b�h�̏���������
	if (FAILED(m_pInputJoyKey->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	CFade::Create(MODE_TITLE);

	return S_OK;
}

//�A�v���P�[�V�����̏I������
void CApplication::Uninit(void)
{
	//�L�[�{�[�h�̔j��
	if (m_pInput != nullptr)
	{
		//�L�[�{�[�h�̏I������
		m_pInput->Uninit();

		delete m_pInput;
		m_pInput = nullptr;
	}

	//�W���C�p�b�h�̔j��
	if (m_pInputJoyKey != nullptr)
	{
		//�W���C�p�b�h�̏I������
		m_pInputJoyKey->Uninit();

		delete m_pInputJoyKey;
		m_pInputJoyKey = nullptr;
	}

	//�����_�����O�̔j��
	if (m_pRenderer != nullptr)
	{
		//�����_�����O�̏I������
		m_pRenderer->Uninit();

		delete m_pRenderer;
		m_pRenderer = nullptr;
	}
	//�I�u�W�F�N�g�̔j������
	CObject::ReleaseAll();
}

//�A�v���P�[�V�����̍X�V����
void CApplication::Update(void)
{
	//**********************************************
	//	�X�V����
	//**********************************************
	if (m_pInput != nullptr)
	{
		//�L�[�{�[�h�̍X�V����
		m_pInput->Update();
	}

	if (m_pInputJoyKey != nullptr)
	{
		//�W���C�p�b�h�̍X�V����
		m_pInputJoyKey->Update();
	}

	if (m_pRenderer != nullptr)
	{
		//�����_�����O�̍X�V����
		m_pRenderer->Update();
	}

	if (m_pMode != nullptr)
	{
		m_pMode->Update();
	}
}

//�A�v���P�[�V�����̕`�揈��
void CApplication::Draw(void)
{
	if (m_pRenderer != nullptr)
	{
		//�����_�����O�̕`�揈��
		m_pRenderer->Draw();
	}
}

//�����_�����O�̃C���X�^���X�擾����
CRenderer *CApplication::GetRenderer (void)
{
	return m_pRenderer;
}

//���[�h�̐ݒ菈��
void CApplication::SetMode(MODE mode)
{
	if (m_pMode != nullptr)
	{
		m_pMode->Uninit();
		m_pMode = nullptr;
	}
	
	CObject::ModeRelease();

	m_mode = mode;

	switch (m_mode)
	{
	case CApplication::MODE_TITLE:
		m_pMode = CTitle::Create();
		break;
	case CApplication::MODE_TUTORIAL:
		m_pMode = CTutorial::Create();
		break;
	case CApplication::MODE_GAME:
		m_pMode = CGame::Create();
		break;
	case CApplication::MODE_RESULT:
		m_pMode = CResult::Create();
		CResult::SetScore();
		break;
	case CApplication::MODE_RANKING:
		m_pMode = CRanking::Create();
		CRanking::SetRankingScore();
		break;
	case CApplication::MODE_MAX:
		break;
	default:
		break;
	}
}


