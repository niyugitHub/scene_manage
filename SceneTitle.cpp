#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneTest.h"

void SceneTitle::init()
{
	m_textPosY = 0;
	m_textVecY = 4;

	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	// 文字の移動
	m_textPosY += m_textVecY;
	if (m_textPosY < 0)
	{
		m_textPosY = 0;
		m_textVecY = 4;
	}
	if (m_textPosY > 200)
	{
		m_textPosY = 200;
		m_textVecY = -4;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		// Mainに切り替え
		return (new SceneMain);
	}
	if (padState & PAD_INPUT_2)
	{
		return(new SceneTest);
	}

	return this;
}

void SceneTitle::draw()
{
	DrawString(0, m_textPosY,"タイトル画面",GetColor(255,255,255));
}