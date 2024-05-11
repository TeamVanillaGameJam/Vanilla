#pragma once
#include "SDL.h"
#include <vector>
#include "Game.h"
const short MOUSEBUTTONSCOUNT = 3;
enum class Mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	void reset();

	bool getMouseButtonState(int buttonNumber) const
	{
		return m_mouseButtonStates[buttonNumber];
	}
	Vector2D getMousePosition() const
	{
		return m_mousePosition;
	}
	bool isKeyDown(SDL_Scancode key);

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

private:
	//key
	void onKeyDown();
	void onKeyUp();
	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

private:
	std::vector<bool> m_mouseButtonStates;
	Vector2D m_mousePosition;
	const Uint8* m_keystates = nullptr;


};
typedef InputHandler TheInputHandler;
