//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : saito shian
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//*****************************************************************************
// �T�E���h�t�@�C��
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_SOUND0 = 0,				// BGM0
	SOUND_LABEL_SOUND1,					// BGM1
	SOUND_LABEL_SOUND2,					// BGM2
	SOUND_LABEL_SOUND3,					// BGM3
	SOUND_LABEL_SOUND4,					// BGM4
	SOUND_LABEL_SOUND5,					// BGM5
	SOUND_LABEL_SOUND6,					// BGM6
	SOUND_LABEL_SE_SHOT,				// �V���b�g
	SOUND_LABEL_SE_BULLET,				// �e�؂�ւ�
	SOUND_LABEL_SE_ENEMYEXPLOSION,		// �G���j
	SOUND_LABEL_SE_ENEMYEXPLOSION1,		// �G�̋@�̌��j
	SOUND_LABEL_SE_SENTOUKI,			// �퓬�@
	SOUND_LABEL_SE_SCORE,				// �X�R�A�A�b�v
	SOUND_LABEL_SE_ATTACK,				// �U��
	SOUND_LABEL_SE_LIFE,				// �̗̓A�b�v
	SOUND_LABEL_SE_BUTTON,				// �{�^������
	SOUND_LABEL_SE_DAMAGE,				// �_���[�W
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);

#endif


