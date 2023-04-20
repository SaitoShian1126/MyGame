//=============================================================================
//
// ��Q������ [obstacle.h]
// Author : saito shian
//
//=============================================================================
#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "gimmick.h"
#include "player.h"

//=============================================================================
// �O����`
//=============================================================================

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CObstacle : public CGimmick
{
public:
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	explicit CObstacle(int nPriority = PRIORITY_LEVEL3);
	~CObstacle() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init() override;			// ����������
	void Uninit() override;				// �I������
	void Update() override;				// �X�V����
	void Draw() override;				// �`�揈��

	void ConstOperate() override;			// ���̑���(�A�ŁA��])
	void KeyCount();												// �L�[���J�E���g����֐�

	bool BarrageMoveWall(CObstacle * pCObstacle, D3DXVECTOR3 ObstaclePos, D3DXVECTOR3 PlayerPos);	// �A�łœ����ǂ̏���
	D3DXVECTOR3 AlternateMoveWal(D3DXVECTOR3 ObstaclePos, D3DXVECTOR3 P1Pos, D3DXVECTOR3 P2Pos, D3DXVECTOR3 ObstacleMove);	// ���ݘA�łœ����ǂ̏���
	//bool PushMoveObject(CObstacle * pCObstacle, D3DXVECTOR3 ObstaclePos, D3DXVECTOR3 PlayerPos);		// �v���C���[�������ē����ǂ̏���
	bool PlayerGoal(D3DXVECTOR3 ObstaclePos , D3DXVECTOR3 P1Pos, D3DXVECTOR3 P2Pos, D3DXVECTOR3 ObstacleMove);				// �v���C���[���S�[���������̏���

	static CObstacle *Create(const D3DXVECTOR3 pos, GIMMICKTYPE gimmicktype,int nPriority);			// ��������

	bool GetCompletion(void) { return m_Completion; }
	void SetCompletion(bool bflag) { m_Completion = bflag; }

	bool GetStopFlag(void) { return m_StopObstacle; }
	void SetStopFlag(bool bflag) { m_StopObstacle = bflag; }

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	D3DXVECTOR3 m_PosOld;			// �O��̈ʒu
	int m_nTriggerCount1;			// �L�[����������
	int m_nTriggerCount2;			// �L�[����������
	int m_ArrowRand;				// ���̎�ރ����_��

	bool m_ArrowRandFlag;			// ���̎�ރ����_���t���O
	bool m_AreaFlag1P;				// 1P���G���A���ɂ��邩�t���O
	bool m_AreaFlag2P;				// 2P���G���A���ɂ��邩�t���O
	bool m_nAlternateFlag;			// ���݂ɃL�[�������Ă��邩
	bool PlayerGoalFlag;			// �v���C���[���S�[��������
	bool m_bIsLanding;				// ���f���Ƃ̓����蔻��t���O(���E,��,��O)
	bool m_bIsLandingUp;			// ���f���Ƃ̓����蔻��t���O(�㑤)

	bool m_Completion;				// Player�������������ۂ��t���O
	bool m_StopObstacle;			// Obstacle�X�g�b�v���邩�̃t���O
};
#endif
