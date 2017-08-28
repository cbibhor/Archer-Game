#include "stdafx.h"
#include "Trajectory.h"

const float RADIAN = 3.141579/180.0f;

Trajectory::Trajectory(){
}
Trajectory::Trajectory(float startX, float startY){

	projectilePosition.x = startX;
	projectilePosition.y = startY;
	defaultProjectilePos.x = startX;
	defaultProjectilePos.y = startY;
	m_Speed = 800;
	m_initialAngle = 0.0f;
	m_maxAngle = 50.0f;
	m_rotatingAngle = m_initialAngle;
	m_SpeedX = m_Speed * cos(m_initialAngle*RADIAN);
	m_SpeedY = m_Speed * sin(m_initialAngle*RADIAN);
	m_GravityX = 0;
	m_GravityY = 200;

}

float Trajectory::gravityAlongX(){
	return m_GravityX;
}

float Trajectory::gravityAlongY(){
	return m_GravityY;
}

float Trajectory::getInitialAngle(){
	return m_initialAngle;
}

float Trajectory::getRotatingAngle(){
	return m_rotatingAngle;
}

Vector2f Trajectory::getProjectilePosition(){
	return projectilePosition;
}

float Trajectory::increaseAngle(float elapsedTime){
	m_initialAngle -= 30.0f * elapsedTime;
	if(m_initialAngle<-m_maxAngle)	m_initialAngle = -m_maxAngle;
	m_rotatingAngle = m_initialAngle;
	m_SpeedX = m_Speed * cos(-m_initialAngle*RADIAN);
	m_SpeedY = m_Speed * sin(-m_initialAngle*RADIAN);
	return m_initialAngle;
}

Vector2f Trajectory::launchProjectile(float elapsedTime){
	projectilePosition.x += m_SpeedX*elapsedTime;
	projectilePosition.y -= m_SpeedY*elapsedTime;
	m_SpeedX -= m_GravityX*elapsedTime;
	m_SpeedY -= m_GravityY*elapsedTime;
	m_rotatingAngle += elapsedTime*22;
	return projectilePosition;
}

void Trajectory::resetProjectile(){
	projectilePosition.x = defaultProjectilePos.x;
	projectilePosition.y = defaultProjectilePos.y;
	m_Speed = 800;
	m_initialAngle = 0.0f;
	m_maxAngle = 50.0f;
	m_rotatingAngle = m_initialAngle;
	m_SpeedX = m_Speed * cos(m_initialAngle*RADIAN);
	m_SpeedY = m_Speed * sin(m_initialAngle*RADIAN);
	m_GravityX = gravityAlongX();
	m_GravityY = gravityAlongY();
}
