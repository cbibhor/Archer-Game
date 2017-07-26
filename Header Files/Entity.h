#pragma once
//#ifndef ENTITY_H
//#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::Vector2f m_Position;
    sf::RectangleShape rectangleShape;
    sf::Sprite m_Sprite;
	sf::Texture m_Texture;
    sf::Text text;
    
private:
protected:
};
//#endif
