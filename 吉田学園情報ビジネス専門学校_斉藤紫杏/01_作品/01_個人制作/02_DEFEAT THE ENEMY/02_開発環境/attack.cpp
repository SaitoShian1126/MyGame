//********************************************
//
//	attack.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include <time.h>
#include "attack.h"
#include "application.h"
#include "renderer.h" 
#include "player.h"
#include "effect.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CAttack::m_pTextureAttack = nullptr;

//�U���̃R���X�g���N�^
CAttack::CAttack()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_nTime = 0;
}

//�U���̃f�X�g���N�^
CAttack::~CAttack()
{
	//���������Ȃ�
}

//�U���̏���������
HRESULT CAttack::Init(void)
{
	//object2D�����������֐��Ăяo��
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_nTime = 0;

	//�e�N�X�`���̔��f
	BindTexture(m_pTextureAttack);

	return S_OK;
}

//�U���̏I������
void CAttack::Uninit(void)
{
	//object2D�I�������֐��Ăяo��
	CObject2D::Uninit();
}

//�U���̍X�V����
void CAttack::Update()
{
	//object2D�X�V�����֐��Ăяo��
	CObject2D::Update();

	D3DXVECTOR3 attackPos = GetPos();
	D3DXVECTOR3 attackMove = GetMove();

	//�G�t�F�N�g�̐���
	CEffect::Create(D3DXVECTOR3(attackPos), D3DXVECTOR3(20.0f, 20.0f, 0.0f), D3DXCOLOR(0.5f, 0.5f, 0.2f, 0.25f), 5);

	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//�I�u�W�F�N�g�̃|�C���^
		CObject *pObject;
		//�ǂ̃^�C�v���̏����|�C���^�ɑ��
		pObject = GetObjects(3, nCntType);

		//null�`�F�b�N
		if (pObject != nullptr)
		{
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//�v���C���[�̈ʒu
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				attackPos = D3DXVECTOR3(PlayerPos.x - 80.0f, PlayerPos.y - 80.0f, PlayerPos.z);
			}
		}
	}

	attackMove = attackPos;

	m_nTime--;
	if (m_nTime <= 0)
	{
		CBullet::Create(D3DXVECTOR3(attackPos), D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f), 0, 2, CBullet::BULLETTYPE_NOMAL);
	}
	if (m_nTime <= 0)
	{
		m_nTime = 15;
	}

	//�ʒu�̐ݒ�
	SetPosition(attackPos);
	SetMove(attackMove);
}

//�U���̕`�揈��
void CAttack::Draw()
{
	CObject2D::Draw();
}

//�U���̐���
CAttack *CAttack::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 move, D3DXVECTOR3 size)
{
	CAttack *pAttack = nullptr;

	//�N���X�̐���
	pAttack = new CAttack;				//2D�I�u�W�F�N�g�̃C���X�^���X����

										//null�`�F�b�N
	if (pAttack != nullptr)
	{
		//����������
		pAttack->Init();
		//�ݒ菈��
		pAttack->SetPosition(pos);
		pAttack->SetMove(move);
		pAttack->SetSize(size);
		pAttack->SetType(TYPE_ATTACK);
	}
	else
	{
		assert(false);
	}

	return pAttack;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CAttack::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/���@1.png",
		&m_pTextureAttack);

	return S_OK;
}

//�e�N�X�`���̔j��
void CAttack::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_pTextureAttack != nullptr)
	{
		m_pTextureAttack->Release();
		m_pTextureAttack = nullptr;
	}
}

//********************************************
//
//	attack2.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include <time.h>
#include "application.h"
#include "renderer.h" 
#include "player.h"
#include "effect.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CAttack2::m_pTextureAttack2 = nullptr;

//�U���̃R���X�g���N�^
CAttack2::CAttack2()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_nTime = 0;
}

//�U���̃f�X�g���N�^
CAttack2::~CAttack2()
{
	//���������Ȃ�
}

//�U���̏���������
HRESULT CAttack2::Init(void)
{
	//object2D�����������֐��Ăяo��
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_nTime = 0;

	//�e�N�X�`���̔��f
	BindTexture(m_pTextureAttack2);

	return S_OK;
}

//�U���̏I������
void CAttack2::Uninit(void)
{
	CObject2D::Uninit();
}

//�U���̍X�V����
void CAttack2::Update()
{
	D3DXVECTOR3 attackPos = GetPos();
	D3DXVECTOR3 attackMove = GetMove();

	//�G�t�F�N�g�̐���
	CEffect::Create(D3DXVECTOR3(attackPos), D3DXVECTOR3(20.0f, 20.0f, 0.0f), D3DXCOLOR(0.5f, 0.5f, 0.2f, 1.0f), 5);

	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//�I�u�W�F�N�g�̃|�C���^
		CObject *pObject;
		//�ǂ̃^�C�v���̏����|�C���^�ɑ��
		pObject = GetObjects(3, nCntType);

		//null�`�F�b�N
		if (pObject != nullptr)
		{
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//�v���C���[�̈ʒu
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				attackPos = D3DXVECTOR3(PlayerPos.x - 80.0f, PlayerPos.y + 80.0f, PlayerPos.z);
			}
		}
	}

	attackMove = attackPos;

	m_nTime--;
	if (m_nTime <= 0)
	{
		CBullet::Create(D3DXVECTOR3(attackPos), D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f), 0, 2, CBullet::BULLETTYPE_NOMAL);
	}
	if (m_nTime <= 0)
	{
		m_nTime = 15;
	}

	//�ʒu�̐ݒ�
	SetPosition(attackPos);
	SetMove(attackMove);
	CObject2D::Update();
}

//�U���̕`�揈��
void CAttack2::Draw()
{
	CObject2D::Draw();
}

//�U���̐���
CAttack2 *CAttack2::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 move, D3DXVECTOR3 size)
{
	CAttack2 *pAttack = nullptr;

	//�N���X�̐���
	pAttack = new CAttack2;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pAttack != nullptr)
	{
		//����������
		pAttack->Init();
		//�ݒ菈��
		pAttack->SetPosition(pos);
		pAttack->SetMove(move);
		pAttack->SetSize(size);
		pAttack->SetType(TYPE_ATTACK);
	}
	else
	{
		assert(false);
	}

	return pAttack;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CAttack2::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/���@1.png",
		&m_pTextureAttack2);

	return S_OK;
}

//�e�N�X�`���̔j��
void CAttack2::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_pTextureAttack2 != nullptr)
	{
		m_pTextureAttack2->Release();
		m_pTextureAttack2 = nullptr;
	}
}

