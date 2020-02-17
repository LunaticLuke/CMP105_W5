#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>
#include "Zombie.h"
#include "Mario.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	sf::Texture zombTexture;
	Zombie zombie;
	Mario mario;
	sf::Texture marioTexture;
	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};