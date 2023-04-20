//********************************************
//
//	bullet.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _BULLE_H_
#define _BULLE_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�O���錾
class CFade;

//�e�̃N���X
class CBullet : public CObject2D
{
public:
	enum BULLETTYPE
	{
		BULLETTYPE_NOMAL = 0,			//�m�[�}���e
		BULLETTYPE_SITA,				//���ɍU������e
	};
public:
	CBullet();					//�e�̃R���X�g���N�^
	~CBullet()override;			//�e�̃f�X�g���N�^

	HRESULT Init(void);			//�e�̏���������
	void Uninit(void)override;	//�e�̏I������
	void Update(void)override;	//�e�̍X�V����
	void Draw(void)override;	//�e�̕`�揈��

	void SetUser(int nUser);
	static bool GetPlayerGameClear() { return PlayerGameClear; }
	static CBullet *Create(const D3DXVECTOR3 &pos,const D3DXVECTOR3 &move,D3DXVECTOR3 size,int nLife, int nUser, BULLETTYPE nType);		//����
	static int GetBullet(void) { return m_nCntDeath; }

	static HRESULT Load(void);							//�e�N�X�`���̓ǂݍ���
	static void Unload(void);							//�e�N�X�`���̔j��

	BULLETTYPE GetBulletType(void) { return BULLETTYPE(); }	//�e�̎�ނ̎擾
	void SetBulletType(BULLETTYPE type);					//�e�̎�ނ̐ݒ�

private:
	static LPDIRECT3DTEXTURE9 m_apTextureBullet[2];		//�e�N�X�`���ւ̃|�C���^
	static D3DXVECTOR3 m_BulletMove;					//�ړ���
	static int m_nCntDeath;								//���񂾓G�̐�
	static bool PlayerGameClear;						//�Q�[���N���A�t���O

	D3DXVECTOR3 m_BulletPos;							//�e�̈ʒu
	BULLETTYPE m_nType;									//�e�̎��
	CFade *m_pFade;										//�t�F�[�h�̃|�C���^
	
	int m_nLife;										//�e�̎���	
	int m_nUser;										//�ǂ̃^�C�v���g���Ă��邩
	int m_nRand;										//�����_��
	int m_nBossUninitTime;								//�{�X���������܂ł̎���
	int m_nItemRand;									//�A�C�e���̎�ނ̃����_��

	bool m_flag;										//�t���O			
	bool m_PlayerDeath;
};

#endif