#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
	/////////////////////////////////////////////////////////////////////////
	/*
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::F5)
			{
				// Capturing the window to a sf::Image
				sf::Image screenshot = m_Window.capture();


				// Making the screenshot name
				std::string screenshotName = "screenshot";

				// Saving to a file
				screenshot.saveToFile("screenshots/" + screenshotName + ".png");
			}
		}

	}
	*/
	////////////////////////////////////////////////////////////////////////

	Event event;
	// Handle the player quitting
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}

	// Handle the player moving
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_Player->moveLeft();
	}
	else
	{
		m_Player->stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_Player->moveRight();
	}
	else
	{
		m_Player->stopRight();
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		m_Player->moveUp();
	}
	else
	{
		m_Player->stopUp();
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		m_Player->moveDown();
	}
	else
	{
		m_Player->stopDown();
	}

	if(Keyboard::isKeyPressed(Keyboard::B)){
		if(m_Projectile->projectileStatus()==false){
			m_Projectile->increaseAngle();
			m_Bow->increaseAngle();
			m_RightHand->increaseAngle();
			m_LeftHand->increaseAngle();
		}
	}
	while(m_Window.pollEvent(event)){
		switch(event.type){
		case sf::Event::Closed:	m_Window.close();
		case sf::Event::KeyReleased:
			if(event.key.code==sf::Keyboard::B){
				m_Projectile->launchProjectile();
				m_Bow->finishStep();
				m_RightHand->finishStep();
				m_LeftHand->finishStep();
			}
		}
	}
	
}