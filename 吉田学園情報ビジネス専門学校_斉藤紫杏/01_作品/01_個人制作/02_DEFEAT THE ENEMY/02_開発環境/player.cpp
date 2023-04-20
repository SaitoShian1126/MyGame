//********************************************
//
//	player.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "player.h"
#include "renderer.h"
#include "application.h"
#include "bullet.h"
#include "effect.h"
#include "sound.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CPlayer::m_pTexturePlayer = nullptr;
int CPlayer::m_nLife = 0;
bool CPlayer::BulletFlag = false;

//�v���C���[�̃R���X�g���N�^
CPlayer::CPlayer()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_PlayerPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�v���C���[�̈ʒu���N���A
	m_nTime = 0;
	BulletFlag = false;
}

//�v���C���[�̃f�X�g���N�^
CPlayer::~CPlayer()
{
	//���������Ȃ�
}

//�v���C���[�̏���������
HRESULT CPlayer::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************BulletFlag
	m_PlayerPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�v���C���[�̈ʒu��������
	m_nTime = BULLET_TIME;
	BulletFlag = false;

	//�e�N�X�`�����f
	BindTexture(m_pTexturePlayer);

	return S_OK;
}

//�v���C���[�̏I������
void CPlayer::Uninit(void)
{
	//�T�E���h�̒�~
	StopSound();
	CObject2D::Uninit();
}

