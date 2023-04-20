//********************************************
//
//	game.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _GAME_H_
#define _GAME_H_

//�C���N���[�h
#include "main.h"
#include "mode.h"

//�O���錾
class CObject2D;

//�Q�[���N���X
class CGame : public CMode
{
public:
	CGame();						//�R���X�g���N�^
	~CGame();					//�f�X�g���N�^

	HRESULT Init(void);			//�Q�[���̏���������
	void Uninit(void);			//�Q�[���̏I������
	void Update(void);			//�Q�[���̍X�V����
	void Draw(void);			//�Q�[���̕`�揈��

	static CScore *GetScore(void) { return m_pScore; }			//�X�R�A�̎擾����
	static CGame *Create();										//����

private:
	static CScore *m_pScore;				//�X�R�A�̃|�C���^	
	int EnemyMoveTime;						//�G�������n�߂�܂ł̎���
	int nCntdeath;							//�G�����̎��񂾂���ۑ�����
	int m_CountTime;						//�T�E���h���ω����鎞��
	bool m_flag;							//�t���O1
	bool m_flag2;							//�t���O2
	bool m_flag3;							//�t���O3
};

#endif






