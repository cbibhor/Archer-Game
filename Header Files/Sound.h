#pragma once
#include "SFML\Audio.hpp"

class SoundClass{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;

public:
	SoundClass();
	void playCheering();
};