//=============================================================================
//
// �|�[�Y���� [ pause.h ]
// Author : Yuda Kaito
//
//=============================================================================
#ifndef _PAUSE_H_
#define _PAUSE_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "object2D.h"

//=============================================================================
// �O���錾
//=============================================================================
class CObject2D;
class CPauseSelect;

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CPause : public CObject
{
public:
	enum ESelect
	{
		QUIT,
		RETRY,
		EXIT
	};
public:
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	CPause();
	~CPause() override;

	// ��������
	static CPause *Create();

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init(void) override;	// ����������
	void Uninit(void) override;		// �I������
	void Update(void) override;		// �X�V����
	void BeginUpdate();				// 
	void SelectUpdate();			// 
	void EndUpdate();				// 
	void Draw(void) override;		// �`�揈��

	bool GetEndFlag() { return m_isEndFlag; }

private:
	CObject2D* m_pBg;

	CPauseSelect* m_quit;
	CPauseSelect* m_retry;
	CPauseSelect* m_exit;

	ESelect m_select;
	int m_beginCount;		// �n�܂��Ă���J�E���g
	int m_endCount;			// �I���܂ł̃J�E���g
	bool m_isEndFlag;		// �I������t���O
	bool m_isBeginFlag;		// �n�܂��Ă�Œ��̃t���O
};

#endif