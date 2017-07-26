#include "stdafx.h"
#include "Bow.h"

Bow::Bow(float pointX, float pointY){

	m_Texture.loadFromFile("Images/bowStretched.png");
	m_Texture.setSmooth(true);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(pointX,pointY);
	//m_Sprite.setOrigin(50,50);

	m_Position.x = pointX;
	m_Position.y = pointY;
	m_DefaultPosition.x = pointX;
	m_DefaultPosition.y = pointY;

	m_Angle=0.0f;
	m_IncreaseAngle = false;
}

Sprite Bow::getSprite(){
	return m_Sprite;
}

void Bow::increaseAngle(){
	m_IncreaseAngle = true;
}

void Bow::finishStep(){
	m_IncreaseAngle = false;
	m_Texture.loadFromFile("Images/bowNormal.png");
	m_Sprite.setTexture(m_Texture);
}

void Bow::update(float elapsedTime){
	if(m_IncreaseAngle){
		m_Angle += 30.0f * elapsedTime;
		m_Sprite.setRotation(-m_Angle);
		if(m_Angle>50)	m_Angle = 50;
	}
	m_Sprite.setPosition(m_Position);
}

void Bow::resetDefault(){
	m_Texture.loadFromFile("Images/bowStretched.png");
	m_Sprite.setTexture(m_Texture);
	m_Position.x = m_DefaultPosition.x;
	m_Position.y = m_DefaultPosition.y;
	m_Angle = 0.0f;
	m_IncreaseAngle = false;
	m_Sprite.setRotation(m_Angle);
}