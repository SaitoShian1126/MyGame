//=============================================================================
//
// �Q�[������ [game.h]
// Author : KADO TAKUMA
//
//=============================================================================
#ifndef _GAME_H_
#define _GAME_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "object2D.h"
#include "mode.h"

//=============================================================================
// �O����`
//=============================================================================
class CPlayer;
class CCamera;
class CMeshfield;
class CTime;
class CSound;
class CFade;
class CObstacle;
class CPause;

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CGame : public CMode
{
public:
	enum class EMode
	{
		SOLO,
		VS
	};

public:
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	CGame();
	~CGame() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init(void) override;	// ����������
	void Uninit(void) override;		// �I������
	void Update(void) override;		// �X�V����
	void Draw(void) override;		// �`�揈��
	static CGame *Create();			// ��������

	static void SetMode(EMode inMode) { m_mode = inMode; }
	static EMode GetMode() { return m_mode; }

	static CPlayer *GetPlayer1P() { return m_pPlayer1P; }
	static CPlayer *GetPlayer2P() { return m_pPlayer2P; }
	static CCamera *GetCamera() { return m_pCamera; }
	static CMeshfield *GetMeshfield() { return m_pMeshField; }
	static CSound *GetSound() { return m_pSound; }

private:

	void SetGimmik(float x);

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	CObject2D *m_pObject2D;					// �I�u�W�F�N�g2D�̃|�C���^
	static EMode m_mode;					// ���[�h
	static CPlayer *m_pPlayer1P;			// 1P�v���C���[�̃|�C���^
	static CPlayer *m_pPlayer2P;			// 2P�v���C���[�̃|�C���^
	static CCamera *m_pCamera;				// �J�����̃|�C���^
	static CLight *m_pLight;				// ���C�g�̃|�C���^
	static CMeshfield *m_pMeshField;		// ���b�V���t�B�[���h�̃|�C���^	
	static CTime *m_pTime;					// �^�C���̃|�C���^

	static CSound *m_pSound;				//�T�E���h�̃|�C���^
	CFade *m_pFade;							// �t�F�[�h�̃|�C���^

	static CPause* m_pPause;				// �|�[�Y

	float m_RandDoor;						// �����_���h�A�̈ʒu�̕ϐ�

	bool m_isCountDownNow;				// �J�E���g�_�E�������ۂ�
	int m_countDown;
};

#endif