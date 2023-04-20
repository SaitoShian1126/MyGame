//=============================================================================
//
// �^�C�g������ [title.cpp]
// Author : KADO TAKUMA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "title.h"
#include "renderer.h"
#include "application.h"
#include "input.h"
#include "fade.h"
#include "camera.h"
#include "sound.h"
#include "meshfield.h"
#include "light.h"
#include "title_logo.h"
#include "title_menu.h"
#include "load_stage.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
LPDIRECT3DTEXTURE9 CTitle::m_pTexture = nullptr;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CTitle::CTitle()
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CTitle::~CTitle()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CTitle::Init(void)
{
	// �J�����̐ݒ�
	CApplication::GetCamera()->SetCameraType(CCamera::CAMERATYPE_TITLE);
	CApplication::GetCamera()->Init();

	//BGM�̐ݒ�
	CApplication::GetSound()->Play(CSound::LABEL_BGM_TITLE);

	// ���C�g�̐���
	m_pLight = CLight::Create();

	// ���b�V���t�B�[���h�̐���
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, -210.0f, 14000.0f), CObject::PRIORITY_LEVEL2);

	// �X�e�[�W�̃��[�h
	CLoadStage::LoadAll();

	// �^�C�g�����S�̐���
	CTitleLogo::Create();

	// �^�C�g�����j���[�̐���
	CTitleMenu::Create();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CTitle::Uninit(void)
{
	// �J�����̐ݒ�
	CApplication::GetCamera()->SetCameraType(CCamera::CAMERATYPE_NONE);

	//BGM���~�߂�ݒ�
	CApplication::GetSound()->Stop();

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
void CTitle::Update(void)
{
	// �J�����̏��擾
	CCamera *pCamera = CApplication::GetCamera();

	// �J�����̎��_�ƒ����_�擾
	D3DXVECTOR3 posV = pCamera->GetPosV();
	D3DXVECTOR3 posR = pCamera->GetPosR();

	// ���_�ƒ����_�����ɂ��炵�Ă�������
	posV += D3DXVECTOR3(0.0f, 0.0f, 2.0f);
	posR += D3DXVECTOR3(0.0f, 0.0f, 2.0f);

	// ���_�ƒ����_��ݒ�
	pCamera->SetPosV(posV);
	pCamera->SetPosR(posR);

	if (posR.z >= 5200.0f)
	{
		CFade::SetFade(CApplication::GetMode());
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CTitle::Draw(void)
{
}

//=============================================================================
// ��������
//=============================================================================
CTitle * CTitle::Create()
{
	// �|�C���^�錾
	CTitle *pTitle = nullptr;

	// �C���X�^���X����
	pTitle = new CTitle;

	if (pTitle != nullptr)
	{// �|�C���^�����݂�������s
		pTitle->Init();
	}
	else
	{// �|�C���^����������������s5
		assert(false);
	}

	// �|�C���^��Ԃ�
	return pTitle;
}
