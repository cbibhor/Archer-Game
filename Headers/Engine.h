#pragma once
#include <SFML/Graphics.hpp>
#include "player.h";
#include "Projectile.h";
#include "Bow.h"
#include "RightHand.h"
#include "LeftHand.h"
#include "Fruit.h"

using namespace sf;

class Engine
{
private:
	
	RenderWindow m_Window;
	int windowWidth;
	int windowHeight;
	
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	
	player* m_Player;
	Bow* m_Bow;
	Projectile* m_Projectile;
	RightHand* m_RightHand;
	LeftHand* m_LeftHand;
	Fruit* m_Fruit;

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
