//=============================================================================
//
// �����L���O���S���� [ranking_rogo.cpp]
// Author : KADO TAKUMA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "precompile.h"
#include "ranking_rogo.h"
#include "object2D.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CObject2D * CRankingRogo::m_apObject2D[7] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CRankingRogo::CRankingRogo(int nPriority)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CRankingRogo::~CRankingRogo()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CRankingRogo::Init()
{
	// �����L���O[���ߕǎ�]
	m_apObject2D[0] = CObject2D::Create("RANKING_BG", D3DXVECTOR3((float)SCREEN_WIDTH_HALF, (float)SCREEN_HEIGHT_HALF, 0.0f), D3DXVECTOR3(1280.0f, 720.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	// �����L���O[1��]
	m_apObject2D[1] = CObject2D::Create("RANKING_1", D3DXVECTOR3(300.0f, 200.0f, 0.0f), D3DXVECTOR3(150.0f, 90.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	// �����L���O[2��]
	m_apObject2D[2] = CObject2D::Create("RANKING_2", D3DXVECTOR3(300.0f, 310.0f, 0.0f), D3DXVECTOR3(150.0f, 90.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	// �����L���O[3��]
	m_apObject2D[3] = CObject2D::Create("RANKING_3", D3DXVECTOR3(300.0f, 420.0f, 0.0f), D3DXVECTOR3(150.0f, 90.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	// �����L���O[4��]
	m_apObject2D[4] = CObject2D::Create("RANKING_4", D3DXVECTOR3(300.0f, 530.0f, 0.0f), D3DXVECTOR3(150.0f, 90.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	// �����L���O[5��]
	m_apObject2D[5] = CObject2D::Create("RANKING_5", D3DXVECTOR3(300.0f, 640.0f, 0.0f), D3DXVECTOR3(150.0f, 90.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	// �����L���O[���S]
	m_apObject2D[6] = CObject2D::Create("RANKING_0", D3DXVECTOR3((float)SCREEN_WIDTH_HALF, (float)SCREEN_HEIGHT_HALF + 10.0f, 0.0f), D3DXVECTOR3(1280.0f, 720.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	// �I�u�W�F�N�g�̏���������
	CObject2D::Init();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CRankingRogo::Uninit()
{
	// �I�u�W�F�N�g�̏I������
	CObject2D::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CRankingRogo::Update()
{
	// �I�u�W�F�N�g�̍X�V����
	CObject2D::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CRankingRogo::Draw()
{
	// �I�u�W�F�N�g�̕`�揈��
	CObject2D::Draw();
}

//=============================================================================
// ��������
//=============================================================================
CRankingRogo * CRankingRogo::Create(void)
{
	//�|�C���^�錾
	CRankingRogo *pRankingRogo = nullptr;

	//�C���X�^���X����
	pRankingRogo = new CRankingRogo;

	if (pRankingRogo != nullptr)
	{//�|�C���^�����݂�������s
		pRankingRogo->Init();
	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	return pRankingRogo;
}
