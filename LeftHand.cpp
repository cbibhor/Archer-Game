#include "stdafx.h"
#include "LeftHand.h"

LeftHand::LeftHand(float pointX, float pointY){

	m_Texture.loadFromFile("Images/hand2.png");
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

Sprite LeftHand::getSprite(){
	return m_Sprite;
}

void LeftHand::increaseAngle(){
	m_IncreaseAngle = true;
}

void LeftHand::finishStep(){
	m_IncreaseAngle = false;
}

void LeftHand::update(float elapsedTime){
	if(m_IncreaseAngle){
		m_Angle += 30.0f * elapsedTime;
		m_Sprite.setRotation(-m_Angle);
		if(m_Angle>50)	m_Angle = 50;
	}
	m_Sprite.setPosition(m_Position);
}

void LeftHand::resetDefault(){
	m_Position.x = m_DefaultPosition.x;
	m_Position.y = m_DefaultPosition.y;
	m_Angle = 0.0f;
	m_IncreaseAngle = false;
	m_Sprite.setRotation(m_Angle);
}