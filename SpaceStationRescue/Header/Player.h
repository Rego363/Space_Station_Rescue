#pragma once

/// <summary>
/// Player: Class handling player actions, attributes and rendering
/// Author: Sean Regan and Jamie Murphy
/// Brief: Character that the user controls
/// </summary>

#include <SFML\Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
	void update();
	void render(sf::RenderWindow & window);

private:

};
