#include "Player.h"
#include "SDLGameObject.h"
#include <iostream>

short const door1x1pos = 533;
short const door1x2pos = 786;

short const door2x1pos = 1107;
short const door2x2pos = 1259;

short const door3x1pos = 1606;
short const door3x2pos = 1762;

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

	if (TheGame::Instance()->getGameWidth() - 150 <= m_position.getX())
		m_position.setX(TheGame::Instance()->getGameWidth() - 150);
	else if (50 >= m_position.getX())
		m_position.setX(50);

	//door pos

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
			m_velocity.setX(6);
	
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		    m_velocity.setX(-6);
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && m_position.getX() >= door1x1pos && m_position.getX() <= door1x2pos)
	{
		std::cout << " firts door detected\n";
		TheGame::Instance()->getStateMachine()->pushState(new DS());
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && m_position.getX() >= door2x1pos && m_position.getX() <= door2x2pos)
	{
		std::cout << " second door detected\n";
		TheGame::Instance()->getStateMachine()->pushState(new DAA());
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && m_position.getX() >= door3x1pos && m_position.getX() <= door3x2pos)
	{
		std::cout << " third door detected\n";
		TheGame::Instance()->getStateMachine()->pushState(new OOP());
	}
	//else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	//{
	//	m_velocity.setY(2);
	//}
	////else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	//{
	//	/*m_position.setY(m_position.getY() - 10);
	//	this->draw();
	//	SDL_Delay(20);
	//	m_velocity.setY(m_velocity.getY() + 5);*/
	//	//m_velocity.setY(-10);
	//}
	
}