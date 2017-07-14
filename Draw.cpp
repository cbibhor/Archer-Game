#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	m_Window.clear(Color::White);

	//m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_LeftHand->getSprite());
	m_Window.draw(m_Player->getSprite());
	m_Window.draw(m_Bow->getSprite());
	m_Window.draw(m_Projectile->getSprite());
	m_Window.draw(m_RightHand->getSprite());
	m_Window.draw(m_Fruit->getSprite());
	if(isCollision){
		m_Fruit->getSprite().setColor(sf::Color::Transparent);
		m_Window.draw(message);
	}

	m_Window.display();
}