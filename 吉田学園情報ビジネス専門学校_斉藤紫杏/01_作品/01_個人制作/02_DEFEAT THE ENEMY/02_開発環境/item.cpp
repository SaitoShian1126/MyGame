//********************************************
//
//	item.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include <time.h>
#include "item.h"
#include "application.h"
#include "renderer.h" 
#include "bullet.h"
#include "attack.h"
#include "game.h"
#include "sound.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CItem::m_pTextureItem[3] = {};
int CItem::m_AttackCount = 0;

//�A�C�e���̃R���X�g���N�^
CItem::CItem() : CObject2D(3)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_ItemMoveTimeCount = 0;
	m_nItemMoveTime = 0;
	m_AttackItemUninitCount = 0;
	m_flag = true;
}

//�A�C�e���̃f�X�g���N�^
CItem::~CItem()
{
	//���������Ȃ�
}

//�A�C�e���̏���������
HRESULT CItem::Init(void)
{
	CObject2D::Init();

	//����
	srand((unsigned int)time(NULL));	//�N�����Ɉ�񂾂��s�����ߏ������ɏ���	

	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_ItemMoveTimeCount = 100;
	m_nItemMoveTime = 30;
	m_AttackItemUninitCount = 500;
	m_flag = true; 

	switch (m_nType)
	{
	case ITEMTYPE_SCOREUP:
		//�e�N�X�`�����f
		BindTexture(m_pTextureItem[0]);
		break;
	case ITEMTYPE_LIFEUP:
		//�e�N�X�`�����f
		BindTexture(m_pTextureItem[1]);
		break;
	case ITEMTYPE_ATTACKUP:
		//�e�N�X�`�����f
		BindTexture(m_pTextureItem[2]);
		break;
	default:
		break;
	}

	return S_OK;
}

//�A�C�e���̏I������
void CItem::Uninit(void)
{
	CObject2D::Uninit();
}

