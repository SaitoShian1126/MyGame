#ifndef _BILLBOARD_H_
#define _BILLBOARD_H_

#include "main.h"
#include "object.h"
#include <string>

class CBillboard : public CObject
{
public:
	enum EAlphaBlend
	{
		BLEND_NONE = 0,
		BLEND_ADDITIVE,
		BLEND_SUBSTRUCT,
		BLEND_MAX
	};

	enum EFlip
	{
		FLIP_NONE = 0,
		FLIP_HORIZON,
		FLIP_VERTICAL,
		FLIP_MAX
	};

	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	explicit CBillboard(int nPriority = PRIORITY_LEVEL3);
	~CBillboard() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init() override;									// ����������
	void Uninit() override;										// �I������
	void Update() override;										// �X�V����
	void Draw() override;										// �`�揈��
	void VtxUpdate() override;									// ���_���W�X�V����
	void SetPos(D3DXVECTOR3 pos) override;						// ���W�ݒ菈��
	void SetSize(D3DXVECTOR3 size) override { m_size = size; }	// �T�C�Y�ݒ菈��
	void SetMove(D3DXVECTOR3 move) override { m_move = move; }	// �ړ��ʐݒ菈��
	void SetCol(D3DXCOLOR col) override { m_col = col; }		// �F�ݒ菈��
	void SetRot(D3DXVECTOR3 rot) override { m_rot = rot; }		// �����ݒ菈��
	void BindTexture(std::string inPath);						// �h���̃e�N�X�`���|�C���^��e�̃e�N�X�`���|�C���^�ɑ�����鏈��
	void SetUV(float x_1, float x_2, float y_1, float y_2);		// �e�N�X�`�����W�X�V����
	void SetAnimation(const int U, const int V, const int Speed, const int Drawtimer, const bool loop);
	void SetFlip(EFlip flip);
	void SetRotate(bool set) { m_bIsRotate = set; }
	void SetBlend(EAlphaBlend blend) { m_blend = blend; }
	void SetStopAnim(const int X, const int Y);

	D3DXVECTOR3 GetPos(void) override { return m_pos; }			// ���W�擾����
	D3DXVECTOR3 GetSize(void) override { return m_size; }		// �T�C�Y�擾����
	D3DXVECTOR3 GetMove(void) override { return m_move; }		// �ړ��ʎ擾����
	D3DXVECTOR3 GetRot(void) override { return m_rot; }			// �����擾����
	D3DXCOLOR GetCol(void) override { return m_col; }			// �F�擾����

	static CBillboard *Create(D3DXVECTOR3 pos, int nPriority);	// ��������
	void LoadTexture(const char *aFileName);					// �e�N�X�`���̓ǂݍ���

private:
	LPDIRECT3DTEXTURE9 m_pTexture;			// �e�N�X�`���̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// ���_�o�b�t�@�̃|�C���^
	D3DXVECTOR3 m_pos;						// ���W
	D3DXVECTOR3 m_move;						// �ړ���
	D3DXVECTOR3 m_rot;						// ����
	D3DXVECTOR3 m_size;						// �T�C�Y
	D3DXCOLOR m_col;						// �F
	int m_CounterAnim;
	int m_PatternAnimX;
	int m_PatternAnimY;
	int m_DivisionX;						// X������
	int m_DivisionY;						// Y������
	int m_DivisionMAX;						// �ő啪����
	int m_AnimationSpeed;					// �A�j���[�V�������鑬�x
	int m_AnimationSpdCnt;
	int m_Timer;							// �^�C�}�[
	int m_CntTime;							// 
	float m_fLength;						// �Ίp���̒���
	float m_fAngle;							// �p�x
	bool m_bIsRotate;
	bool m_bAnimation;
	bool m_bLoop;
	EObjType m_type;						// �I�u�W�F�N�g�̃^�C�v
	EAlphaBlend m_blend;
	EFlip m_flip;
	D3DXMATRIX m_mtxWorld;					// ���[���h�}�g���b�N�X
};

#endif