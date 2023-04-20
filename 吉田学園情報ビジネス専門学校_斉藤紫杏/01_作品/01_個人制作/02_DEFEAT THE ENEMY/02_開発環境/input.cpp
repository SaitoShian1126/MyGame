//********************************************
//
//	input.cpp
//	Author: saito shian
//
//********************************************

//�C���N���[�h
#include "input.h"

//�ÓI�����o�ϐ��錾
LPDIRECTINPUT8 CInput::m_pInput = nullptr;

//���͂̃R���X�g���N�^
CInput::CInput(void)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
	m_pDevice = nullptr;							//���̓f�o�C�X�ւ̃|�C���^
	for (int nCnt = 0; nCnt < NUM_KEY_MAX; nCnt++)
	{
		m_aKeyState[nCnt] = {};
		m_aKeyStateTrigger[nCnt] = {};
		m_aKeyStateRelease[nCnt] = {};
	}
}

//���͂̃f�X�g���N�^
CInput::~CInput(void)
{

}

//���͂̏���������
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	//Directinput�I�u�W�F�N�g�̐���
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void **)&m_pInput, NULL)))
	{
		return E_FAIL;
	}
	//���̓f�o�C�X�i�L�[�{�[�h�j�̐���
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}
	//�f�[�^�t�H�[�}�b�g�̂�ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	//�������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//�L�[�{�[�h�ւ̃A�N�Z�X��
	m_pDevice->Acquire();

	return S_OK;
}

//���͂̏I������
void CInput::Uninit(void)
{
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();		//�L�[�{�[�h�ւ̃A�N�Z�X�������
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//���͂̍X�V����
void CInput::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX];			//�L�[�{�[�h�̓��͏��

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (int nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey])  & aKeyState[nCntKey];
			m_aKeyStateRelease[nCntKey] = (m_aKeyStateTrigger[nCntKey] ^ 0);
			m_aKeyState[nCntKey] = aKeyState[nCntKey];
		}
	}
	else
	{
		m_pDevice->Acquire();
	}
}

//�L�[����������
bool CInput::GetKeyboardPress(int nKey)
{
	return (m_aKeyState[nKey] & 0x80) ? true : false;
}

//�L�[�P������
bool CInput::GetKeyboardTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//Release����
bool CInput::GetRelease(int nKey)
{
	return (m_aKeyStateRelease[nKey] & 0x80) ? true : false;
}

//**********************************
//	�W���C�p�b�h
//**********************************
//���͂̃R���X�g���N�^
CJoyPad::CJoyPad(void)
{
	//********************************
	//�����o�ϐ��̃N���A
	//********************************
}

//���͂̃f�X�g���N�^
CJoyPad::~CJoyPad(void)
{

}
//�W���C�p�b�h�̏���������
HRESULT CJoyPad::Init(HINSTANCE hInstance, HWND hWnd)
{
	//Xinput�̃X�e�[�g�ݒ�(�L���ɂ���)
	XInputEnable(true);
	//�������[�̃N���A
	memset(&m_JoykeyState, 0, sizeof(XINPUT_STATE));
	memset(&m_JoykeyStateTrigger, 0, sizeof(XINPUT_STATE));

	return S_OK;
}

//�W���C�p�b�h�̏I������
void CJoyPad::Uninit(void)
{
	//Xinput�̃X�e�[�g��ݒ�(�����ɂ���)
	XInputEnable(false);
}

//�W���C�p�b�h�̍X�V����
void CJoyPad::Update(void)
{
	XINPUT_STATE joykeyState;	//�W���C�p�b�h�̓��͏���

	//�W���C�p�b�h�̏�Ԃ̎擾
	if (XInputGetState(0, &joykeyState) == ERROR_SUCCESS)		//0�Ԗڂ̃W���C�p�b�h
	{
		m_aJoykeyStateTrigger = ~m_JoykeyState.Gamepad.wButtons & joykeyState.Gamepad.wButtons;
		m_aJoykeyStateRelese = m_JoykeyState.Gamepad.wButtons & ~joykeyState.Gamepad.wButtons;
		m_JoykeyState = joykeyState;	//�W���C�p�b�h�̃v���X����ۑ�
	}
}

//�W���C�p�b�h�v���X�̎擾����
bool CJoyPad::GetJoypadPress(JOYKEY key)
{
	return (m_JoykeyState.Gamepad.wButtons & (0x01 << key)) ? true : false;
}

//�W���C�p�b�h�g���K�[�̎擾����
bool CJoyPad::GetJoypadTrigger(JOYKEY key)
{
	return(m_aJoykeyStateTrigger & (0x01 << key)) ? true : false;
}
