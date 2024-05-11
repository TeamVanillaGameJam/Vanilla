#pragma once
#include "PlayState.h"

class ClassRoom 
	: public PlayState
{
public:
	virtual void update() override;
	virtual bool onEnter();
	//virtual bool onExit();

	virtual bool examFailed();

};

class DS
	: ClassRoom
{
	virtual void update() override;
};

class DAA
	: ClassRoom
{
	virtual void update() override;
};


class OOP
	: ClassRoom
{
	virtual void update() override;
};
