#include "InputHandler.h"


InputHandler* InputHandler::s_pInstance = nullptr;
InputHandler::InputHandler() : m_mousePosition(0, 0)
{
	for (int i = 0; i < MOUSEBUTTONSCOUNT; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

void InputHandler::clean()
{
}

void InputHandler::reset()
{
	for (short i = 0; i < 3; ++i)
	{
		m_mouseButtonStates[i] = false;
	}
}

void InputHandler::update()
{
	SDL_Event event;
	m_keystates = SDL_GetKeyboardState(nullptr);
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}
void InputHandler::onMouseButtonDown(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[(int)Mouse_buttons::LEFT] = true;
	}
	else if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[(int)Mouse_buttons::MIDDLE] = true;
	}
	else if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[(int)Mouse_buttons::RIGHT] = true;
	}
}
void InputHandler::onKeyDown()
{
}
void InputHandler::onKeyUp()
{
}
void InputHandler::onMouseMove(SDL_Event& event)
{
	m_mousePosition.setX(event.motion.x);
	m_mousePosition.setY(event.motion.y);
}
void InputHandler::onMouseButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[(int)Mouse_buttons::LEFT] = false;
	}
	else if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[(int)Mouse_buttons::MIDDLE] = false;
	}
	else if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[(int)Mouse_buttons::RIGHT] = false;
	}
}


//void InputHandler::update()
//{
//	SDL_Event event;
//	m_keystates = SDL_GetKeyboardState(nullptr);
//	while (SDL_PollEvent(&event))
//	{
//		if (event.type == SDL_QUIT)
//		{
//			TheGame::Instance()->quit();
//		}
//		else if (event.type == SDL_MOUSEBUTTONDOWN)
//		{
//			if (event.button.button == SDL_BUTTON_LEFT)
//			{
//				m_mouseButtonStates[(int)Mouse_buttons::LEFT] = true;
//			}
//			else if (event.button.button == SDL_BUTTON_MIDDLE)
//			{
//				m_mouseButtonStates[(int)Mouse_buttons::MIDDLE] = true;
//			}
//			else if (event.button.button == SDL_BUTTON_RIGHT)
//			{
//				m_mouseButtonStates[(int)Mouse_buttons::RIGHT] = true;
//			}
//		}
//	}
//}
bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		//else
		//{
		//	return false;
		//}
	}
	return false;
}
