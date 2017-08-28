#include "stdafx.h"
#include "player.h"

player::player(float startX, float startY)
{
	m_Texture.loadFromFile("Images/pirate.png");
	m_Sprite.setTexture(m_Texture);	

	m_Speed = 400;
	m_Angle=0.0f;
	m_Velocity=10.0f;
	m_xVelocity=10.0f;
	m_yVelocity=0.0f;
	m_StartProjectile=false;
	m_FinishProjectile=true;

	m_Position.x = startX;
	m_Position.y = startY;
	m_Sprite.setPosition(m_Position);

	lives = 3;
}

Sprite player::getSprite(){
	return m_Sprite;
}

FloatRect player::getPosition(){
	return rectangleShape.getGlobalBounds();
}

RectangleShape player::getShape(){
	return rectangleShape;
}

void player::setLives(int newLives){
	lives = newLives;
}

int player::getLives(){
	return lives;
}

void player::moveLeft(){
	m_LeftPressed = true;
}

void player::moveRight(){
	m_RightPressed = true;
}

void player::moveUp(){
	m_UpPressed = true;
}

void player::moveDown(){
	m_DownPressed = true;
}

void player::stopLeft(){
	m_LeftPressed = false;
}

void player::stopRight(){
	m_RightPressed = false;
}

void player::stopUp(){
	m_UpPressed = false;
}

void player::stopDown(){
	m_DownPressed = false;
}

void player::update(float elapsedTime){

	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}
	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}
	if (m_UpPressed)
	{
		m_Position.y -= m_Speed * elapsedTime;
	}
	if (m_DownPressed)
	{
		m_Position.y += m_Speed * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);	
	
}

