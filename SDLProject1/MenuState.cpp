#include "MenuState.h"
#include <iostream>
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"


const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
	// nothing for now
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void MenuState::render()
{
	// nothing for now
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu()
{
	std::cout << "Exit button clicked\n";
	TheGame::Instance()->quit();
}
bool MenuState::onEnter()
{

	if (!TheTextureManager::Instance()->load("Images/Sprite-0001A.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/Sprite-0001A.png",	"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Images/fmi.png", "background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 133, 100, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 133, 100, "exitbutton"), s_exitFromMenu);
	GameObject* background = new Background(new LoaderParams(0, 0, TheGame::Instance()->getGameWidth() * 0.5, TheGame::Instance()->getGameHeight(), "background"), s_menuToPlay);
	m_gameObjects.push_back(background);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	//TheInputHandler::Instance()->reset(); should this be avaliable
	std::cout << "exiting MenuState\n";
	return true;
}