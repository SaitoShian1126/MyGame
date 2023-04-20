//********************************************
//
//	item.cpp
//	Author: saito shian
//
//********************************************

//インクルード
#include <assert.h>
#include <time.h>
#include "item.h"
#include "application.h"
#include "renderer.h" 
#include "bullet.h"
#include "attack.h"
#include "game.h"
#include "sound.h"

//静的メンバ変数宣言
LPDIRECT3DTEXTURE9 CItem::m_pTextureItem[3] = {};
int CItem::m_AttackCount = 0;

//アイテムのコンストラクタ
CItem::CItem() : CObject2D(3)
{
	//********************************
	//メンバ変数のクリア
	//********************************
	m_ItemMoveTimeCount = 0;
	m_nItemMoveTime = 0;
	m_AttackItemUninitCount = 0;
	m_flag = true;
}

//アイテムのデストラクタ
CItem::~CItem()
{
	//何も書かない
}

//アイテムの初期化処理
HRESULT CItem::Init(void)
{
	CObject2D::Init();

	//乱数
	srand((unsigned int)time(NULL));	//起動時に一回だけ行うため初期化に書く	

	//********************************
	//メンバ変数の初期化
	//********************************
	m_ItemMoveTimeCount = 100;
	m_nItemMoveTime = 30;
	m_AttackItemUninitCount = 500;
	m_flag = true; 

	switch (m_nType)
	{
	case ITEMTYPE_SCOREUP:
		//テクスチャ反映
		BindTexture(m_pTextureItem[0]);
		break;
	case ITEMTYPE_LIFEUP:
		//テクスチャ反映
		BindTexture(m_pTextureItem[1]);
		break;
	case ITEMTYPE_ATTACKUP:
		//テクスチャ反映
		BindTexture(m_pTextureItem[2]);
		break;
	default:
		break;
	}

	return S_OK;
}

//アイテムの終了処理
void CItem::Uninit(void)
{
	CObject2D::Uninit();
}

