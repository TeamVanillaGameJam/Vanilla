#include "Game.h"
#include <iostream>
#include "LoaderParams.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = nullptr;

bool Game::init(const char* title, int xpos, int ypos, int width,
	int height, bool fullscreen)
{

	m_gameHeight = height;
	m_gameWidth = width;
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer,
					143, 188, 143, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	
	// to load
	//if (!TheTextureManager::Instance()->load("Images/anim.png",
	if (!TheTextureManager::Instance()->load("Images/mysprite.png","animate", m_pRenderer)) // in the example is TextureManager --> TheTextureManager
	{
		return false;
	}
	//m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 164, "animate")));
	//m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 164, "animate")));
	//m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 64, 64, "animate")));

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	//TheInputHandler::Instance()->

	m_bRunning = true; // everything inited successfully, start the main loop
		return true;
}

//void Game::render()
//{
//	SDL_RenderClear(m_pRenderer); // clear to the draw colour
//	// loop through our objects and draw them
//	size_t GameObjectsCount = m_gameObjects.size();
//	for (size_t i = 0; i < GameObjectsCount; i++)
//	{
//		m_gameObjects[i]->draw();
//	}
//	SDL_RenderPresent(m_pRenderer); // draw to the screen
//}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);

	TheInputHandler::Instance()->clean();


	SDL_Quit();
}

void Game::handleEvents()
{
	//SDL_Event event;
	//if (SDL_PollEvent(&event))
	//{
	//	switch (event.type)
	//	{
	//	case SDL_QUIT:
	//		m_bRunning = false;
	//		break;
	//	default:
	//		break;
	//	}
	//}

	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

//void Game::update()
//{
//	// loop through and update our objects
//	// to take m_gameObjects.size() in another var
//	size_t GameObjectsCount = m_gameObjects.size();
//	for (size_t i = 0; i < GameObjectsCount; i++)
//	{
//		m_gameObjects[i]->update();
//	}
//}

void Game::draw()
{
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}
void Game::update()
{
	m_pGameStateMachine->update();
}