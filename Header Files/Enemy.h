#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Fruit.h"
#include "RandomGenerator.h"

using namespace sf;

class Enemy: public Entity
{
private:
	Fruit* m_Fruit;
	randomGenerator* m_Random;
	RectangleShape m_Thread;
	Vector2f m_ThreadEnd;
	Vector2f m_DefaultPosition;

	float m_Gravity;
	float m_Speed1;
	float m_Speed2;
	float m_UpperBound;
	float m_LowerBound;
	bool isUp;
	bool collided;

public:
	Enemy(float pointX, float pointY);
	Sprite getSpiderSprite();
	Sprite getFruitSprite();
	RectangleShape getThreadShape();
	Vector2f getThreadEnd(); 
	RectangleShape getBoxShape();
	bool isCollision(float arrowX, float arrowY);
	void update(float elapsedTime, int difficulty);
	void movementX(float elapsedTime);
	void movementY(float elapsedTime);
	void movement1y(float elapsedTime);
	void movement2y(float elapsedTime);
	void resetEnemy();
};