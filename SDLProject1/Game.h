#ifndef __Game__
#define __Game__

#include "SDL.h"
#include <SDL_image.h>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "GameStateMachine.h"

class Game
{
public:
	~Game() {}

	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int
		height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { clean(); } // to check if it is ok
	void draw();
	// a function to access the private running variable 
	bool running() { return m_bRunning; }
	int getGameWidth() const
	{
		return m_gameWidth;
	}
	int getGameHeight() const
	{
		return m_gameHeight;
	}

	// create the public instance function
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	// make the constructor private
private:
	//Game() {}; // to define

	// create the s_pInstance member variable
	static Game* s_pInstance;
private:

	int m_gameWidth;
	int m_gameHeight;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;
	GameStateMachine* m_pGameStateMachine;

	bool m_bRunning;
};


// create the typedef
typedef Game TheGame;

#endif /* defined(__Game__) */
