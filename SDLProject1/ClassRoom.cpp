#include "ClassRoom.h"



bool ClassRoom::onEnter()
{
	//teacher png
	if (!TheTextureManager::Instance()->load("Images/mysprite.png", "animate", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	//clasroom background
	if (!TheTextureManager::Instance()->load("Images/hallway.png", "hallway", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* teacher = new Player(new LoaderParams(75, TheGame::Instance()->getGameHeight() - 300, 128, 164, "animate"));
	GameObject* background = new Background(new LoaderParams(0, 0, TheGame::Instance()->getGameWidth(), TheGame::Instance()->getGameHeight(), "hallway"), 0);
	m_gameObjects.push_back(background);
	m_gameObjects.push_back(teacher);
	std::cout << "entering Clasroom\n";
	return true;
}



void ClassRoom::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	//chek
	if (examFailed())
	{
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}
}
