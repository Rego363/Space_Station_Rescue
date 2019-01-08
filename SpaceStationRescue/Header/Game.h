#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

/// <summary>
/// Game Class
/// </summary>
class Game
{
public:
	Game();
	~Game();

	void init();
	void run();

	sf::RenderWindow m_window;

private:
	void update(sf::Time);
	void render();
	void processInput();

	//time 
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame;
	float totalTime;


};