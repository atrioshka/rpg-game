#include "GameMath.h"

sf::Vector2f GameMath::NormalizeVector(sf::Vector2f vector) {

	float magnitude = sqrt(pow(vector.x, 2) + pow(vector.y, 2));

	sf::Vector2f normalizedVector;

	normalizedVector.x = vector.x / magnitude;
	normalizedVector.y = vector.y / magnitude;

	return normalizedVector;
}
