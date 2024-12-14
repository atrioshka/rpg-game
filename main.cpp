#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "FrameRate.h"

int main() {

	//----------------- INITIALIZE ----------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
	window.setFramerateLimit(360);
	
	Player player;
	Enemy enemy;
	FrameRate frameRate;
	sf::Clock clock;

	player.Initialize();
	enemy.Initialize();
	frameRate.Initialize();
	//----------------- INITIALIZE ----------------------

	//----------------- LOAD ----------------------------
	frameRate.Load();
	player.Load();
	enemy.Load();
	//----------------- LOAD -----------------------------

	
	//----------------- (START) MAIN GAME LOOP -----------

	while (window.isOpen()) {

		sf::Time deltaTimer = clock.restart();
		double deltaTime = deltaTimer.asMicroseconds() / 1000.0;
		
		sf::Event event;
		
		//----------------- UPDATE --------------------
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		frameRate.Update(deltaTime);
		enemy.Update(deltaTime);
		player.Update(deltaTime, enemy);
		//----------------- UPDATE --------------------

		//----------------- DRAW ----------------------
		window.clear(sf::Color::Black);
		enemy.Draw(window);
		player.Draw(window);
		frameRate.Draw(window);
		window.display();
		//----------------- DRAW ----------------------
	}
	//----------------- (END) MAIN GAME LOOP -------------------
	return 0;
}