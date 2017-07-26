#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "BoxCollision.h"
#include "RandomGenerator.h"

using namespace sf;

class Fruit: public Entity
{
private:
	BoxCollision* boxCollision;
	randomGenerator* m_Random;
	Vector2f m_DefaultPosition;
	int randomNumber;
	bool collided;
	
public:
	Fruit();
	Fruit(float pointX, float pointY);
	Sprite getSprite();
	FloatRect getPosition();
	RectangleShape getShape();
	void setBoxDimensions(float left, float right, float top, float bottom);
	bool isCollision(float arrowX, float arrowY);
	void selectRandom();
	void update(float elapsedTime, Vector2f m_ThreadEnd);
	void resetDefault();
};

