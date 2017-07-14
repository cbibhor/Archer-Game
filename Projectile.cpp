#include "stdafx.h"
#include "Projectile.h"
#include "World.h"

const float RADIAN = 3.141579/180.0f;

Projectile::Projectile(){
}
Projectile::Projectile(float startX, float startY){
	// Associate a texture with the sprite
	m_Texture.loadFromFile("Images/arrowDef.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(startX,startY);

	// Initialise player variables
	world = new World(0, 200);
	m_Position.x = startX;
	m_Position.y = startY;
	m_Speed = 800;
	m_Angle = 0.0f;
	m_SpeedX = m_Speed * cos(m_Angle*RADIAN);
	m_SpeedY = m_Speed * sin(m_Angle*RADIAN);
	m_GravityX = world->gravityAlongX();
	m_GravityY = world->gravityAlongY();
	m_rotationAngle = m_Angle;
	m_DefaultPosition.x = startX;
	m_DefaultPosition.y = startY;
	m_TipX = startX+30+40;
	m_TipY = startY+40;
	
	m_IncreaseAngle = false;
	m_LaunchProjectile = false;
}


// Make the private sprite available to the draw() function
Sprite Projectile::getSprite(){
	return m_Sprite;
}

FloatRect Projectile::getPosition(){
	return m_Sprite.getGlobalBounds();
}

RectangleShape Projectile::getShape(){
	return objectShape;
}

float Projectile::getTipX(){
	return m_TipX;
}

float Projectile::getTipY(){
	return m_TipY;
}

void Projectile::increaseAngle(){
	m_IncreaseAngle = true;
	m_LaunchProjectile = false;
}

void Projectile::launchProjectile(){
	m_IncreaseAngle=false;
	m_LaunchProjectile=true;
}

bool Projectile::projectileStatus(){
	return m_LaunchProjectile;
}



// Move player based on the input this frame, 
// the time elapsed, and the speed
void Projectile::update(float elapsedTime){

	if(m_IncreaseAngle){
		m_Angle -= 30.0f * elapsedTime;
		m_Sprite.setRotation(m_Angle);
		if(m_Angle<-50)	m_Angle = -50;
		m_rotationAngle = m_Angle;
		m_SpeedX = m_Speed * cos(-m_Angle*RADIAN);
		m_SpeedY = m_Speed * sin(-m_Angle*RADIAN);
	}
	if(m_LaunchProjectile){
		m_Position.x += m_SpeedX*elapsedTime;
		m_Position.y -= m_SpeedY*elapsedTime;
		m_SpeedX -= m_GravityX*elapsedTime;
		m_SpeedY -= m_GravityY*elapsedTime;
		m_rotationAngle += elapsedTime*22;
		m_Sprite.setRotation(m_rotationAngle);

		m_TipX = m_Position.x+30+40*cos(-m_rotationAngle);
		m_TipY = m_Position.y+40-40*sin(-m_rotationAngle);
	}

	// Now move the sprite to its new position
	m_Sprite.setPosition(m_Position);
	
}

void Projectile::resetDefault(){
	m_Position.x = m_DefaultPosition.x;
	m_Position.y = m_DefaultPosition.y;
	m_Angle = 0.0f;
	m_rotationAngle = m_Angle;
	m_SpeedX = m_Speed * cos(m_Angle*RADIAN);
	m_SpeedY = m_Speed * sin(m_Angle*RADIAN);
	m_IncreaseAngle = false;
	m_LaunchProjectile = false;
	m_Sprite.setRotation(m_Angle);
}


