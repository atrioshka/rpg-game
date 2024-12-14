#pragma once
#include <SFML/Graphics.hpp>
class FrameRate{
private:
	sf::Text frameRateText;
	sf::Font font;
	float timer;

public:
	FrameRate();
	~FrameRate();
	void Initialize();
	void Load();
	//called once per frame
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
};

