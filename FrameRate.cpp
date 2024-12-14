#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() : timer(0){}
FrameRate::~FrameRate(){}

void FrameRate::Initialize() {}

void FrameRate::Load() {

	if (font.loadFromFile("Assets/Fonts/cour.ttf")) {
		std::cout << "Font Loaded!" << std::endl;
		frameRateText.setFont(font);
	}
	else {
		std::cout << "Font failed to load" << std::endl;
	}
}

//called once per frame
void FrameRate::Update(double deltaTime) {

	timer += deltaTime;

	if (timer >= 100.f) {

		double fps = 1000.0f / deltaTime;

		frameRateText.setString(
			"FPS: " + std::to_string((int)fps) +
			"\nFrame Time: " + std::to_string((int)deltaTime));

		timer = 0;
	}
}

void FrameRate::Draw(sf::RenderWindow& window) {
	window.draw(frameRateText);
}
