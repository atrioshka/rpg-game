#include "Enemy.h"
#include <iostream>

void Enemy::Initialize() {
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Yellow);
	boundingRectangle.setOutlineThickness(1.0);
	size = sf::Vector2i(64, 64);
}
void Enemy::Load() {
	if (texture.loadFromFile("Assets/Enemy/Textures/enemy.png")) {

		std::cout << "Enemy Image has successfully loaded!" << std::endl;

		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(600, 400));

		int xIndex = 8;
		int yIndex = 1;

		sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
		sprite.scale(sf::Vector2f(2, 2));

		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else {
		std::cout << "Enemy Image has failed to load!" << std::endl;
	}
}
void Enemy::Update() {
	sf::Vector2f position = sprite.getPosition();
	boundingRectangle.setPosition(position);
}
void Enemy::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
	window.draw(boundingRectangle);
}
