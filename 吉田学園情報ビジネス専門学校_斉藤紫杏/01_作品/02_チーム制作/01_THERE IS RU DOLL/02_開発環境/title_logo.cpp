//=============================================================================
//
// �^�C�g�����S���� [title_rogo.cpp]
// Author : KADO TAKUMA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "title_logo.h"
#include "object2D.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CObject2D * CTitleLogo::m_apObject2D[14] = {};
bool CTitleLogo::m_bTitleMenuFlag = false;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CTitleLogo::CTitleLogo(int nPriority) :
	m_bTitleRogoSwitch(false),
	m_nTime(0),
	m_nTextureMax(14),
	m_nSinCount(0),
	m_fRotZ(0.0f)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CTitleLogo::~CTitleLogo()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CTitleLogo::Init()
{
	auto LogoCreate = [](const char* inTag)
	{
		D3DXVECTOR3 pos = D3DXVECTOR3((float)SCREEN_WIDTH_HALF, -(float)SCREEN_HEIGHT_HALF, 0.0f);
		D3DXVECTOR3 size = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);
		return CObject2D::Create(inTag, pos, size, CObject::PRIORITY_LEVEL5);
	};

	//THERE IS RUN DOLL
	m_apObject2D[0] = LogoCreate("TITLE_D");
	m_apObject2D[1] = LogoCreate("TITLE_E_01");
	m_apObject2D[2] = LogoCreate("TITLE_E_02");
	m_apObject2D[3] = LogoCreate("TITLE_I");
	m_apObject2D[4] = LogoCreate("TITLE_L_01");
	m_apObject2D[5] = LogoCreate("TITLE_L_02");
	m_apObject2D[6] = LogoCreate("TITLE_N");
	m_apObject2D[7] = LogoCreate("TITLE_H");
	m_apObject2D[8] = LogoCreate("TITLE_O");
	m_apObject2D[9] = LogoCreate("TITLE_R_01");
	m_apObject2D[10] = LogoCreate("TITLE_R_02");
	m_apObject2D[11] = LogoCreate("TITLE_S");
	m_apObject2D[12] = LogoCreate("TITLE_U");
	m_apObject2D[13] = LogoCreate("TITLE_T");

	for (int i = 0; i < m_nMaxTex; i++)
	{
		m_nDelay[i] = rand() % 35;
		m_fSpeed[i] = (rand() % 7 + 50) * 0.1f;
	}

	// �t���O�̏�����
	m_bTitleMenuFlag = false;

	// �I�u�W�F�N�g�̏���������
	CObject2D::Init();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CTitleLogo::Uninit()
{
	for (int i = 0; i < m_nMaxTex; i++)
	{
		m_apObject2D[i]->Uninit();
	}

	// �I�u�W�F�N�g�̏I������
	CObject2D::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CTitleLogo::Update()
{
	m_nTime++;

	// ���W�擾
	D3DXVECTOR3 pos[14];
	for (int nCnt = 0; nCnt < m_nTextureMax; nCnt++)
	{
		pos[nCnt] = m_apObject2D[nCnt]->GetPos();
	}

	// �p�x�擾
	D3DXVECTOR3 rot[14];
	for (int nCnt = 0; nCnt < m_nTextureMax; nCnt++)
	{
		rot[nCnt] = m_apObject2D[nCnt]->GetRot();
	}

	//�^�C�g�����S�̏c�̓���
	if (m_bTitleRogoSwitch == false)
	{
		for (int nCnt = 0; nCnt < m_nTextureMax; nCnt++)
		{
			if (pos[nCnt].y < 360.0f)
			{
				if (m_nDelay[nCnt] >= m_nTime)
				{
					continue;
				}

				m_apObject2D[nCnt]->SetMove(D3DXVECTOR3(0.0f, m_fSpeed[nCnt], 0.0f));
			}
			else
			{
				m_apObject2D[nCnt]->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				m_bTitleRogoSwitch = true;
			}
		}
	}
	else
	{
		for (int nCnt = 0; nCnt < m_nTextureMax; nCnt++)
		{
			if (pos[nCnt].y >= 180.0f)
			{
				m_apObject2D[nCnt]->SetMove(D3DXVECTOR3(0.0f, -2.0f, 0.0f));
			}
			else
			{
				m_apObject2D[nCnt]->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				m_bTitleMenuFlag = true;
			}
		}
	}

	// Sin�g�Ŋp�x�����炷
	if (m_bTitleRogoSwitch)
	{
		m_nSinCount++;
		m_fRotZ = (((sinf(m_nSinCount * 0.03f) * 0.5f) * 0.5f) * 0.5f);
	}

	// �p�x�̐ݒ�
	for (int nCnt = 0; nCnt < m_nTextureMax; nCnt++)
	{
		rot[nCnt] = D3DXVECTOR3(0.0f, 0.0f, m_fRotZ);
		m_apObject2D[nCnt]->SetRot(rot[nCnt]);
	}

	// �I�u�W�F�N�g�̍X�V����
	CObject2D::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CTitleLogo::Draw()
{
	// �I�u�W�F�N�g�̕`�揈��
	CObject2D::Draw();
}

//=============================================================================
// ��������
//=============================================================================
CTitleLogo * CTitleLogo::Create(void)
{
	//�|�C���^�錾
	CTitleLogo *pTitleRogo = nullptr;

	//�C���X�^���X����
	pTitleRogo = new CTitleLogo;

	if (pTitleRogo != nullptr)
	{//�|�C���^�����݂�������s
		pTitleRogo->Init();
	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	return pTitleRogo;
}
