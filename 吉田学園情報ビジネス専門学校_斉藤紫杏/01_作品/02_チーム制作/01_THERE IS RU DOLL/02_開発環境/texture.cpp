//**************************************************
// 
// texture.cpp
// Author  : katsuki mizuki
// Author  : Yuda Kaito
// 
//**************************************************

//==================================================
// インクルード
//==================================================
#include "application.h"
#include "renderer.h"
#include "texture.h"
#include "file.h"

#include <assert.h>

//--------------------------------------------------
// デフォルトコンストラクタ
//--------------------------------------------------
CTexture::CTexture()
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CTexture::~CTexture()
{
}

//--------------------------------------------------
// 全ての読み込み
//--------------------------------------------------
void CTexture::LoadAll()
{
	nlohmann::json list = LoadJsonStage(L"Data/FILE/texture.json");
	
	for (int i = 0; i < (int)list["TEXTURE"].size(); ++i)
	{
		m_texturePath.insert(std::make_pair(list["TEXTURE"].at(i)[0], list["TEXTURE"].at(i)[1]));
	}
}

//--------------------------------------------------
// 読み込み
//--------------------------------------------------
void CTexture::Load(std::string inKey, std::string inFileName)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();
	LPDIRECT3DTEXTURE9 texture = nullptr;
	std::string fileName = inFileName;

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, &fileName.front(), &texture);

	assert(texture != nullptr);	// テクスチャのURLがないかキーが間違ってる。


	if (!ExistsKey(inKey))
	{
		m_texture.insert(std::make_pair(inKey, texture));
	}
	else
	{
		m_texture[inKey] = texture;
	}
}

//--------------------------------------------------
// 読み込み
//--------------------------------------------------
void CTexture::Load(std::vector<std::string> inTexture)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();
	LPDIRECT3DTEXTURE9 texture = nullptr;
	std::string fileName = inTexture[1];

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, &fileName.front(), &texture);

	assert(texture != nullptr);	// テクスチャのURLがないかキーが間違ってる。

	if (!ExistsKey(inTexture[0]))
	{
		m_texture.insert(std::make_pair(inTexture[0], texture));
	}
	else
	{
		m_texture[inTexture[0]] = texture;
	}
}

//--------------------------------------------------
// 全ての解放
//--------------------------------------------------
void CTexture::UnloadAll()
{
	m_texture.clear();
}

//--------------------------------------------------
// 解放
//--------------------------------------------------
void CTexture::Unload(std::string inKey)
{
	m_texture.erase(inKey);
}

//--------------------------------------------------
// 取得
//--------------------------------------------------
LPDIRECT3DTEXTURE9 CTexture::GetTexture(std::string inKey)
{
	// Keyが存在するか否か。
	if (!ExistsPath(inKey))
	{
		// Keyがなかった場合
		return nullptr;
	}

	// Keyが存在するか否か。
	if (!ExistsKey(inKey))
	{
		Load(inKey, m_texturePath[inKey]);
	} 

	/* ↓Keyがあった場合↓ */

	return m_texture[inKey];
}
