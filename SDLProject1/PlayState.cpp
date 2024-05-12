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

//void ClassRoom::render()
//{
//	PlayState::render();
//	//for (size_t i = 0; i < questions.size(); ++i)
//	//{
//	//	questions[i]->draw();
// //   }
//}



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
	answer1 = new MenuButton(new LoaderParams(800, 280, 200, 100, "oopanswer21"), correctAnswer);
	answer2 = new MenuButton(new LoaderParams(800, 380, 200, 100, "oopanswer22"), incorrectAnswer);
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

