#include "Enemy.h"

float Enemy::angle = 0;

Enemy::Enemy(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
	m_velocity.setY(0.3);
	m_velocity.setX(1);
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 8)); // 100) & k where k is the frames count per sprite sheet
	/*if (m_position.getY() < 0)
	{
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400)
	{
		m_velocity.setY(-2);
	}
	if (m_position.getX() < 0)
	{
		m_velocity.setX(2);
	}
	else if (m_position.getX() > 400)
	{
		m_velocity.setX(-2);
	}*/

	m_position.setX(512 + std::cos(angle) * 90);
	m_position.setY(256 + std::sin(angle) * 90);
	angle += 0.03;
	SDLGameObject::update(); // ? this line can be removed - the line m_position.setX(m_position.getX() + 1); should stay active
}
void Enemy::clean()
{
}

void Enemy::handleInput()
{

}