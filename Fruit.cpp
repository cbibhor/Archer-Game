#include "stdafx.h"
#include "Fruit.h"

Fruit::Fruit(float pointX, float pointY){

	m_Texture.loadFromFile("Images/strawberry.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(pointX,pointY);
	//m_Sprite.setOrigin(50,50);

	boxCollision = new BoxCollision(pointY,pointY+20,pointX+20,pointX);
	arrow = new Projectile();

	m_Position.x = pointX;
	m_Position.y = pointY;
	m_DefaultPosition.x = pointX;
	m_DefaultPosition.y = pointY;

}

Sprite Fruit::getSprite(){
	return m_Sprite;
}

FloatRect Fruit::getPosition(){
	return m_Sprite.getGlobalBounds();
}


void Fruit::update(float elapsedTime){
	m_Sprite.setPosition(m_Position);
}

void Fruit::resetDefault(){
	m_Position.x = m_DefaultPosition.x;
	m_Position.y = m_DefaultPosition.y;
}

bool Fruit::isCollision(){
	return boxCollision->isCollision(arrow->getTipX(),arrow->getTipY());
}