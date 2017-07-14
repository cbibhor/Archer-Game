#include "stdafx.h"
#include "player.h"

player::player(float startX, float startY)
{
	// Associate a texture with the sprite
	m_Texture.loadFromFile("Images/pirate.png");
	m_Sprite.setTexture(m_Texture);		

	// Initialise player variables
	m_Speed = 400;
	m_Angle=0.0f;
	m_Velocity=10.0f;
	m_xVelocity=10.0f;
	m_yVelocity=0.0f;
	m_StartProjectile=false;
	m_FinishProjectile=true;

	m_Position.x = startX;
	m_Position.y = startY;
	objectShape.setSize(sf::Vector2f(10,10));
	objectShape.setPosition(m_Position);
}


// Make the private sprite available to the draw() function
Sprite player::getSprite(){
	return m_Sprite;
}

FloatRect player::getPosition(){
	return objectShape.getGlobalBounds();
}

RectangleShape player::getShape(){
	return objectShape;
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


// Move player based on the input this frame, 
// the time elapsed, and the speed
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

	// Now move the sprite to its new position
	m_Sprite.setPosition(m_Position);	
	
}

