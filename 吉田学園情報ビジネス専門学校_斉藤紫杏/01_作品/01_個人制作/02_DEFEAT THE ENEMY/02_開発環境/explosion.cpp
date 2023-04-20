//********************************************
//
//	explosion.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include "explosion.h"
#include "application.h"
#include "renderer.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CExplosion::m_pTextureExplosion[2] = {};

//爆発のコンストラクタ
CExplosion::CExplosion()
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_ExplosionPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//位置のクリア
	m_ExplosionCol = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	//色のクリア
	m_nCounterAnimExplosion = 0;						//カウントアニメーションのクリア
	m_nPatternAnimExplosion = 0;						//パターンアニメーションのクリア
	m_nPatternAnimExplosionY = 0;
}

//爆発のデストラクタ
CExplosion::~CExplosion()
{
	//何も書かない
}

//爆発の初期化処理
HRESULT CExplosion::Init(void)
{
	CObject2D::Init();

	//********************************
	//メンバ変数の初期化
	//********************************
  	m_ExplosionPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//位置の初期化
	m_nCounterAnimExplosion = 0;						//カウントアニメーションの初期化
	m_nPatternAnimExplosion = 0;						//パターンアニメーションの初期化
	m_nPatternAnimExplosionY = 0;

	//色の設定
	//SetColor(1.0f, 0.3f, 0.0f, 1.0f);

	switch (m_nType)
	{
	case EXPLOTIONTYPE_BAKUHATU:
		//テクスチャ反映
		BindTexture(m_pTextureExplosion[0]);
		//テクスチャの設定
		SetTexture(8.0f, 0.0f, 2.0f, 0.0f);
		break;
	case EXPLOTIONTYPE_KOUGEKI:
		//テクスチャ反映
		BindTexture(m_pTextureExplosion[1]);
		//テクスチャの設定
		SetTexture(6.0f, 0.0f, 1.0f, 0.0f);
		break;
	case EXPLOTIONTYPE_BOSS:
		//テクスチャ反映
		BindTexture(m_pTextureExplosion[0]);
		//テクスチャの設定
		SetTexture(8.0f, 0.0f, 2.0f, 0.0f);
		break;
	default:
		break;
	}

	return S_OK;
}

//爆発の終了処理
void CExplosion::Uninit(void)
{
	//object2D終了処理関数呼び出し
	CObject2D::Uninit();
}

