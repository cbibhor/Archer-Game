#include "stdafx.h"
#include "Fruit.h"

Fruit::Fruit(){
}
Fruit::Fruit(float pointX, float pointY){
	m_Texture.loadFromFile("Images/Fruits.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setTextureRect(sf::IntRect(0,0,50,50));
	m_DefaultPosition.x = pointX;
	m_DefaultPosition.y = pointY;
	pointX = pointX-23;
	boxCollision = new BoxCollision(pointX+15,pointX+30,pointY+10,pointY+45);
	rectangleShape.setSize(sf::Vector2f(15,35));
	rectangleShape.setFillColor(sf::Color::Yellow);
	rectangleShape.setPosition(pointX+15,pointY+10);
	m_Sprite.setPosition(pointX,pointY);
	m_Position.x = pointX;
	m_Position.y = pointY;
	collided = false;
}

Sprite Fruit::getSprite(){
	return m_Sprite;
}

FloatRect Fruit::getPosition(){
	return m_Sprite.getGlobalBounds();
}

RectangleShape Fruit::getShape(){
	return rectangleShape;
}

void Fruit::update(float elapsedTime, Vector2f m_ThreadEnd){
	float pointX = m_ThreadEnd.x;
	float pointY = m_ThreadEnd.y;
	if(randomNumber==0){
		pointX = pointX-23;
		setBoxDimensions(pointX+15,pointX+30,pointY+10,pointY+45);
		rectangleShape.setPosition(pointX+15,pointY+10);
	}
	else if(randomNumber==1){
		pointX = pointX-30;
		setBoxDimensions(pointX+25,pointX+40,pointY+10,pointY+45);
		rectangleShape.setPosition(pointX+25,pointY+10);
	}
	else if(randomNumber==2){
		pointX = pointX-23;
		setBoxDimensions(pointX+15,pointX+30,pointY+10,pointY+42);
		rectangleShape.setPosition(pointX+15,pointY+10);
	}
	else if(randomNumber==3){
		pointX = pointX-25;
		setBoxDimensions(pointX+20,pointX+35,pointY+10,pointY+45);
		rectangleShape.setPosition(pointX+20,pointY+10);
	}
	else if(randomNumber==4){
		pointX = pointX-23;
		setBoxDimensions(pointX+20,pointX+35,pointY+10,pointY+65);
		rectangleShape.setPosition(pointX+20,pointY+10);
	}
	else if(randomNumber==5){
		pointX = pointX-23;
		setBoxDimensions(pointX+16,pointX+26,pointY+15,pointY+65);
		rectangleShape.setPosition(pointX+16,pointY+15);
	}
	else if(randomNumber==6){
		pointX = pointX-30;
		setBoxDimensions(pointX+25,pointX+35,pointY+5,pointY+60);
		rectangleShape.setPosition(pointX+25,pointY+5);
	}
	else if(randomNumber==7){
		pointX = pointX-23;
		setBoxDimensions(pointX+20,pointX+30,pointY+15,pointY+50);
		rectangleShape.setPosition(pointX+20,pointY+15);
	}
	else if(randomNumber==8){
		pointX = pointX-32;
		setBoxDimensions(pointX+30,pointX+40,pointY+7,pointY+57);
		rectangleShape.setPosition(pointX+30,pointY+7);
	}
	m_Sprite.setPosition(pointX,pointY);
}

void Fruit::resetDefault(){
	m_Position.x = m_DefaultPosition.x;
	m_Position.y = m_DefaultPosition.y;
}

void Fruit::setBoxDimensions(float left, float right, float top, float bottom){
	boxCollision->updateRight(right);
	boxCollision->updateLeft(left);
	boxCollision->updateTop(top);
	boxCollision->updateBottom(bottom);
}

bool Fruit::isCollision(float arrowX, float arrowY){
	return boxCollision->isCollision(arrowX,arrowY);
}

void Fruit::selectRandom(){
	float pointX = m_DefaultPosition.x;
	float pointY = m_DefaultPosition.y;
	m_Random = new randomGenerator();
	randomNumber = m_Random->generateRandom(9);
	if(randomNumber==0){
		m_Sprite.setTextureRect(sf::IntRect(0,0,50,50));
		pointX = pointX-23;
		setBoxDimensions(pointX+15,pointX+30,pointY+10,pointY+45);
		rectangleShape.setSize(sf::Vector2f(15,35));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+15,pointY+10);
	}
	else if(randomNumber==1){
		m_Sprite.setTextureRect(sf::IntRect(50,0,60,50));
		pointX = pointX-30;
		setBoxDimensions(pointX+25,pointX+40,pointY+10,pointY+45);
		rectangleShape.setSize(sf::Vector2f(15,35));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+25,pointY+10);
	}
	else if(randomNumber==2){
		m_Sprite.setTextureRect(sf::IntRect(120,0,60,50));
		pointX = pointX-23;
		setBoxDimensions(pointX+15,pointX+30,pointY+10,pointY+42);
		rectangleShape.setSize(sf::Vector2f(15,32));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+15,pointY+10);
	}
	else if(randomNumber==3){
		m_Sprite.setTextureRect(sf::IntRect(180,0,50,50));
		pointX = pointX-25;
		setBoxDimensions(pointX+20,pointX+35,pointY+10,pointY+45);
		rectangleShape.setSize(sf::Vector2f(15,35));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+20,pointY+10);
	}
	else if(randomNumber==4){
		m_Sprite.setTextureRect(sf::IntRect(0,50,60,70));
		pointX = pointX-23;
		setBoxDimensions(pointX+20,pointX+35,pointY+10,pointY+65);
		rectangleShape.setSize(sf::Vector2f(15,55));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+20,pointY+10);
	}
	else if(randomNumber==5){
		m_Sprite.setTextureRect(sf::IntRect(70,50,60,70));
		pointX = pointX-23;
		setBoxDimensions(pointX+16,pointX+26,pointY+15,pointY+65);
		rectangleShape.setSize(sf::Vector2f(10,50));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+16,pointY+15);
	}
	else if(randomNumber==6){
		m_Sprite.setTextureRect(sf::IntRect(0,120,60,60));
		pointX = pointX-30;
		setBoxDimensions(pointX+25,pointX+35,pointY+5,pointY+60);
		rectangleShape.setSize(sf::Vector2f(10,55));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+25,pointY+5);
	}
	else if(randomNumber==7){
		m_Sprite.setTextureRect(sf::IntRect(70,120,60,60));
		pointX = pointX-23;
		setBoxDimensions(pointX+20,pointX+30,pointY+15,pointY+50);
		rectangleShape.setSize(sf::Vector2f(10,35));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+20,pointY+15);
	}
	else if(randomNumber==8){
		m_Sprite.setTextureRect(sf::IntRect(130,120,70,60));
		pointX = pointX-32;
		setBoxDimensions(pointX+30,pointX+40,pointY+7,pointY+57);
		rectangleShape.setSize(sf::Vector2f(10,50));
		rectangleShape.setFillColor(sf::Color::Yellow);
		rectangleShape.setPosition(pointX+30,pointY+7);
	}
	m_Sprite.setPosition(pointX,pointY);
	collided=false;
}