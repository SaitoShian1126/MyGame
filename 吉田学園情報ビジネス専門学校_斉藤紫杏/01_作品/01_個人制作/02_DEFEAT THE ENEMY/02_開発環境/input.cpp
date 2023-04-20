//********************************************
//
//	input.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include "input.h"

//静的メンバ変数宣言
LPDIRECTINPUT8 CInput::m_pInput = nullptr;

//入力のコンストラクタ
CInput::CInput(void)
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_pDevice = nullptr;							//入力デバイスへのポインタ
	for (int nCnt = 0; nCnt < NUM_KEY_MAX; nCnt++)
	{
		m_aKeyState[nCnt] = {};
		m_aKeyStateTrigger[nCnt] = {};
		m_aKeyStateRelease[nCnt] = {};
	}
}

//入力のデストラクタ
CInput::~CInput(void)
{

}

//入力の初期化処理
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	//Directinputオブジェクトの生成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void **)&m_pInput, NULL)))
	{
		return E_FAIL;
	}
	//入力デバイス（キーボード）の生成
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}
	//データフォーマットのを設定
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	//協調モードを設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//キーボードへのアクセス権
	m_pDevice->Acquire();

	return S_OK;
}

//入力の終了処理
void CInput::Uninit(void)
{
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();		//キーボードへのアクセス権を放棄
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//入力の更新処理
void CInput::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX];			//キーボードの入力情報

	//入力デバイスからデータを取得
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

//キー長押し処理
bool CInput::GetKeyboardPress(int nKey)
{
	return (m_aKeyState[nKey] & 0x80) ? true : false;
}

//キー単発処理
bool CInput::GetKeyboardTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//Release処理
bool CInput::GetRelease(int nKey)
{
	return (m_aKeyStateRelease[nKey] & 0x80) ? true : false;
}

//**********************************
//	ジョイパッド
//**********************************
//入力のコンストラクタ
CJoyPad::CJoyPad(void)
{
	//********************************
	//メンバ変数のクリア
	//********************************
}

//入力のデストラクタ
CJoyPad::~CJoyPad(void)
{

}
//ジョイパッドの初期化処理
HRESULT CJoyPad::Init(HINSTANCE hInstance, HWND hWnd)
{
	//Xinputのステート設定(有効にする)
	XInputEnable(true);
	//メモリーのクリア
	memset(&m_JoykeyState, 0, sizeof(XINPUT_STATE));
	memset(&m_JoykeyStateTrigger, 0, sizeof(XINPUT_STATE));

	return S_OK;
}

//ジョイパッドの終了処理
void CJoyPad::Uninit(void)
{
	//Xinputのステートを設定(無効にする)
	XInputEnable(false);
}

//ジョイパッドの更新処理
void CJoyPad::Update(void)
{
	XINPUT_STATE joykeyState;	//ジョイパッドの入力処理

	//ジョイパッドの状態の取得
	if (XInputGetState(0, &joykeyState) == ERROR_SUCCESS)		//0番目のジョイパッド
	{
		m_aJoykeyStateTrigger = ~m_JoykeyState.Gamepad.wButtons & joykeyState.Gamepad.wButtons;
		m_aJoykeyStateRelese = m_JoykeyState.Gamepad.wButtons & ~joykeyState.Gamepad.wButtons;
		m_JoykeyState = joykeyState;	//ジョイパッドのプレス情報を保存
	}
}

//ジョイパッドプレスの取得処理
bool CJoyPad::GetJoypadPress(JOYKEY key)
{
	return (m_JoykeyState.Gamepad.wButtons & (0x01 << key)) ? true : false;
}

//ジョイパッドトリガーの取得処理
bool CJoyPad::GetJoypadTrigger(JOYKEY key)
{
	return(m_aJoykeyStateTrigger & (0x01 << key)) ? true : false;
}
