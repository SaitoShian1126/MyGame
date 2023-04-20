//********************************************
//
//	attack.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _ATTACK_H_
#define _ATTACK_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�X�|�i�[�N���X
class CAttack : public CObject2D
{
public:
	CAttack();							//�R���X�g���N�^
	~CAttack()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�U���̏���������
	void Uninit(void)override;			//�U���̏I������
	void Update(void)override;			//�U���̍X�V����
	void Draw(void)override;			//�U���̕`�揈��

	static HRESULT Load(void);			//�e�N�X�`���̓ǂݍ���
	static void Unload(void);			//�e�N�X�`���̔j��
	static CAttack *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 move,D3DXVECTOR3 size);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureAttack;		//�e�N�X�`���ւ̃|�C���^
	int m_nTime;									//�U������܂ł̎���
};

//********************************************
//
//	attack2.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _ATTACK2_H_
#define _ATTACK2_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�U��2�N���X
class CAttack2 : public CAttack
{
public:
	CAttack2();							//�R���X�g���N�^
	~CAttack2()override;				//�f�X�g���N�^

	HRESULT Init(void)override;			//�U��2�̏���������
	void Uninit(void)override;			//�U��2�̏I������
	void Update(void)override;			//�U��2�̍X�V����
	void Draw(void)override;			//�U��2�̕`�揈��

	static HRESULT Load(void);			//�e�N�X�`���̓ǂݍ���
	static void Unload(void);			//�e�N�X�`���̔j��
	static CAttack2 *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 move, D3DXVECTOR3 size);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureAttack2;		//�e�N�X�`���ւ̃|�C���^
	int m_nTime;									//�U��2����܂ł̎���
};

#endif









#endif







