//=============================================================================
//
// �^�C������ [time.h]
// Author : kubota yuuki
// Author : kado takuma
//
//=============================================================================
#ifndef _TIME_H_
#define _TIME_H_
#include "main.h"
#include "object.h"

//=============================================================================
//  �O����`
//=============================================================================
class CNumber;

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CTime : public CObject
{
public:
	//-------------------------------------------------------------------------
	// �񋓌^
	//-------------------------------------------------------------------------
	enum EType
	{
		TYPE_TIMER = 0,
		TYPE_RANKING,
		TYPE_NONE
	};

	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	CTime(int nPriority = PRIORITY_LEVEL5);
	~CTime()override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init() override;									// ����������
	void Uninit() override;										// �I������
	void Update() override;										// �X�V����
	void Draw() override;										// �`�揈��
	
	void VtxUpdate() override {};										// ���_���W�X�V����
	void SetPos(D3DXVECTOR3 pos) override;								// ���W�ݒ菈��
	void SetSize(D3DXVECTOR3 size) override { m_size = size; };			// �T�C�Y�ݒ菈��
	void SetMove(D3DXVECTOR3 move) override { D3DXVECTOR3 i = move; };	// �ړ��ʐݒ菈��
	void SetCol(D3DXCOLOR col) override { D3DXCOLOR i = col; };			// �F�ݒ菈��
	void SetRot(D3DXVECTOR3 rot) override { D3DXVECTOR3 i = rot; };		// �����ݒ菈��
	void SetDigit(int nDigit) { m_nDigit = nDigit; }					// �����ݒ菈��
	void SetType(EType type) { m_Type = type; }							// �^�C�v�Z�b�g����

	D3DXVECTOR3 GetPos(void) override { return m_pos; }				// ���W�擾����
	D3DXVECTOR3 GetSize(void) override { return m_size; }			// �T�C�Y�擾����
	D3DXVECTOR3 GetMove(void) override { return D3DXVECTOR3(); }	// �ړ��ʎ擾����
	D3DXVECTOR3 GetRot(void) override { return D3DXVECTOR3(); }		// �����擾����
	D3DXCOLOR GetCol(void) override { return D3DXCOLOR(); }			// �F�擾����

	static CTime *Create(EType type, D3DXVECTOR3 pos,D3DXVECTOR3 size, int nScore, int nPriority);
	void SetTime(int nScore);
	void AddTime(int nValue);
	int GetTime();

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	static CNumber *m_apNumBer[5];
	static	CObject2D *	m_apObject2D[2];

	D3DXVECTOR3 m_pos;							// ���W
	D3DXVECTOR3 m_size;							// �T�C�Y
	int  m_nDigit;								// �g�p���錅��
	int m_nTime;								// �X�^�[�g����
	int  m_apnTime;								// ���i�[�ϐ�
	EType m_Type;								// �^�C�v
};

#endif