#ifndef __Enemy__
#define __Enemy__
#include "GameObject.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void handleInput();

	float static angle;
};


#endif
