//********************************************
//
//	effect.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _EFFECT_H_
#define _EFFECT_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�G�t�F�N�g�N���X
class CEffect : public CObject2D
{
public:
	CEffect();							//�R���X�g���N�^
	~CEffect()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�v���C���[�̏���������
	void Uninit(void)override;			//�v���C���[�̏I������
	void Update(void)override;			//�v���C���[�̍X�V����
	void Draw(void)override;			//�v���C���[�̕`�揈��

	void SetLife(int nLife);			//���C�t�̐ݒ�

	static HRESULT Load(void);			//�e�N�X�`���̓ǂݍ���
	static void Unload(void);			//�e�N�X�`���̔j��
	static CEffect *Create(D3DXVECTOR3 pos,D3DXVECTOR3 size, D3DXCOLOR col, int nLife);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureEffect;	//�e�N�X�`���ւ̃|�C���^
	D3DXCOLOR m_nCol;							//�F
	int m_nLife;								//�G�t�F�N�g�̗̑�
};

#endif






