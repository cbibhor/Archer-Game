#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class LeftHand
{
	// All the private variables can only be accessed internally
private:
	Vector2f m_Position;
	Vector2f m_DefaultPosition;
	Sprite m_Sprite;
	Texture m_Texture;

	bool m_IncreaseAngle;

	float m_Angle;

	// Public functions
public:
	LeftHand(float pointX, float pointY);
	Sprite getSprite();

	void increaseAngle();
	void finishStep();
	void update(float elapsedTime);
	void resetDefault();
};

