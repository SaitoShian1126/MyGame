//********************************************
//
//	ui.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "ui.h"
#include "application.h"
#include "renderer.h"
#include "explosion.h"
#include "fade.h"
#include "input.h"
#include "player.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CUi::m_pTextureUi[2] = {};

//�G�̃R���X�g���N�^
CUi::CUi() : CObject2D(4)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
}

//�G�̃f�X�g���N�^
CUi::~CUi()
{
	//���������Ȃ�
}

//�G�̏���������
HRESULT CUi::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************

	switch (m_nType)
	{
	case CUi::UITYPE_NONE:
		break;
	case CUi::UITYPE_BULLET:
		//�e�N�X�`�����f
		BindTexture(m_pTextureUi[0]);
		break;
	case CUi::UITYPE_LIFE:
		//�e�N�X�`�����f
		BindTexture(m_pTextureUi[1]);
		break;
	default:
		break;
	}
	return S_OK;
}

//�G�̏I������
void CUi::Uninit(void)
{
	CObject2D::Uninit();
}

//�G�̍X�V����
void CUi::Update()
{
	if (m_nType == UITYPE_BULLET)
	{
		if (CPlayer::GetBulletFlag() == true)
		{
			//�e�N�X�`���̐ݒ�
			SetTexture(2.0f, 1.0f, 1.0f, 0.0f);
		}
		else if (CPlayer::GetBulletFlag() == false)
		{
			//�e�N�X�`���̐ݒ�
			SetTexture(2.0f, 2.0f, 1.0f, 0.0f);
		}
	}
}

//�G�̕`�揈��
void CUi::Draw()
{
	CObject2D::Draw();
}

//ui�̎�ނ̐ݒ�
void CUi::SetUiType(UITYPE type)
{
	m_nType = type;
}

//�X�|�[���̐���
CUi *CUi::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, UITYPE type)
{
	CUi *pUi = nullptr;

	//�N���X�̐���
	pUi = new CUi;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pUi != nullptr)
	{
		pUi->SetUiType(type);
		//����������
		pUi->Init();
		//�ݒ菈��
		pUi->SetPosition(pos);
		pUi->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pUi;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CUi::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�e�؂�ւ�.png",
		&m_pTextureUi[0]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�Q�[�W�J�o�[.png",
		&m_pTextureUi[1]);

	return S_OK;
}

//�e�N�X�`���̔j��
void CUi::Unload(void)
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_pTextureUi[nCnt] != nullptr)
		{				
			m_pTextureUi[nCnt]->Release();
			m_pTextureUi[nCnt] = nullptr;
		}
	}
}
