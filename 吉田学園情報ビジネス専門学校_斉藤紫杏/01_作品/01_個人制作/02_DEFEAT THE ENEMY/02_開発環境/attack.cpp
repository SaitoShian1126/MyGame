//********************************************
//
//	attack.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include <time.h>
#include "attack.h"
#include "application.h"
#include "renderer.h" 
#include "player.h"
#include "effect.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CAttack::m_pTextureAttack = nullptr;

//攻撃のコンストラクタ
CAttack::CAttack()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_nTime = 0;
}

//攻撃のデストラクタ
CAttack::~CAttack()
{
	//何も書かない
}

//攻撃の初期化処理
HRESULT CAttack::Init(void)
{
	//object2D初期化処理関数呼び出し
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************
	m_nTime = 0;

	//テクスチャの反映
	BindTexture(m_pTextureAttack);

	return S_OK;
}

//攻撃の終了処理
void CAttack::Uninit(void)
{
	//object2D終了処理関数呼び出し
	CObject2D::Uninit();
}

//攻撃の更新処理
void CAttack::Update()
{
	//object2D更新処理関数呼び出し
	CObject2D::Update();

	D3DXVECTOR3 attackPos = GetPos();
	D3DXVECTOR3 attackMove = GetMove();

	//エフェクトの生成
	CEffect::Create(D3DXVECTOR3(attackPos), D3DXVECTOR3(20.0f, 20.0f, 0.0f), D3DXCOLOR(0.5f, 0.5f, 0.2f, 0.25f), 5);

	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//オブジェクトのポインタ
		CObject *pObject;
		//どのタイプかの情報をポインタに代入
		pObject = GetObjects(3, nCntType);

		//nullチェック
		if (pObject != nullptr)
		{
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//プレイヤーの位置
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				attackPos = D3DXVECTOR3(PlayerPos.x - 80.0f, PlayerPos.y - 80.0f, PlayerPos.z);
			}
		}
	}

	attackMove = attackPos;

	m_nTime--;
	if (m_nTime <= 0)
	{
		CBullet::Create(D3DXVECTOR3(attackPos), D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f), 0, 2, CBullet::BULLETTYPE_NOMAL);
	}
	if (m_nTime <= 0)
	{
		m_nTime = 15;
	}

	//位置の設定
	SetPosition(attackPos);
	SetMove(attackMove);
}

//攻撃の描画処理
void CAttack::Draw()
{
	CObject2D::Draw();
}

//攻撃の生成
CAttack *CAttack::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 move, D3DXVECTOR3 size)
{
	CAttack *pAttack = nullptr;

	//クラスの生成
	pAttack = new CAttack;				//2Dオブジェクトのインスタンス生成

										//nullチェック
	if (pAttack != nullptr)
	{
		//初期化処理
		pAttack->Init();
		//設定処理
		pAttack->SetPosition(pos);
		pAttack->SetMove(move);
		pAttack->SetSize(size);
		pAttack->SetType(TYPE_ATTACK);
	}
	else
	{
		assert(false);
	}

	return pAttack;
}

//テクスチャの読み込み
HRESULT CAttack::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/自機1.png",
		&m_pTextureAttack);

	return S_OK;
}

//テクスチャの破棄
void CAttack::Unload(void)
{
	//テクスチャの破棄
	if (m_pTextureAttack != nullptr)
	{
		m_pTextureAttack->Release();
		m_pTextureAttack = nullptr;
	}
}

//********************************************
//
//	attack2.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include <time.h>
#include "application.h"
#include "renderer.h" 
#include "player.h"
#include "effect.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CAttack2::m_pTextureAttack2 = nullptr;

//攻撃のコンストラクタ
CAttack2::CAttack2()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_nTime = 0;
}

//攻撃のデストラクタ
CAttack2::~CAttack2()
{
	//何も書かない
}

//攻撃の初期化処理
HRESULT CAttack2::Init(void)
{
	//object2D初期化処理関数呼び出し
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************
	m_nTime = 0;

	//テクスチャの反映
	BindTexture(m_pTextureAttack2);

	return S_OK;
}

//攻撃の終了処理
void CAttack2::Uninit(void)
{
	CObject2D::Uninit();
}

//攻撃の更新処理
void CAttack2::Update()
{
	D3DXVECTOR3 attackPos = GetPos();
	D3DXVECTOR3 attackMove = GetMove();

	//エフェクトの生成
	CEffect::Create(D3DXVECTOR3(attackPos), D3DXVECTOR3(20.0f, 20.0f, 0.0f), D3DXCOLOR(0.5f, 0.5f, 0.2f, 1.0f), 5);

	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//オブジェクトのポインタ
		CObject *pObject;
		//どのタイプかの情報をポインタに代入
		pObject = GetObjects(3, nCntType);

		//nullチェック
		if (pObject != nullptr)
		{
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//プレイヤーの位置
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				attackPos = D3DXVECTOR3(PlayerPos.x - 80.0f, PlayerPos.y + 80.0f, PlayerPos.z);
			}
		}
	}

	attackMove = attackPos;

	m_nTime--;
	if (m_nTime <= 0)
	{
		CBullet::Create(D3DXVECTOR3(attackPos), D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 5.0f, 0.0f), 0, 2, CBullet::BULLETTYPE_NOMAL);
	}
	if (m_nTime <= 0)
	{
		m_nTime = 15;
	}

	//位置の設定
	SetPosition(attackPos);
	SetMove(attackMove);
	CObject2D::Update();
}

//攻撃の描画処理
void CAttack2::Draw()
{
	CObject2D::Draw();
}

//攻撃の生成
CAttack2 *CAttack2::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 move, D3DXVECTOR3 size)
{
	CAttack2 *pAttack = nullptr;

	//クラスの生成
	pAttack = new CAttack2;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pAttack != nullptr)
	{
		//初期化処理
		pAttack->Init();
		//設定処理
		pAttack->SetPosition(pos);
		pAttack->SetMove(move);
		pAttack->SetSize(size);
		pAttack->SetType(TYPE_ATTACK);
	}
	else
	{
		assert(false);
	}

	return pAttack;
}

//テクスチャの読み込み
HRESULT CAttack2::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/自機1.png",
		&m_pTextureAttack2);

	return S_OK;
}

//テクスチャの破棄
void CAttack2::Unload(void)
{
	//テクスチャの破棄
	if (m_pTextureAttack2 != nullptr)
	{
		m_pTextureAttack2->Release();
		m_pTextureAttack2 = nullptr;
	}
}