//�A�C�e���̍X�V����
void CItem::Update()
{
	D3DXVECTOR3 ItemPos = GetPos();
	D3DXVECTOR3 ItemMove = GetMove();
	D3DXVECTOR3 ItemSize = GetSize();

	//�ʒu�̐ݒ�
	SetPosition(ItemPos);
	CObject2D::Update();

	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//�I�u�W�F�N�g�̃|�C���^
		CObject *pObject;
		//�ǂ̃^�C�v���̏����|�C���^�ɑ��
		pObject = GetObjects(3, nCntType);

		//null�`�F�b�N
		if (pObject != nullptr)
		{
			//**********************************************************
			// �A�C�e���ƃv���C���[�̓����蔻��
			//**********************************************************
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//�v���C���[�̈ʒu
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				//�v���C���[�̈ړ�
				D3DXVECTOR3 PlayerMove = pObject->GetMove();
				//�v���C���[�̃T�C�Y
				D3DXVECTOR3 PlayerSize = pObject->GetSize();
				//�v���C���[�̗̑�
				int nLife = pObject->GetLife();

				//�v���C���[�̓����蔻��
				if (ItemPos.x + ItemSize.x >= PlayerPos.x - PlayerSize.x
					&&ItemPos.x - ItemSize.x <= PlayerPos.x + PlayerSize.x
					&&ItemPos.y + ItemSize.y >= PlayerPos.y - PlayerSize.y
					&&ItemPos.y - ItemSize.y <= PlayerPos.y + PlayerSize.y)
				{
					if (m_nType == ITEMTYPE_SCOREUP)
					{
						//�X�R�A�̉��Z
						CGame::GetScore()->AddScore(2500);
						//�T�E���h�̍Đ�
						PlaySound(SOUND_LABEL_SE_SCORE);
					}
					else if (m_nType == ITEMTYPE_LIFEUP)
					{
						//�v���C���[�̗̑̓A�b�v
						nLife++;
						//�v���C���[�̗̑͂̕ۑ�
						pObject->SetLife(nLife);
						//�T�E���h�̍Đ�
						PlaySound(SOUND_LABEL_SE_LIFE);
					}
					else if (m_nType == ITEMTYPE_ATTACKUP)
					{
						CAttack::Create(D3DXVECTOR3(PlayerPos.x - 80.0f, PlayerPos.y - 80.0f, PlayerPos.z), D3DXVECTOR3(PlayerMove.x, PlayerMove.y, PlayerMove.z), D3DXVECTOR3(20.0f, 20.0f, 0.0f));
						CAttack2::Create(D3DXVECTOR3(PlayerPos.x - 80.0f, PlayerPos.y + 80.0f, PlayerPos.z), D3DXVECTOR3(PlayerMove.x, PlayerMove.y, PlayerMove.z), D3DXVECTOR3(20.0f, 20.0f, 0.0f));
						m_AttackCount++;
						//�T�E���h�̍Đ�
						PlaySound(SOUND_LABEL_SE_ATTACK);
					}
					//�A�C�e���̍폜
					Uninit();
					return;
				}
			}
		}
	}

	//�v���C���[�����񂾂�G�̏o���J�E���g������������
	if (CEnemy::GetPlayerDeathFlag() == true || CBullet::GetPlayerGameClear() == true)
	{
		m_AttackCount = 0;
		m_AttackItemUninitCount = 500;
	}

	if (m_nType == ITEMTYPE_ATTACKUP)
	{
		m_AttackItemUninitCount--;
		if (m_AttackItemUninitCount <= 0)
		{
			//�A�C�e���̍폜
			Uninit();
			return;
		}
	}

	//*******************************************
	//	�A�C�e���̈ړ�
	//*******************************************
	m_ItemMoveTimeCount--;
	if (m_ItemMoveTimeCount >= 0)
	{
		ItemMove.y = 3.0f;
		//�ʒu�ݒ�
		SetMove(ItemMove);
	}
	if (m_ItemMoveTimeCount <= 0)
	{
		m_nItemMoveTime--;
		if (m_nItemMoveTime <= 0)
		{
			m_nRand = rand() % 4 + 1;	//0�`9�̃����_���̐������o�������Ƃ���%10������	1�`6���o�������Ƃ���% 6 + 1�ɂȂ�
			m_flag = false;
		}
		if (m_nItemMoveTime <= 0)
		{
			m_nItemMoveTime = 30;
		}

		if (m_nRand == 1 && m_flag == false)
		{
			ItemMove.x = -3.0f;
			//�ʒu�ݒ�
			SetMove(ItemMove);
		}
		else if (m_nRand == 2 && m_flag == false)
		{
			ItemMove.y = 3.0f;
			//�ʒu�ݒ�
			SetMove(ItemMove);
		}
		else if (m_nRand == 3 && m_flag == false)
		{
			ItemMove.y = -3.0f;
			//�ʒu�ݒ�
			SetMove(ItemMove);
		}

		else if (m_nRand == 4 && m_flag == false)
		{
			ItemMove.x = 3.0f;
			//�ʒu�ݒ�
			SetMove(ItemMove);
		}

		//*********************************************
		//	�G�̈ړ��͈͐���
		//*********************************************
		//���͈̔�
		if (ItemPos.x < 0.0f + 20.0f)
		{
			ItemPos.x = 0.0f + 20.0f;
		}
		//�E�͈̔�
		if (ItemPos.x > SCREEN_WIDTH - 20.0f)
		{
			ItemPos.x = SCREEN_WIDTH - 20.0f;
		}
		//��͈̔�
		if (ItemPos.y < 0.0f + 20.0f / 2)
		{
			ItemPos.y = 0.0f + 20.0f / 2;
		}
		//���͈̔�
		if (ItemPos.y > SCREEN_HEIGHT - 20.0f / 2)
		{
			ItemPos.y = SCREEN_HEIGHT - 20.0f / 2;
		}
	}

	//�ʒu�X�V
	ItemPos.x += ItemMove.x;
	ItemPos.y += ItemMove.y;
	ItemPos.z += ItemMove.z;

	//�ړ��ʌ���
	ItemPos.x += (0.0f - ItemMove.x) * 0.1f;
	ItemPos.y += (0.0f - ItemMove.y) * 0.1f;
	ItemPos.z += (0.0f - ItemMove.z) * 0.1f;

	//�ʒu�̐ݒ�
	SetPosition(ItemPos);
	SetMove(ItemMove);
}

//�A�C�e���̕`�揈��
void CItem::Draw()
{
	CObject2D::Draw();
}

//�A�C�e���̐���
CItem *CItem::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, ITEMTYPE type)
{
	CItem *pitem = nullptr;

	//�N���X�̐���
	pitem = new CItem;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pitem != nullptr)
	{
		//����������
		pitem->SetItemType(type);
		pitem->Init();
		//�ݒ菈��
		pitem->SetPosition(pos);
		pitem->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pitem;
}

//�A�C�e���̎�ނ̐ݒ�
void CItem::SetItemType(ITEMTYPE type)
{
	m_nType = type;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CItem::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�X�R�A�A�C�e��.png",
		&m_pTextureItem[0]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�̗̓A�C�e��.png",
		&m_pTextureItem[1]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�U���A�C�e��.png",
		&m_pTextureItem[2]);

	return S_OK;
}

//�e�N�X�`���̔j��
void CItem::Unload(void)
{
	for (int nCnt = 0; nCnt < 3; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (m_pTextureItem[nCnt] != nullptr)
		{
			m_pTextureItem[nCnt]->Release();
			m_pTextureItem[nCnt] = nullptr;
		}
	}
}
