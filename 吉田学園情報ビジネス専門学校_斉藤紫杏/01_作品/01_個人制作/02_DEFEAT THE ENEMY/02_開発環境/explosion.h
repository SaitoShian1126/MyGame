//********************************************
//
//	explosion.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�}�N����`
#define MAX_EXPLOSION_PATTERN	(8.0f)	//�����p�^�[�����̍ő�l
#define MAX_KOUGEKI_PATTERN		(6.0f)	//�U���p�^�[�����̍ő�l
#define EXPLOSION_SIZE			(25.0f)	//�����̑傫��

//�����̃N���X
class CExplosion : public CObject2D
{
public:
	enum EXPLOTIONTYPE
	{
		EXPLOTIONTYPE_BAKUHATU,	//�G�����񂾂Ƃ��̔���
		EXPLOTIONTYPE_BOSS,	//�{�X�����񂾂Ƃ��̔���
		EXPLOTIONTYPE_KOUGEKI	//�G�ɒe�������������̔���
	};
public:
	CExplosion();											//�����̃R���X�g���N�^
	~CExplosion()override;									//�����̃f�X�g���N�^
															  
	HRESULT Init(void)override;								//�����̏���������
	void Uninit(void)override;								//�����̏I������
	void Update(void)override;								//�����̍X�V����
	void Draw(void)override;								//�����̕`�揈��

	static HRESULT Load(void);								//�e�N�X�`���̓ǂݍ���
	static void Unload(void);								//�e�N�X�`���̔j��
	static CExplosion *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, D3DXCOLOR col, EXPLOTIONTYPE nType);	//����

	EXPLOTIONTYPE GetExplotionType(void) { return EXPLOTIONTYPE(); }	//�����̎�ނ̎擾
	void SetExplotionType(EXPLOTIONTYPE type);							//�����̎�ނ̐ݒ�

private:
	static LPDIRECT3DTEXTURE9 m_pTextureExplosion[2];		//�e�N�X�`���ւ̃|�C���^
	D3DXVECTOR3 m_ExplosionPos;								//�ʒu
	D3DXCOLOR m_ExplosionCol;								//�F
	EXPLOTIONTYPE m_nType;									//�����̃^�C�v
	int m_nCounterAnimExplosion;							//�A�j���[�V�����J�E���^�[
	int m_nPatternAnimExplosion;							//�A�j���[�V����X�p�^�[��No.
	int m_nPatternAnimExplosionY;							//�A�j���[�V����Y�p�^�[��No.
};

#endif