//アイテムの更新処理
void CItem::Update()
{
	D3DXVECTOR3 ItemPos = GetPos();
	D3DXVECTOR3 ItemMove = GetMove();
	D3DXVECTOR3 ItemSize = GetSize();

	//位置の設定
	SetPosition(ItemPos);
	CObject2D::Update();

	for (int nCntType = 0; nCntType < MAX_OBJECT; nCntType++)
	{
		//オブジェクトのポインタ
		CObject *pObject;
		//どのタイプかの情報をポインタに代入
		pObject = GetObjects(3, nCntType);

		//nullチェック
		if (pObject != nullptr)
		{
			//**********************************************************
			// アイテムとプレイヤーの当たり判定
			//**********************************************************
			if (pObject->GetType() == TYPE_PLAYER)
			{
				//プレイヤーの位置
				D3DXVECTOR3 PlayerPos = pObject->GetPos();
				//プレイヤーの移動
				D3DXVECTOR3 PlayerMove = pObject->GetMove();
				//プレイヤーのサイズ
				D3DXVECTOR3 PlayerSize = pObject->GetSize();
				//プレイヤーの体力
				int nLife = pObject->GetLife();

				//プレイヤーの当たり判定
				if (ItemPos.x + ItemSize.x >= PlayerPos.x - PlayerSize.x
					&&ItemPos.x - ItemSize.x <= PlayerPos.x + PlayerSize.x
					&&ItemPos.y + ItemSize.y >= PlayerPos.y - PlayerSize.y
					&&ItemPos.y - ItemSize.y <= PlayerPos.y + PlayerSize.y)
				{
					if (m_nType == ITEMTYPE_SCOREUP)
					{
						//スコアの加算
						CGame::GetScore()->AddScore(2500);
						//サウンドの再生
						PlaySound(SOUND_LABEL_SE_SCORE);
					}
					else if (m_nType == ITEMTYPE_LIFEUP)
					{
						//プレイヤーの体力アップ
						nLife++;
						//プレイヤーの体力の保存
						pObject->SetLife(nLife);
						//サウンドの再生
						PlaySound(SOUND_LABEL_SE_LIFE);
					}
					else if (m_nType == ITEMTYPE_ATTACKUP)
					{
						CAttack::Create(D3DXVECTOR3(PlayerPos.x - 80.0f, PlayerPos.y - 80.0f, PlayerPos.z), D3DXVECTOR3(PlayerMove.x, PlayerMove.y, PlayerMove.z), D3DXVECTOR3(20.0f, 20.0f, 0.0f));
						CAttack2::Create(D3DXVECTOR3(PlayerPos.x - 80.0f, PlayerPos.y + 80.0f, PlayerPos.z), D3DXVECTOR3(PlayerMove.x, PlayerMove.y, PlayerMove.z), D3DXVECTOR3(20.0f, 20.0f, 0.0f));
						m_AttackCount++;
						//サウンドの再生
						PlaySound(SOUND_LABEL_SE_ATTACK);
					}
					//アイテムの削除
					Uninit();
					return;
				}
			}
		}
	}

	//プレイヤーが死んだら敵の出現カウントを初期化する
	if (CEnemy::GetPlayerDeathFlag() == true || CBullet::GetPlayerGameClear() == true)
	{
		m_AttackCount = 0;
		m_AttackItemUninitCount = 500;
	}

	if (m_nType == ITEMTYPE_ATTACKUP)
	{
		m_AttackItemUninitCount--;
		if (m_AttackItemUninitCount <= 0)
		{
			//アイテムの削除
			Uninit();
			return;
		}
	}

	//*******************************************
	//	アイテムの移動
	//*******************************************
	m_ItemMoveTimeCount--;
	if (m_ItemMoveTimeCount >= 0)
	{
		ItemMove.y = 3.0f;
		//位置設定
		SetMove(ItemMove);
	}
	if (m_ItemMoveTimeCount <= 0)
	{
		m_nItemMoveTime--;
		if (m_nItemMoveTime <= 0)
		{
			m_nRand = rand() % 4 + 1;	//0～9のランダムの数字を出したいときは%10を書く	1～6を出したいときは% 6 + 1になる
			m_flag = false;
		}
		if (m_nItemMoveTime <= 0)
		{
			m_nItemMoveTime = 30;
		}

		if (m_nRand == 1 && m_flag == false)
		{
			ItemMove.x = -3.0f;
			//位置設定
			SetMove(ItemMove);
		}
		else if (m_nRand == 2 && m_flag == false)
		{
			ItemMove.y = 3.0f;
			//位置設定
			SetMove(ItemMove);
		}
		else if (m_nRand == 3 && m_flag == false)
		{
			ItemMove.y = -3.0f;
			//位置設定
			SetMove(ItemMove);
		}

		else if (m_nRand == 4 && m_flag == false)
		{
			ItemMove.x = 3.0f;
			//位置設定
			SetMove(ItemMove);
		}

		//*********************************************
		//	敵の移動範囲制限
		//*********************************************
		//左の範囲
		if (ItemPos.x < 0.0f + 20.0f)
		{
			ItemPos.x = 0.0f + 20.0f;
		}
		//右の範囲
		if (ItemPos.x > SCREEN_WIDTH - 20.0f)
		{
			ItemPos.x = SCREEN_WIDTH - 20.0f;
		}
		//上の範囲
		if (ItemPos.y < 0.0f + 20.0f / 2)
		{
			ItemPos.y = 0.0f + 20.0f / 2;
		}
		//下の範囲
		if (ItemPos.y > SCREEN_HEIGHT - 20.0f / 2)
		{
			ItemPos.y = SCREEN_HEIGHT - 20.0f / 2;
		}
	}

	//位置更新
	ItemPos.x += ItemMove.x;
	ItemPos.y += ItemMove.y;
	ItemPos.z += ItemMove.z;

	//移動量減衰
	ItemPos.x += (0.0f - ItemMove.x) * 0.1f;
	ItemPos.y += (0.0f - ItemMove.y) * 0.1f;
	ItemPos.z += (0.0f - ItemMove.z) * 0.1f;

	//位置の設定
	SetPosition(ItemPos);
	SetMove(ItemMove);
}

//アイテムの描画処理
void CItem::Draw()
{
	CObject2D::Draw();
}

//アイテムの生成
CItem *CItem::Create(const D3DXVECTOR3 &pos, D3DXVECTOR3 size, ITEMTYPE type)
{
	CItem *pitem = nullptr;

	//クラスの生成
	pitem = new CItem;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pitem != nullptr)
	{
		//初期化処理
		pitem->SetItemType(type);
		pitem->Init();
		//設定処理
		pitem->SetPosition(pos);
		pitem->SetSize(size);
	}
	else
	{
		assert(false);
	}

	return pitem;
}

//アイテムの種類の設定
void CItem::SetItemType(ITEMTYPE type)
{
	m_nType = type;
}

//テクスチャの読み込み
HRESULT CItem::Load(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/スコアアイテム.png",
		&m_pTextureItem[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/体力アイテム.png",
		&m_pTextureItem[1]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/攻撃アイテム.png",
		&m_pTextureItem[2]);

	return S_OK;
}

//テクスチャの破棄
void CItem::Unload(void)
{
	for (int nCnt = 0; nCnt < 3; nCnt++)
	{
		//テクスチャの破棄
		if (m_pTextureItem[nCnt] != nullptr)
		{
			m_pTextureItem[nCnt]->Release();
			m_pTextureItem[nCnt] = nullptr;
		}
	}
}
