//********************************************
//
//	player.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _PLAYER_H_
#define _PLAYER_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"
#include "bullet.h"

//�}�N����`
#define PLAYER_SIZE_X	(50.0f)	//�v���C���[��x�T�C�Y
#define PLAYER_SIZE_Y	(35.0f)	//�v���C���[��y�T�C�Y
#define BULLET_TIME		(6)		//�e���o�鎞��

//�v���C���[�N���X
class CPlayer : public CObject2D
{
public:
	CPlayer();							//�R���X�g���N�^
	~CPlayer()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�v���C���[�̏���������
	void Uninit(void)override;			//�v���C���[�̏I������
	void Update(void)override;			//�v���C���[�̍X�V����
	void Draw(void)override;			//�v���C���[�̕`�揈��
	void SetLife(int nLife)override;					//�̗͂̐ݒ�
	int GetLife(void)override { return m_nLife; }		//�̗͂̎擾

	static bool GetBulletFlag() { return BulletFlag; }	//�e�̃t���O�̎擾����
	static HRESULT Load(void);							//�e�N�X�`���̓ǂݍ���
	static void Unload(void);							//�e�N�X�`���̔j��
	static CPlayer *Create(int nLife);					//����

private:
	static LPDIRECT3DTEXTURE9 m_pTexturePlayer;	//�e�N�X�`���ւ̃|�C���^
	static 	int m_nLife;						//�v���C���[�̗̑�
	static bool BulletFlag;						//�e�̃t���O	
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;			//���_�o�b�t�@�̃|�C���^
	D3DXVECTOR3	m_PlayerPos;					//�ʒu
	int m_nTime;								//�e���˂܂ł̎���
};

#endif





