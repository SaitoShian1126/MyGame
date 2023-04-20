//********************************************
//
//	ui.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _UI_H_
#define _UI_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�}�N����`
#define UI_SIZE_X		 (20.0f)	//ui��x�T�C�Y
#define UI_SIZE_Y		 (25.0f)	//ui��y�T�C�Y

//ui�N���X
class CUi : public CObject2D
{
public:
	enum UITYPE
	{
		UITYPE_NONE = 0,
		UITYPE_BULLET,
		UITYPE_LIFE
	};
public:
	CUi();							//�R���X�g���N�^
	~CUi()override;					//�f�X�g���N�^

	HRESULT Init(void)override;		//ui�̏���������
	void Uninit(void)override;		//ui�̏I������
	void Update(void)override;		//ui�̍X�V����
	void Draw(void)override;		//ui�̕`�揈��
	void SetUiType(UITYPE type);	//ui�̎�ނ̐ݒ�

	UITYPE GetUiType(void) { return UITYPE(); }	//�X�|�[���̎�ނ̎擾

	static HRESULT Load(void);		//�e�N�X�`���̓ǂݍ���
	static void Unload(void);		//�e�N�X�`���̔j��
	static CUi *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size,UITYPE type);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureUi[2];	//�e�N�X�`���ւ̃|�C���^
	UITYPE m_nType;							//ui�̎��
};

#endif







