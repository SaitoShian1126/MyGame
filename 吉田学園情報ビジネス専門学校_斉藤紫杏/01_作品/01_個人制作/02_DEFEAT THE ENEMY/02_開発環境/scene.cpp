//********************************************
//
//	scene.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "scene.h"
#include "application.h"
#include "renderer.h"
#include "explosion.h"
#include "fade.h"
#include "bullet.h"
#include "hp.h"
#include "ui.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CScene::m_pTextureScene[2] = {};

//�G�̃R���X�g���N�^
CScene::CScene() : CObject2D(4)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_nUninitTimer = 0;
	m_flag = false;
}

//�G�̃f�X�g���N�^
CScene::~CScene()
{
	//���������Ȃ�
}

//�G�̏���������
HRESULT CScene::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_nUninitTimer = 0;
	m_flag = false;

	switch (m_nType)
	{
	case SCENETYPE_BOSS:
		//�e�N�X�`�����f
		BindTexture(m_pTextureScene[0]);
		break;
	case SCENETYPE_START:
		//�e�N�X�`�����f
		BindTexture(m_pTextureScene[1]);
		break;
	default:
		break;
	}

	return S_OK;
}

//�G�̏I������
void CScene::Uninit(void)
{
	CObject2D::Uninit();
}

//�G�̍X�V����
void CScene::Update()
{
	D3DXVECTOR3 ScenePos = GetPos();
	D3DXVECTOR3 SceneMove = GetMove();

	//�ʒu�X�V
	ScenePos.x += SceneMove.x;
	ScenePos.y += SceneMove.y;
	ScenePos.z += SceneMove.z;

	CObject2D::Update();

	if (m_nType == SCENETYPE_BOSS)
	{
		if (m_flag == false)
		{
			m_nUninitTimer = 400;
			m_flag = true;
		}
		SceneMove.x = -5.0f;
		SetMove(SceneMove);

		if (ScenePos.x <= 640.0f)
		{
			SceneMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			SetMove(SceneMove);
		}

		m_nUninitTimer--;
		if (m_nUninitTimer <= 0)
		{
			Uninit();
			//�{�X�̐���
			CEnemy::Create(D3DXVECTOR3(1050.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(BOSS_SIZE_X, BOSS_SIZE_Y, 0.0f), CEnemy::ENEMYTYPE_BOSS, 1100);
			//UI�̐���
			CUi::Create(D3DXVECTOR3(645.0f, 685.0f, 0.0f), D3DXVECTOR3(310.0f, 20.0f, 0.0f), CUi::UITYPE_LIFE);
			CBossHp::Create();
			return;
		}
	}
	if (m_nType == SCENETYPE_START)
	{
		if (m_flag == false)
		{
			m_nUninitTimer = 200;
			m_flag = true;
		}
		SceneMove.y = -5.0f;
		SetMove(SceneMove);
		if (ScenePos.y <= 360.0f)
		{
			SceneMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			SetMove(SceneMove);
		}
		m_nUninitTimer--;
		if (m_nUninitTimer <= 0)
		{
			SceneMove.y = -5.0f;
			SetMove(SceneMove);
			if (ScenePos.y <= -360.0f)
			{
				Uninit();
				return;
			}
		}
	}

	SetMove(SceneMove);
	SetPosition(ScenePos);
}

//�G�̕`�揈��
void CScene::Draw()
{
	CObject2D::Draw();
}

//�X�|�[���̐���
CScene *CScene::Create(const D3DXVECTOR3 &pos,D3DXVECTOR3 size, SCENETYPE type)
{
	CScene *pScene = nullptr;

	//�N���X�̐���
	pScene = new CScene;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pScene != nullptr)
	{
		pScene->SetSceneType(type);
		//����������
		pScene->Init();
		//�ݒ菈��
		pScene->SetPosition(pos);
		pScene->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pScene;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CScene::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�{�X�o��.png",
		&m_pTextureScene[0]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/start1.png",
		&m_pTextureScene[1]);

	return S_OK;
}

//�e�N�X�`���̔j��
void CScene::Unload(void)
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_pTextureScene[nCnt] != nullptr)
		{
			m_pTextureScene[nCnt]->Release();
			m_pTextureScene[nCnt] = nullptr;
		}
	}
}

//�V�[���̐ݒ�
void CScene::SetSceneType(SCENETYPE type)
{
	m_nType = type;
}