//�v���C���[�̍X�V����
void CPlayer::Update(void)
{
	//�C���v�b�g�̃C���X�^���X����
	CInput *pInput = CApplication::GetInput();
	CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();
	D3DXVECTOR3 PlayerPos = GetPos();

	//****************************************************
	//	�v���C���[�̍U������
	//****************************************************
	//space�L�[�������ꂽ
	if (pInput->GetKeyboardPress(DIK_SPACE) == true && BulletFlag == false || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_RBUTTON5) == true && BulletFlag == false)
	{//�e�̐���
		m_nTime--;
		if (m_nTime <= 0)
		{
			//�T�E���h�̍Đ�
			PlaySound(SOUND_LABEL_SE_SHOT);
			CBullet::Create(D3DXVECTOR3(PlayerPos.x, PlayerPos.y, PlayerPos.z), D3DXVECTOR3(15.0f,0.0f, 0.0f), D3DXVECTOR3(5.0f, 0.0f, 0.0f),0, 0,CBullet::BULLETTYPE_NOMAL);
		}
		if (m_nTime <= 0)
		{
			m_nTime = BULLET_TIME;
		}
	}
	//*******************************************************
	//	�e�̐؂�ւ�
	//*******************************************************
	if (pInput->GetKeyboardTrigger(DIK_C) == true && BulletFlag == false || pInputJoyKey->GetJoypadTrigger(CJoyPad::JOYKEY_B) == true && BulletFlag == false)
	{
		BulletFlag = true;
		//�T�E���h�̍Đ�
		PlaySound(SOUND_LABEL_SE_BULLET);
	}
	else if (pInput->GetKeyboardTrigger(DIK_C) == true && BulletFlag == true || pInputJoyKey->GetJoypadTrigger(CJoyPad::JOYKEY_B) == true && BulletFlag == true)
	{
		BulletFlag = false;
		//�T�E���h�̍Đ�
		PlaySound(SOUND_LABEL_SE_BULLET);
	}
	else if (pInput->GetKeyboardPress(DIK_SPACE) == true && BulletFlag == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_RBUTTON5) == true && BulletFlag == true)
	{//�e�̐���
		m_nTime--;
		if (m_nTime <= 0)
		{
			//�T�E���h�̍Đ�
			PlaySound(SOUND_LABEL_SE_SHOT);
			CBullet::Create(D3DXVECTOR3(PlayerPos.x, PlayerPos.y + 15.0f, PlayerPos.z), D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f),0, 0,CBullet::BULLETTYPE_NOMAL);
			CBullet::Create(D3DXVECTOR3(PlayerPos.x, PlayerPos.y - 15.0f, PlayerPos.z), D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f),0, 0, CBullet::BULLETTYPE_NOMAL);
		}
		if (m_nTime <= 0)
		{
			m_nTime = BULLET_TIME;
		}
	}

	//*****************************************************
	//	�v���C���[�̈ړ�����
	//****************************************************
	//A�L�[�������ꂽ
	if (pInput->GetKeyboardPress(DIK_A) == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_LEFT) == true)
	{
		//�G�t�F�N�g�̐���
		CEffect::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 0.5f, 0.25f), 7);
		m_PlayerPos.x += sinf(-D3DX_PI * 0.5f) * 1.0f;
	}

	//D�L�[�������ꂽ
	if (pInput->GetKeyboardPress(DIK_D) == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_RIGHT) == true)
	{
		//�G�t�F�N�g�̐���
		CEffect::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 0.5f, 0.25f), 7);
		m_PlayerPos.x -= sinf(-D3DX_PI * 0.5f) * 1.0f;
	}

	//w�L�[�������ꂽ
	if (pInput->GetKeyboardPress(DIK_W) == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_UP) == true)
	{
		//�G�t�F�N�g�̐���
		CEffect::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 0.5f, 0.25f), 7);
		m_PlayerPos.y += sinf(-D3DX_PI * 0.5f) * 1.0f;
	}

	//s�L�[�������ꂽ
	if (pInput->GetKeyboardPress(DIK_S) == true || pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_DOWN) == true)
	{
		//�G�t�F�N�g�̐���
		CEffect::Create(D3DXVECTOR3(PlayerPos), D3DXVECTOR3(25.0f, 25.0f, 0.0f), D3DXCOLOR(0.1f, 0.5f, 0.5f, 0.25f), 7);
		m_PlayerPos.y -= sinf(-D3DX_PI * 0.5f) * 1.0f;
	}

	//*********************************************
	//	�v���C���[�̈ړ��͈͐���
	//*********************************************
	//���͈̔�
	if (PlayerPos.x < 0.0f + PLAYER_SIZE_X)
	{
		PlayerPos.x = 0.0f + PLAYER_SIZE_X;
	}
	//�E�͈̔�
	if (PlayerPos.x > SCREEN_WIDTH - PLAYER_SIZE_X)
	{
		PlayerPos.x = SCREEN_WIDTH - PLAYER_SIZE_X;
	}
	//��͈̔�
	if (PlayerPos.y < 0.0f + PLAYER_SIZE_X / 2)
	{
		PlayerPos.y = 0.0f + PLAYER_SIZE_X / 2;
	}
	//���͈̔�
	if (PlayerPos.y > SCREEN_HEIGHT - PLAYER_SIZE_X / 2)
	{
		PlayerPos.y = SCREEN_HEIGHT - PLAYER_SIZE_X / 2;
	}

	//�ʒu���X�V
	PlayerPos.x += m_PlayerPos.x;
	PlayerPos.y += m_PlayerPos.y;
	PlayerPos.z += m_PlayerPos.z;

	//�ړ��ʌ���
	m_PlayerPos.x += (0.0f - m_PlayerPos.x) * 0.1f;
	m_PlayerPos.y += (0.0f - m_PlayerPos.y) * 0.1f;
	m_PlayerPos.z += (0.0f - m_PlayerPos.z) * 0.1f;

	SetPosition(PlayerPos);
	CObject2D::Update();
}

//�v���C���[�̕`�揈��
void CPlayer::Draw(void)
{
	CObject2D::Draw();
}

//����
CPlayer *CPlayer::Create(int nLife)
{
	CPlayer *pPlayer = nullptr;

	//�N���X�̐���
	pPlayer = new CPlayer;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pPlayer != nullptr)
	{
		//����������
		pPlayer->Init();
		//�ݒ菈��
		pPlayer->SetPosition(D3DXVECTOR3(200.0f,360.0f,0.0f));
		pPlayer->SetSize(D3DXVECTOR3(50.0f, 35.0f, 0.0f));
		pPlayer->SetType(TYPE_PLAYER);
		pPlayer->SetLife(nLife);
	}
	else
	{
		assert(false);
	}
	return pPlayer;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CPlayer::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/player.png",
		&m_pTexturePlayer);

	return S_OK;
}

//�e�N�X�`���̔j��
void CPlayer::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_pTexturePlayer != nullptr)
	{
		m_pTexturePlayer->Release();
		m_pTexturePlayer = nullptr;
	}
}

//�v���C���[�̗̑͂̐ݒ菈��
void CPlayer::SetLife(int nLife)
{
	m_nLife = nLife;
}