//********************************************
//
//	enemy.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _ENEMY_H_
#define _ENEMY_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�}�N����`
#define ENEMY_SIZE_X			(35.0f)		//�G��x�T�C�Y
#define ENEMY_SIZE_Y			(35.0f)		//�G��y�T�C�Y
#define ENEMY_MOVE_X			(-3.0f)		//�G��x�̈ړ���
#define ENEMY_MOVE_Y			(6.0f)		//�G��y�̈ړ���
#define RANGE_HIGH_Y			(450.0f)	//y�͈̔�(����)
#define RANGE_DOWN_Y			(650.0f)	//y�͈̔�(�Ⴓ)
#define TIME					(200)		//����
#define ENEMY_LIFE_MEDAMA		(10)		//�ڋʂ̗̑�
#define ENEMY_LIFE_BOMB			(5)			//���e�̗̑�
#define ENEMY_LIFE_ZIGUZAGU		(30)		//�W�O�U�O�̗̑�
#define ENEMY_LIFE_ENN			(25)		//�~�̗̑�
#define ENEMY_LIFE_HEBI			(20)		//�ւ̗̑�
#define ENEMY_LIFE_RANDAM		(250)		//�����_��(�{�X)�̗̑�
#define ENEMY_LIFE_KYODAIMEDAMA	(15)		//����ڋʂ̗̑�
#define ENEMY_LIFE_SOGEKI		(5)			//�_���̗̑�

#define BOSS_SIZE_X				(200.0f)	//�G��x�T�C�Y
#define BOSS_SIZE_Y				(225.0f)	//�G��y�T�C�Y
#define BOSS_BULLET_TIME		(100)		//�G���U�����Ă���܂ł̎���	
#define BOSS_LIFE				(899)		//�{�X�̗̑�

#define MAX_BOSSTEXTURE_X		(2.0f)		//�{�X��x�̃e�N�X�`��
#define MAX_BOSSTEXTURE_Y		(6.0f)		//�{�X��y�̃e�N�X�`��

//�G�N���X
class CEnemy : public CObject2D
{
public:
	//�G�̎��
	enum ENEMYTYPE
	{
		ENEMYTYPE_NONE = 0,
		ENEMYTYPE_MEDAMA,			//�ڋʂ̓G
		ENEMYTYPE_BOMB,				//��������G
		ENEMYTYPE_ZIGUZAGU,			//�W�O�U�O�ɓ����G
		ENEMYTYPE_ENN,				//�~��`���G
		ENEMYTYPE_HEBI,				//�ւ̓G
		ENEMYTYPE_BOSS,				//�{�X
		ENEMYTYPE_KYODAIMEDAMA,		//����ڋ�
		ENEMYTYPE_SOGEKI,			//�_���G
		ENEMYTYPE_BOSSTUKAI,		//�{�X���o���G
		ENEMYTYPE_MAX
	};

public:
	CEnemy();							//�R���X�g���N�^
	~CEnemy()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�G�̏���������
	void Uninit(void)override;			//�G�̏I������
	void Update(void)override;			//�G�̍X�V����
	void Draw(void)override;			//�G�̕`�揈��

	int GetLife(void)override { return m_nLife; }	//�̗͂̎擾
	void SetLife(int nLife)override;				//�̗͂̐ݒ�

	ENEMYTYPE GetEnemyType(void) { return ENEMYTYPE(); }	//�G�̎�ނ̎擾
	void SetEnemyType(ENEMYTYPE type);	//�G�̎�ނ̐ݒ�

	void HitJudgment(D3DXVECTOR3 pos);				//�G�̓����蔻��
	void HitBossJudgment(D3DXVECTOR3 pos);			//�{�X�̓����蔻��

	static bool GetPlayerDeathFlag() { return m_PlayerGameOver; }
	static HRESULT Load(void);			//�e�N�X�`���̓ǂݍ���
	static void Unload(void);			//�e�N�X�`���̔j��
	static CEnemy *Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move, D3DXVECTOR3 size,ENEMYTYPE nType, int nLife);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureEnemy[7];	//�e�N�X�`���ւ̃|�C���^
	static bool m_PlayerGameOver;					//�v���C���[�����񂾂̂��t���O
	D3DXVECTOR3 m_BulletMove;						//�e�̈ړ�
	ENEMYTYPE m_nType;								//�G�̎��
	float m_fRotMove;								//�����̈ړ�
	int m_nLife;									//�G�̗̑�
	int m_sLifeTime;								//���ԂŎ��ʓG		
	int m_nTime;									//�G���U�����Ă���܂ł̎���
	int m_nRand;									//�����_��
	int m_nCounterAnimEnemy;						//�A�j���[�V�����J�E���^�[
	int m_nPatternAnimEnemy;						//�A�j���[�V�����p�^�[��No.
	int m_Count;									//�J�E���g
	int m_nBulletCnt;								//�e�̃J�E���g
	int m_nAttackTime;								//�G���U�����Ă���܂ł̎���
	int m_nAttackTime2;								//�G���U�����Ă���܂ł̎���
	int m_AttackCount;								//�U������
	int m_nBossTime;								//�{�X�̃J�E���g
	int m_nMoveTime;								//�ړ�����܂ł̎���
	bool m_flag;									//�G�����ǂ̓��������邩�̃t���O
	bool m_flag2;									//�G�����ǂ̓��������邩�̃t���O
	bool m_UseFlag;									//�g���Ă��邩�̃t���O
	bool m_Bossflag1;								//�{�X�̃t���O1
	bool m_Bossflag2;								//�{�X�̃t���O2
	bool m_Bossflag3;								//�{�X�̃t���O3
	bool m_Bossflag4;								//�{�X�̃t���O4
};

#endif





