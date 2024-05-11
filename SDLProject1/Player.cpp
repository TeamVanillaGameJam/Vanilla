#include "Player.h"
#include "SDLGameObject.h"


Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw();

}
void Player::update()
{
	////m_x -= 1;
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	//m_velocity.setX(2);
	////m_acceleration.setX(1);

	m_velocity.setX(0);
	m_velocity.setY(0);

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	handleInput();


	SDLGameObject::update();
}
void Player::clean()
{
}

//*************************************************************************************
/*
void Player::handleInput()
{
	Vector2D target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = target - m_position;
	m_velocity /= 50;
}*/

void Player::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState((int)Mouse_buttons::LEFT))
	{
		//m_velocity.setX(2);

		Vector2D vec = TheInputHandler::Instance()->getMousePosition();
		m_velocity = (vec - m_position) / 100;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	/*}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);*/
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		m_velocity.setY(-10);
		//m_velocity.setY(-10);
	}
	
}