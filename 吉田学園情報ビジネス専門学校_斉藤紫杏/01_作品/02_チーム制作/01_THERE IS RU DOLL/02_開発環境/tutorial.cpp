#include "application.h"
#include "renderer.h"
#include "objectX.h"
#include "object3D.h"
#include "object2D.h"
#include "object.h"
#include "input.h"
#include "tutorial.h"
#include "fade.h"
#include "player.h"
#include "camera.h"
#include "light.h"
#include "meshfield.h"
#include "time.h"
#include "obstacle.h"
#include "load_stage.h"

CPlayer *CTutorial::m_pPlayer = nullptr;
CCamera *CTutorial::m_pCamera = nullptr;
CMeshfield *CTutorial::m_pMeshField = nullptr;
CLight *CTutorial::m_pLight = nullptr;
CTime *CTutorial::m_pTime = nullptr;
CObstacle *CTutorial::m_pObstacle = nullptr;

CTutorial::CTutorial()
{

}

CTutorial::~CTutorial()
{

}

HRESULT CTutorial::Init(void)
{
	// ���C�g�̐���
	m_pLight = CLight::Create();

	//// �^�C�}�[�̐���
	//m_pTime = CTime::Create(D3DXVECTOR3(100.0f, 0.0f, 0.0f), D3DXVECTOR3(500.0f, 0.0f, 0.0f), 0,CObject::PRIORITY_LEVEL4);

	// ���b�V���t�B�[���h�̐���
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, -210.0f, 14000.0f), CObject::PRIORITY_LEVEL2);

	// �M�~�b�N�̐���(�A�ŃM�~�b�N)
	//CBarrageMoveWall::Create(D3DXVECTOR3(-700.0f, 0.0f, 2000.0f));
	// �M�~�b�N�̐���(���ݘA�ŃM�~�b�N)
	//CAlternateMoveWall::Create(D3DXVECTOR3(-700.0f, 0.0f, 2000.0f));
	// �M�~�b�N�̐���(�����M�~�b�N)
	//CPushMoveWall::Create(D3DXVECTOR3(-700.0f,0.0f,2000.0f));

	//�v���C���[�̐���
	//m_pPlayer1P = CPlayer::Create(CPlayer::EPLAYER_1P, D3DXVECTOR3(-700.0f, 0.0f, 0.0f), CObject::PRIORITY_LEVEL3);
	//CLoadStage::LoadAll(m_pPlayer1P->GetPos());
	//CApplication::GetCamera()->SetCameraType(CCamera::CAMERATYPE_ONE);

	// �J�����̐ݒ�
	CApplication::GetCamera()->Init();

	return S_OK;
}

void CTutorial::Uninit(void)
{
	// �J�����̐ݒ�
	CApplication::GetCamera()->SetCameraType(CCamera::CAMERATYPE_NONE);

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

void CTutorial::Update(void)
{
	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::GetInput();

	if (m_pFade->GetFade() == CFade::FADE_NONE)
	{
		if (pInputKeyboard->Trigger(DIK_RETURN))
		{
			// �J��
			CFade::SetFade(CApplication::MODE_TITLE);
		}
	}
}

void CTutorial::Draw(void)
{

}

CTutorial * CTutorial::Create()
{
	//�|�C���^�錾
	CTutorial *pTutorial = nullptr;

	//�C���X�^���X����
	pTutorial = new CTutorial;

	if (pTutorial != nullptr)
	{//�|�C���^�����݂�������s
		pTutorial->Init();
	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	//�|�C���^��Ԃ�
	return pTutorial;
}