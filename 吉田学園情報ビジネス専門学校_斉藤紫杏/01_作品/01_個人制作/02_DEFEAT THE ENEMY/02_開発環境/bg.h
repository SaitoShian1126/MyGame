//********************************************
//
//	bg.h
//	Author: saito shian
//
//********************************************

//2重インクルードガード
#ifndef _BG_H_
#define _BG_H_

//インクルード
#include "main.h"
#include "object.h"

//背景クラス
class CBg : public CObject
{
public:
	CBg();							//コンストラクタ
	~CBg() override;				//デストラクタ

	HRESULT Init(void)override;		//背景の初期化処理
	void Uninit(void)override;		//背景の終了処理
	void Update(void)override;		//背景の更新処理
	void Draw(void)override;		//背景の描画処理

	void SetPosition(D3DXVECTOR3 pos)override { pos; }				//背景の位置
	void SetMove(D3DXVECTOR3 move)override { move; }				//背景の移動
	void SetSize(D3DXVECTOR3 size);									//背景のサイズ
	void SetLength(float length)override { length; }				//背景の長さ
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);					//テクスチャ反映

	float GetLength(void) override { return m_fLength; }			//拡大縮小のスケールの取得

	D3DXVECTOR3 GetPos(void) override { return m_pos; }				//位置の取得
	D3DXVECTOR3 GetMove(void) override { return m_move; }			//移動量の取得
	D3DXVECTOR3 GetSize(void) override { return m_size; }			//サイズの取得
	D3DXVECTOR3 GetRot(void) override { return m_rot; }				//回転の取得

	D3DXCOLOR GetCol(void) override { return m_col; }				//色の取得
	LPDIRECT3DVERTEXBUFFER9 GetBuffer() { return m_pVtxBuff; }		//バッファーの取得

	static CBg *Create(const D3DXVECTOR3 &pos,D3DXVECTOR3 size);	//生成
	static HRESULT Load(void);										//テクスチャの読み込み
	static void Unload(void);										//テクスチャの破棄

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;	//テクスチャ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		//頂点バッファのポインタ
	D3DXVECTOR3	m_pos;						//位置
	D3DXVECTOR3	m_move;						//移動
	D3DXVECTOR3 m_rot;						//回転
	D3DXVECTOR3 m_size;						//サイズ
	D3DXCOLOR m_col;						//色

	float m_fAngle;							//角度
	float m_fLength;						//拡大縮小のスケール
	float m_fPosTexV;						//テクスチャ座標の開始位置(V値)
};

#endif