//爆発の更新処理
void CExplosion::Update(void)
{
	//位置の取得
	D3DXVECTOR3 ExplosionPos = GetPos();

	//for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	//{
	//	//オブジェクトのポインタ
	//	CObject *pObject;
	//	//どのタイプかの情報をポインタに代入
	//	pObject = GetObjects(3, nCntType);
	//
	//	//nullチェック
	//	if (pObject != nullptr)
	//	{
	//		//**********************************************************
	//		//	爆発とプレイヤーの当たり判定
	//		//**********************************************************
	//		if (pObject->GetType() == TYPE_PLAYER && m_nType == 0)
	//		{
	//			//プレイヤーの位置
	//			D3DXVECTOR3 PlayerPos = pObject->GetPos();
	//			//プレイヤーのサイズ
	//			D3DXVECTOR3 PlayerSize = pObject->GetSize();
	//			//プレイヤーの体力
	//			int nLife = pObject->GetLife();
	//
	//			//プレイヤーの当たり判定
	//			if (ExplosionPos.x + EXPLOSION_SIZE >= PlayerPos.x - PlayerSize.x
	//				&&ExplosionPos.x - EXPLOSION_SIZE <= PlayerPos.x + PlayerSize.x
	//				&&ExplosionPos.y + EXPLOSION_SIZE >= PlayerPos.y - PlayerSize.y
	//				&&ExplosionPos.y - EXPLOSION_SIZE <= PlayerPos.y + PlayerSize.y)
	//			{
	//				//敵の体力を減らす
	//				nLife--;
	//				//体力の保存
	//				pObject->SetLife(nLife);
	//				//体力が0になったら
	//				if (nLife == 0)
	//				{
	//					pObject->Uninit();
	//				}
	//			}
	//		}
	//	}
	//}

	//*******************************************
	//	爆発のアニメーション
	//*******************************************
	//object2Dの更新処理関数呼び出し
	CObject2D::Update();

	//爆発の位置
	SetPosition(ExplosionPos);

	if (m_nType == EXPLOTIONTYPE_BAKUHATU)
	{
		//アニメーションカウンターをインクリメント
		m_nCounterAnimExplosion++;

		if (m_nCounterAnimExplosion % 5 == 0)
		{
			//テクスチャの設定
			SetTexture(8.0f, (float)m_nPatternAnimExplosion, 2.0f, (float)m_nPatternAnimExplosionY);

			//アニメーションパターンのインクリメン
			m_nPatternAnimExplosion++;
		}

		//アニメーションパターンが最後まで行ったら終了
		else if (m_nPatternAnimExplosion == 8.0f)
		{
			m_nPatternAnimExplosion = 0;
			m_nPatternAnimExplosionY++;
			m_nPatternAnimExplosion++;
			if (m_nPatternAnimExplosionY == 2.0f)
			{
				Uninit();	//使用されてない
				return;
			}
		}
	}
	else if (m_nType == EXPLOTIONTYPE_KOUGEKI)
	{
		//アニメーションカウンターをインクリメント
		m_nCounterAnimExplosion++;

		if (m_nCounterAnimExplosion % 5 == 0)
		{
			//テクスチャの設定
			SetTexture(6.0f, (float)m_nPatternAnimExplosion, 1.0f, 0.0f);

			//アニメーションパターンのインクリメン
			m_nPatternAnimExplosion++;
		}

		//アニメーションパターンが最後まで行ったら終了
		if (m_nPatternAnimExplosion == MAX_KOUGEKI_PATTERN)
		{
			Uninit();	//使用されてない
			return;
		}
	}
	if (m_nType == EXPLOTIONTYPE_BOSS)
	{
		//アニメーションカウンターをインクリメント
		m_nCounterAnimExplosion++;

		if (m_nCounterAnimExplosion % 5 == 0)
		{
			//テクスチャの設定
			SetTexture(8.0f, (float)m_nPatternAnimExplosion, 2.0f, (float)m_nPatternAnimExplosionY);

			//アニメーションパターンのインクリメン
			m_nPatternAnimExplosion++;
		}

		//アニメーションパターンが最後まで行ったら終了
		else if (m_nPatternAnimExplosion == 8.0f)
		{
			m_nPatternAnimExplosion = 0;
			m_nPatternAnimExplosionY++;
			m_nPatternAnimExplosion++;
			//if (m_nPatternAnimExplosionY == 2.0f)
			//{
			//	Uninit();	//使用されてない
			//	return;
			//}
		}
	}
}

//爆発の描画処理
void CExplosion::Draw(void)
{
	CObject2D::Draw();
}

//爆発の生成
CExplosion *CExplosion::Create(const D3DXVECTOR3 &pos,D3DXVECTOR3 size,D3DXCOLOR col, EXPLOTIONTYPE nType)
{
	CExplosion *pExplosion = nullptr;

	//弾のインスタンスの生成
	pExplosion = new CExplosion;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pExplosion != nullptr)
	{
		pExplosion->SetExplotionType(nType);
		//初期化処理
		pExplosion->Init();
		//設定処理
		pExplosion->SetPosition(pos);
		pExplosion->SetSize(size);
		pExplosion->SetColor(col.r, col.g, col.b, col.a);
		pExplosion->SetType(TYPE_EXPLOSION);
	}
	else
	{
		assert(false);
	}

	return pExplosion;
}

//テクスチャの読み込み
HRESULT CExplosion::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/爆発.png",
		&m_pTextureExplosion[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/爆発1.png",
		&m_pTextureExplosion[1]);

	return S_OK;
}

//テクスチャの破棄
void CExplosion::Unload(void)
{
	//テクスチャの破棄
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_pTextureExplosion[nCnt] != NULL)
		{					  
			m_pTextureExplosion[nCnt]->Release();
			m_pTextureExplosion[nCnt] = NULL;
		}
	}
}

//爆発のタイプの設定
void CExplosion::SetExplotionType(EXPLOTIONTYPE type)
{
	m_nType = type;
}