//=============================================================================
//
// サウンド処理 [sound.h]
// Author : saito shian
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//*****************************************************************************
// サウンドファイル
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
	SOUND_LABEL_SE_SHOT,				// ショット
	SOUND_LABEL_SE_BULLET,				// 弾切り替え
	SOUND_LABEL_SE_ENEMYEXPLOSION,		// 敵撃破
	SOUND_LABEL_SE_ENEMYEXPLOSION1,		// 敵の機体撃破
	SOUND_LABEL_SE_SENTOUKI,			// 戦闘機
	SOUND_LABEL_SE_SCORE,				// スコアアップ
	SOUND_LABEL_SE_ATTACK,				// 攻撃
	SOUND_LABEL_SE_LIFE,				// 体力アップ
	SOUND_LABEL_SE_BUTTON,				// ボタン押す
	SOUND_LABEL_SE_DAMAGE,				// ダメージ
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);

#endif


