#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

	//----------------- INITIALIZE ----------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

	//----------------- INITIALIZE ----------------------

	//----------------- LOAD ----------------------------
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/player.png")) {
		
		std::cout << "Player Image Loaded!" << std::endl;

		playerSprite.setTexture(playerTexture);

		//Coordinates for the character sprite on the 576x256 pixel sprite sheet
		//Each character square is 64x64 pixels
		int xIndex = 0;
		int yIndex = 3;

		//Int (x, y, width, height)
		playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		playerSprite.setScale(sf::Vector2f(3, 3));
	
	}
	else {
		std::cout << "Player Image Failed To Load!" << std::endl;
	}
	//----------------- LOAD -----------------------------
	

	//----------------- (START) MAIN GAME LOOP -------------------
	while (window.isOpen()) {

		//----------------- UPDATE --------------------
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//Initialize player position
		sf::Vector2f position = playerSprite.getPosition();

		//Character moves one unit to the right (FORWARD)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playerSprite.setPosition(position + sf::Vector2f(1, 0));
		}
		//Character moves one unit to the left (BACKWARDS)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));
		}
		//Character moves one unit UP
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			playerSprite.setPosition(position + sf::Vector2f(0, -1));
		}
		//Character moves one unit DOWN
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playerSprite.setPosition(position + sf::Vector2f(0, 1));
		}
		//----------------- UPDATE --------------------


		//----------------- DRAW ----------------------
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
		//----------------- DRAW ----------------------
	}
	//----------------- (END) MAIN GAME LOOP -------------------

	return 0;
}





































