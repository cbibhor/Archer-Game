#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace sf;

class player: public Entity
{
	// All the private variables can only be accessed internally
private:
	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_AngleIncrease;
	bool m_StartProjectile;
	bool m_FinishProjectile;

	float m_Speed;
	float m_Angle;
	float m_Velocity;
	float m_xVelocity;
	float m_yVelocity;

	int lives;


	// Public functions
public:
	player();
	player(float startX, float startY);
	Sprite getSprite();
	FloatRect getPosition();
	RectangleShape getShape();
	void setLives(int newLives);
	int getLives();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
		
	void update(float elapsedTime);

};

