#include "PlayState.h"
static std::vector<bool> drawQuestion;

void setDraw() {
	if (clickedCount == 0)
	{
		drawQuestion[0] = true;
		drawQuestion[1] = true;
		drawQuestion[2] = true;
		drawQuestion[3] = true;
	}
	if (clickedCount == 1)
	{
		drawQuestion[0] = false;
		drawQuestion[1] = false;
		drawQuestion[2] = false;
		drawQuestion[3] = false;

		drawQuestion[4] = true;
		drawQuestion[5] = true;
		drawQuestion[6] = true;
		drawQuestion[7] = true;
	}

	if (clickedCount == 2)
	{
		drawQuestion[0] = false;
		drawQuestion[1] = false;
		drawQuestion[2] = false;
		drawQuestion[3] = false;

		drawQuestion[4] = false;
		drawQuestion[5] = false;
		drawQuestion[6] = false;
		drawQuestion[7] = false;

			drawQuestion[8] = true;
			drawQuestion[9] = true;
			drawQuestion[10] = true;
			drawQuestion[11] = true;
		}
		if (clickedCount == 3)
		{
			drawQuestion[0] = false;
			drawQuestion[1] = false;
			drawQuestion[2] = false;
			drawQuestion[3] = false;

			drawQuestion[4] = false;
			drawQuestion[5] = false;
			drawQuestion[6] = false;
			drawQuestion[7] = false;
		}
	
}


void placeholder()
{
	return;
}

void correctAnswer()
{
	std::cout << starsCount << "\n";
	std::cout << clickedCount << "\n";

	clickedCount++;
	setDraw();


	starsCount++;
}

