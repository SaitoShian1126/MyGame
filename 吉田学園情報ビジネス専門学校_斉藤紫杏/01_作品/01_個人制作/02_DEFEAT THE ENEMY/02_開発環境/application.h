//********************************************
//
//	application.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

//�C���N���[�h
#include "main.h"
#include "input.h"
#include "enemy.h"
#include "score.h"
#include "title.h"

//�O���錾
class CMode;

//�A�v���P�[�V�����N���X
class CApplication
{
public:
	enum MODE
	{
		MODE_NONE = 0,	
		MODE_TITLE,		//�^�C�g��
		MODE_TUTORIAL,	//�`���[�g���A��
		MODE_GAME,		//�Q�[��
		MODE_RESULT,	//���U���g
		MODE_RANKING,	//�����L���O
		MODE_MAX
	 };
public:
	CApplication();		//�A�v���P�[�V�����̃R���X�g���N�^
	~CApplication();	//�A�v���P�[�V�����̃f�X�g���N�^

	HRESULT Init(HINSTANCE hInstance,HWND hWnd, bool bWindow);			//�A�v���P�[�V�����̏���������
	void Uninit(void);													//�A�v���P�[�V�����̏I������
	void Update(void);													//�A�v���P�[�V�����̍X�V����
	void Draw(void);													//�A�v���P�[�V�����̕`�揈��

	static CRenderer *GetRenderer(void);								//�����_�����O�̎擾����
	static CInput *GetInput(void) { return m_pInput; }					//�L�[�{�[�h�̎擾����
	static CJoyPad *GetInputJoyKey(void) { return m_pInputJoyKey; }		//�W���C�p�b�h�̎擾����
	static void SetMode(MODE mode);										//���[�h�̐ݒ�
	static MODE GetModeType() { return m_mode; }						//���[�h��ނ̎擾����
	
private:
	static CRenderer *m_pRenderer;			//�����_�����O�̃|�C���^
	static CInput *m_pInput;				//�C���v�b�g�̃|�C���^
	static CJoyPad *m_pInputJoyKey;			//�W���C�p�b�h�C���v�b�g�̃|�C���^
	static CMode *m_pMode;					//���[�h�̃|�C���^
	static MODE m_mode;						//���[�h
};

#endif
