#include "PlayState.h"

void placeholder(){ return; }

const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	if (checkCollision(dynamic_cast<SDLGameObject*> (m_gameObjects[0]), dynamic_cast<SDLGameObject*> (m_gameObjects[1])))
	{
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}
}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("Images/mysprite.png", "animate", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/hallway.png", "hallway", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	GameObject* player = new Player(new LoaderParams(75, TheGame::Instance()->getGameHeight() - 300, 128, 164, "animate"));
	//GameObject* enemy = (new Enemy(new LoaderParams(400, 100, 128, 164, "animate"))); // if the animation is different - load and check
	GameObject* background = new Background(new LoaderParams(0, 0, TheGame::Instance()->getGameWidth(), TheGame::Instance()->getGameHeight(), "hallway"), 0);
	m_gameObjects.push_back(background);
	//m_gameObjects.push_back(enemy);
	m_gameObjects.push_back(player);
	std::cout << "entering PlayState\n";
	return true;
}
bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("animate");
	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(const SDLGameObject* p1, const SDLGameObject* p2) const
{
	//int leftA, leftB;
	//int rightA, rightB;
	//int topA, topB;
	//int bottomA, bottomB;
	//leftA = p1->getPosition().getX();
	//rightA = p1->getPosition().getX() + p1->getWidth();
	//topA = p1->getPosition().getY();
	//bottomA = p1->getPosition().getY() + p1->getHeight();
	////Calculate the sides of rect B
	//leftB = p2->getPosition().getX();
	//rightB = p2->getPosition().getX() + p2->getWidth();
	//topB = p2->getPosition().getY();
	//bottomB = p2->getPosition().getY() + p2->getHeight();
	////If any of the sides from A are outside of B
	//if (bottomA <= topB) { return false; }
	//if (topA >= bottomB) { return false; }
	//if (rightA <= leftB) { return false; }
	//if (leftA >= rightB) { return false; }
	//return true;
	return false;
}