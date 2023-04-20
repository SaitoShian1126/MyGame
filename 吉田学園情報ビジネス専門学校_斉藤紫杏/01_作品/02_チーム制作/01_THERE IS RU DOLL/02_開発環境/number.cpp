#include "object2d.h"
#include "number.h"
#include "renderer.h"
#include "application.h"
#include <assert.h>

CNumber::CNumber() : CObject2D(CObject::PRIORITY_LEVEL4)
{

}

CNumber::~CNumber()
{

}

//=============================================================================
// �|���S���̏�����.
//=============================================================================
HRESULT CNumber::Init()
{
	CObject2D::Init();

	//���_�J���[�̐ݒ�
	CObject2D::SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	//�h���̃e�N�X�`���|�C���^��e�̃e�N�X�`���|�C���^�ɑ�����鏈��
	BindTexture("NUMBER");
	return S_OK;
}

void CNumber::Draw()
{
	//�I�u�W�F�N�g�̕`�揈��
	CObject2D::Draw();
}

//=============================================================================
//���������̐���
//=============================================================================
CNumber *CNumber::Create(const D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CNumber *pNumber = nullptr;

	pNumber = new CNumber;

	if (pNumber != nullptr)
	{
		pNumber->Init();
		pNumber->SetSize(size);
		pNumber->SetPos(pos);
	}
	else
	{
		assert(false);
	}
	return pNumber;
}

void CNumber::Unload()
{
}
