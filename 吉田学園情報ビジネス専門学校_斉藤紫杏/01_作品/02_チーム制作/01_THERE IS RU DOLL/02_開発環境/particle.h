//=============================================================================
// particle.h
//=============================================================================
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "billboard.h"
#include <vector>

class CParticle : public CBillboard
{
public:
	enum EBehaviorType
	{
		BEHAVIOR_NONE = 0,
		BEHAVIOR_FLY,
		BEHAVIOR_FIREWORKS,
		BEHAVIOR_SMOKE,
		BEHAVIOR_MAX,
		BEHAVIOR_INVALID
	};

	struct SData
	{
		D3DXVECTOR3 destPos;	//�ړI�̈ʒu
		int frame;
	};

	explicit CParticle(int nPriority = PRIORITY_LEVEL3);
	~CParticle() override;

	HRESULT Init() override;			// ����������
	void Update() override;				// �X�V����

	//�Z�b�^�[
	void SetPath(std::string url) { m_path = url; }
	void SetBehavior(EBehaviorType behavior) { m_behavior = behavior; }
	void SetLower(D3DXVECTOR3 pos) { m_lowerPos = pos; }
	void SetDestCol(D3DXCOLOR col) { m_destCol = col; }
	void SetDelay(int time) { m_nDelay = time; }
	void SetGravity(bool set) { m_bGravity = set; }
	void SetGravity(bool set, float value) { m_bGravity = set, m_fFallSpeed = value; }
	void SetFade(bool set) { m_bFade = set; }
	void SetFade(bool set, float value) { m_bFade = set, m_fFadeValue = value; }
	void SetRotation(bool set, float value) { m_bRotate = set, m_fRotateSpeed = value; }
	void SetScaling(bool set) { m_bScaling = set; }
	void SetScaling(bool set, float value) { m_bScaling = set, m_fScalingValue = value; }
	void SetLocus(bool set) { m_bLocus = set; }
	void SetBounce(bool set) { m_bBounce = set; }
	void SetPosSpecify(bool set) { m_bPosSpecify = set; }
	void SetTransitionColor(bool set, D3DXCOLOR col) { m_bTransition = set, m_destCol = col; }

	//�Q�b�^�[
	D3DXVECTOR3 GetPos(void) { return m_pos; }

	static CParticle *Create(const D3DXVECTOR3 pos, EBehaviorType type, int nPriority);	// �p�[�e�B�N���̕��ő�̐ݒ肵���Ⴄ�Ƃ��p
	static CParticle *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move, const D3DXCOLOR col, const std::string url, int nPriority);	// ��������

private:
	void DetailSetting();
	void Preset();

	D3DXVECTOR3 m_pos;					// �ʒu
	D3DXVECTOR3 m_beginPos;				// �J�n���̈ʒu
	D3DXVECTOR3 m_posOld;				// �O��̈ʒu
	D3DXVECTOR3 m_destPos;				// �ړI�̈ʒu
	D3DXVECTOR3 m_lowerPos;
	D3DXVECTOR3 m_moveTransition;
	D3DXCOLOR m_col;					// �F
	D3DXCOLOR m_destCol;				// �ړI�̐F
	CParticle *m_pParticle;
	std::vector<SData> m_data;
	std::string m_path;
	SData m_effect;
	EBehaviorType m_behavior;
	int m_nTime;						// ����
	int m_nDelay;						// �x��
	int m_nDestroyTime;					// �G�t�F�N�g����������
	float m_fAngle;						// �p�x ���g�p
	float m_fRadius;					// ���a ���g�p
	float m_fAttenuation;				// ����
	float m_fSpeed;						// �X�s�[�h
	float m_fFadeValue;					// �G�t�F�N�g���t�F�[�h���鐔�l
	float m_fFallSpeed;					// �������x
	float m_fRotateSpeed;				// ��]���x
	float m_fScalingValue;				// �g�k���鐔�l
	float m_fTouchAttenuation = 1.0f;	// �n�ʂɐG�ꂽ���̌�����
	bool m_bGravity;					// ���ɗ����Ă������ǂ���
	bool m_bFade;						// �G�t�F�N�g�̃t�F�[�h���g�p���邩�ǂ���
	bool m_bRotate;						// ��]�����邩�ǂ���
	bool m_bScaling;					// �g�k���s�����ǂ���
	bool m_bLocus;						// �p�[�e�B�N���ɋO�Ղ����邩�ǂ���
	bool m_bBounce;						// �o�E���h�������邩�ǂ���
	bool m_bTransition;					// �F�̕ω������邩�ǂ���
	bool m_bPosSpecify;					// �ʒu�̎w������邩�ǂ���
	bool m_bPosOperate = false;			// �ʒu�̑���p
};
#endif