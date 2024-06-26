#ifndef __SDLGameObject__
#define __SDLGameObject__

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"


class Background;
class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {}; // to define

	const Vector2D& getPosition() const
	{
		return m_position;
	}
	int getWidth() const
	{
		return m_width;
	}
	int getHeight() const
	{
		return m_height;
	}

	//virtual void collision() = 0;
	bool dead() { return false; }
	void ressurect();
protected:
	//int m_x;
	//int m_y;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;

	friend Background;
};


#endif

