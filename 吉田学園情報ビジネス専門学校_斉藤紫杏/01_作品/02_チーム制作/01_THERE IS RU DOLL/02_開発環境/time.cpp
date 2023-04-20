//=============================================================================
//
// �^�C������ [time.cpp]
// Author : kubota yuuki
// Author : kado takuma
//
//=============================================================================
#include "number.h"
#include "object2D.h"
#include "time.h"
#include <time.h>
#include <math.h>
#include "ranking.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CNumber *CTime::m_apNumBer[5] = {};
CObject2D *CTime::m_apObject2D[2] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CTime::CTime(int nPriority) :
	CObject(nPriority),
	m_apnTime(0)
{
	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		m_apNumBer[nCnt] = nullptr;
	}
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CTime::~CTime()
{

}

//=============================================================================
// �^�C���̏�����
//=============================================================================
HRESULT CTime::Init()
{
	//�e�N�X�`�����W�̐ݒ�
	for (int nCntScore = 0; nCntScore < 5; nCntScore++)
	{
		m_apNumBer[nCntScore] = CNumber::Create(D3DXVECTOR3(m_pos.x + (103.0f * nCntScore), m_pos.y, 0.0f), m_size);
	}

	m_apObject2D[0] = CObject2D::Create("TIMER_DOT", D3DXVECTOR3(m_pos.x + 45.0f, m_pos.y, 0.0f), D3DXVECTOR3(40.0f, 60.0f, 0.0f), CObject::PRIORITY_LEVEL5);
	m_apObject2D[1] = CObject2D::Create("TIMER_DOT", D3DXVECTOR3(m_pos.x + 255.0f, m_pos.y, 0.0f), D3DXVECTOR3(40.0f, 60.0f, 0.0f), CObject::PRIORITY_LEVEL5);

	if (m_Type == TYPE_TIMER)
	{
		// �~���b�ݒ�
		m_nTime = timeGetTime();
	}

	return S_OK;
}

//=============================================================================
// �^�C���̏I��
//=============================================================================
void CTime::Uninit()
{
}

//=============================================================================
// �^�C���̍X�V
//=============================================================================
void CTime::Update()
{
	if (m_Type == TYPE_TIMER)
	{
		// �o�ߎ��Ԃ̍X�V
		AddTime(1);
	}
}

//=============================================================================
// �^�C���̕`��
//=============================================================================
void CTime::Draw()
{

}

//=============================================================================
// �^�C���̃N���G�C�g
//=============================================================================
CTime *CTime::Create(EType type, D3DXVECTOR3 pos, D3DXVECTOR3 size, int nScore, int nPriority)
{
	CTime *pTime = nullptr;

	pTime = new CTime(nPriority);

	if (pTime != nullptr)
	{
		pTime->SetType(type);
		pTime->SetPos(pos);
		pTime->SetSize(size);
		pTime->Init();
		pTime->SetTime(nScore);
	}

	return pTime;
}

//=============================================================================
//�Z�b�g�^�C��
//=============================================================================
void CTime::SetTime(int nScore)
{
	//�e���̐������i�[
	int nNumber[5];

	//�l�i�[
	int second;
	int minute;
	int millisecond;
	int secondSave;

	minute = nScore / 60000;
	secondSave = nScore / 600;
	second = nScore - (minute * 60000);
	millisecond = nScore - (secondSave * 600);

	nNumber[0] = minute;
	nNumber[1] = second % 100000 / 10000;
	nNumber[2] = second % 10000 / 1000;
	nNumber[3] = millisecond % 1000 / 100;
	nNumber[4] = millisecond % 100 / 10;

	//�e�N�X�`�����W�̐ݒ�
	for (int nCntTime = 0; nCntTime < 5; nCntTime++)
	{
		float fShiftWidth = 1.0f / 10;
		m_apNumBer[nCntTime]->SetUV((nNumber[nCntTime] * fShiftWidth), (fShiftWidth + (nNumber[nCntTime] * fShiftWidth)), 0.0f, 1.0f);
	}
}

//=============================================================================
// ���W�ݒ菈��
//=============================================================================
void CTime::SetPos(D3DXVECTOR3 pos)
{
	//���g�̃T�C�Y���擾
	D3DXVECTOR3 size = GetSize();

	//���W
	m_pos = pos;

	//�^�C���̍��W�ݒ�
	for (int nCnt = 0; nCnt < m_nDigit; nCnt++)
	{
		if (m_apNumBer[nCnt] != nullptr)
		{
			m_apNumBer[nCnt]->SetPos(D3DXVECTOR3((m_pos.x + (nCnt * size.x)) - (m_nDigit * size.x / 2) + (size.x / 2), m_pos.y, m_pos.z));
		}
	}
}

//=============================================================================
//�^�C�����Z
//=============================================================================
void CTime::AddTime(int nValue)
{
	SetTime((int)(timeGetTime() - m_nTime));

	// �����L���O�Ƀ^�C���Z�b�g
	CRanking::GetRanking((int)(timeGetTime() - m_nTime));
}

//=============================================================================
//�^�C���̏����擾
//=============================================================================
int CTime::GetTime()
{
	return m_nTime;
}