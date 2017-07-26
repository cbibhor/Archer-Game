#include "stdafx.h"
#include "World.h"

World::World(){
	difficulty = 1;
	gamestate = 1;

	m_Arrows1.loadFromFile("Images/arrowOne.png");
	m_Arrows2.loadFromFile("Images/arrowTwo.png");
	m_Arrows3.loadFromFile("Images/arrowThree.png");
	m_SpriteArrows.setPosition(200,0);

	m_Texture1.loadFromFile("Images/ashe1.png");
	m_Sprite1.setTexture(m_Texture1);
	m_Sprite1.setPosition(0,0);

	m_Texture2.loadFromFile("Images/ashe2.png");
	m_Sprite2.setTexture(m_Texture2);
	m_Sprite2.setPosition(0,0);

	font1.loadFromFile("Fonts/Carten.otf");
	font2.loadFromFile("Fonts/Montague.ttf");
	font3.loadFromFile("Fonts/Montserrat-Regular.ttf");

	gameName.setFont(font2);
	gameName.setCharacterSize(100);
	gameName.setFillColor(sf::Color(32,178,170));
	gameName.setString("Archer");
	gameName.setPosition(50,50);

	text1.setFont(font1);
	text1.setCharacterSize(40);
	text1.setFillColor(sf::Color::Yellow);
	text1.setString("Enter: Play\n Esc: Quit");
	text1.setPosition(120,200);
	
	text2.setFont(font1);
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color(147,147,147));
	text2.setString("Instructions:\nTap and Hold Space Bar to aim.\nRelease Space Bar to shoot.\nHit as many fruits as you can.");
	text2.setPosition(50,350);
	
	text3.setFont(font1);
	text3.setCharacterSize(70);
	text3.setFillColor(sf::Color::Blue);
	text3.setString("Game Over");
	text3.setPosition(100,50);

	text5.setFont(font1);
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setString("Enter: Play\n Esc: Quit");
	text5.setPosition(150,300);

	text6.setFont(font3);
	text6.setCharacterSize(15);
	text6.setFillColor(sf::Color(147,147,147));
	text6.setString("Developed By:");
	text6.setPosition(145,550);

	text7.setFont(font3);
	text7.setCharacterSize(20);
	text7.setFillColor(sf::Color::Magenta);
	text7.setString("Bibhor Chauhan");
	text7.setPosition(120,570);
}

Sprite World::getSprite(){
	if(gamestate==1){
		return m_Sprite1;
	}
	else if(gamestate==3){
		return m_Sprite2;
	}
}

Sprite World::getArrows(int lives){
	if(lives==1){
		m_SpriteArrows.setTexture(m_Arrows1);
	}
	else if(lives==2){
		m_SpriteArrows.setTexture(m_Arrows2);
	}
	else if(lives==3){
		m_SpriteArrows.setTexture(m_Arrows3);
	}
	return m_SpriteArrows;
}

Text World::getGameName(){
	return gameName;
}

Text World::getText1(){
	return text1;
}

Text World::getText2(){
	return text2;
}

Text World::getText3(){
	return text3;
}

Text World::getText5(){
	return text5;
}

Text World::getText6(){
	return text6;
}

Text World::getText7(){
	return text7;
}

void World::setGamestate(int state){
	gamestate = state;
}

void World::setDifficulty(int diff){
	difficulty = diff;
}

int World::getGamestate(){
	return gamestate;
}

int World::getDifficulty(){
	return difficulty;
}

void World::update(){
	difficulty++;
}