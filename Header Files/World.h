#pragma once
#include <SFML/Graphics.hpp>
#include "Score.h"

using namespace sf;

class World
{
private:
	Texture m_Texture1;
	Texture m_Texture2;
	Texture m_Arrows1;
	Texture m_Arrows2;
	Texture m_Arrows3;
	Sprite m_Sprite1;
	Sprite m_Sprite2;
	Sprite m_SpriteArrows;
	Font font1;
	Font font2;
	Font font3;
	Text gameName;
	Text text1;
	Text text2;
	Text text3;
	Text text5;
	Text text6;
	Text text7;
	int difficulty;
	int gamestate;

public:
	World();
	Sprite getSprite();
	Sprite getArrows(int lives);
	Text getGameName();
	Text getText1();
	Text getText2();
	Text getText3();
	Text getText4();
	Text getText5();
	Text getText6();
	Text getText7();
	void setGamestate(int state);
	void setDifficulty(int diff);
	int getGamestate();
	int getDifficulty();
	void update();
};

