//=============================================================================
//
// �����L���O���� [ranking.cpp]
// Author : KADO TAKUMA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include <stdio.h>
#include "application.h"
#include "fade.h"
#include "input.h"
#include "ranking.h"
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "ranking_rogo.h"
#include "camera.h"
#include "light.h"
#include "meshfield.h"
#include "sound.h"
#include "load_stage.h"
#include "number.h"
#include "time.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CNumber *CRanking::m_apNumber[MAX_RANKINGRANK][MAX_RANKING] = {};
int CRanking::aData[MAX_RANKINGRANK] = {};
int CRanking::m_nRanking = 0;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CRanking::CRanking()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CRanking::~CRanking()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CRanking::Init(void)
{
	// �J�����̐ݒ�
	CApplication::GetCamera()->SetCameraType(CCamera::CAMERATYPE_TITLE);
	CApplication::GetCamera()->Init();

	//BGM�̐ݒ�
	CApplication::GetSound()->Play(CSound::LABEL_BGM_RESULT);

	// ���C�g�̐���
	m_pLight = CLight::Create();

	// ���b�V���t�B�[���h�̐���
	CMeshfield::Create(D3DXVECTOR3(-1500.0f, -210.0f, 14000.0f), CObject::PRIORITY_LEVEL2);

	// �X�e�[�W�̃��[�h
	CLoadStage::LoadAll();

	// �����L���O���S�̐���
	CRankingRogo::Create();

	//�t�@�C���ǂݍ��ݏ���
	Load();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CRanking::Uninit(void)
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

	//�C���X�^���X�̉������
	CObject::Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CRanking::Update(void)
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

	// �L�[�{�[�h�̏��擾
	CInput *pInput = CApplication::GetInput();

	if (pInput->Trigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADE_NONE)
	{
		//�t�@�C�������o������
		Save();

		//���[�h�ݒ�
		CFade::SetFade(CApplication::MODE_TITLE);
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CRanking::Draw(void)
{
}

//=============================================================================
// �t�@�C���ǂݍ��ݏ���
//=============================================================================
void CRanking::Load(void)
{
	//�t�@�C���|�C���^�錾
	FILE*pFile;

	//�t�@�C�����J��
	pFile = fopen("Data\\RANKING\\ranking.txt", "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ
		for (int nCntData = 0; nCntData < MAX_RANKINGRANK; nCntData++)
		{
			//�t�@�C���ɐ��l�������o��
			fscanf(pFile, "%d\n", &aData[nCntData]);
		}
		//�t�@�C�������
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***");
	}
}

//=============================================================================
// �t�@�C�������o������
//=============================================================================
void CRanking::Save(void)
{
	//�t�@�C���|�C���^�錾
	FILE*pFile;

	//�t�@�C�����J��
	pFile = fopen("Data\\RANKING\\ranking.txt", "w");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ
		for (int nCnt = 0; nCnt < MAX_RANKINGRANK; nCnt++)
		{
			//�t�@�C���ɐ��l�������o��
			fprintf(pFile, "%d\n", aData[nCnt]);
		}
		//�t�@�C�������
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***");
	}
}

//=============================================================================
// �X�R�A�̐ݒ菈��
//=============================================================================
void CRanking::SetRankingScore()
{
	if (m_nRanking > aData[MAX_RANKINGRANK - 1])
	{
		aData[MAX_RANKINGRANK - 1] = m_nRanking;
	}

	for (int nCount = 0; nCount < MAX_RANKINGRANK - 1; nCount++)
	{
		for (int nCount2 = nCount + 1; nCount2 < MAX_RANKINGRANK; nCount2++)
		{
			if (aData[nCount] < aData[nCount2])
			{
				int nMin = aData[nCount];
				aData[nCount] = aData[nCount2];
				aData[nCount2] = nMin;
			}
		}
	}

	CTime::Create(CTime::TYPE_RANKING, D3DXVECTOR3(SCREEN_WIDTH_HALF - 190.0f, 200.0f, 0.0f), D3DXVECTOR3(100.0f, 170.0f, 0.0f), aData[4], CObject::PRIORITY_LEVEL4);

	CTime::Create(CTime::TYPE_RANKING, D3DXVECTOR3(SCREEN_WIDTH_HALF - 190.0f, 310.0f, 0.0f), D3DXVECTOR3(100.0f, 170.0f, 0.0f), aData[3], CObject::PRIORITY_LEVEL4);

	CTime::Create(CTime::TYPE_RANKING, D3DXVECTOR3(SCREEN_WIDTH_HALF - 190.0f, 420.0f, 0.0f), D3DXVECTOR3(100.0f, 170.0f, 0.0f), aData[2], CObject::PRIORITY_LEVEL4);

	CTime::Create(CTime::TYPE_RANKING, D3DXVECTOR3(SCREEN_WIDTH_HALF - 190.0f, 530.0f, 0.0f), D3DXVECTOR3(100.0f, 170.0f, 0.0f), aData[1], CObject::PRIORITY_LEVEL4);

	CTime::Create(CTime::TYPE_RANKING, D3DXVECTOR3(SCREEN_WIDTH_HALF - 190.0f, 640.0f, 0.0f), D3DXVECTOR3(100.0f, 170.0f, 0.0f), aData[0], CObject::PRIORITY_LEVEL4);

	//for (int nCntScore = 0; nCntScore < MAX_RANKINGRANK; nCntScore++)
	//{
	//	aPosTexU[nCntScore][0] = aData[nCntScore] % 100000 / 10000;
	//	aPosTexU[nCntScore][1] = aData[nCntScore] % 10000 / 1000;
	//	aPosTexU[nCntScore][2] = aData[nCntScore] % 1000 / 100;
	//	aPosTexU[nCntScore][3] = aData[nCntScore] % 100 / 10;
	//	aPosTexU[nCntScore][4] = aData[nCntScore] % 10 / 1;
	//}

	////�e�N�X�`�����W�̐ݒ�
	//for (int nCnt = 0; nCnt < MAX_RANKINGRANK; nCnt++)
	//{
	//	for (int nCntScore = 0; nCntScore < MAX_RANKING; nCntScore++)
	//	{
	//		float fShiftWidth = 1.0f / 10;
	//		m_apNumber[nCnt][nCntScore]->SetUV((float)aPosTexU[nCnt][nCntScore] * fShiftWidth, (fShiftWidth + (float)aPosTexU[nCnt][nCntScore] * fShiftWidth), 0.0f, 1.0f);
	//	}
	//}
}

//=============================================================================
// ���̎擾
//=============================================================================
void CRanking::GetRanking(int Ranking)
{
	m_nRanking = Ranking;
}

//=============================================================================
// ��������
//=============================================================================
CRanking * CRanking::Create()
{
	CRanking *pRanking = new CRanking;

	if (pRanking != nullptr)
	{
		pRanking->Init();
	}

	return pRanking;
}
