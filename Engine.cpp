#include "stdafx.h"
#include "Engine.h"


Engine::Engine(){
	//windowWidth = VideoMode::getDesktopMode().width;
	//windowHeight = VideoMode::getDesktopMode().height;
	windowWidth = 800;
	windowHeight = 600;

	m_Window.create(VideoMode(windowWidth, windowHeight),
		"Simple Game Engine");
		//Style::Fullscreen);

	m_BackgroundTexture.loadFromFile("background.jpg");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	m_Player = new player(-50,220);
	m_Projectile = new Projectile(90,390);
	m_Bow = new Bow(90,390);
	m_RightHand = new RightHand(115,420);
	m_LeftHand = new LeftHand(90,390);
	m_Fruit = new Fruit(650, 300);

	isCollision=false;
}

void Engine::start()
{	 
	// We need to choose a font
    sf::Font font;
    font.loadFromFile("28 Days Later.ttf");
 
    // Set the font to our message
    message.setFont(font);
 
    // Assign the actual message
    message.setString("Collided");
 
    // Make it really big
    message.setCharacterSize(20); 
 
    // Choose a color
	message.setFillColor(sf::Color::Black);
	Clock clock;

	while (m_Window.isOpen())
	{
		// Restart the clock and save the elapsed time into dt
		Time dt = clock.restart();
		
		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}