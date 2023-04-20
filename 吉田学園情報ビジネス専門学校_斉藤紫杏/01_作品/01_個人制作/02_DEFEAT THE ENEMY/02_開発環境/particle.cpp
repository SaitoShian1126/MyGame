//********************************************
//
//	particle.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
//#include <time.h>
#include <assert.h>
#include "particle.h"
#include "application.h"
#include "renderer.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CParticle::m_pTextureParticle = nullptr;
D3DXVECTOR3 CParticle::m_nMove = {};

//�p�[�e�B�N���̃R���X�g���N�^
CParticle::CParticle()
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_nLife = 0;
	m_nCol = {};
	m_nMove = {};
}

//�p�[�e�B�N���̃f�X�g���N�^
CParticle::~CParticle()
{
	//���������Ȃ�
}

//�p�[�e�B�N���̏���������
HRESULT CParticle::Init(void)
{
	//����
	//srand((unsigned int)time(NULL));	//�N�����Ɉ�񂾂��s�����ߏ������ɏ���	

	CObject2D::Init();

	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_nLife = 0;
	m_nCol = {};
	m_nMove = {};

	//�e�N�X�`�����f
	BindTexture(m_pTextureParticle);

	return S_OK;
}

//�p�[�e�B�N���̏I������
void CParticle::Uninit(void)
{
	CObject2D::Uninit();
}

//�p�[�e�B�N���̍X�V����
void CParticle::Update(void)
{
	CObject2D::Update();

	//����
	m_nLife--;

	m_nLife = ((rand() % 5));

	D3DXVECTOR3 ParticleSize = GetSize();

	ParticleSize.x = MAX_PARTICLESIZE;
	ParticleSize.y = MAX_PARTICLESIZE;

	ParticleSize.x--;
	ParticleSize.y--;
	ParticleSize.x -= 0.05f;
	ParticleSize.y -= 0.05f;

	if (ParticleSize.x <= 0)
	{
		ParticleSize.x = 0;
	}
	if (ParticleSize.y <= 0)
	{
		ParticleSize.y = 0;
	}
	if (m_nLife <= 0.0f)
	{
		Uninit();
		return;
	}

	//pos���
	D3DXVECTOR3 ParticlePos = GetPos();
	D3DXVECTOR3 ParticleMove = GetMove();

	//�ړ�����
	ParticleMove.x = cosf((float)(rand() % 360) / 100) * ((float)(rand() % 10) + 1);
	ParticleMove.y = sinf((float)(rand() % 360) / 100) * ((float)(rand() % 10) + 1);

	SetMove(D3DXVECTOR3(ParticleMove));
	SetPosition(D3DXVECTOR3(ParticlePos));
	SetSize(D3DXVECTOR3(ParticleSize));
}

//�p�[�e�B�N���̕`�揈��
void CParticle::Draw(void)
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

//�p�[�e�B�N���̐���
CParticle *CParticle::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, int nLife)
{
	CParticle *pParticle = nullptr;

	//�N���X�̐���
	pParticle = new CParticle;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pParticle != nullptr)
	{
		//����������
		pParticle->Init();
		//�ݒ菈��
		pParticle->SetPosition(pos);
		pParticle->SetSize(size);
		pParticle->SetLife(nLife);
		pParticle->SetColor(col.r, col.g, col.b, col.a);
	}
	else
	{
		assert(false);
	}

	return pParticle;
}

//�e�N�X�`���̓ǂݍ���
HRESULT CParticle::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/effect000.jpg",
		&m_pTextureParticle);

	return S_OK;
}

//�e�N�X�`���̔j��
void CParticle::Unload(void)
{
	//�e�N�X�`���̔j��
	if (m_pTextureParticle != nullptr)
	{
		m_pTextureParticle->Release();
		m_pTextureParticle = nullptr;
	}
}

//���C�t�̐ݒ�
void CParticle::SetLife(int nLife)
{
	m_nLife = nLife;
}