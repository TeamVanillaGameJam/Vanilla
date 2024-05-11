#pragma once
#include "LoaderParams.h"
#include "SDLGameObject.h"
enum class Button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};
class MenuButton : public SDLGameObject
{
private:
	void (*m_callback)();

public:
	bool m_bReleased; 
public:
	MenuButton(const LoaderParams* pParams, void (*callback)());
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

};

class Background : public MenuButton
{
public:
	Background(const LoaderParams* pParams, void (*callback)());
	virtual void update() override;
};