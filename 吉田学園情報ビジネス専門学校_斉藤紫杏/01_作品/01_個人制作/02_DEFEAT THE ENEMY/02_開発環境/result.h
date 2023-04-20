//********************************************
//
//	result.h
//	Author: saito shian
//
//********************************************

//2�d�C���N���[�h�K�[�h
#ifndef _RESULT_H_
#define _RESULT_H_

//�C���N���[�h
#include "main.h"
#include "mode.h"

//�O���錾
class CObject2D;
class CFade;
class CNumber;

//���U���g�N���X
class CResult : public CMode
{
public:
	enum TYPE
	{
		TYPE_NONE = 0,
		TYPE_GAMEOVER,		//�Q�[���I�[�o�[
		TYPE_GAMECLEAR,		//�Q�[���N���A
		TYPE_MAX
	};
public:
	CResult();							//�R���X�g���N�^
	~CResult();							//�f�X�g���N�^

	HRESULT Init(void);					//���U���g�̏���������
	void Uninit(void);					//���U���g�̏I������
	void Update(void);					//���U���g�̍X�V����
	void Draw(void);					//���U���g�̕`�揈��

	static void SetScore(int score);	//�X�R�A�̐ݒ�
	static void SetScore(void);			//�����L���O�X�R�A�̐ݒ�
	static void SetType(TYPE type);		//���U���g�̎�ނ̐ݒ�
	static CResult *Create();			//����

private:
	static LPDIRECT3DTEXTURE9 m_pTextureResult[3];	//�e�N�X�`���ւ̃|�C���^
	static TYPE m_type;								//���U���g�̎��
	static CNumber *m_pNumber[7];					//�����̃|�C���^
	static int m_nScore;							//�X�R�A
	static int m_aData;								//�f�[�^
	CObject2D *m_pObject;							//�I�u�W�F�N�g�̃|�C���^
	CFade *m_pFade;									//�t�F�[�h
};

#endif






