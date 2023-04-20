//********************************************
//
//	spawn.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "spawn.h"
#include "application.h"
#include "renderer.h"
#include "explosion.h"
#include "fade.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CSpawn::m_pTextureSpawn[3] = {};

//�G�̃R���X�g���N�^
CSpawn::CSpawn()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_nUninitTimer = 0;
	m_nTimer = 0;
}

//�G�̃f�X�g���N�^
CSpawn::~CSpawn()
{
	//���������Ȃ�
}

//�G�̏���������
HRESULT CSpawn::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************m_nLife
	m_nUninitTimer = 500;
	m_nTimer = 0;

	switch (m_nType)
	{
	case SPAWNTYPE_MAGICCIRCLE1:
		//�e�N�X�`�����f
		BindTexture(m_pTextureSpawn[0]);
		break;
	case SPAWNTYPE_MAGICCIRCLE2:
		//�e�N�X�`�����f
		BindTexture(m_pTextureSpawn[1]);
		break;
	case SPAWNTYPE_MAGICCIRCLE3:
		//�e�N�X�`�����f
		BindTexture(m_pTextureSpawn[2]);
		break;
	default:
		break;
	}
	
	return S_OK;
}

//�G�̏I������
void CSpawn::Uninit(void)
{
	CObject2D::Uninit();
}

//�G�̍X�V����
void CSpawn::Update()
{
	CObject2D::Update();
	D3DXVECTOR3 SpawnRot = GetRot();
	D3DXVECTOR3 SpawnPos = GetPos();
	
	//*************************************
	//	��]
	//*************************************
	if (m_nType == SPAWNTYPE_MAGICCIRCLE2)
	{
		//��]��
		SpawnRot.z += 0.05f;
		SetRot(SpawnRot);
	}
	if (m_nType == SPAWNTYPE_MAGICCIRCLE1)
	{
		//��]��
		SpawnRot.z -= 0.025f;
		SetRot(SpawnRot);
	}

	m_nUninitTimer--;
	if (m_nUninitTimer <= 0)
	{
		//����
		CExplosion::Create(D3DXVECTOR3(SpawnPos), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 0.8f, 0.8f, 1.0f), CExplosion::EXPLOTIONTYPE_BAKUHATU);
		Uninit();
		return;
	}
}

//�G�̕`�揈��
void CSpawn::Draw()
{
	CObject2D::Draw();
}

//�X�|�[���̐���
CSpawn *CSpawn::Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move,D3DXVECTOR3 size, SPAWNTYPE nType,int nLife)
{
	CSpawn *pSpawn = nullptr;

	//�N���X�̐���
	pSpawn = new CSpawn;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pSpawn != nullptr)
	{
		pSpawn->SetSpawnType(nType);
		//����������
		pSpawn->Init();
		//�ݒ菈��
		pSpawn->SetPosition(pos);
		pSpawn->SetMove(move);
		pSpawn->SetSize(size);
		pSpawn->SetLife(nLife);
		pSpawn->SetType(TYPE_SPAWN);
	}
	else
	{
		assert(false);
	}

	return pSpawn;
}

//�X�|�[���̃^�C�v
void CSpawn::SetSpawnType(SPAWNTYPE type)
{
	m_nType = type;
}

//�X�|�[���̐ݒ�
void CSpawn::SetLife(int nLife)
{
	m_nLife = nLife;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CSpawn::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/MagicCircle1.png",
		&m_pTextureSpawn[0]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/MagicCircle6.png",
		&m_pTextureSpawn[1]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/MagicCircle4.png",
		&m_pTextureSpawn[2]);

	return S_OK;
}

//�e�N�X�`���̔j��
void CSpawn::Unload(void)
{
	//�e�N�X�`���̔j��
	for (int nCnt = 0; nCnt < 3; nCnt++)
	{
		if (m_pTextureSpawn[nCnt] != nullptr)
		{
			m_pTextureSpawn[nCnt]->Release();
			m_pTextureSpawn[nCnt] = nullptr;
		}
	}
}