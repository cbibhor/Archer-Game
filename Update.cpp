#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if(m_World->getGamestate()==2){

		if(m_Arrow->getPosition().left > windowWidth){
			m_Player->setLives(m_Player->getLives()-1);
			m_Bow->resetDefault();
			m_Arrow->resetDefault();
			m_RightHand->resetDefault();
			m_LeftHand->resetDefault();
		}
		
		if(isCollision==false && m_Player->getLives()==0){
			timeDelay++;
			if(timeDelay==500){
				m_Score->writeHighScore();
				m_World->setGamestate(3);
				timeDelay=0;
			}
		}
		
		if(isCollision==false && m_Enemy->isCollision(m_Arrow->getTipX(),m_Arrow->getTipY())==true){
			isCollision = true;
			m_Sound->playCheering();
			m_Arrow->finishProjectile();
			m_Score->setplusScore(m_Arrow->getTipX(),m_Arrow->getTipY());
			m_Score->updateScore();
			m_Player->setLives(m_Player->getLives()-1);
		}
		
		if(isCollision == true){
			timeDelay++;
			if(timeDelay==700){
				m_Score->setMessage();
			}
			if(timeDelay==1700){
				isCollision=false;
				m_Player->setLives(3);
				m_Enemy->resetEnemy();
				m_Bow->resetDefault();
				m_Arrow->resetDefault();
				m_RightHand->resetDefault();
				m_LeftHand->resetDefault();
				m_World->update();
				if(m_World->getDifficulty() <= 3){
					m_Enemy->movementY(dtAsSeconds);
				}
				else if(m_World->getDifficulty() > 3 && m_World->getDifficulty() <= 6){
					m_Enemy->movementX(dtAsSeconds);
					m_Enemy->movementY(dtAsSeconds);
				}
				else if(m_World->getDifficulty() > 6 && m_World->getDifficulty() <= 9){
					m_Enemy->resetEnemy();
				}
				else if(m_World->getDifficulty() > 9 && m_World->getDifficulty() <= 12){
					m_Enemy->movementX(dtAsSeconds);
				}
				else if(m_World->getDifficulty() > 12 && m_World->getDifficulty() <= 15){
					m_Enemy->resetEnemy();
				}
				else if(m_World->getDifficulty() > 15){
					m_Enemy->movementX(dtAsSeconds);
				}
				timeDelay=0;
			}
		}

		//m_Player->update(dtAsSeconds);
		m_Enemy->update(dtAsSeconds,m_World->getDifficulty());
		m_Arrow->update(dtAsSeconds);
		m_Bow->update(dtAsSeconds);
		m_RightHand->update(dtAsSeconds);
		m_LeftHand->update(dtAsSeconds);
	}

}