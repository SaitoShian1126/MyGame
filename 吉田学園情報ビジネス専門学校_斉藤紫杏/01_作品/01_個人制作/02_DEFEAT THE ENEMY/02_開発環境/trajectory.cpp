//********************************************
//
//	trajectory.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "trajectory.h"
#include "application.h"
#include "renderer.h" 

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CTrajectory::m_pTextureTrajectory[5] = {};

//�O���̃R���X�g���N�^
CTrajectory::CTrajectory()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_UninitCount = 0;
	m_flag = true;
}

//�O���̃f�X�g���N�^
CTrajectory::~CTrajectory()
{
	//���������Ȃ�
}

//�O���̏���������
HRESULT CTrajectory::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************m_UninitCount
	m_UninitCount = 50;
	m_flag = true;
	
	switch (m_nType)
	{
	case TRAJECTORY_DOWN:
		BindTexture(m_pTextureTrajectory[0]);
		break;
	case TRAJECTORY_LIGHT:
		BindTexture(m_pTextureTrajectory[1]);
		break;
	case TRAJECTORY_LEFT:
		BindTexture(m_pTextureTrajectory[2]);
		break;
	case TRAJECTORY_LIGHTDOWN:
		BindTexture(m_pTextureTrajectory[3]);
		break;
	case TRAJECTORY_LEFTDOWN:
		BindTexture(m_pTextureTrajectory[4]);
		break;
	default:
		break;
	}

	return S_OK;
}

//�O���̏I������
void CTrajectory::Uninit(void)
{
	CObject2D::Uninit();
}

//�O���̍X�V����
void CTrajectory::Update()
{
	D3DXVECTOR3 TrajectoryPos = GetPos();

	m_UninitCount--;
	if (m_UninitCount <= 0)
	{
		Uninit();
		return;
	}

	//�ʒu�̐ݒ�
	SetPosition(TrajectoryPos);
	CObject2D::Update();
}

//�O���̕`�揈��
void CTrajectory::Draw()
{
	CObject2D::Draw();
}

//�O���̐���
CTrajectory *CTrajectory::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, TRAJECTORY nType)
{
	CTrajectory *pTrajectory = nullptr;

	//�N���X�̐���
	pTrajectory = new CTrajectory;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pTrajectory != nullptr)
	{
		pTrajectory->SetTrajectoryType(nType);
		//����������
		pTrajectory->Init();
		//�ݒ菈��
		pTrajectory->SetPosition(pos);
		pTrajectory->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pTrajectory;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CTrajectory::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/������.jpg",
		&m_pTextureTrajectory[0]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�E����.jpg",
		&m_pTextureTrajectory[1]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/������.jpg",
		&m_pTextureTrajectory[2]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�E������.jpg",
		&m_pTextureTrajectory[3]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/��������.jpg",
		&m_pTextureTrajectory[4]);

	return S_OK;
}

//�e�N�X�`���̔j��
void CTrajectory::Unload(void)
{
	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_pTextureTrajectory[nCnt] != nullptr)
		{						
			m_pTextureTrajectory[nCnt]->Release();
			m_pTextureTrajectory[nCnt] = nullptr;
		}
	}
}

//�O���̃^�C�v�̐ݒ�
void CTrajectory::SetTrajectoryType(TRAJECTORY type)
{
	m_nType = type;
}
