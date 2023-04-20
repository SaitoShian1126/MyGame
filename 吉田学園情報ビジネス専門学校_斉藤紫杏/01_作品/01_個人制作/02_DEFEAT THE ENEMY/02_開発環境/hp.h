//********************************************
//
//	hp.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _hp_H_
#define _hp_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�}�N����`
#define LIFE_WIDTH		(25.0f)	//�|���S���̕�
#define BOSSLIFE_WIDTH	(0.5f)	//�{�X�̃|���S���̕�

//�̗̓o�[�N���X
class CHp : public CObject
{
public:
	CHp();							//�R���X�g���N�^
	~CHp()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�̗̓o�[�̏���������
	void Uninit(void)override;			//�̗̓o�[�̏I������
	void Update(void)override;			//�̗̓o�[�̍X�V����
	void Draw(void)override;			//�̗̓o�[�̕`�揈��

	void SetPosition(D3DXVECTOR3 pos) { pos; }		//�̗̓o�[�̈ʒu
	void SetMove(D3DXVECTOR3 move) { move; }		//�̗̓o�[�̈ړ�
	void SetSize(D3DXVECTOR3 size) { size; };		//�̗̓o�[�̃T�C�Y
	void SetCol(D3DXCOLOR col) { col; }				//�F
	void SetRot(D3DXVECTOR3 rot) { rot; }			//��]
	void SetLength(float length) { length; }					//�g��k���̃X�P�[��
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture) { pTexture; }	//�e�N�X�`�����f

	D3DXVECTOR3 GetPos(void) override { return m_pos; }				//�ʒu�̎擾
	D3DXVECTOR3 GetMove(void) override { return m_move; }			//�ړ��ʂ̎擾
	D3DXVECTOR3 GetSize(void) override { return m_size; }			//�T�C�Y�̎擾
	D3DXCOLOR GetCol(void) override { return m_col; }				//�F�̎擾
	D3DXVECTOR3 GetRot(void) override { return m_rot; }				//��]�̎擾
	float GetLength(void) override { return m_fLength; }			//�g��k���̃X�P�[���̎擾
	LPDIRECT3DVERTEXBUFFER9 GetBuffer() { return m_pVtxBuff; }		//�o�b�t�@�[�̎擾
	void SetColor(float Red, float Green, float Blue, float ��);	//�F�̐ݒ�

	static CHp *Create(void);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTexturehp;	//�e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		//���_�o�b�t�@�̃|�C���^
	D3DXVECTOR3	m_pos;						//�ʒu
	D3DXVECTOR3	m_move;						//�ړ�
	D3DXVECTOR3 m_rot;						//��]
	D3DXVECTOR3 m_size;						//�T�C�Y
	D3DXCOLOR m_col;						//�F
	int m_nPlayreLife;						//�v���C���[�̗̑͂�ۑ�����
	float m_fLength;						//�g��k���̃X�P�[��
};

//BOSS�̗̓o�[�N���X
class CBossHp : public CObject
{
public:
	CBossHp();							//�R���X�g���N�^
	~CBossHp()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//Boss�̗̓o�[�̏���������
	void Uninit(void)override;			//Boss�̗̓o�[�̏I������
	void Update(void)override;			//Boss�̗̓o�[�̍X�V����
	void Draw(void)override;			//Boss�̗̓o�[�̕`�揈��

	void SetPosition(D3DXVECTOR3 pos) { pos; }		//Boss�̗̓o�[�̈ʒu
	void SetMove(D3DXVECTOR3 move) { move; }		//Boss�̗̓o�[�̈ړ�
	void SetSize(D3DXVECTOR3 size) { size; };		//Boss�̗̓o�[�̃T�C�Y
	void SetCol(D3DXCOLOR col) { col; }				//�F
	void SetRot(D3DXVECTOR3 rot) { rot; }			//��]
	void SetLength(float length) { length; }					//�g��k���̃X�P�[��
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture) { pTexture; }	//�e�N�X�`�����f

	D3DXVECTOR3 GetPos(void) override { return m_pos; }				//�ʒu�̎擾
	D3DXVECTOR3 GetMove(void) override { return m_move; }			//�ړ��ʂ̎擾
	D3DXVECTOR3 GetSize(void) override { return m_size; }			//�T�C�Y�̎擾
	D3DXCOLOR GetCol(void) override { return m_col; }				//�F�̎擾
	D3DXVECTOR3 GetRot(void) override { return m_rot; }				//��]�̎擾
	float GetLength(void) override { return m_fLength; }			//�g��k���̃X�P�[���̎擾
	LPDIRECT3DVERTEXBUFFER9 GetBuffer() { return m_pVtxBuff; }		//�o�b�t�@�[�̎擾
	void SetColor(float Red, float Green, float Blue, float ��);	//�F�̐ݒ�

	static CBossHp *Create(void);	//����

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		//���_�o�b�t�@�̃|�C���^
	D3DXVECTOR3	m_pos;						//�ʒu
	D3DXVECTOR3	m_move;						//�ړ�
	D3DXVECTOR3 m_rot;						//��]
	D3DXVECTOR3 m_size;						//�T�C�Y
	D3DXCOLOR m_col;						//�F
	int m_nBossLife;						//�{�X�̗̑͂�ۑ�����
	float m_fLength;						//�g��k���̃X�P�[��
};

#endif








