#include "stdafx.h"
#include "Arrow.h"

const float RADIAN = 3.141579/180.0f;

Arrow::Arrow(float startX, float startY){
	m_Texture.loadFromFile("Images/arrowDef.png");
	m_Texture.setSmooth(true);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(startX,startY);

	m_Trajectory = new Trajectory(startX, startY);

	m_Position.x = startX;
	m_Position.y = startY;
	m_DefaultPosition.x = startX;
	m_DefaultPosition.y = startY;
	m_TipX = startX+120;
	m_TipY = startY+54;
	m_Angle=0.0f;
	m_rotationAngle = m_Angle;

	m_IncreaseAngle = false;
	m_LaunchProjectile = false;

	rectangleShape.setSize(sf::Vector2f(10,10));
	rectangleShape.setFillColor(sf::Color::Cyan);
	rectangleShape.setPosition(m_TipX, m_TipY);
}

Sprite Arrow::getSprite(){
	return m_Sprite;
}

FloatRect Arrow::getPosition(){
	return m_Sprite.getGlobalBounds();
}

RectangleShape Arrow::getShape(){
	return rectangleShape;
}

float Arrow::getTipX(){
	return m_TipX;
}

float Arrow::getTipY(){
	return m_TipY;
}

void Arrow::increaseAngle(){
	m_IncreaseAngle = true;
	m_LaunchProjectile = false;
}

void Arrow::launchProjectile(){
	m_IncreaseAngle=false;
	m_LaunchProjectile=true;
}

void Arrow::finishProjectile(){
	m_IncreaseAngle=false;
	m_LaunchProjectile=false;
}

bool Arrow::projectileStatus(){
	return m_LaunchProjectile;
}

void Arrow::update(float elapsedTime){

	if(m_IncreaseAngle){
		m_Angle = m_Trajectory->increaseAngle(elapsedTime);
		m_Sprite.setRotation(m_Angle);
		m_TipX = m_Position.x + 54*sin(-m_Angle*RADIAN) + 120*cos(-m_Angle*RADIAN);
		m_TipY = m_Position.y + 54*cos(-m_Angle*RADIAN) - 120*sin(-m_Angle*RADIAN);
		rectangleShape.setPosition(m_TipX, m_TipY);
	}
	if(m_LaunchProjectile){
		m_Position = m_Trajectory->launchProjectile(elapsedTime);
		m_rotationAngle = m_Trajectory->getRotatingAngle();
		m_Sprite.setRotation(m_rotationAngle);
		m_TipX = m_Position.x + 54*sin(-m_rotationAngle*RADIAN) + 120*cos(-m_rotationAngle*RADIAN);
		m_TipY = m_Position.y + 54*cos(-m_rotationAngle*RADIAN) - 120*sin(-m_rotationAngle*RADIAN);
		rectangleShape.setPosition(m_TipX, m_TipY);
	}

	m_Sprite.setPosition(m_Position);
	
}

void Arrow::resetDefault(){
	m_Trajectory->resetProjectile();
	m_Position.x = m_DefaultPosition.x;
	m_Position.y = m_DefaultPosition.y;
	m_Angle = 0.0f;
	m_rotationAngle = m_Angle;
	m_IncreaseAngle = false;
	m_LaunchProjectile = false;
	m_Sprite.setRotation(m_Angle);
	m_TipX = m_Position.x+120;
	m_TipY = m_Position.y+54;
	rectangleShape.setPosition(m_TipX, m_TipY);
}