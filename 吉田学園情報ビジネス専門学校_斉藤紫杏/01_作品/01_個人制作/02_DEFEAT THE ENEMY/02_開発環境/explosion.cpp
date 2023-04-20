//********************************************
//
//	explosion.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "explosion.h"
#include "application.h"
#include "renderer.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CExplosion::m_pTextureExplosion[2] = {};

//�����̃R���X�g���N�^
CExplosion::CExplosion()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_ExplosionPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�ʒu�̃N���A
	m_ExplosionCol = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	//�F�̃N���A
	m_nCounterAnimExplosion = 0;						//�J�E���g�A�j���[�V�����̃N���A
	m_nPatternAnimExplosion = 0;						//�p�^�[���A�j���[�V�����̃N���A
	m_nPatternAnimExplosionY = 0;
}

//�����̃f�X�g���N�^
CExplosion::~CExplosion()
{
	//���������Ȃ�
}

//�����̏���������
HRESULT CExplosion::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************
  	m_ExplosionPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�ʒu�̏�����
	m_nCounterAnimExplosion = 0;						//�J�E���g�A�j���[�V�����̏�����
	m_nPatternAnimExplosion = 0;						//�p�^�[���A�j���[�V�����̏�����
	m_nPatternAnimExplosionY = 0;

	//�F�̐ݒ�
	//SetColor(1.0f, 0.3f, 0.0f, 1.0f);

	switch (m_nType)
	{
	case EXPLOTIONTYPE_BAKUHATU:
		//�e�N�X�`�����f
		BindTexture(m_pTextureExplosion[0]);
		//�e�N�X�`���̐ݒ�
		SetTexture(8.0f, 0.0f, 2.0f, 0.0f);
		break;
	case EXPLOTIONTYPE_KOUGEKI:
		//�e�N�X�`�����f
		BindTexture(m_pTextureExplosion[1]);
		//�e�N�X�`���̐ݒ�
		SetTexture(6.0f, 0.0f, 1.0f, 0.0f);
		break;
	case EXPLOTIONTYPE_BOSS:
		//�e�N�X�`�����f
		BindTexture(m_pTextureExplosion[0]);
		//�e�N�X�`���̐ݒ�
		SetTexture(8.0f, 0.0f, 2.0f, 0.0f);
		break;
	default:
		break;
	}

	return S_OK;
}

//�����̏I������
void CExplosion::Uninit(void)
{
	//object2D�I�������֐��Ăяo��
	CObject2D::Uninit();
}

