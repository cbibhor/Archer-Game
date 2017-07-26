#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(float pointX, float pointY){
	m_Texture.loadFromFile("Images/spider1.png");
	m_Sprite.setTexture(m_Texture);
	m_Position.x = pointX;
	m_Position.y = pointY;
	m_DefaultPosition.x = pointX;
	m_DefaultPosition.y = pointY;
	m_Sprite.setPosition(m_Position);
	m_ThreadEnd.x = pointX + m_Texture.getSize().x/2;
	m_ThreadEnd.y = pointY + 300;
	m_Fruit = new Fruit(m_ThreadEnd.x,m_ThreadEnd.y);
	m_Random = new randomGenerator();
	m_Thread.setSize(sf::Vector2f(2,m_ThreadEnd.y-5));
	m_Thread.setFillColor(sf::Color(147,147,147));
	m_Thread.setPosition(m_ThreadEnd.x,m_Texture.getSize().y/2);
	m_Speed1 = 7;
	m_Speed2 = 20;
	m_Gravity = 0.01;
	m_UpperBound = 150;
	m_LowerBound = 400;
	isUp = true;
	collided = false;
}

Sprite Enemy::getSpiderSprite(){
	return m_Sprite;
}

Sprite Enemy::getFruitSprite(){
	return m_Fruit->getSprite();
}

Vector2f Enemy::getThreadEnd(){
	return m_ThreadEnd;
}

RectangleShape Enemy::getThreadShape(){
	return m_Thread;
}

RectangleShape Enemy::getBoxShape(){
	return m_Fruit->getShape();
}

bool Enemy::isCollision(float arrowX, float arrowY){
	if(m_Fruit->isCollision(arrowX, arrowY)==true)
		collided = true;
	return collided;
}

void Enemy::update(float elapsedTime, int difficulty){
	if(collided==false){
		if(difficulty > 6 && difficulty <= 12){
			movement1y(elapsedTime);
		}
		else if(difficulty > 12){
			movement2y(elapsedTime);
		}
	}
}

void Enemy::movementX(float elapsedTime){
	int randomNum = m_Random->generateRandom(250);
	m_Position.x = 300 + randomNum;
	m_ThreadEnd.x = m_Position.x + m_Texture.getSize().x/2;
	m_Fruit->update(elapsedTime,m_ThreadEnd);
	m_Sprite.setPosition(m_Position);
	m_Thread.setPosition(m_ThreadEnd.x,m_Texture.getSize().y/2);
}

void Enemy::movementY(float elapsedTime){
	int randomNum = m_Random->generateRandom(250);
	m_ThreadEnd.y = 150 + randomNum;
	m_Fruit->update(elapsedTime,m_ThreadEnd);
	m_Thread.setSize(sf::Vector2f(2,m_ThreadEnd.y-5));
}

void Enemy::movement1y(float elapsedTime){
	if(m_ThreadEnd.y <= m_UpperBound)
		isUp = false;
	if(m_ThreadEnd.y >= m_LowerBound)
		isUp = true;
	if(isUp==true)
		m_ThreadEnd.y-=(m_Speed1/100);
	else
		m_ThreadEnd.y+=(m_Speed1/100);
	m_Fruit->update(elapsedTime,m_ThreadEnd);
	m_Thread.setSize(sf::Vector2f(2,m_ThreadEnd.y-5));
}

void Enemy::movement2y(float elapsedTime){
	if(m_Speed2 <= 0)
		isUp = false;
	if(m_ThreadEnd.y >= m_LowerBound)
		isUp = true;
	if(isUp==true){
		m_ThreadEnd.y -= (m_Speed2/100);
		m_Speed2 -= m_Gravity;
	}
	else{
		m_ThreadEnd.y += (m_Speed2/100);
		m_Speed2 += m_Gravity;
	}
	m_Fruit->update(elapsedTime,m_ThreadEnd);
	m_Thread.setSize(sf::Vector2f(2,m_ThreadEnd.y-5));
}

void Enemy::resetEnemy(){
	m_Position.x = m_DefaultPosition.x;
	m_Position.y = m_DefaultPosition.y;
	m_Sprite.setPosition(m_Position);
	m_ThreadEnd.x = m_Position.x + m_Texture.getSize().x/2;
	m_ThreadEnd.y = m_Position.y + 300;
	m_Thread.setPosition(m_ThreadEnd.x,m_Texture.getSize().y/2);
	m_Thread.setSize(sf::Vector2f(2,m_ThreadEnd.y-5));
	m_Speed1 = 7;
	m_Speed2 = 20;
	isUp = true;
	collided = false;
	m_Fruit->selectRandom();
}