#include "GameMath.h"

sf::Vector2f GameMath::NormalizeVector(sf::Vector2f vector) {

	float magnitude = sqrt(pow(vector.x, 2) + pow(vector.y, 2));

	sf::Vector2f normalizedVector;

	normalizedVector.x = vector.x / magnitude;
	normalizedVector.y = vector.y / magnitude;

	return normalizedVector;
}

bool GameMath::RectangleCollides(sf::FloatRect rectangleA, sf::FloatRect rectangleB) {

	/*
	right = left + width
	bottom = top + height
	if right side (x position) of both rectangles is larger than the left side of both rectangles
	AND
	if bottom (y height) of both rectangles is larger than the top side of both rectangles
	THEN there is a collision
	*/
	//Conditions for a collision between two rectangle boundaries 
	if (rectangleA.left + rectangleA.width > rectangleB.left && 
		rectangleB.left + rectangleB.width > rectangleA.left &&
		rectangleA.top + rectangleA.height > rectangleB.top && 
		rectangleB.top + rectangleB.height > rectangleA.top) {
		return true;
	}
	return false;
}
