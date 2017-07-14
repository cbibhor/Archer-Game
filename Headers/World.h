#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class World
{
	// All the private variables can only be accessed internally
private:
	float m_GravityY;
	float m_GravityX;


	// Public functions
public:
	World(float gravityX, float gravityY);

	float gravityAlongX();
	float gravityAlongY();
};

