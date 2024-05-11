#pragma once
#include "GameState.h"
#include "TextureManager.h"
#include <iostream>
#include <vector>
#include "Game.h"
#include "PauseState.h"

class GameObject;
class GameOverState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }
private:
	static void s_gameOverToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;
	std::vector<GameObject*> m_gameObjects;
};