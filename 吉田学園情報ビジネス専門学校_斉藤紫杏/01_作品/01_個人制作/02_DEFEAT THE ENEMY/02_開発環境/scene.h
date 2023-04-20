//********************************************
//
//	scene.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _SCENE_H_
#define _SCENE_H_

//�C���N���[�h
#include "main.h"
#include "object2D.h"

//�}�N����`
#define SCENE_SIZE_X		 (20.0f)	//�V�[����x�T�C�Y
#define SCENE_SIZE_Y		 (25.0f)	//�V�[����y�T�C�Y

//�X�|�[���N���X
class CScene : public CObject2D
{
public:
	enum SCENETYPE
	{
		SCENETYPE_NONE = 0,
		SCENETYPE_BOSS,
		SCENETYPE_START,
		SCENETYPE_MAX
	};
public:
	CScene();							//�R���X�g���N�^
	~CScene()override;					//�f�X�g���N�^

	HRESULT Init(void)override;			//�V�[���̏���������
	void Uninit(void)override;			//�V�[���̏I������
	void Update(void)override;			//�V�[���̍X�V����
	void Draw(void)override;			//�V�[���̕`�揈��

	static HRESULT Load(void);			//�e�N�X�`���̓ǂݍ���
	static void Unload(void);			//�e�N�X�`���̔j��
	static CScene *Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, SCENETYPE type);	//����

	SCENETYPE GetSceneType(void) { return SCENETYPE(); }	//�V�[���̎�ނ̎擾
	void SetSceneType(SCENETYPE type);						//�V�[���̎�ނ̐ݒ�

private:
	static LPDIRECT3DTEXTURE9 m_pTextureScene[2];	//�e�N�X�`���ւ̃|�C���^
	SCENETYPE m_nType;								//�V�[���̎��
	int m_nUninitTimer;								//�폜����	
	bool m_flag;									//�t���O
};

#endif






