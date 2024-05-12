#pragma once
#include "GameState.h"
#include "TextureManager.h"
#include <iostream>
#include <vector>
#include "Game.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "MenuButton.h"

static size_t starsCount = 0;
static size_t clickedCount = 0;

class GameObject;

class PlayState : public GameState
{
public:
	//todo

//this was not implemented
	virtual ~PlayState();
//
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

void correctAnswer();
void incorrectAnswer();

class ClassRoom
	: public PlayState
{
public:
	virtual void update();
	virtual bool onEnter();
	//virtual bool onExit();
	bool clicked = false;
	//short clickedCount = 0;
	virtual bool examFailed();
	short indexes[4];

protected:

	//bool clicked = false;
	std::vector<MenuButton*> questions;
	std::vector<int>state;
	//virtual void correctAnswer();
	//virtual void incorrectAnswer();


};




class DS
	: public ClassRoom
{
public:
	bool onEnter() override;
	void update() override;
};

class DAA
	: public ClassRoom
{
public:
	bool onEnter() override;
	void update() override;
};

class OOP
	: public ClassRoom
{
public:
	bool onEnter() override;
	void update() override;
};

