#include "../Header/Game.h"

Game::Game() :
	m_window(sf::VideoMode(2560, 1440), "Space Station Rescue")
{

}


Game::~Game()
{
}

void Game::init()
{
	// Display the list of all the video modes available for fullscreen
	//vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	timePerFrame = sf::seconds(1.0f / 60.0f);
}


void Game::run()
{
	timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		processInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();

	}
}

void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 255));

	m_window.display();
}

void Game::update(sf::Time time)
{
	
}

void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}
	}
}