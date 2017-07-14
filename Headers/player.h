#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class player
{
	// All the private variables can only be accessed internally
private:
	Vector2f m_Position;
	Sprite m_Sprite;
	Texture m_Texture;
	RectangleShape objectShape;
	
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


	// Public functions
public:
	player(float startX, float startY);
	Sprite getSprite();
	FloatRect getPosition();
	RectangleShape getShape();

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

