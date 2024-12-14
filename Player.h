#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
class Player
{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> ammo;
	float ammoSpeed = 0.5f;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	//Called once per app start
	void Initialize();
	void Load();
	//called once per frame
	void Update(Enemy &enemy);
	void Draw(sf::RenderWindow &window);
};

