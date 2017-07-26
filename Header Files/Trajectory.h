#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Trajectory
{

private:
	Vector2f projectilePosition;
	Vector2f defaultProjectilePos;
	float m_initialAngle;
	float m_maxAngle;
	float m_rotatingAngle;
	float m_Speed;
	float m_SpeedX;
	float m_SpeedY;
	float m_GravityX;
	float m_GravityY;

public:
	Trajectory();
	Trajectory(float startX, float startY);

	Sprite getSprite();
	FloatRect getPosition();
	RectangleShape getShape();
	float gravityAlongX();
	float gravityAlongY();
	float getInitialAngle();
	float getRotatingAngle();
	Vector2f getProjectilePosition();

	float increaseAngle(float elapsedTime);
	Vector2f launchProjectile(float elapsedTime);
	void resetProjectile();

};

