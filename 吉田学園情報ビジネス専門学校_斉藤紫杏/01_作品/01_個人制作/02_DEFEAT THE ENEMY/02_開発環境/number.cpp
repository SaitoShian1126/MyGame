//********************************************
//
//	number.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "number.h"
#include "application.h"
#include "renderer.h" 

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CNumber::m_pTextureNumber = nullptr;

//�����̃R���X�g���N�^
CNumber::CNumber() : CObject2D(4)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
}

//�����̃f�X�g���N�^
CNumber::~CNumber()
{
	//���������Ȃ�
}

//�����̏���������
HRESULT CNumber::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************

	SetTexture(10.0f, 0.0f, 1.0f, 0.0f);
	BindTexture(m_pTextureNumber);

	return S_OK;
}

//�����̏I������
void CNumber::Uninit(void)
{
	CObject2D::Uninit();
}

//�����̍X�V����
void CNumber::Update()
{
	D3DXVECTOR3 NumberPos = GetPos();

	//�ʒu�̐ݒ�
	SetPosition(NumberPos);
	CObject2D::Update();
}

//�����̕`�揈��
void CNumber::Draw()
{
	CObject2D::Draw();
}

//�����̐���
CNumber *CNumber::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size)
{
	CNumber *pNumber = nullptr;

	//�N���X�̐���
	pNumber = new CNumber;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pNumber != nullptr)
	{
		//����������
		pNumber->Init();
		//�ݒ菈��
		pNumber->SetPosition(pos);
		pNumber->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pNumber;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CNumber::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/number000.png",
		&m_pTextureNumber);

	return S_OK;
}

//�e�N�X�`���̔j��
void CNumber::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_pTextureNumber != nullptr)
	{
		m_pTextureNumber->Release();
		m_pTextureNumber = nullptr;
	}
}
