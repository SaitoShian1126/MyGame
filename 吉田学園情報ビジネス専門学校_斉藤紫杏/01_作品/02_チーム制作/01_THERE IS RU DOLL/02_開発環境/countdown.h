//=============================================================================
//
//�J�E���g�_�E������ [countdown.h]
// Author : KADO TAKUMA
//
//=============================================================================
#ifndef _COUNTDOWN_H_
#define _COUNTDOWN_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "object2D.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define COUNTDOWN_TEXTURE	(4)				// �g�p����e�N�X�`���̖���
#define COUNTDOWN_WIDTH		(700.0f)		// �J�E���g�_�E���̕�
#define COUNTDOWN_HEIGHT	(700.0f)		// �J�E���g�_�E���̍���

//=============================================================================
// �񋓌^
//=============================================================================
enum ECountDown
{
	COUNTDOWN_3,
	COUNTDOWN_2,
	COUNTDOWN_1,
	COUNTDOWN_START,
	COUNTDOWN_MAX
};

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CCountDown : public CObject2D
{
public:
	//--------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//--------------------------------
	CCountDown(int nPriority = PRIORITY_LEVEL5);
	~CCountDown() override;

	//--------------------------------
	// �����o�[�֐�
	//--------------------------------
	HRESULT Init(void) override;					// ����������
	void Uninit(void) override;						// �I������
	void Update(void) override;						// �X�V����
	void Draw(void) override;						// �`�揈��
	static CCountDown *Create(D3DXVECTOR3 pos);		// �A�C�e���̐����֐�
	static HRESULT Load(void);						// �e�N�X�`���̓ǂݍ��݊֐�
	static void UnLoad(void);						// �e�N�X�`���̔j���֐�

private:
	//--------------------------------
	// �����o�[�ϐ�
	//--------------------------------
	static LPDIRECT3DTEXTURE9 m_pTexture[COUNTDOWN_TEXTURE];		// �e�N�X�`���̃|�C���^
	int m_nCounter;

	CObject2D *m_pObject;
};

#endif