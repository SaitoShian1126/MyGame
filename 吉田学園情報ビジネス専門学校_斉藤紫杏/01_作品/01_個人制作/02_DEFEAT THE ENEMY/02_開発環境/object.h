//********************************************
//
//	object.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _OBJECT_H_
#define _OBJECT_H_

//�C���N���[�h
#include "main.h"

//�}�N����`
#define MAX_OBJECT	(2048)		//�I�u�W�F�N�g�̍ő吔
#define MAX_DRAWPRIORITY (5)	//�v���C�I���e�B�̍ő吔

//�I�u�W�F�N�g�N���X
class CObject
{
public:
	//�I�u�W�F�N�g�̎��
	enum TYPE
	{
		TYPE_NONE = 0,
		TYPE_PLAYER,		//�v���C���[
		TYPE_ENEMY,			//�G
		TYPE_BULLET,		//�e
		TYPE_BOSS,			//�{�X
		TYPE_EXPLOSION,		//����
		TYPE_SPAWN,			//�X�|�[��
		TYPE_ATTACK,		//�U��
		TYPE_MODE,			//���[�h
		TYPE_MPENEMY,		//�ʎY�G
		TYPE_MAX
	};
public:
	explicit CObject(int nPriority = 3);				//�I�u�W�F�N�g�D�揇��
	virtual ~CObject();									//�f�X�g���N�^

	virtual HRESULT Init(void) = 0;						//�|���S���̏���������
	virtual void Uninit(void) = 0;						//�|���S���̏I������
	virtual void Update(void) = 0;						//�|���S���̍X�V����
	virtual void Draw(void) = 0;						//�|���S���̕`�揈��

	virtual void SetPosition(D3DXVECTOR3 pos) = 0;		//�|���S���̈ʒu����
	virtual void SetMove(D3DXVECTOR3 move) = 0;			//�|���S���̈ړ�����
	virtual void SetLength(float length) = 0;

	virtual D3DXVECTOR3 GetPos(void) = 0;				//�ʒu�̎擾����
	virtual D3DXVECTOR3 GetMove(void) = 0;				//�ړ��ʂ̎擾
	virtual D3DXVECTOR3 GetSize(void) = 0;				//�T�C�Y�̎擾����
	virtual D3DXVECTOR3 GetRot(void) = 0;				//��]�̎擾
	virtual float GetLength(void) = 0;					//�g��k���̃X�P�[���̎擾
	virtual D3DXCOLOR GetCol(void) = 0;					//�F�̎擾����
	
	virtual int GetLife(void) { return 0; }				//�̗͂̎擾
	virtual void SetLife(int nLife) { nLife; }			//�̗͂̐ݒ�

	void SetType(TYPE type);							//�^�C�v�̐ݒ�

	CObject *GetObjects(int nPriority,int nCntType);	//���Ԗڂ̃I�u�W�F�N�g���擾
	TYPE GetType(void) { return m_Type; }				//�^�C�v�̎擾����

	static void ReleaseAll(void);						//���ׂĂ̔j������
	static void UpdateAll(void);						//���ׂĂ̍X�V����
	static void DrawAll(void);							//���ׂĂ̕`�揈��
	static void ModeRelease(void);						//���[�h�̔j��

	void Release();										//�j��

private:
	static CObject *m_apObject[MAX_DRAWPRIORITY][MAX_OBJECT];		//�I�u�W�F�N�g2D�̃C���X�^���X
	static int m_nNumAll;											//���ׂĂ̔ԍ�
	TYPE m_Type;													//�I�u�W�F�N�g�̎��
	int m_nID;														//�i�[��̔ԍ�
	int m_nPriority;												//�`�揇
};

#endif


