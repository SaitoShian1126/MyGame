//=============================================================================
//
// �J�E���g�_�E������ [countdown.cpp]
// Author : KADO TAKUMA
//
//=============================================================================
#include "countdown.h"
#include "application.h"
#include "renderer.h"
#include "sound.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
LPDIRECT3DTEXTURE9 CCountDown::m_pTexture[4] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCountDown::CCountDown(int nPriority) :
	CObject2D(nPriority)
{
	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_COUNTDOWN);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCountDown::~CCountDown()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCountDown::Init(void)
{
	//�I�u�W�F�N�g�̏���������
	CObject2D::Init();

	//���_�J���[�̐ݒ�
	CObject2D::SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	//���_�T�C�Y�̐ݒ�
	CObject2D::SetSize(D3DXVECTOR3(COUNTDOWN_WIDTH, COUNTDOWN_HEIGHT, 0.0f));

	//�h���̃e�N�X�`���|�C���^��e�̃e�N�X�`���|�C���^�ɑ�����鏈��
	BindTexture("COUNTDOWN_3");

	m_pObject = CObject2D::Create("COUNT_LOCUS", D3DXVECTOR3(640.0f, 360.0f, 0.0f), GetSize(), CObject::PRIORITY_LEVEL3);
	m_pObject->SetCol(D3DXCOLOR(1.0f,1.0f,1.0f,0.7f));
	m_pObject->SetRotate(true, 475);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCountDown::Uninit(void)
{
	//�I�u�W�F�N�g�̏I������
	CObject2D::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CCountDown::Update(void)
{
	auto col = CObject2D::GetCol();
	auto scale = CObject2D::GetSize();

	//�J�E���^�[���Z
	m_nCounter++;

	if (m_nCounter >= 220)
	{
		col.a -= 0.05f;
		scale.x += 25.0f;
		scale.y += 25.0f;
	}

	//�J�E���g�_�E���ɍ��킹�ĉ摜�ύX
	if (m_nCounter == 60)
	{
		//�h���̃e�N�X�`���|�C���^��e�̃e�N�X�`���|�C���^�ɑ�����鏈��
		BindTexture("COUNTDOWN_2");
	}
	else if (m_nCounter == 120)
	{
		//�h���̃e�N�X�`���|�C���^��e�̃e�N�X�`���|�C���^�ɑ�����鏈��
		BindTexture("COUNTDOWN_1");
	}
	else if (m_nCounter == 180)
	{
		//�h���̃e�N�X�`���|�C���^��e�̃e�N�X�`���|�C���^�ɑ�����鏈��
		BindTexture("COUNTDOWN_START");
	}
	else if (m_nCounter == 240)
	{
		//�I������
		if (m_pObject != nullptr)
		{
			m_pObject->Uninit();
		}

		Uninit();
		return;
	}

	//�I�u�W�F�N�g�̍X�V����
	CObject2D::Update();
	CObject2D::SetCol(col);
	CObject2D::SetSize(scale);
}

//=============================================================================
// �`�揈��
//=============================================================================
void CCountDown::Draw(void)
{
	//�I�u�W�F�N�g�̕`�揈��
	CObject2D::Draw();
}

//=============================================================================
// ��������
//=============================================================================
CCountDown * CCountDown::Create(D3DXVECTOR3 pos)
{
	//�|�C���^�錾
	CCountDown *pCountDown;

	//�C���X�^���X����
	pCountDown = new CCountDown;

	if (pCountDown != nullptr)
	{//�|�C���^�����݂�������s
		pCountDown->Init();
		pCountDown->SetPos(pos);
	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	return pCountDown;
}

//=============================================================================
// �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CCountDown::Load(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���*
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/CountDown_3.png",
		&m_pTexture[COUNTDOWN_3]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/CountDown_2.png",
		&m_pTexture[COUNTDOWN_2]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/CountDown_1.png",
		&m_pTexture[COUNTDOWN_1]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/CountDown_0.png",
		&m_pTexture[COUNTDOWN_START]);

	return S_OK;
}

//=============================================================================
// �e�N�X�`���̔j��
//=============================================================================
void CCountDown::UnLoad(void)
{
	//�e�N�X�`���̔j��
	for (int nCnt = 0; nCnt < COUNTDOWN_TEXTURE; nCnt++)
	{
		if (m_pTexture[nCnt] != NULL)
		{
			m_pTexture[nCnt]->Release();
			m_pTexture[nCnt] = NULL;
		}
	}
}
