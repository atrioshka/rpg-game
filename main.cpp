#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

int main() {

	//----------------- INITIALIZE ----------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

	Player player;
	Enemy enemy;

	player.Initialize();
	enemy.Initialize();
	//----------------- INITIALIZE ----------------------

	//----------------- LOAD ----------------------------
	//Load player and enemy images
	player.Load();
	enemy.Load();
	//----------------- LOAD -----------------------------

	//----------------- (START) MAIN GAME LOOP -----------

	while (window.isOpen()) {

		sf::Event event;

		//----------------- UPDATE --------------------
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		//Initialize player and enemy positions
		enemy.Update();
		player.Update(enemy);
		//----------------- UPDATE --------------------

		//----------------- DRAW ----------------------
		window.clear(sf::Color::Black);
		enemy.Draw(window);
		player.Draw(window);
		window.display();
		//----------------- DRAW ----------------------
	}
	//----------------- (END) MAIN GAME LOOP -------------------
	return 0;
}