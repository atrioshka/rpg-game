#include "Enemy.h"
#include <iostream>

void Enemy::Initialize() {

}
void Enemy::Load() {
	if (texture.loadFromFile("Assets/Enemy/Textures/enemy.png")) {

		std::cout << "Enemy Image has successfully loaded!" << std::endl;

		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(600, 400));

		int xIndex = 8;
		int yIndex = 1;

		sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(2, 2));
	}
	else {
		std::cout << "Enemy Image has failed to load!" << std::endl;
	}
}
void Enemy::Update() {
	sf::Vector2f position = sprite.getPosition();
}
void Enemy::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
}
