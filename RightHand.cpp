#include "stdafx.h"
#include "RightHand.h"

RightHand::RightHand(float pointX, float pointY){

	m_Texture.loadFromFile("Images/hand1.png");
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

Sprite RightHand::getSprite(){
	return m_Sprite;
}

void RightHand::increaseAngle(){
	m_IncreaseAngle = true;
}

void RightHand::finishStep(){
	m_IncreaseAngle = false;
}

void RightHand::update(float elapsedTime){
	if(m_IncreaseAngle){
		m_Angle += 37.0f * elapsedTime;
		m_Sprite.setRotation(-m_Angle);
		if(m_Angle>55)	m_Angle = 55;
	}
	m_Sprite.setPosition(m_Position);
}

void RightHand::resetDefault(){
	m_Position.x = m_DefaultPosition.x;
	m_Position.y = m_DefaultPosition.y;
	m_Angle = 0.0f;
	m_IncreaseAngle = false;
	m_Sprite.setRotation(m_Angle);
}