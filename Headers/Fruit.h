#pragma once
#include <SFML/Graphics.hpp>
#include "BoxCollision.h"
#include "Projectile.h"

using namespace sf;

class Fruit
{
	// All the private variables can only be accessed internally
private:
	Vector2f m_Position;
	Vector2f m_DefaultPosition;
	Sprite m_Sprite;
	Texture m_Texture;
	BoxCollision* boxCollision;
	Projectile* arrow;

	// Public functions
public:
	Fruit(float pointX, float pointY);
	Sprite getSprite();
	FloatRect getPosition();

	bool isCollision();
	void update(float elapsedTime);
	void resetDefault();
};

