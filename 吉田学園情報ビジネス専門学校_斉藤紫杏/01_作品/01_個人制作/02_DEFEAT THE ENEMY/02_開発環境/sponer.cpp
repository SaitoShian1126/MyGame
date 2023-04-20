//********************************************
//
//	sponer.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include <time.h>
#include "sponer.h"
#include "application.h"
#include "renderer.h" 

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CSponer::m_pTextureSponer = nullptr;

//�A�C�e���̃R���X�g���N�^
CSponer::CSponer() : CObject2D(0)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
}

//�A�C�e���̃f�X�g���N�^
CSponer::~CSponer()
{
	//���������Ȃ�
}

//�A�C�e���̏���������
HRESULT CSponer::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************

	//�e�N�X�`���̔��f
	BindTexture(m_pTextureSponer);

	return S_OK;
}

//�A�C�e���̏I������
void CSponer::Uninit(void)
{
	CObject2D::Uninit();
}

//�A�C�e���̍X�V����
void CSponer::Update()
{
	D3DXVECTOR3 SponerPos = GetPos();

	//�ʒu�̐ݒ�
	SetPosition(SponerPos);
	CObject2D::Update();
}

//�A�C�e���̕`�揈��
void CSponer::Draw()
{
	CObject2D::Draw();
}

//�A�C�e���̐���
CSponer *CSponer::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size)
{
	CSponer *pSponer = nullptr;

	//�N���X�̐���
	pSponer = new CSponer;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pSponer != nullptr)
	{
		//����������
		pSponer->Init();
		//�ݒ菈��
		pSponer->SetPosition(pos);
		pSponer->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pSponer;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CSponer::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�A�C�e���X�|�i�[.png",
		&m_pTextureSponer);

	return S_OK;
}

//�e�N�X�`���̔j��
void CSponer::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_pTextureSponer != nullptr)
	{
		m_pTextureSponer->Release();
		m_pTextureSponer = nullptr;
	}
}
