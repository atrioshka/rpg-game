#pragma once
#include <SFML/Graphics.hpp>

class GameMath
{
public:

	static sf::Vector2f NormalizeVector(sf::Vector2f vector);

	static bool RectangleCollides(sf::FloatRect rectangleA, sf::FloatRect rectangleB);
};

