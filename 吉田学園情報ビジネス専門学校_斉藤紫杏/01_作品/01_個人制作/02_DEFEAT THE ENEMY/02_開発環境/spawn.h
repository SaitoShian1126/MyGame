//********************************************
//
//	spawn.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _SPAWN_H_
#define _SPAWN_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�}�N����`
#define SPAWN_SIZE_X		 (20.0f)	//�X�|�[����x�T�C�Y
#define SPAWN_SIZE_Y		 (25.0f)	//�X�|�[����y�T�C�Y

//�X�|�[���N���X
class CSpawn : public CObject2D
{
public:
	enum SPAWNTYPE
	{
		SPAWNTYPE_MAGICCIRCLE1 = 0,
		SPAWNTYPE_MAGICCIRCLE2,
		SPAWNTYPE_MAGICCIRCLE3
	};
public:
	CSpawn();							//�R���X�g���N�^
	~CSpawn()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�X�|�[���̏���������
	void Uninit(void)override;			//�X�|�[���̏I������
	void Update(void)override;			//�X�|�[���̍X�V����
	void Draw(void)override;			//�X�|�[���̕`�揈��
	void SetSpawnType(SPAWNTYPE type);	//�X�|�[���̎�ނ̐ݒ�
	void SetLife(int nLife)override;	//�̗͂̐ݒ�

	SPAWNTYPE GetSpawnType(void) { return SPAWNTYPE(); }	//�X�|�[���̎�ނ̎擾

	int GetLife(void)override { return m_nLife; }			//�̗͂̎擾

	static HRESULT Load(void);								//�e�N�X�`���̓ǂݍ���
	static void Unload(void);								//�e�N�X�`���̔j��
	static CSpawn *Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &move, D3DXVECTOR3 size, SPAWNTYPE nType, int nLife);	//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureSpawn[3];	//�e�N�X�`���ւ̃|�C���^
	SPAWNTYPE m_nType;								//�X�|�[���̎��
	int m_nUninitTimer;								//�폜����
	int m_nTimer;									//�g��k������
	int m_nLife;
};

#endif





