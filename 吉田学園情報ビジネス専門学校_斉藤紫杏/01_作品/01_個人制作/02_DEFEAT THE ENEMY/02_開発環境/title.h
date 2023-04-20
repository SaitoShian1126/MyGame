//********************************************
//
//	title.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _TITLE_H_
#define _TITLE_H_

//�C���N���[�h
#include "main.h"
#include "mode.h"

//�O���錾
class CObject2D;
class CFade;

//�}�N����`
#define TITLE_TIME	(120.0f)	//�t�F�[�h�Ɋ|���鎞��

//�^�C�g���N���X
class CTitle : public CMode
{
public:
	CTitle();					//�R���X�g���N�^
	~CTitle() ;					//�f�X�g���N�^

	HRESULT Init(void) ;		//�^�C�g���̏���������
	void Uninit(void) ;			//�^�C�g���̏I������
	void Update(void) ;			//�^�C�g���̍X�V����
	void Draw(void);			//�^�C�g���̕`�揈��

	void SetColor(float Red, float Green, float Blue, float ��);									//�F�̐ݒ�
	static CTitle *Create();			//����

private:
	LPDIRECT3DTEXTURE9 m_pTextureTitle;		//�e�N�X�`���ւ̃|�C���^
	CObject2D *m_pObject;					//�I�u�W�F�N�g�̃|�C���^
	CFade *m_pFade;								//�t�F�[�h
	bool m_SoundFlag;							//�T�E���h�t���O
	bool m_flag;								//�t���O
};

#endif






