#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

	//----------------- INITIALIZE ----------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

	//Defines a 120x50 rectangle
	sf::RectangleShape rectangle(sf::Vector2f(240.f, 100.f));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(sf::Vector2f(200, 250));
	rectangle.setOutlineThickness(6);
	rectangle.setOutlineColor(sf::Color::Red);
	//rectangle.setOrigin(rectangle.getSize() / 2.0f);
	rectangle.setRotation(45);

	//Defines a triangle
	sf::CircleShape triange(80.f, 3);
	triange.setFillColor(sf::Color::Magenta);
	triange.setPosition(sf::Vector2f(0, 10));

	//Defines a diamond
	sf::CircleShape diamond(80.f, 4);
	diamond.setFillColor(sf::Color::Yellow);
	diamond.setPosition(sf::Vector2f(200, 10));

	//Defines an octogon
	sf::CircleShape octogon(80.f, 8);
	octogon.setFillColor(sf::Color::Green);
	octogon.setPosition(sf::Vector2f(400, 10));

	//----------------- INITIALIZE ----------------------
	

	//main game loop
	while (window.isOpen()) {

		//----------------- UPDATE --------------------
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		//----------------- UPDATE --------------------


		//----------------- DRAW ----------------------
		window.clear(sf::Color::Black);
		window.draw(rectangle);
		window.draw(triange);
		window.draw(diamond);
		window.draw(octogon);
		window.display();
		//----------------- DRAW ----------------------
	}

	return 0;
}





































