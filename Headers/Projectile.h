#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

using namespace sf;

class Projectile
{
	// All the private variables can only be accessed internally
private:
	Vector2f m_Position;
	Vector2f m_DefaultPosition;
	Sprite m_Sprite;
	Texture m_Texture;
	RectangleShape objectShape;

	World* world;
	
	bool m_IncreaseAngle;
	bool m_LaunchProjectile;

	float m_Angle;
	float m_Speed;
	float m_SpeedX;
	float m_SpeedY;
	float m_GravityX;
	float m_GravityY;
	float m_rotationAngle;
	float m_TipX;
	float m_TipY;


	// Public functions
public:
	Projectile();
	Projectile(float startX, float startY);
	Sprite getSprite();
	FloatRect getPosition();
	RectangleShape getShape();

	void increaseAngle();
	void launchProjectile();
	void update(float elapsedTime);
	void resetDefault();
	float getTipX();
	float getTipY();
	bool projectileStatus();

};

