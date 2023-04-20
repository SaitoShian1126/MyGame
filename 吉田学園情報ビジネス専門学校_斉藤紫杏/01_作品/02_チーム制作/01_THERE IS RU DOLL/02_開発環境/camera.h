//=============================================================================
//
// �J�������� [camera.cpp]
// Author : saito shian
//
//=============================================================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CCamera
{
public:
	static const float MOVE_SPEED;			// �ړ����x
	static const unsigned int MAX_NUMBER;	// �ő吔
	static const D3DXVECTOR3 INIT_POSV;		// ���_�̏����l
	static const D3DXVECTOR3 INIT_POSR;		// �����_�̏����l
	static const float Z_DEPTH;				// �����_��Z�������Ă����ʒu��艜�[���ʒu�ɂ���
	static const float Z_SEPARATE;			// ���_��Z�������Ă����ʒu���痣��

public:
	enum CAMERATYPE
	{
		CAMERATYPE_NONE = 0,
		CAMERATYPE_TITLE,		// �^�C�g����
		CAMERATYPE_ONE,			// �J����1��(�\�����[�h)
		CAMERATYPE_TWO,			// �J����2��(�ΐ�)
		CAMERATYPE_RANKING,		// �����L���O��
		CAMERATYPE_MAX
	};
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	CCamera();
	~CCamera();

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init(void);					// ����������
	void Uninit(void);					// �I������
	void Update(void);					// �X�V����
	void SetCamera(int nCntCamera);	// �ݒ菈��
	void SetCameraType(CAMERATYPE type);							// �J�����̎�ނ̐ݒ�
	static CAMERATYPE GetCameraType(void) { return m_nCameraType; }	// �J�����̎�ނ̎擾
	static D3DXVECTOR3 GetRot() { return m_rot; }
	D3DXVECTOR3 GetPosV() { return m_posV[0]; }
	D3DXVECTOR3 GetPosR() { return m_posR[0]; }
	void SetPosV(D3DXVECTOR3 posV);
	void SetPosR(D3DXVECTOR3 posR);

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	D3DVIEWPORT9 m_Viewport[2];			//�r���[�|�[�g
	D3DXVECTOR3	m_posV[2];				//���_
	D3DXVECTOR3	m_posR[2];				//�����_
	D3DXVECTOR3	m_vecU[2];				//������x�N�g��
	D3DXMATRIX	m_mtxProjection[2];		//�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX	m_mtxView[2];			//�r���[�}�g���b�N�X
	D3DXVECTOR3	m_posVDest;				//�ړI�̎��_
	D3DXVECTOR3	m_posRDest;				//�ړI�̒����_

	float		m_fDistance;			//���_���璍���_�̋���

	static D3DXVECTOR3 m_rot;			//����
	static CAMERATYPE m_nCameraType;	//�J�����̃^�C�v
};

#endif