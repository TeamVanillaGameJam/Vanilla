#ifndef __GameObject__
#define __GameObject__

#include "SDL.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include <cmath>

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	/*virtual const Vector2D& getPosition() const = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;*/

	//this was protected
	virtual ~GameObject() {}

protected:
	GameObject(const LoaderParams* pParams) {}
};




#endif
