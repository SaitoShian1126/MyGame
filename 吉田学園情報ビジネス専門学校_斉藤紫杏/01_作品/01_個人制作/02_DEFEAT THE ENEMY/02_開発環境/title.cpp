//********************************************
//
//	title.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "title.h"
#include "application.h"
#include "renderer.h" 
#include "input.h"
#include "object2D.h"
#include "fade.h"
#include "bullet.h"
#include "sound.h"
#include "enter.h"

//�����̃R���X�g���N�^
CTitle::CTitle()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_SoundFlag = false;
}

//�����̃f�X�g���N�^
CTitle::~CTitle()
{
	//���������Ȃ�
}

//�����̏���������
HRESULT CTitle::Init(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/�^�C�g�����.png",
		&m_pTextureTitle);

	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_SoundFlag = false;
	m_flag = false;

	m_pObject = CObject2D::Create(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->SetSize(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->BindTexture(m_pTextureTitle);

	return S_OK;
}

//�����̏I������
void CTitle::Uninit(void)
{
	//�T�E���h�̒�~
	StopSound();
	CObject::Release();
}

//�����̍X�V����
void CTitle::Update()
{
	
	if (m_SoundFlag == false)
	{
		//�T�E���h�̍Đ�
		PlaySound(SOUND_LABEL_SOUND1);
		m_SoundFlag = true;
	}
	//�C���v�b�g�̃C���X�^���X����
	CInput *pInput = CApplication::GetInput();
	CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();
	if (m_pFade->GetFade() == CFade::FADETYPE_NONE && m_flag == false)
	{
		CEnter::Create(D3DXVECTOR3(640.0f, 550.0f, 0.0f), D3DXVECTOR3(250.0f, 75.0f, 0.0f));
		m_flag = true;
	}

	if (pInput->GetKeyboardTrigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE && CApplication::GetModeType() == CApplication::MODE_TITLE
		|| pInputJoyKey->GetJoypadPress(CJoyPad::JOYKEY_B) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE && CApplication::GetModeType() == CApplication::MODE_TITLE)
	{
		CFade::SetFade(CApplication::MODE_TUTORIAL);
		//�T�E���h�̍Đ�
		PlaySound(SOUND_LABEL_SE_BUTTON);
	}
}

//�����̕`�揈��
void CTitle::Draw()
{

}

//�����̐���
CTitle *CTitle::Create()
{
	CTitle *pTitle = nullptr;

	//�N���X�̐���
	pTitle = new CTitle;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pTitle != nullptr)
	{
		//����������
		pTitle->Init();
	}
	else
	{
		assert(false);
	}

	return pTitle;
}

//�F�̐ݒ�
void CTitle::SetColor(float Red, float Green, float Blue, float ��)
{
	VERTEX_2D*pVtx;				//���_���ւ̃|�C���^

	LPDIRECT3DVERTEXBUFFER9 Buffer = GetBuffer();

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	Buffer->Lock(0, 0, (void**)&pVtx, 0);

	// ���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(Red, Green, Blue, ��);
	pVtx[1].col = D3DXCOLOR(Red, Green, Blue, ��);
	pVtx[2].col = D3DXCOLOR(Red, Green, Blue, ��);
	pVtx[3].col = D3DXCOLOR(Red, Green, Blue, ��);

	//���_�o�b�t�@���A�����b�N����
	Buffer->Unlock();
}