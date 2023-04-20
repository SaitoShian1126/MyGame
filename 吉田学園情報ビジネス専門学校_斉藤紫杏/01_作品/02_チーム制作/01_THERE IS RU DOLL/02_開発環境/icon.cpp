//=============================================================================
//
// �r���{�[�h�ŃA�C�R���̕\�� [icon.cpp]
// Author : Tanaka Kouta
//
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "icon.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CIcon::CIcon(int nPriority) : 
	m_bDestroy(false),
	m_bScaling(false),
	m_bLimit(false),
	m_bFade(false)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CIcon::~CIcon()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CIcon::Init(void)
{
	CBillboard::SetCol(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f));
	m_beginScale = CBillboard::GetSize();

	//�e�N�X�`���̓ǂݍ���
	BindTexture(m_path);

	CBillboard::Init();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CIcon::Uninit(void)
{
	CBillboard::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CIcon::Update(void)
{
	CBillboard::Update();

	if (m_bScaling)
	{
		D3DXVECTOR3 scale = CBillboard::GetSize();

		scale.x += 0.5f;
		scale.y += 0.5f;

		if (m_bLimit)
		{
			if (scale.x >= m_beginScale.x + 15.0f && scale.y >= m_beginScale.y + 15.0f)
			{
				scale.x -= 10.5f;
				scale.y -= 10.5f;
			}
		}

		CBillboard::SetSize(scale);
	}

	if (m_bFade)
	{
		auto col = CBillboard::GetCol();

		col.a -= 0.05f;

		CBillboard::SetCol(col);

		if (col.a <= 0.0f)
		{
			CBillboard::Uninit();
			return;
		}
	}

	if (m_bDestroy)
	{
		CBillboard::Uninit();
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CIcon::Draw(void)
{
	CBillboard::Draw();
}

//=============================================================================
// ��������
//=============================================================================
CIcon *CIcon::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, std::string url, int nPriority)
{
	//�|�C���^�錾
	CIcon *pIcon = nullptr;

	pIcon = new CIcon(nPriority);

	if (pIcon != nullptr)
	{
		pIcon->SetPos(pos);
		pIcon->SetSize(size);
		pIcon->SetPath(url);
		pIcon->Init();
	}

	return pIcon;
}

void CIcon::SwapTexture(std::string url)
{
	//�e�N�X�`���̓ǂݍ���
	BindTexture(url);
}