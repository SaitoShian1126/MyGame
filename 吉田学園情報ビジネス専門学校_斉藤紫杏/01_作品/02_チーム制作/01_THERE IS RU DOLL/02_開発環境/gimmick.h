//=============================================================================
//
// �M�~�b�N�̊�Տ��� [gimmick.h]
// Author : saito shian
//
//=============================================================================
#ifndef _GIMMICK_H_
#define _GIMMICK_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "objectX.h"

//=============================================================================
// �O����`
//=============================================================================
class CPlayer;
class CIcon;

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CGimmick : public CObjectX
{
public:
	//-------------------------------------------------------------------------
	// �M�~�b�N�̃^�C�v
	//-------------------------------------------------------------------------
	enum GIMMICKTYPE
	{
		GIMMICKTYPE_NONE = 0,
		GIMMICKTYPE_BARRAGEMOVEWALL,		// �A�łœ�����
		GIMMICKTYPE_ALTERNATEMOVEWALL,		// ���݂ɘA�łœ�����
		GIMMICKTYPE_PUSHMOVEWALL,			// �����M�~�b�N
		GIMMICKTYPE_GOAL,					// �S�[��
		GIMMICKTYPE_MAX
	};
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	explicit CGimmick(int nPriority = PRIORITY_LEVEL3);
	~CGimmick() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init() override;			// ����������
	void Uninit() override;				// �I������
	void Update() override;				// �X�V����
	void Draw() override;				// �`�揈��

	GIMMICKTYPE GetGimmickType(void) { return m_GimmickType; }	// �M�~�b�N�̎�ނ̎擾
	void SetGimmickType(GIMMICKTYPE type);						// �M�~�b�N�̎�ނ̐ݒ�

	bool Collision(CPlayer* inPlayer);							// �v���C���[���ڐG
	bool CollisionGimmick(CPlayer* inPlayer);					// �v���C���[���M�~�b�N�ɐڐG

	virtual void ConstOperate() = 0;		// ���̑���(�A�ŁA��])

	void SetCompletion(bool flag) { m_Completion = flag; }		// ������������ݒ�
	bool GetCompletion() { return m_Completion; }				// ������������m�点��

	void SetHitPlayer(CPlayer* inPlayer) { m_pHitPlayer = inPlayer; }
	CPlayer* GetHitPlayer() { return m_pHitPlayer; }

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	D3DXVECTOR3 m_Pos;				// �M�~�b�N�̈ʒu
	GIMMICKTYPE m_GimmickType;		// �M�~�b�N�̎��
	CPlayer* m_pHitPlayer;			// ���������v���C���[
	bool m_Completion;				// �����������ۂ��t���O
};
#endif
