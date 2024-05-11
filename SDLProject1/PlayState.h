#pragma once
#include "GameState.h"
#include "TextureManager.h"
#include <iostream>
#include <vector>
#include "Game.h"
#include "PauseState.h"
#include "GameOverState.h"

class GameObject;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
protected:
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	bool checkCollision(const SDLGameObject* p1, const SDLGameObject* p2) const;
};



class ClassRoom
	: public PlayState
{
public:
	virtual void update();
	virtual bool onEnter();
	//virtual bool onExit();

	virtual bool examFailed();

};

class DS
	: public ClassRoom
{
public:
	bool onEnter() override;
};

class DAA
	: public ClassRoom
{
public:

	bool onEnter() override;
};

class OOP
	: public ClassRoom
{
public:
	bool onEnter();
};

