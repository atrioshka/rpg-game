#include <iostream>
#include "Player.h"
#include "GameMath.h"

void Player::Initialize() {
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1.0);
	size = sf::Vector2i(64, 64);
}

void Player::Load() {
	if (texture.loadFromFile("Assets/Player/Textures/player.png")) {

		//Confirms the image was loaded correctly 
		std::cout << "Player Image Loaded!" << std::endl;

		sprite.setTexture(texture);

		//Coordinates for the character sprite on the 576x256 pixel sprite sheet
		//Each character square is 64x64 pixels
		int xIndex = 0;
		int yIndex = 3;

		//Int (x, y, width, height)
		sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
		sprite.setScale(sf::Vector2f(2, 2));

		//Sets bounding rectangle to the size of the scaled sprite
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

	}
	else {
		//Message that confirms the image was not loaded correctly 
		std::cout << "Player Image Failed To Load!" << std::endl;
	}
}

void Player::Update(float deltaTime, Enemy &enemy) {
	sf::Vector2f position = sprite.getPosition();

	//Character moves one unit to the right (FORWARD)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);
	}
	//Character moves one unit to the left (BACKWARDS)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);
	}
	//Character moves one unit UP
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);
	}
	//Character moves one unit DOWN
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		ammo.push_back(sf::RectangleShape(sf::Vector2f(10, 5)));
		int i = ammo.size() - 1;
		ammo[i].setPosition(sprite.getPosition());
	}

	for (size_t i = 0; i < ammo.size(); i++) {
		sf::Vector2f ammoDirection = enemy.sprite.getPosition() - ammo[i].getPosition();
		ammoDirection = GameMath::NormalizeVector(ammoDirection);
		ammo[i].setPosition(ammo[i].getPosition() + ammoDirection * ammoSpeed * deltaTime);
	}

	boundingRectangle.setPosition(position);

	//Detects if the player collides with the enemy
	if (GameMath::RectangleCollides(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds())) {
		std::cout << "Collision!" << std::endl;
	}
}

void Player::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < ammo.size(); i++) {
		window.draw(ammo[i]);
	}
}
