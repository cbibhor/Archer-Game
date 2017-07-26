#include "stdafx.h"
#include "Engine.h"


Engine::Engine(){
	//windowWidth = VideoMode::getDesktopMode().width;
	//windowHeight = VideoMode::getDesktopMode().height;
	windowWidth = 800;
	windowHeight = 600;

	m_Window.create(VideoMode(windowWidth, windowHeight),
		"Archer Game");
		//Style::Fullscreen);

	m_BackgroundTexture.loadFromFile("Images/jungle.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	m_World = new World();
	m_Player = new player(-50,280);
	m_Enemy = new Enemy(550,0);
	m_Arrow = new Arrow(90,450);
	m_Bow = new Bow(90,450);
	m_RightHand = new RightHand(115,480);
	m_LeftHand = new LeftHand(90,450);
	m_Score = new Score();
	m_Sound = new SoundClass();

	isCollision=false;
	timeDelay=0;
}

void Engine::start()
{	 
    sf::Font font;
    font.loadFromFile("Fonts/Carten.otf");
    message.setFont(font);
    message.setString("Collided");
    message.setCharacterSize(20); 
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