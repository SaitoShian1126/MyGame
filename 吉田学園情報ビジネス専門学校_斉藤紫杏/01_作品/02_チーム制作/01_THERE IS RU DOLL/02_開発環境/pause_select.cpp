#include "pause_select.h"
#include "object2D.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPauseSelect::CPauseSelect() :
	CObject(PRIORITY_LEVEL5)
{
	SetType(OBJTYPE_PAUSE);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPauseSelect::~CPauseSelect()
{
}

//=============================================================================
// ��������
//=============================================================================
CPauseSelect * CPauseSelect::Create(ESelect inSelect)
{
	CPauseSelect *pLogo = new CPauseSelect();

	auto TextCreate = [](const char* inTag, float inPosX)
	{
		D3DXVECTOR3 pos = D3DXVECTOR3(inPosX, (float)-SCREEN_HEIGHT_HALF, 0.0f);
		D3DXVECTOR3 size = D3DXVECTOR3(400.0f * 0.25f, 850.0f * 0.5f, 0.0f);
		CObject2D* object = CObject2D::Create(inTag, pos, size, CObject::PRIORITY_LEVEL5);
		object->SetCanPoseUpdate();
		return object;
	};

	if (pLogo != nullptr)
	{
		pLogo->Init();
		switch (inSelect)
		{
		case CPauseSelect::QUIT:
		{
			float SelectBackPos = (float)SCREEN_WIDTH_HALF - 50.0f;

			pLogo->m_pText.resize(4);
			pLogo->m_pText[0] = TextCreate("BACK_B", (float)SCREEN_WIDTH_HALF - 200.0f - 380.0f);
			pLogo->m_pText[1] = TextCreate("BACK_A", (float)SCREEN_WIDTH_HALF - 200.0f - 300.0f);
			pLogo->m_pText[2] = TextCreate("BACK_C", (float)SCREEN_WIDTH_HALF - 200.0f - 200.0f);
			pLogo->m_pText[3] = TextCreate("BACK_K", (float)SCREEN_WIDTH_HALF - 200.0f - 100.0f);
		}
			break;
		case CPauseSelect::RETRY:
		{
			pLogo->m_pText.resize(5);
			pLogo->m_pText[0] = TextCreate("RETRY_R1", (float)SCREEN_WIDTH_HALF - 180.0f);
			pLogo->m_pText[1] = TextCreate("RETRY_E", (float)SCREEN_WIDTH_HALF - 100.0f);
			pLogo->m_pText[2] = TextCreate("RETRY_T", (float)SCREEN_WIDTH_HALF - 20.0f);
			pLogo->m_pText[3] = TextCreate("RETRY_R2", (float)SCREEN_WIDTH_HALF + 80.0f);
			pLogo->m_pText[4] = TextCreate("RETRY_Y", (float)SCREEN_WIDTH_HALF + 140.0f);
		}
		break;
		case CPauseSelect::EXIT:
		{
			pLogo->m_pText.resize(4);
			pLogo->m_pText[0] = TextCreate("QUIT_Q", (float)SCREEN_WIDTH_HALF + 200.0f + 50.0f);
			pLogo->m_pText[1] = TextCreate("QUIT_U", (float)SCREEN_WIDTH_HALF + 200.0f + 150.0f);
			pLogo->m_pText[2] = TextCreate("QUIT_I", (float)SCREEN_WIDTH_HALF + 200.0f + 250.0f);
			pLogo->m_pText[3] = TextCreate("QUIT_T",(float)SCREEN_WIDTH_HALF + 200.0f + 350.0f);
		}
		break;
		default:
			break;
		}
	}
	else
	{
		assert(false);
	}

	return pLogo;
}

//=============================================================================
// ������
//=============================================================================
HRESULT CPauseSelect::Init()
{

	return S_OK;
}

//=============================================================================
// �I��
//=============================================================================
void CPauseSelect::Uninit()
{
	for (int i = 0; i < (int)m_pText.size(); i++)
	{
		m_pText[i]->Uninit();
	}
	Release();
}

//=============================================================================
// �X�V
//=============================================================================
void CPauseSelect::Update()
{
}

//=============================================================================
// �`��
//=============================================================================
void CPauseSelect::Draw()
{
}

//=============================================================================
// �o��X�V
//=============================================================================
void CPauseSelect::BeginUpdate()
{
	for (int i = 0; i < (int)m_pText.size(); i++)
	{
		m_pText[i]->SetPos(m_pText[i]->GetPos() + D3DXVECTOR3(0.0f, 22.0f,0.0f));
	}
}

//=============================================================================
// �I�𒆍X�V
//=============================================================================
void CPauseSelect::SelectNowUpdate()
{
	static float time = 0.0f;
	for (int i = 0; i < (int)m_pText.size(); i++)
	{
		time += 0.05f;
		//D3DXVECTOR3 size = D3DXVECTOR3(400.0f * 0.5f, 850.0f * 0.5f, 0.0f);
		m_pText[i]->SetSize(D3DXVECTOR3(400.0f * 0.5f + sinf(time) * 40.0f, 850.0f * 0.5f + sinf(time) * 40.0f, 0.0f));
	}
}

//=============================================================================
// �I�����ĂȂ��X�V
//=============================================================================
void CPauseSelect::SelectNoUpdate()
{
}

void CPauseSelect::EndNowUpdate()
{
	static float time = 0.0f;
	for (int i = 0; i < (int)m_pText.size(); i++)
	{
		time += 0.05f;
		m_pText[i]->SetSize(D3DXVECTOR3(400.0f * 0.5f + sinf(time) * 50.0f, 850.0f * 0.5f + sinf(time) * 50.0f, 0.0f));
	}
}

void CPauseSelect::EndNoUpdate()
{
	for (int i = 0; i < (int)m_pText.size(); i++)
	{
		m_pText[i]->SetPos(m_pText[i]->GetPos() - D3DXVECTOR3(0.0f, 22.0f, 0.0f));
	}
}
