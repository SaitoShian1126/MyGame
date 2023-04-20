//********************************************
//
//	particle.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _particle_H_
#define _particle_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�}�N����`
#define MAX_PARTICLESIZE (10.0f);	//�p�[�e�B�N���T�C�Y

//�p�[�e�B�N���N���X
class CParticle : public CObject2D
{
public:
	CParticle();						//�R���X�g���N�^
	~CParticle()override;				//�f�X�g���N�^

	HRESULT Init(void)override;			//�p�[�e�B�N���̏���������
	void Uninit(void)override;			//�p�[�e�B�N���̏I������
	void Update(void)override;			//�p�[�e�B�N���̍X�V����
	void Draw(void)override;			//�p�[�e�B�N���̕`�揈��

	void SetLife(int nLife);			//���C�t�̐ݒ�

	static HRESULT Load(void);			//�e�N�X�`���̓ǂݍ���
	static void Unload(void);			//�e�N�X�`���̔j��
	static CParticle *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, int nLife);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureParticle;	//�e�N�X�`���ւ̃|�C���^
	static D3DXVECTOR3 m_nMove;						//�ړ�
	D3DXCOLOR m_nCol;								//�F
	int m_nLife;									//�p�[�e�B�N���̗̑�
};

#endif







