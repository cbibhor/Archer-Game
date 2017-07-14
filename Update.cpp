#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if(m_Projectile->getPosition().left > windowWidth){
		m_Bow->resetDefault();
		m_Projectile->resetDefault();
		m_RightHand->resetDefault();
		m_LeftHand->resetDefault();
	}

	if(m_Fruit->isCollision()==true){
		isCollision = true;
	}

	m_Player->update(dtAsSeconds);
	m_Projectile->update(dtAsSeconds);
	m_Bow->update(dtAsSeconds);
	m_RightHand->update(dtAsSeconds);
	m_LeftHand->update(dtAsSeconds);
}