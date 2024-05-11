#include "MenuButton.h"
#include "InputHandler.h"
MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()) 
	: SDLGameObject(pParams), m_callback(callback), m_bReleased(true)
{
	m_currentFrame =  (int)Button_state::MOUSE_OUT;
}
void MenuButton::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}
void MenuButton::update()
{
	Vector2D pMousePos = TheInputHandler::Instance()->getMousePosition();
	if (pMousePos.getX() < (m_position.getX() + m_width)
		&& pMousePos.getX() > m_position.getX()
		&& pMousePos.getY() < (m_position.getY() + m_height)
		&& pMousePos.getY() > m_position.getY())
	{
		//nz
		//m_currentFrame = (int)Button_state::MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState((int)Mouse_buttons::LEFT) && m_bReleased)
		{
			//m_currentFrame = (int)Button_state::CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState((int)Mouse_buttons::LEFT))
		{
			m_bReleased = true;
			//m_currentFrame = (int)Button_state::MOUSE_OVER;
		}
	}
	else
	{
		//m_currentFrame = (int)Button_state::MOUSE_OUT;
	}
}
void MenuButton::clean()
{
	SDLGameObject::clean();
}



Background::Background(const LoaderParams* pParams, void (*callback)())
		:MenuButton(pParams, callback)
{
	}
void Background::update()
{

}