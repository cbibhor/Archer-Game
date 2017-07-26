#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Trajectory.h"

using namespace sf;

class Arrow: public Entity
{
private:
	Vector2f m_DefaultPosition;
	Trajectory* m_Trajectory;

	bool m_IncreaseAngle;
	bool m_LaunchProjectile;

	float m_Angle;
	float m_rotationAngle;
	float m_TipX;
	float m_TipY;

public:
	Arrow(float startX, float startY);
	Sprite getSprite();
	FloatRect getPosition();
	RectangleShape getShape();

	void increaseAngle();
	void launchProjectile();
	void finishProjectile();
	void update(float elapsedTime);
	void resetDefault();
	float getTipX();
	float getTipY();
	bool projectileStatus();
};