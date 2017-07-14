#include "stdafx.h"
#include "World.h"

World::World(float gravityX, float gravityY){
	m_GravityX = gravityX;
	m_GravityY = gravityY;
}

float World::gravityAlongX(){
	return m_GravityX;
}

float World::gravityAlongY(){
	return m_GravityY;
}