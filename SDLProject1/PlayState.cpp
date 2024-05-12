#include "PlayState.h"



void placeholder()
{
	return;
}
void correctAnswer()
{
	std::cout << starsCount << "\n";
	starsCount++;
	std::cout << starsCount << "\n";
	clickedCount++;
}
void incorrectAnswer()
{
	clickedCount++;
	std::cout << "losho\n";
	return;//kolega sepemvri

}
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

	GameObject* star = nullptr;
	for (size_t x = 0; x < starsCount; ++x)
	{
		star = new MenuButton(new LoaderParams(0 + 60 * x, 40, 128, 128, "star"), placeholder);
		m_gameObjects.push_back(star);
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
	std::cout << "Here we are\n";
	if (!TheTextureManager::Instance()->load("Images/mysprite.png", "animate", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/hallwaystefo.png", "hallway", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	//std::cout << "last x position: " << lastm_positionX << std::endl;
	
	GameObject* player = new Player(new LoaderParams(TheGame::Instance()->lastm_positionX, TheGame::Instance()->getGameHeight() - 300, 128, 164, "animate"));
	GameObject* background = new Background(new LoaderParams(0, 0, TheGame::Instance()->getGameWidth(), TheGame::Instance()->getGameHeight(), "hallway"), 0);
	m_gameObjects.push_back(background);
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
//TODO

//this was not implemented
PlayState::~PlayState()
{
	for (size_t i = 0; i < m_gameObjects.size(); ++i)
		delete m_gameObjects[i];

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




bool ClassRoom::onEnter()
{
	//clasroom background
	if (!TheTextureManager::Instance()->load("Images/classroom.png", "classroom", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* background = new Background(new LoaderParams(0, 0, 1000, 800, "classroom"), 0);
	m_gameObjects.push_back(background);

	state.push_back(1);

	std::cout << "entering Clasroom\n";
	return true;
}



void ClassRoom::update()
{
	if (starsCount)
	{
		//star
		if (!TheTextureManager::Instance()->load("Images/star.png", "star", TheGame::Instance()->getRenderer()))
		{
			return;
		}
	}
	GameObject* star = nullptr;
	for (size_t x = 0; x < starsCount; ++x)
	{
		star = new MenuButton(new LoaderParams(0 + 60 * x, 40, 128, 128, "star"), placeholder);
		m_gameObjects.push_back(star);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
	     m_gameObjects[i]->update();
	}
	for (int i = 0; i < questions.size(); i++)
	{
		if (drawQuestion[i])
		{
			questions[i]->update();
		}
	}

	if (clickedCount >= 3)
	{
		std::cout << "clickled 5 times\n";
		clickedCount = 0;
		TheGame::Instance()->getStateMachine()->popState();
		TheGame::Instance()->getStateMachine()->pushState(new PlayState());
	}

}

bool ClassRoom::examFailed()
{
	return false;
}

void ClassRoom::render()
{
	PlayState::render();
	//for (size_t i = 0; i < questions.size(); ++i)
	//{
	//	questions[i]->draw();
	//}
}



bool DS::onEnter()
{	
	//if (!TheTextureManager::Instance()->load("Images/DSquestion.png", "dsquestion", TheGame::Instance()->getRenderer()))
	//{
	//	return false;
	//}
	//if (!TheTextureManager::Instance()->load("Images/DSAnswer1.png", "dsanswer1", TheGame::Instance()->getRenderer()))
	//{
	//	return false;
	//}
	//if (!TheTextureManager::Instance()->load("Images/DSAnswer2.png", "dsanswer2", TheGame::Instance()->getRenderer()))
	//{
	//	return false;
	//}
	//if (!TheTextureManager::Instance()->load("Images/DSAnswer3.png", "dsanswer3", TheGame::Instance()->getRenderer()))
	//{
	//	return false;
	//}

	if (!ClassRoom::onEnter())
		return false;

	//GameObject* question = new MenuButton(new LoaderParams(0, 0, 1000, 800, "dsquestion"), nullptr);
	//GameObject* answer1 = new MenuButton(new LoaderParams(0, 0, 1000, 800, "dsanswer1"), 0);
	//GameObject* answer2 = new MenuButton(new LoaderParams(0, 0, 1000, 800, "dsanswer2"), 0);
	//GameObject* answer3 = new MenuButton(new LoaderParams(0, 0, 1000, 800, "dsanswer3"), 0);
	//m_gameObjects.push_back(question);
	//m_gameObjects.push_back(answer1);
	//m_gameObjects.push_back(answer2);
	//m_gameObjects.push_back(answer3);

	std::cout << "ds\n";
	return true;
}
void DS::update()
{

	ClassRoom::update();

}


bool DAA::onEnter()
{
	/*if (!TheTextureManager::Instance()->load("Images/DAAquestion.png", "daaquestion", TheGame::Instance()->getRenderer()))
	{
		return false;
	}*/
	//if (!TheTextureManager::Instance()->load("Images/DAAAnswer1.png", "daaanswer1", TheGame::Instance()->getRenderer()))
	//{
	//	return false;
	//}
	//if (!TheTextureManager::Instance()->load("Images/DAAAnswer2.png", "daaanswer2", TheGame::Instance()->getRenderer()))
	//{
	//	return false;
	//}
	//if (!TheTextureManager::Instance()->load("Images/DAAAnswer3.png", "daaanswer3", TheGame::Instance()->getRenderer()))
	//{
	//	return false;
	//}


	if (!ClassRoom::onEnter())
		return false;
	/*GameObject* teacher = new Player(new LoaderParams(75, TheGame::Instance()->getGameHeight() - 300, 128, 164, "animate"));
	m_gameObjects.push_back(teacher);*/

	//GameObject* question = new MenuButton(new LoaderParams(0, 0, 1000, 800, "daaquestion"), nullptr);
	//GameObject* answer1 = new MenuButton(new LoaderParams(0, 0, 1000, 800, "daaanswer1"), 0);
	//GameObject* answer2 = new MenuButton(new LoaderParams(0, 0, 1000, 800, "daaanswer2"), 0);
	//GameObject* answer3 = new MenuButton(new LoaderParams(0, 0, 1000, 800, "daaanswer3"), 0);
	//m_gameObjects.push_back(question);
	//m_gameObjects.push_back(answer1);
	//m_gameObjects.push_back(answer2);
	//m_gameObjects.push_back(answer3);

	std::cout << "stefo\n";
	return true;
}


void  DAA::update()
{
	ClassRoom::update();
	/*for (size_t i = 0; i < questions.size(); ++i)
	{
		questions[i]->update();
	}*/
}

void OOP::render()
{
	ClassRoom::render();
	for (size_t i = 0; i < questions.size(); ++i)
	{
		if (drawQuestion[i])
		{
			questions[i]->draw();
		}

	}
}

bool OOP::onEnter()
{


	if (!ClassRoom::onEnter())
		return false;

	if (!TheTextureManager::Instance()->load("Images/OOPQuestion.png", "oopquestion", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer1.png", "oopanswer1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer2.png", "oopanswer2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer3.png", "oopanswer3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	std::cout << "Clicks count is " << clickedCount << std::endl;
	std::cout << "Objects count is:" << m_gameObjects.size() << std::endl;
	SDLGameObject* question = nullptr;
	SDLGameObject* answer1 = nullptr;
	SDLGameObject* answer2 = nullptr;
	SDLGameObject* answer3 = nullptr;
	question = new MenuButton(new LoaderParams(600, 180, 200, 100, "oopquestion"), placeholder);
	answer1 = new MenuButton(new LoaderParams(600, 280, 200, 100, "oopanswer1"), correctAnswer);
	answer2 = new MenuButton(new LoaderParams(600, 380, 200, 100, "oopanswer2"), incorrectAnswer);
	answer3 = new MenuButton(new LoaderParams(800, 180, 200, 100, "oopanswer3"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);











	//m_gameObjects.push_back(question);
	//m_gameObjects.push_back(answer1);
	//m_gameObjects.push_back(answer2);
	//m_gameObjects.push_back(answer3);

	///*GameObject* teacher = new Player(new LoaderParams(75, TheGame::Instance()->getGameHeight() - 300, 128, 164, "animate"));
	//m_gameObjects.push_back(teacher);*/

	//GameObject* question = nullptr;
	//GameObject* answer1 =  nullptr;
	//GameObject* answer2 =  nullptr;
	//GameObject* answer3 =  nullptr;

	//question = new MenuButton(new LoaderParams(600, 180, 200, 100, "oopquestion"), placeholder);
	//answer1 = new MenuButton(new LoaderParams(600, 280, 200, 100, "oopanswer1"), correctAnswer);
	//answer2 = new MenuButton(new LoaderParams(600, 380, 200, 100, "oopanswer2"), incorrectAnswer);
	//answer3 = new MenuButton(new LoaderParams(800, 180, 200, 100, "oopanswer3"), incorrectAnswer);

	//m_gameObjects.push_back(question);
	//indexes[0] = m_gameObjects.size();
	//m_gameObjects.push_back(answer1);
	//indexes[1] = m_gameObjects.size();
	//m_gameObjects.push_back(answer2);
	//indexes[2] = m_gameObjects.size();
	//m_gameObjects.push_back(answer3);
	//indexes[3] = m_gameObjects.size();


	std::cout << "stefo\n";
	return true;
}


void  OOP::update()
{
	//size_t localClikedCount = clickedCount;
	  ClassRoom::update();
	  //if (clickedForClassroom)
	  //{
		 // std::cout << "clickled 5 times\n";
		 // clickedCount = 0;
		 // TheGame::Instance()->getStateMachine()->popState();
		 // TheGame::Instance()->getStateMachine()->pushState(new OOP());
	  //}
	//if (clickedCount != localClikedCount)
	 //  clicked = true;
	/*if (clickedCount > 0 && m_gameObjects.size() > 4)
	{
		std::cout << "Clicks count is " << clickedCount << std::endl;
		std::cout << "Objects count is:" << m_gameObjects.size() << std::endl;
		GameObject* question = nullptr;
		GameObject* answer1 = nullptr;
		GameObject* answer2 = nullptr;
		GameObject* answer3 = nullptr;*/


		/*m_gameObjects.pop_back();
		std::cout << "Objects NEW count is:" << m_gameObjects.size() << std::endl;

		m_gameObjects.pop_back();
		std::cout << "Objects NEW count is:" << m_gameObjects.size() << std::endl;

		m_gameObjects.pop_back();
		std::cout << "Objects NEW count is:" << m_gameObjects.size() << std::endl;

		m_gameObjects.pop_back();
		std::cout << "Objects NEW count is:" << m_gameObjects.size() << std::endl;*/
		/*if (clickedCount % 3 == 0)
		{
			if (!TheTextureManager::Instance()->load("Images/OOPAnswer1.png", "oopanswer3", TheGame::Instance()->getRenderer()))
			{
				return;
			}
			if (!TheTextureManager::Instance()->load("Images/OOPQuestion.png", "oopquestion", TheGame::Instance()->getRenderer()))
			{

				return;
			}
			if (!TheTextureManager::Instance()->load("Images/OOPAnswer3.png", "oopanswer1", TheGame::Instance()->getRenderer()))
			{
				return;
			}
			if (!TheTextureManager::Instance()->load("Images/OOPAnswer2.png", "oopanswer2", TheGame::Instance()->getRenderer()))
			{
				return;
			}

			question = new MenuButton(new LoaderParams(600, 180, 200, 100, "oopquestion"), placeholder);
			answer1 = new MenuButton(new LoaderParams(600, 280, 200, 100, "oopanswer1"), correctAnswer);
			answer2 = new MenuButton(new LoaderParams(600, 380, 200, 100, "oopanswer2"), incorrectAnswer);
			answer3 = new MenuButton(new LoaderParams(800, 180, 200, 100, "oopanswer3"), incorrectAnswer);

		}
		else if (clickedCount % 3 == 1)
		{
			if (!TheTextureManager::Instance()->load("Images/newgame.png", "oopanswer3", TheGame::Instance()->getRenderer()))
			{
				std::cout << "Changed image1\n";
				return;

			}
			if (!TheTextureManager::Instance()->load("Images/OOPQuestion.png", "oopquestion", TheGame::Instance()->getRenderer()))
			{

				return;
			}
			if (!TheTextureManager::Instance()->load("Images/OOPAnswer2.png", "oopanswer1", TheGame::Instance()->getRenderer()))
			{
				return;
			}
			if (!TheTextureManager::Instance()->load("Images/OOPAnswer3.png", "oopanswer2", TheGame::Instance()->getRenderer()))
			{
				return;
			}

			question = new MenuButton(new LoaderParams(600, 180, 200, 100, "oopquestion"), placeholder);
			answer1 = new MenuButton(new LoaderParams(600, 280, 200, 100, "oopanswer1"), correctAnswer);
			answer2 = new MenuButton(new LoaderParams(600, 380, 200, 100, "oopanswer2"), incorrectAnswer);
			answer3 = new MenuButton(new LoaderParams(800, 180, 200, 100, "oopanswer3"), incorrectAnswer);

		}
		else if (clickedCount % 3 == 2)
		{
			if (!TheTextureManager::Instance()->load("Images/OOPAnswer1.png", "oopanswer3", TheGame::Instance()->getRenderer()))
			{
				return;
			}
			if (!TheTextureManager::Instance()->load("Images/exit.png", "oopquestion", TheGame::Instance()->getRenderer()))
			{
				std::cout << "Changed image2\n";
				return;
			}
			if (!TheTextureManager::Instance()->load("Images/OOPAnswer3.png", "oopanswer1", TheGame::Instance()->getRenderer()))
			{
				return;
			}
			if (!TheTextureManager::Instance()->load("Images/OOPAnswer2.png", "oopanswer2", TheGame::Instance()->getRenderer()))
			{
				return;
			}

			question = new MenuButton(new LoaderParams(600, 180, 200, 100, "oopquestion"), placeholder);
			answer1 = new MenuButton(new LoaderParams(600, 280, 200, 100, "oopanswer1"), correctAnswer);
			answer2 = new MenuButton(new LoaderParams(600, 380, 200, 100, "oopanswer2"), incorrectAnswer);
			answer3 = new MenuButton(new LoaderParams(800, 180, 200, 100, "oopanswer3"), incorrectAnswer);

		}
		m_gameObjects.push_back(question);
		m_gameObjects.push_back(answer1);
		m_gameObjects.push_back(answer2);
		m_gameObjects.push_back(answer3);*/
		//clicked = false;
	}

