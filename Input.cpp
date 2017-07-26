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
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}

	if(Keyboard::isKeyPressed(Keyboard::Return)){
		if(m_World->getGamestate()==1 || m_World->getGamestate()==3){
			m_World->setGamestate(2);
			isCollision=false;
			m_Player->setLives(3);
			m_Enemy->resetEnemy();
			m_Bow->resetDefault();
			m_Arrow->resetDefault();
			m_RightHand->resetDefault();
			m_LeftHand->resetDefault();
			m_Score->resetScore();
			m_World->setDifficulty(1);
		}
	}
	
	/*	if (Keyboard::isKeyPressed(Keyboard::A)){
			m_Player->moveLeft();
		}
		else{
			m_Player->stopLeft();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::D)){
			m_Player->moveRight();
		}
		else{
			m_Player->stopRight();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::W)){
			m_Player->moveUp();
		}
		else{
			m_Player->stopUp();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::S)){
			m_Player->moveDown();
		}
		else{
			m_Player->stopDown();
		}*/
		
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		if(m_World->getGamestate()==2){
			if(m_Arrow->projectileStatus()==false && isCollision==false && m_Player->getLives()!=0){
				m_Arrow->increaseAngle();
				m_Bow->increaseAngle();
				m_RightHand->increaseAngle();
				m_LeftHand->increaseAngle();
			}
		}
	}
	
	while(m_Window.pollEvent(event)){
		switch(event.type){
		case sf::Event::Closed:	m_Window.close();
		case sf::Event::KeyReleased:
			if(event.key.code==sf::Keyboard::Space){
				if(m_World->getGamestate()==2){
					if(isCollision==false){
						m_Arrow->launchProjectile();
						m_Bow->finishStep();
						m_RightHand->finishStep();
						m_LeftHand->finishStep();
					}
				}
			}
		}
	}
	
}