#pragma once
#include "SceneBase.h"

class SceneMain : public SceneBase
{
public:
	SceneMain()
	{
		m_textPosX = 0;
		m_textVecX = 0;
		m_isEnd = false;
	}
	virtual ~SceneMain() {}


	virtual void init() override;
	virtual void end()override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

	virtual bool isEnd() { return m_isEnd; }
private:
	// テキスト表示位置変更
	int m_textPosX;
	int m_textVecX;

	bool m_isEnd;
};