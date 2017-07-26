#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace sf;

class Bow: public Entity
{
	// All the private variables can only be accessed internally
private:
	Vector2f m_DefaultPosition;
	bool m_IncreaseAngle;
	float m_Angle;

	// Public functions
public:
	Bow(float pointX, float pointY);
	Sprite getSprite();

	void increaseAngle();
	void finishStep();
	void update(float elapsedTime);
	void resetDefault();
};

