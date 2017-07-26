#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::draw()
{
	m_Window.clear(Color::White);
	m_Window.draw(m_BackgroundSprite);
	
	if(m_World->getGamestate()==1){
		m_Window.draw(m_World->getSprite());
		m_Window.draw(m_World->getGameName());
		m_Window.draw(m_World->getText1());
		m_Window.draw(m_World->getText2());
	}
	else if(m_World->getGamestate()==2){
		m_Window.draw(m_LeftHand->getSprite());
		m_Window.draw(m_Player->getSprite());
		m_Window.draw(m_Bow->getSprite());
		//m_Window.draw(m_Arrow->getShape());
		m_Window.draw(m_Arrow->getSprite());
		m_Window.draw(m_RightHand->getSprite());
		m_Window.draw(m_Enemy->getThreadShape());
		m_Window.draw(m_Enemy->getSpiderSprite());
		m_Window.draw(m_Enemy->getFruitSprite());
		//m_Window.draw(m_Enemy->getBoxShape());
		m_Window.draw(m_Score->getCurScore());
		if(m_Player->getLives() > 0){
			m_Window.draw(m_World->getArrows(m_Player->getLives()));
		}
		if(isCollision){
			//m_Window.draw(message);
			m_Window.draw(m_Score->getMessage());
		}
	}
	else if(m_World->getGamestate()==3){
		m_Window.draw(m_World->getSprite());
		m_Window.draw(m_World->getText3());
		m_Window.draw(m_Score->getScores());
		m_Window.draw(m_World->getText5());
		m_Window.draw(m_World->getText6());
		m_Window.draw(m_World->getText7());
	}

	m_Window.display();
}