//�����̍X�V����
void CExplosion::Update(void)
{
	//�ʒu�̎擾
	D3DXVECTOR3 ExplosionPos = GetPos();

	//for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	//{
	//	//�I�u�W�F�N�g�̃|�C���^
	//	CObject *pObject;
	//	//�ǂ̃^�C�v���̏����|�C���^�ɑ��
	//	pObject = GetObjects(3, nCntType);
	//
	//	//null�`�F�b�N
	//	if (pObject != nullptr)
	//	{
	//		//**********************************************************
	//		//	�����ƃv���C���[�̓����蔻��
	//		//**********************************************************
	//		if (pObject->GetType() == TYPE_PLAYER && m_nType == 0)
	//		{
	//			//�v���C���[�̈ʒu
	//			D3DXVECTOR3 PlayerPos = pObject->GetPos();
	//			//�v���C���[�̃T�C�Y
	//			D3DXVECTOR3 PlayerSize = pObject->GetSize();
	//			//�v���C���[�̗̑�
	//			int nLife = pObject->GetLife();
	//
	//			//�v���C���[�̓����蔻��
	//			if (ExplosionPos.x + EXPLOSION_SIZE >= PlayerPos.x - PlayerSize.x
	//				&&ExplosionPos.x - EXPLOSION_SIZE <= PlayerPos.x + PlayerSize.x
	//				&&ExplosionPos.y + EXPLOSION_SIZE >= PlayerPos.y - PlayerSize.y
	//				&&ExplosionPos.y - EXPLOSION_SIZE <= PlayerPos.y + PlayerSize.y)
	//			{
	//				//�G�̗̑͂����炷
	//				nLife--;
	//				//�̗͂̕ۑ�
	//				pObject->SetLife(nLife);
	//				//�̗͂�0�ɂȂ�����
	//				if (nLife == 0)
	//				{
	//					pObject->Uninit();
	//				}
	//			}
	//		}
	//	}
	//}

	//*******************************************
	//	�����̃A�j���[�V����
	//*******************************************
	//object2D�̍X�V�����֐��Ăяo��
	CObject2D::Update();

	//�����̈ʒu
	SetPosition(ExplosionPos);

	if (m_nType == EXPLOTIONTYPE_BAKUHATU)
	{
		//�A�j���[�V�����J�E���^�[���C���N�������g
		m_nCounterAnimExplosion++;

		if (m_nCounterAnimExplosion % 5 == 0)
		{
			//�e�N�X�`���̐ݒ�
			SetTexture(8.0f, (float)m_nPatternAnimExplosion, 2.0f, (float)m_nPatternAnimExplosionY);

			//�A�j���[�V�����p�^�[���̃C���N������
			m_nPatternAnimExplosion++;
		}

		//�A�j���[�V�����p�^�[�����Ō�܂ōs������I��
		else if (m_nPatternAnimExplosion == 8.0f)
		{
			m_nPatternAnimExplosion = 0;
			m_nPatternAnimExplosionY++;
			m_nPatternAnimExplosion++;
			if (m_nPatternAnimExplosionY == 2.0f)
			{
				Uninit();	//�g�p����ĂȂ�
				return;
			}
		}
	}
	else if (m_nType == EXPLOTIONTYPE_KOUGEKI)
	{
		//�A�j���[�V�����J�E���^�[���C���N�������g
		m_nCounterAnimExplosion++;

		if (m_nCounterAnimExplosion % 5 == 0)
		{
			//�e�N�X�`���̐ݒ�
			SetTexture(6.0f, (float)m_nPatternAnimExplosion, 1.0f, 0.0f);

			//�A�j���[�V�����p�^�[���̃C���N������
			m_nPatternAnimExplosion++;
		}

		//�A�j���[�V�����p�^�[�����Ō�܂ōs������I��
		if (m_nPatternAnimExplosion == MAX_KOUGEKI_PATTERN)
		{
			Uninit();	//�g�p����ĂȂ�
			return;
		}
	}
	if (m_nType == EXPLOTIONTYPE_BOSS)
	{
		//�A�j���[�V�����J�E���^�[���C���N�������g
		m_nCounterAnimExplosion++;

		if (m_nCounterAnimExplosion % 5 == 0)
		{
			//�e�N�X�`���̐ݒ�
			SetTexture(8.0f, (float)m_nPatternAnimExplosion, 2.0f, (float)m_nPatternAnimExplosionY);

			//�A�j���[�V�����p�^�[���̃C���N������
			m_nPatternAnimExplosion++;
		}

		//�A�j���[�V�����p�^�[�����Ō�܂ōs������I��
		else if (m_nPatternAnimExplosion == 8.0f)
		{
			m_nPatternAnimExplosion = 0;
			m_nPatternAnimExplosionY++;
			m_nPatternAnimExplosion++;
			//if (m_nPatternAnimExplosionY == 2.0f)
			//{
			//	Uninit();	//�g�p����ĂȂ�
			//	return;
			//}
		}
	}
}

//�����̕`�揈��
void CExplosion::Draw(void)
{
	CObject2D::Draw();
}

//�����̐���
CExplosion *CExplosion::Create(const D3DXVECTOR3 &pos,D3DXVECTOR3 size,D3DXCOLOR col, EXPLOTIONTYPE nType)
{
	CExplosion *pExplosion = nullptr;

	//�e�̃C���X�^���X�̐���
	pExplosion = new CExplosion;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pExplosion != nullptr)
	{
		pExplosion->SetExplotionType(nType);
		//����������
		pExplosion->Init();
		//�ݒ菈��
		pExplosion->SetPosition(pos);
		pExplosion->SetSize(size);
		pExplosion->SetColor(col.r, col.g, col.b, col.a);
		pExplosion->SetType(TYPE_EXPLOSION);
	}
	else
	{
		assert(false);
	}

	return pExplosion;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CExplosion::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/����.png",
		&m_pTextureExplosion[0]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/����1.png",
		&m_pTextureExplosion[1]);

	return S_OK;
}

//�e�N�X�`���̔j��
void CExplosion::Unload(void)
{
	//�e�N�X�`���̔j��
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_pTextureExplosion[nCnt] != NULL)
		{					  
			m_pTextureExplosion[nCnt]->Release();
			m_pTextureExplosion[nCnt] = NULL;
		}
	}
}

//�����̃^�C�v�̐ݒ�
void CExplosion::SetExplotionType(EXPLOTIONTYPE type)
{
	m_nType = type;
}