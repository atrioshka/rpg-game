#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;

public:
	//Called once per app start
	void Initialize();
	void Load();
	//called once per frame
	void Update();
	void Draw(sf::RenderWindow &window);
};

