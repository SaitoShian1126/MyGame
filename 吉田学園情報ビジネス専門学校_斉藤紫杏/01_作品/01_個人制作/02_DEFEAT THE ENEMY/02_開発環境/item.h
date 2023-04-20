//********************************************
//
//	item.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _ITEM_H_
#define _ITEM_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�A�C�e���N���X
class CItem : public CObject2D
{
public:
	enum ITEMTYPE
	{
		ITEMTYPE_SCOREUP = 0,			//�X�R�A�A�b�v�A�C�e��
		ITEMTYPE_LIFEUP,				//�̗̓A�b�v�A�C�e��
		ITEMTYPE_ATTACKUP				//�U���̓A�b�v�A�C�e��
	};
public:
	CItem();							//�R���X�g���N�^
	~CItem()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�A�C�e���̏���������
	void Uninit(void)override;			//�A�C�e���̏I������
	void Update(void)override;			//�A�C�e���̍X�V����
	void Draw(void)override;			//�A�C�e���̕`�揈��
	void SetItemType(ITEMTYPE type);	//�A�C�e���̎�ނ̐ݒ�

	static int GetAttackCount(void) { return m_AttackCount; }	//�U���A�C�e���̃J�E���g�̎擾
	static HRESULT Load(void);									//�e�N�X�`���̓ǂݍ���
	static void Unload(void);									//�e�N�X�`���̔j��
	static CItem *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, ITEMTYPE nType);	//����

	ITEMTYPE GetItemType(void) { return ITEMTYPE(); }	//�A�C�e���̎�ނ̎擾

private:
	static LPDIRECT3DTEXTURE9 m_pTextureItem[3];	//�e�N�X�`���ւ̃|�C���^
	static int m_AttackCount;						//�U���A�C�e���̃J�E���g
	ITEMTYPE m_nType;								//�G�̎��
	int m_nRand;									//�����_��
	int m_ItemMoveTimeCount;						//�A�C�e���������܂ł̎���
	int m_nItemMoveTime;							//�ړ�����܂ł̎���
	int m_AttackItemUninitCount;					//�U���A�C�e���폜�܂ł̎���
	bool m_flag;									//�A�C�e�������ǂ̓��������邩�̃t���O
};

#endif






