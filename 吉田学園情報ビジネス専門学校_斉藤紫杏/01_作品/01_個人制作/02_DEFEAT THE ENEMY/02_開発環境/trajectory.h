//********************************************
//
//	trajectory.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _TRAJECTORY_H_
#define _TRAJECTORY_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�}�N����`
#define TRAJECTORY_SIZE_X		 (40.0f)	//�O����x�T�C�Y
#define TRAJECTORY_SIZE_Y		 (25.0f)	//�O����y�T�C�Y

//�O���N���X
class CTrajectory : public CObject2D
{
public:
	enum TRAJECTORY
	{
		TRAJECTORY_NONE = 0,
		TRAJECTORY_DOWN,		//�O����
		TRAJECTORY_LIGHTDOWN,	//�O���E��
		TRAJECTORY_LEFTDOWN,	//�O������
		TRAJECTORY_LIGHT,		//�O���E
		TRAJECTORY_LEFT,		//�O����
		TRAJECTRY_MAX
	};
public:
	CTrajectory();						//�R���X�g���N�^
	~CTrajectory()override;				//�f�X�g���N�^

	HRESULT Init(void)override;			//�O���̏���������
	void Uninit(void)override;			//�O���̏I������
	void Update(void)override;			//�O���̍X�V����
	void Draw(void)override;			//�O���̕`�揈��
	void SetTrajectoryType(TRAJECTORY type);					//�O���̎�ނ̐ݒ�
	TRAJECTORY GetTrajectoryType(void) { return TRAJECTORY(); }	//�O���̎�ނ̎擾
	
	static HRESULT Load(void);									//�e�N�X�`���̓ǂݍ���
	static void Unload(void);									//�e�N�X�`���̔j��
	static CTrajectory *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, TRAJECTORY nType);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureTrajectory[5];		//�e�N�X�`���ւ̃|�C���^
	TRAJECTORY m_nType;										//�O���̎��
	int m_UninitCount;										//������܂ł̎���
	bool m_flag;											//�t���O
};

#endif






