//=============================================================================
//
// �r���{�[�h�ŃA�C�R���̕\�� [icon.h]
// Author : Tanaka Kouta
//
//=============================================================================
#ifndef _ICON_H_
#define _ICON_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "billboard.h"

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CIcon : public CBillboard
{
public:
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	explicit CIcon(int nPriority = PRIORITY_LEVEL3);
	~CIcon() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init(void) override;	// ����������
	void Uninit(void) override;		// �I������
	void Update(void) override;		// �X�V����
	void Draw(void) override;		// �`�揈��
	void SwapTexture(std::string url);

	void SetPath(std::string path) { m_path = path; }
	void SetDestroy(bool set) { m_bDestroy = set; }
	void SetScaling(bool set) { m_bScaling = set; }
	void SetFade(bool set) { m_bFade = set; }
	void SetScaling(bool set, bool limit) { m_bScaling = set, m_bLimit = limit; }

	static CIcon *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, std::string url, int nPriority);    // ����

private:
	D3DXVECTOR3 m_beginScale;
	std::string m_path;
	bool m_bScaling;
	bool m_bFade;
	bool m_bLimit;
	bool m_bDestroy;
	bool m_bAnim;
};

#endif