void incorrectAnswer()
{
	clickedCount++;	
	setDraw();


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
	if (!TheTextureManager::Instance()->load("Images/hallwayFINAL.png", "hallway", TheGame::Instance()->getRenderer()))
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


	//for (size_t i = 0; i < 12; ++i)
	//{
	//	drawQuestion.push_back(false);
	//}

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
	//if (clickedCount == 0)
	//{
	//	questions[0]->update();
	//	questions[1]->update();
	//	questions[2]->update();
	//	questions[3]->update();
	//}
	//else if (clickedCount == 1)
	//{
	//	questions[4]->update();
	//	questions[5]->update();
	//	questions[6]->update();
	//	questions[7]->update();
	//}
	//else if (clickedCount == 2)
	//{
	//	questions[8]->update();
	//	questions[9]->update();
	//	questions[10]->update();
	//	questions[11]->update();
	//}
	for (int i = 0; i < questions.size(); i++)
	{
		if (drawQuestion[i])
		{
			questions[i]->update();
		}
	}


	size_t debug = drawQuestion.size();
	if (clickedCount >= 3)
	{
		size_t debug = drawQuestion.size();
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



bool DS::onEnter()
{

	if (!ClassRoom::onEnter())
		return false;

	if (!TheTextureManager::Instance()->load("Images/DSQuesiton1.png", "dsquestion1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer11.png", "dsanswer11", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer12.png", "dsanswer12", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer13.png", "dsanswer13", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	std::cout << "Clicks count is " << clickedCount << std::endl;
	std::cout << "Objects count is:" << m_gameObjects.size() << std::endl;
	SDLGameObject* question = nullptr;
	SDLGameObject* answer1 = nullptr;
	SDLGameObject* answer2 = nullptr;
	SDLGameObject* answer3 = nullptr;
	question = new MenuButton(new LoaderParams(600, 180, 200, 100, "dsquestion1"), placeholder);
	answer1 = new MenuButton(new LoaderParams(600, 280, 200, 100, "dsanswer11"), correctAnswer);
	answer2 = new MenuButton(new LoaderParams(600, 380, 200, 100, "dsanswer12"), incorrectAnswer);
	answer3 = new MenuButton(new LoaderParams(600, 480, 200, 100, "dsanswer13"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);



	if (!TheTextureManager::Instance()->load("Images/DSQuestion2.png", "dsquestion2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer21.png", "dsanswer21", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer22.png", "dsanswer22", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer23.png", "dsanswer23", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	question = nullptr;
	answer1 = nullptr;
	answer2 = nullptr;
	answer3 = nullptr;
	question = new MenuButton(new LoaderParams(800, 180, 200, 100, "dsquestion2"), placeholder);
	answer1 = new MenuButton(new LoaderParams(800, 280, 200, 100, "dsanswer21"), incorrectAnswer);
	answer2 = new MenuButton(new LoaderParams(800, 380, 200, 100, "dsanswer22"), correctAnswer);
	answer3 = new MenuButton(new LoaderParams(800, 480, 200, 100, "dsanswer23"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);



	if (!TheTextureManager::Instance()->load("Images/DSQuestion3.png", "dsquestion3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer31.png", "dsanswer31", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer32.png", "dsanswer32", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DSAnswer33.png", "dsanswer33", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	question = nullptr;
	answer1 = nullptr;
	answer2 = nullptr;
	answer3 = nullptr;
	question = new MenuButton(new LoaderParams(1000, 180, 200, 100, "dsquestion3"), placeholder);
	answer1 = new MenuButton(new LoaderParams(1000, 280, 200, 100, "dsanswer31"), correctAnswer);
	answer2 = new MenuButton(new LoaderParams(1000, 380, 200, 100, "dsanswer32"), incorrectAnswer);
	answer3 = new MenuButton(new LoaderParams(1000, 480, 200, 100, "dsanswer33"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);

	std::cout << "stefo\n";
	return true;
}
void DS::update()
{

	ClassRoom::update();

}


bool DAA::onEnter()
{

	if (!ClassRoom::onEnter())
		return false;

	if (!TheTextureManager::Instance()->load("Images/DAAQuestion1.png", "daaquestion1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer11.png", "daaanswer11", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer12.png", "daaanswer12", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer13.png", "daaanswer13", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	std::cout << "Clicks count is " << clickedCount << std::endl;
	std::cout << "Objects count is:" << m_gameObjects.size() << std::endl;
	SDLGameObject* question = nullptr;
	SDLGameObject* answer1 = nullptr;
	SDLGameObject* answer2 = nullptr;
	SDLGameObject* answer3 = nullptr;
	question = new MenuButton(new LoaderParams(600, 180, 200, 100, "daaquestion1"), placeholder);
	answer1 = new MenuButton(new LoaderParams(600, 280, 200, 100, "daaanswer11"), correctAnswer);
	answer2 = new MenuButton(new LoaderParams(600, 380, 200, 100, "daaanswer12"), incorrectAnswer);
	answer3 = new MenuButton(new LoaderParams(600, 480, 200, 100, "daaanswer13"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);



	if (!TheTextureManager::Instance()->load("Images/DAAQuestion2.png", "daaquestion2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer21.png", "daaanswer21", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer22.png", "daaanswer22", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer23.png", "daaanswer23", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	question = nullptr;
	answer1 = nullptr;
	answer2 = nullptr;
	answer3 = nullptr;
	question = new MenuButton(new LoaderParams(800, 180, 200, 100, "daaquestion2"), placeholder);
	answer1 = new MenuButton(new LoaderParams(800, 280, 200, 100, "daaanswer21"), incorrectAnswer);
	answer2 = new MenuButton(new LoaderParams(800, 380, 200, 100, "daaanswer22"), correctAnswer);
	answer3 = new MenuButton(new LoaderParams(800, 480, 200, 100, "daaanswer23"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);



	if (!TheTextureManager::Instance()->load("Images/DAAQuestion3.png", "daaquestion3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer31.png", "daaanswer31", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer32.png", "daaanswer32", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/DAAAnswer33.png", "daaanswer33", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	question = nullptr;
	answer1 = nullptr;
	answer2 = nullptr;
	answer3 = nullptr;
	question = new MenuButton(new LoaderParams(1000, 180, 200, 100, "daaquestion3"), placeholder);
	answer1 = new MenuButton(new LoaderParams(1000, 280, 200, 100, "daaanswer31"), correctAnswer);
	answer2 = new MenuButton(new LoaderParams(1000, 380, 200, 100, "daaanswer32"), incorrectAnswer);
	answer3 = new MenuButton(new LoaderParams(1000, 480, 200, 100, "daaanswer33"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);

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
void DAA::render()
{
	PlayState::render();
	for (size_t i = 0; i < questions.size(); ++i)
	{
		if (drawQuestion[i])
		{
			questions[i]->draw();
		}
	}
}

void DS::render()
{
	PlayState::render();
	for (size_t i = 0; i < questions.size(); ++i)
	{
		if (drawQuestion[i])
		{
			questions[i]->draw();
		}
	}
}


void OOP::render()
{
	PlayState::render();
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

	if (!TheTextureManager::Instance()->load("Images/OOPQuestion1.png", "oopquestion1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer11.png", "oopanswer11", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer12.png", "oopanswer12", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer13.png", "oopanswer13", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	std::cout << "Clicks count is " << clickedCount << std::endl;
	std::cout << "Objects count is:" << m_gameObjects.size() << std::endl;
	SDLGameObject* question = nullptr;
	SDLGameObject* answer1 = nullptr;
	SDLGameObject* answer2 = nullptr;
	SDLGameObject* answer3 = nullptr;
	question = new MenuButton(new LoaderParams(600, 180, 200, 100, "oopquestion1"), placeholder);
	answer1 = new MenuButton(new LoaderParams(600, 280, 200, 100, "oopanswer11"), correctAnswer);
	answer2 = new MenuButton(new LoaderParams(600, 380, 200, 100, "oopanswer12"), incorrectAnswer);
	answer3 = new MenuButton(new LoaderParams(600, 480, 200, 100, "oopanswer13"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);
	drawQuestion.push_back(true);



	if (!TheTextureManager::Instance()->load("Images/OOPQuestion2.png", "oopquestion2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer21.png", "oopanswer21", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer22.png", "oopanswer22", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer23.png", "oopanswer23", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	question = nullptr;
	answer1 = nullptr;
	answer2 = nullptr;
	answer3 = nullptr;
	question = new MenuButton(new LoaderParams(800, 180, 200, 100, "oopquestion2"), placeholder);
	answer1 = new MenuButton(new LoaderParams(800, 280, 200, 100, "oopanswer21"), incorrectAnswer);
	answer2 = new MenuButton(new LoaderParams(800, 380, 200, 100, "oopanswer22"), correctAnswer);
	answer3 = new MenuButton(new LoaderParams(800, 480, 200, 100, "oopanswer23"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);



	if (!TheTextureManager::Instance()->load("Images/OOPQuestion3.png", "oopquestion3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer31.png", "oopanswer31", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer32.png", "oopanswer32", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/OOPAnswer33.png", "oopanswer33", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	question = nullptr;
	answer1 = nullptr;
	answer2 = nullptr;
	answer3 = nullptr;
	question = new MenuButton(new LoaderParams(1000, 180, 200, 100, "oopquestion3"), placeholder);
	answer1 = new MenuButton(new LoaderParams(1000, 280, 200, 100, "oopanswer31"), correctAnswer);
	answer2 = new MenuButton(new LoaderParams(1000, 380, 200, 100, "oopanswer32"), incorrectAnswer);
	answer3 = new MenuButton(new LoaderParams(1000, 480, 200, 100, "oopanswer33"), incorrectAnswer);
	questions.push_back(question);
	questions.push_back(answer1);
	questions.push_back(answer2);
	questions.push_back(answer3);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);
	drawQuestion.push_back(false);

	std::cout << "stefo\n";
	return true;
}


void  OOP::update()
{
	//size_t localClikedCount = clickedCount;
	  ClassRoom::update();

}

