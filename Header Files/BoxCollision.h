#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class BoxCollision
{
	// All the private variables can only be accessed internally
private:
	float top;
	float bottom;
	float right;
	float left;

	// Public functions
public:
	BoxCollision(float left, float right, float top, float bottom);

	void updateTop(float Top);
	void updateBottom(float Bottom);
	void updateRight(float Right);
	void updateLeft(float Left);
	bool isCollision(float pointX, float pointY);
};

