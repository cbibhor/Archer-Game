#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"
#include "player.h";
#include "Enemy.h"
#include "Arrow.h"
#include "Bow.h"
#include "RightHand.h"
#include "LeftHand.h"
#include "Score.h"
#include "Sound.h"

using namespace sf;

class Engine
{
private:
	
	RenderWindow m_Window;
	int windowWidth;
	int windowHeight;
	int timeDelay;
	
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	
	World* m_World;
	player* m_Player;
	Enemy* m_Enemy;
	Bow* m_Bow;
	Arrow* m_Arrow;
	RightHand* m_RightHand;
	LeftHand* m_LeftHand;
	Score* m_Score;
	SoundClass* m_Sound;

	bool isCollision;
	sf::Text message;
	
	void input();
	void update(float dtAsSeconds);
	void draw();
	
public:
	// The Engine constructor
	Engine();

	// start will call all the private functions
	void start();

};
