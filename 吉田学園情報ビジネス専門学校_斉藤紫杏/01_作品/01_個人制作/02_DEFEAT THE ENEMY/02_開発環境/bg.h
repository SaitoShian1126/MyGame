//********************************************
//
//	bg.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _BG_H_
#define _BG_H_

//�C���N���[�h
#include "main.h"
#include "object.h"

//�w�i�N���X
class CBg : public CObject
{
public:
	CBg();							//�R���X�g���N�^
	~CBg() override;				//�f�X�g���N�^

	HRESULT Init(void)override;		//�w�i�̏���������
	void Uninit(void)override;		//�w�i�̏I������
	void Update(void)override;		//�w�i�̍X�V����
	void Draw(void)override;		//�w�i�̕`�揈��

	void SetPosition(D3DXVECTOR3 pos)override { pos; }				//�w�i�̈ʒu
	void SetMove(D3DXVECTOR3 move)override { move; }				//�w�i�̈ړ�
	void SetSize(D3DXVECTOR3 size);									//�w�i�̃T�C�Y
	void SetLength(float length)override { length; }				//�w�i�̒���
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);					//�e�N�X�`�����f

	float GetLength(void) override { return m_fLength; }			//�g��k���̃X�P�[���̎擾

	D3DXVECTOR3 GetPos(void) override { return m_pos; }				//�ʒu�̎擾
	D3DXVECTOR3 GetMove(void) override { return m_move; }			//�ړ��ʂ̎擾
	D3DXVECTOR3 GetSize(void) override { return m_size; }			//�T�C�Y�̎擾
	D3DXVECTOR3 GetRot(void) override { return m_rot; }				//��]�̎擾

	D3DXCOLOR GetCol(void) override { return m_col; }				//�F�̎擾
	LPDIRECT3DVERTEXBUFFER9 GetBuffer() { return m_pVtxBuff; }		//�o�b�t�@�[�̎擾

	static CBg *Create(const D3DXVECTOR3 &pos,D3DXVECTOR3 size);	//����
	static HRESULT Load(void);										//�e�N�X�`���̓ǂݍ���
	static void Unload(void);										//�e�N�X�`���̔j��

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;	//�e�N�X�`��
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		//���_�o�b�t�@�̃|�C���^
	D3DXVECTOR3	m_pos;						//�ʒu
	D3DXVECTOR3	m_move;						//�ړ�
	D3DXVECTOR3 m_rot;						//��]
	D3DXVECTOR3 m_size;						//�T�C�Y
	D3DXCOLOR m_col;						//�F

	float m_fAngle;							//�p�x
	float m_fLength;						//�g��k���̃X�P�[��
	float m_fPosTexV;						//�e�N�X�`�����W�̊J�n�ʒu(V�l)
};

#endif




