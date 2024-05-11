#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);

	void update();
	void draw();
	void clean();

private:
	int m_animSpeed = 0;;
	short m_numFrames = 0;
};