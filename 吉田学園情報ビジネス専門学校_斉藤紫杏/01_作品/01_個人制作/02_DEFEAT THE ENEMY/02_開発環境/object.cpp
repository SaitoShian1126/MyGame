//********************************************
//
//	object.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include "object.h"
#include "renderer.h"

//�ÓI�����o�ϐ��錾
CObject *CObject::m_apObject[MAX_DRAWPRIORITY][MAX_OBJECT] = {};
int CObject::m_nNumAll;

//�I�u�W�F�N�g�D�揇��
CObject::CObject(int nPriority /* = 3*/)
{
	m_nPriority = nPriority;

	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
	{
		if (m_apObject[nPriority][nCntObject] == nullptr)
		{
			m_apObject[nPriority][nCntObject] = this;	//CObject2D��pObject2D��this
			//�����̔ԍ���ݒ�
			m_nID = nCntObject;
			m_nNumAll++;
			break;
		}
	}
}

//�I�u�W�F�N�g�̃f�X�g���N�^
CObject::~CObject()
{
	//���������Ȃ�
}

//���ׂĂ̔j������
void CObject::ReleaseAll(void)
{
	for (int nCntPriority = 0; nCntPriority < MAX_DRAWPRIORITY; nCntPriority++)
	{
		for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
		{
			//null�`�F�b�N
			if (m_apObject[nCntPriority][nCnt] != nullptr)
			{
				//�I�������̊֐��Ăяo��
				m_apObject[nCntPriority][nCnt]->Uninit();

				//�������̉��
				delete m_apObject[nCntPriority][nCnt];
				m_apObject[nCntPriority][nCnt] = nullptr;
			}
		}
	}
}

//���ׂĂ̍X�V����
void CObject::UpdateAll(void)
{
	for (int nCntPriority = 0; nCntPriority < MAX_DRAWPRIORITY; nCntPriority++)
	{
		for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
		{
			//null�`�F�b�N
			if (m_apObject[nCntPriority][nCnt] != nullptr)
			{
				//�X�V�����̊֐��Ăяo��
				m_apObject[nCntPriority][nCnt]->Update();
			}
		}
	}
}

//���ׂĂ̕`�揈��
void CObject::DrawAll(void)
{
	for (int nCntPriority = 0; nCntPriority < MAX_DRAWPRIORITY; nCntPriority++)
	{
		for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
		{
			//null�`�F�b�N
			if (m_apObject[nCntPriority][nCnt] != nullptr)
			{
				//�`�揈���̊֐��Ăяo��
				m_apObject[nCntPriority][nCnt]->Draw();
			}
		}
	}
}

//���[�h�̔j��
void CObject::ModeRelease(void)
{
	for (int nCntPriority = 0; nCntPriority < MAX_DRAWPRIORITY; nCntPriority++)
	{
		for (int nCnt = 0; nCnt < MAX_OBJECT; nCnt++)
		{
			if (m_apObject[nCntPriority][nCnt] != nullptr)
			{
				if (m_apObject[nCntPriority][nCnt]->GetType() != TYPE_MODE)
				{
					m_apObject[nCntPriority][nCnt]->Uninit();
				}
			}
		}
	}
}

//�j��
void CObject::Release(void)
{
	if (m_apObject[m_nPriority][m_nID] != nullptr)
	{
		//�ԍ��ۑ�
		const int nID = m_nID;
		const int nPriority = m_nPriority;
		delete m_apObject[nPriority][nID];
		m_apObject[nPriority][nID] = nullptr;
		
	}
	m_nNumAll--;
}

//���Ԗڂ̃I�u�W�F�N�g���擾
CObject *CObject::GetObjects(int nPriority, int nCntType)
{
	return m_apObject[nPriority][nCntType];
}

//�^�C�v�̐ݒ�
void CObject::SetType(TYPE type)
{
	m_Type = type;
}