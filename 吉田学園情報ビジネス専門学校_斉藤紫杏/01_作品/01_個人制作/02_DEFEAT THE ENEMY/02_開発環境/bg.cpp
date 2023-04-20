//********************************************
//
//	bg.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include <assert.h>
#include "bg.h"
#include "renderer.h"
#include "object.h"
#include "application.h"
#include "input.h"
#include "bullet.h"

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CBg::m_pTexture = {};

//�I�u�W�F�N�g�̃R���X�g���N�^
CBg::CBg() : CObject(0)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_pVtxBuff = nullptr;						//�o�b�t�@�̃N���A
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�ʒu�̃N���A
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�ړ��̃N���A
}

//�I�u�W�F�N�g�̃f�X�g���N�^
CBg::~CBg()
{
	//���������Ȃ�
}

//�I�u�W�F�N�g(�|���S��)�̏���������
HRESULT CBg::Init(void)
{
	//********************************
	//�����o�ϐ��̏�����
	//********************************
	m_pVtxBuff = nullptr;											//�o�b�t�@�̏�����
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);							//�ʒu�̏�����
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);							//�ړ��̏�����

	m_fPosTexV = 0.0f;												//�e�N�X�`�����W�̊J�n�ʒu(V�l)
	
	m_fPosTexV;

	//�e�N�X�`�����f
	BindTexture(m_pTexture);
	
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_����ݒ�
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0);

	// rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// ���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(m_fPosTexV, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(m_fPosTexV + 1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(m_fPosTexV, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(m_fPosTexV + 1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//�I�u�W�F�N�g(�|���S��)�̏I������
void CBg::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//�j������
	Release();
}

//�I�u�W�F�N�g(�|���S��)�̍X�V����
void CBg::Update(void)
{
	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0);

	m_fPosTexV += 0.002f;

	//���_���W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(m_fPosTexV, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(m_fPosTexV + 1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(m_fPosTexV, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(m_fPosTexV + 1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//�I�u�W�F�N�g(�|���S��)�̕`�揈��
void CBg::Draw(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	// �|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,									//���_���̐擪�A�h���X
		2);											//�v���~�e�B�u�̐�
	//�e�N�X�`���̉���
	pDevice->SetTexture(0, NULL);
}

//����
CBg *CBg::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size)
{
	CBg *pBg = nullptr;

	//2D�I�u�W�F�N�g�N���X�̐���
	pBg = new CBg;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pBg != nullptr)
	{
		//����������
		pBg->Init();
		//�ݒ菈��
		pBg->SetPosition(pos);
		pBg->SetSize(size);
	}
	else
	{
		assert(false);
	}
	return pBg;
}

//�e�N�X�`���ǂݍ���
HRESULT CBg::Load(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/bg108.png",
		&m_pTexture);

	return S_OK;
}

//�e�N�X�`���j��
void CBg::Unload(void)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}
}

//�|���S���̃T�C�Y�̐ݒ菈��
void CBg::SetSize(D3DXVECTOR3 size)
{
	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	m_size = size;

	m_fLength = sqrtf(((m_size.x * m_size.x) + (m_size.y * m_size.y))) / 2;	//�g��k���̃X�P�[���̏�����
	m_fAngle = atan2f(m_size.y, m_size.x);									//�p�x�̏�����

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_���̍X�V
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//�e�N�X�`�����f
void CBg::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}