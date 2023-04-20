//=============================================================================
//
// �J�������� [camera.cpp]
// Author : saito shian
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "camera.h"
#include "application.h"
#include "renderer.h"
#include "input.h"
#include "player.h"
#include "game.h"
#include "tutorial.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
D3DXVECTOR3 CCamera::m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
CCamera::CAMERATYPE CCamera::m_nCameraType = CAMERATYPE_NONE;
const float CCamera::MOVE_SPEED = 5.0f;										// �ړ����x
const unsigned int CCamera::MAX_NUMBER = 2;									// �ő吔
const D3DXVECTOR3 CCamera::INIT_POSV = D3DXVECTOR3(0.0f, 180.0f, -400.0f);	// ���_�̏����l
const D3DXVECTOR3 CCamera::INIT_POSR = D3DXVECTOR3(0.0f, 20.0f, -1.0f);		// �����_�̏����l
const float CCamera::Z_DEPTH = 140.0f;										// �����_��Z�������Ă����ʒu��艜�[���ʒu�ɂ���
const float CCamera::Z_SEPARATE = 290.0f;									// ���_��Z�������Ă����ʒu���痣��		

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCamera::CCamera()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCamera::~CCamera()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCamera::Init(void)
{
	m_posRDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posVDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_Viewport[nCnt] = {};
	}

	switch (m_nCameraType)
	{
	case CCamera::CAMERATYPE_NONE:
		break;
	case CCamera::CAMERATYPE_TITLE:
	{
		// ���_�E�����_�E�������ݒ肷��i�\���̂̏������j
		m_posV[0] = D3DXVECTOR3(0.0f, 500.0f, -500.0f);	// ���_
		m_posR[0] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// �����_
		m_vecU[0] = D3DXVECTOR3(0.0f, 1.0f, 0.0f);		// ������x�N�g�� ���Œ��OK!!
		m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// ����
		D3DXVECTOR3 length = m_posV[0] - m_posR[0];		// ����
		m_fDistance = sqrtf((length.x * length.x) + (length.z * length.z));	// ���_���璍���_�܂ł̋���
	}
		break;
	case CCamera::CAMERATYPE_ONE:
	{
		// ���_�E�����_�E�������ݒ肷��i�\���̂̏������j
		D3DXVECTOR3 PlayerPos1P = CGame::GetPlayer1P()->GetPos();		//�v���C���[POS���̎擾

		//************************
		// �v���C���[�̃J����
		//************************
		// ���_�A�����_�A�������ݒ肷��
		m_posV[0] = INIT_POSV;
		m_posR[0] = INIT_POSR;
		m_posV[0].x = PlayerPos1P.x;
		m_posR[0].x = PlayerPos1P.x;
		m_vecU[0] = D3DXVECTOR3(0.0f, 1.0f, 0.0f);	//<-�Œ�ŗǂ�

		m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// ����
		D3DXVECTOR3 length = m_posV[0] - m_posR[0];		// ����
		m_fDistance = sqrtf((length.x * length.x) + (length.z * length.z));	// ���_���璍���_�܂ł̋���
	}
		break;
	case CCamera::CAMERATYPE_TWO:
	{
		D3DXVECTOR3 PlayerPos1P = CGame::GetPlayer1P()->GetPos();		//�v���C���[POS���̎擾
		D3DXVECTOR3 PlayerPos2P = CGame::GetPlayer2P()->GetPos();		//�v���C���[POS���̎擾

		//************************
		// �v���C���[�̃J����
		//************************
		// ���_�A�����_�A�������ݒ肷��
		m_posV[0] = INIT_POSV;
		m_posR[0] = INIT_POSR;
		m_posV[0].x = PlayerPos1P.x;
		m_posR[0].x = PlayerPos1P.x;
		m_vecU[0] = D3DXVECTOR3(0.0f, 1.0f, 0.0f);	//<-�Œ�ŗǂ�

		//************************
		// �Q�v���C���[�̃J����
		//************************
		// ���_�A�����_�A�������ݒ肷��
		m_posV[1] = INIT_POSV;
		m_posR[1] = INIT_POSR;
		m_posV[1].x = PlayerPos2P.x;
		m_posR[1].x = PlayerPos2P.x;
		m_vecU[1] = D3DXVECTOR3(0.0f, 1.0f, 0.0f);	// <-�Œ�ŗǂ�

		for (int nCnt = 0; nCnt < MAX_NUMBER; nCnt++)
		{
			D3DXVECTOR3 length = m_posR[nCnt] - m_posV[nCnt];	// �����_�Ǝ��_�̍���

			// �O�����̒藝(sqrtf�̓��[�g�̖���)
			m_fDistance = sqrtf((length.x * length.x) + (length.z * length.z));
		}

		//************************
		// �v���C���[
		//************************
		// �r���[�|�[�g�\���̕ۑ�
		m_Viewport[0].X = 0;		// �r���[�|�[�g�̊J�n�ʒu(x���W)
		m_Viewport[0].Y = 0;		// �r���[�|�[�g�̊J�n�ʒu(y���W)
		m_Viewport[0].Width = 639;	// �r���[�|�[�g�̕�
		m_Viewport[0].Height = 720;	// �r���[�|�[�g�̍���
		m_Viewport[0].MinZ = 0.0f;
		m_Viewport[0].MaxZ = 1.0f;

		//************************
		// 2�v���C���[
		//************************
		// �r���[�|�[�g�\���̕ۑ�
		m_Viewport[1].X = 641;		// �r���[�|�[�g�̊J�n�ʒu(x���W)
		m_Viewport[1].Y = 0;		// �r���[�|�[�g�̊J�n�ʒu(y���W)
		m_Viewport[1].Width = 640;	// �r���[�|�[�g�̕�
		m_Viewport[1].Height = 720;	// �r���[�|�[�g�̍���
		m_Viewport[1].MinZ = 0.0f;
		m_Viewport[1].MaxZ = 1.0f;
	}
		break;
	case CCamera::CAMERATYPE_RANKING:
		break;
	case CCamera::CAMERATYPE_MAX:
		break;
	default:
		break;
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCamera::Uninit(void)
{

}

//=============================================================================
// �X�V����
//=============================================================================
void CCamera::Update(void)
{
	//************************
	// �J�����̒Ǐ]����
	//************************
	if (CApplication::GetMode() == CApplication::MODE_GAME_SOLO || CApplication::GetMode() == CApplication::MODE_GAME_VS)
	{
		switch (m_nCameraType)
		{
		case CCamera::CAMERATYPE_NONE:
			break;
		case CCamera::CAMERATYPE_TITLE:
			break;
		case CCamera::CAMERATYPE_ONE:	// �\�����[�h�̏ꍇ���s
		{
			D3DXVECTOR3 PlayerPos = CGame::GetPlayer1P()->GetPos();	//�v���C���[POS���̎擾

			//*******************************
			// �J�����̒Ǐ]����
			//*******************************
			//�ړI�̒����_�̐ݒ�
			m_posRDest.z = PlayerPos.z + Z_DEPTH;
			//�ړI�̎��_�̐ݒ�
			m_posVDest.z = PlayerPos.z - cosf(m_rot.y) * Z_SEPARATE;

			//���_�̌�������
			for (int nCnt = 0; nCnt < m_nCameraType; nCnt++)
			{
				m_posR[nCnt].z += (m_posRDest.z - m_posR[nCnt].z) * 0.1f;
				m_posV[nCnt].z += (m_posVDest.z - m_posV[nCnt].z) * 0.1f;
			}
		}
		break;
		case CCamera::CAMERATYPE_TWO:
		{
			D3DXVECTOR3 PlayerPos1P = CGame::GetPlayer1P()->GetPos();		//�v���C���[POS���̎擾
			D3DXVECTOR3 PlayerPos2P = CGame::GetPlayer2P()->GetPos();		//�v���C���[POS���̎擾

			if (CGame::GetPlayer1P()->GetPlayerType() == CPlayer::EPLAYER_1P)
			{ //1P�̏ꍇ���s
			  //�ړI�̒����_�̐ݒ�
				m_posRDest.z = PlayerPos1P.z + Z_DEPTH;
				//�ړI�̎��_�̐ݒ�
				m_posVDest.z = PlayerPos1P.z - cosf(m_rot.y) * Z_SEPARATE;
				m_posR[0].z += (m_posRDest.z - m_posR[0].z) * 0.5f;
				m_posV[0].z += (m_posVDest.z - m_posV[0].z) * 0.5f;
			}
			if (CGame::GetPlayer2P()->GetPlayerType() == CPlayer::EPLAYER_2P)
			{ //2P�̏ꍇ���s
			  //�ړI�̒����_�̐ݒ�
				m_posRDest.z = PlayerPos2P.z + Z_DEPTH;
				//�ړI�̎��_�̐ݒ�
				m_posVDest.z = PlayerPos2P.z - cosf(m_rot.y) * Z_SEPARATE;
				m_posR[1].z += (m_posRDest.z - m_posR[1].z) * 0.1f;
				m_posV[1].z += (m_posVDest.z - m_posV[1].z) * 0.1f;
			}
		}
		break;
		case CCamera::CAMERATYPE_MAX:
			break;
		default:
			break;
		}
	}
}

//=============================================================================
// �ݒ菈��
//=============================================================================
void CCamera::SetCamera(int nCntCamera)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//**************************************************
	//	�\�����[�h
	//**************************************************
	if (m_nCameraType == CAMERATYPE_ONE)
	{
		//�r���[�}�g���b�N�X�̏����� 
		D3DXMatrixIdentity(&m_mtxView[0]);

		//�r���[�}�g���b�N�X�̍쐬
		D3DXMatrixLookAtLH(&m_mtxView[0],
			&m_posV[0],
			&m_posR[0],
			&m_vecU[0]);

		//�r���[�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_VIEW, &m_mtxView[0]);

		//�v���W�F�N�V�����}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxProjection[0]);

		//�v���W�F�N�V�����}�g���b�N�X�̍쐬
		D3DXMatrixPerspectiveFovLH(&m_mtxProjection[0],
			D3DXToRadian(45.0f),						//����p
			(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,	//�A�X�y�N�g��
			10.0f,										//�j�A�i�ǂ�����ǂ��܂ŃJ�����ŕ\�����邩�ݒ�j
			3000.0f);									//�t�@�[

		//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection[0]);
	}

	//**************************************************
	//	vs���[�h
	//**************************************************
	if (m_nCameraType == CAMERATYPE_TWO && CApplication::GetMode() == CApplication::MODE_GAME_VS)
	{
		//�r���[�|�[�g�̐ݒ�
		pDevice->SetViewport(&m_Viewport[nCntCamera]);

		//�r���[�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxView[nCntCamera]);

		//�r���[�}�g���b�N�X�̍쐬
		D3DXMatrixLookAtLH(&m_mtxView[nCntCamera],
			&m_posV[nCntCamera],
			&m_posR[nCntCamera],
			&m_vecU[nCntCamera]);

		//�r���[�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_VIEW, &m_mtxView[nCntCamera]);

		//�v���W�F�N�V�����}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxProjection[nCntCamera]);

		//�v���W�F�N�V�����}�g���b�N�X�̍쐬
		D3DXMatrixPerspectiveFovLH(&m_mtxProjection[nCntCamera],
			D3DXToRadian(45.0f),																//����p
			(float)m_Viewport[nCntCamera].Width / (float)m_Viewport[nCntCamera].Height,			//�A�X�y�N�g��
			10.0f,																				//�ǂ�����(�j�A)�ǂ��܂�(�t�@�[)���J������
			3000.0f);																			//�\�����邩�ݒ�

		//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection[nCntCamera]);
	}

	//**************************************************
	//	�^�C�g��
	//**************************************************
	if (CApplication::GetMode() == CApplication::MODE_TITLE)
	{
		//�r���[�}�g���b�N�X�̏����� 
		D3DXMatrixIdentity(&m_mtxView[0]);

		//�r���[�}�g���b�N�X�̍쐬
		D3DXMatrixLookAtLH(&m_mtxView[0],
			&m_posV[0],
			&m_posR[0],
			&m_vecU[0]);

		//�r���[�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_VIEW, &m_mtxView[0]);

		//�v���W�F�N�V�����}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxProjection[0]);

		//�v���W�F�N�V�����}�g���b�N�X�̍쐬
		D3DXMatrixPerspectiveFovLH(&m_mtxProjection[0],
			D3DXToRadian(45.0f),						//����p
			(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,	//�A�X�y�N�g��
			10.0f,										//�j�A�i�ǂ�����ǂ��܂ŃJ�����ŕ\�����邩�ݒ�j
			3000.0f);									//�t�@�[

		//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection[0]);
	}
}
// �J�����̎�ނ̐ݒ�
void CCamera::SetCameraType(CAMERATYPE type)
{
	m_nCameraType = type;
}

// �J�����̎��_�̐ݒ�
void CCamera::SetPosV(D3DXVECTOR3 posV)
{
	m_posV[0] = posV;
}

// �J�����̒����_�̐ݒ�
void CCamera::SetPosR(D3DXVECTOR3 posR)
{
	m_posR[0] = posR;
}

