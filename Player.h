#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
class Player
{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> ammo;
	float ammoSpeed;
	float playerSpeed;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	Player();
	~Player();

	//Called once per app start
	void Initialize();
	void Load();
	//called once per frame
	void Update(float deltaTime, Enemy &enemy);
	void Draw(sf::RenderWindow &window);
};

