//********************************************
//
//	effect.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "effect.h"
#include "application.h"
#include "renderer.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CEffect::m_pTextureEffect = nullptr;

//�G�t�F�N�g�̃R���X�g���N�^
CEffect::CEffect() : CObject2D(2)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_nLife = 0;
	m_nCol = {};
}

//�G�t�F�N�g�̃f�X�g���N�^
CEffect::~CEffect()
{
	//���������Ȃ�
}

//�G�t�F�N�g�̏���������
HRESULT CEffect::Init(void)
{
	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_nLife = 0;
	m_nCol = {};

	//�e�N�X�`�����f
	BindTexture(m_pTextureEffect);

	return S_OK;
}

//�G�t�F�N�g�̏I������
void CEffect::Uninit(void)
{
	CObject2D::Uninit();
}

//�G�t�F�N�g�̍X�V����
void CEffect::Update(void)
{
	D3DXVECTOR3 EffectSize = GetSize();
	EffectSize.x -= 1.5f;
	EffectSize.y -= 1.5f;
	SetSize(EffectSize);

	m_nLife--;
	if (m_nLife <= 0)
	{
		Uninit();
	}
}

//�G�t�F�N�g�̕`�揈��
void CEffect::Draw(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//**********************************
	// ���u�����f�B���O�����Z�����ɐݒ�
	//**********************************
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CObject2D::Draw();

	//***************************
	//���u�����f�B���O�����ɖ߂�
	//***************************
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//�G�t�F�N�g�̐���
CEffect *CEffect::Create(D3DXVECTOR3 pos,D3DXVECTOR3 size,D3DXCOLOR col,int nLife)
{
	CEffect *pEffect= nullptr;

	//�N���X�̐���
	pEffect = new CEffect;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pEffect != nullptr)
	{
		//����������
		pEffect->Init();
		//�ݒ菈��
		pEffect->SetPosition(pos);
		pEffect->SetSize(size);
		pEffect->SetLife(nLife);
		pEffect->SetColor(col.r, col.g, col.b, col.a);
	}
	else
	{
		assert(false);
	}

	return pEffect;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CEffect::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/effect000.jpg",
		&m_pTextureEffect);

	return S_OK;
}

//�e�N�X�`���̔j��
void CEffect::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_pTextureEffect != nullptr)
	{
		m_pTextureEffect->Release();
		m_pTextureEffect = nullptr;
	}
}

//���C�t�̐ݒ�
void CEffect::SetLife(int nLife)
{
	m_nLife = nLife;
}