//********************************************
//
//	sponer.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _SPONER_H_
#define _SPONER_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�X�|�i�[�N���X
class CSponer : public CObject2D
{
public:
	CSponer();							//�R���X�g���N�^
	~CSponer()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�X�|�i�[�̏���������
	void Uninit(void)override;			//�X�|�i�[�̏I������
	void Update(void)override;			//�X�|�i�[�̍X�V����
	void Draw(void)override;			//�X�|�i�[�̕`�揈��

	static HRESULT Load(void);			//�e�N�X�`���̓ǂݍ���
	static void Unload(void);			//�e�N�X�`���̔j��
	static CSponer *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureSponer;		//�e�N�X�`���ւ̃|�C���^
};

#endif






