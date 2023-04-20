//********************************************
//
//	input.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _INPUT_H_
#define _INPUT_H_

//�C���N���[�h
#include "main.h"

//�}�N����`
#define NUM_KEY_MAX	(256)		//�L�[�̍ő�l

//���̓N���X
class CInput
{
public:
	CInput();	//�R���X�g���N�^
	~CInput();	//�f�X�g���N�^

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);	//����������
	virtual void Uninit(void);								//�I������
	virtual void Update(void);								//�X�V����
	bool GetKeyboardPress(int nKey);						//�L�[�{�[�h�v���X�̎擾����
	bool GetKeyboardTrigger(int nKey);						//�L�[�{�[�h�g���K�[�̎擾����
	bool GetRelease(int nKey);								//�L�[�{�[�h�����[�X�̎擾����

protected:
	BYTE m_aKeyState[NUM_KEY_MAX];					//�L�[�{�[�h�̃v���X���
	BYTE m_aKeyStateTrigger[NUM_KEY_MAX];			//�L�[�{�[�h�̃g���K�[���
	BYTE m_aKeyStateRelease[NUM_KEY_MAX];			//�L�[�{�[�h�̃����[�X���
	LPDIRECTINPUTDEVICE8 m_pDevice;					//�f�o�C�X
	static LPDIRECTINPUT8 m_pInput;					//DirectInput�I�u�W�F�N�g�ւ̃|�C���^
};

//���̓N���X(�W���C�p�b�h)
class CJoyPad : public CInput
{
public:
	//�L�[�̎��
	enum JOYKEY
	{
		JOYKEY_UP = 0,			//�\���L�[�i��j
		JOYKEY_DOWN,			//�\���L�[�i���j
		JOYKEY_LEFT,			//�\���L�[�i���j
		JOYKEY_RIGHT,			//�\���L�[�i�E�j
		JOYKEY_START,			//START�{�^��
		JOYKEY_BACK,			//BACK�{�^��
		JOYKEY_PUSHLSTICK,		//���X�e�B�b�N��������
		JOYKEY_PUSHRSTICK,		//�E�X�e�B�b�N��������
		JOYKEY_LBUTTON5,		//���{�^����
		JOYKEY_RBUTTON5,		//�E�{�^����
		JOYKEY_10,				//�s��
		JOYKEY_11,				//�s��
		JOYKEY_A,				//A�{�^��
		JOYKEY_B,				//B�{�^��
		JOYKEY_X,				//X�{�^��
		JOYKEY_Y,				//Y�{�^��
		JOYKEY_LEFT_STICK,		//L�X�e�B�b�N
		JOYKEY_RIGHT_STICK,		//R�X�e�B�b�N
		JOYKEY_MAX
	};
public:
	CJoyPad();	//�R���X�g���N�^
	~CJoyPad();	//�f�X�g���N�^

	HRESULT Init(HINSTANCE hInstance, HWND hWnd)override;	//�W���C�p�b�h�̏���������
	void Uninit(void)override;								//�W���C�p�b�h�̏I������
	void Update(void)override;								//�W���C�p�b�h�̍X�V����
	bool GetJoypadPress(JOYKEY key);						//�W���C�p�b�h�̃v���X�̎擾����
	bool GetJoypadTrigger(JOYKEY key);						//�W���C�p�b�h�̃g���K�[����

private:
	XINPUT_STATE m_JoykeyState;						//�W���C�p�b�h�̃v���X���
	XINPUT_STATE m_JoykeyStateTrigger;				//�W���C�p�b�h�̃g���K�[���
	int m_aJoykeyStateTrigger;						//�W���C�p�b�h�̃g���K�[���
	int m_aJoykeyStateRelese;						//�W���C�p�b�h�̃����[�X���
};

#endif