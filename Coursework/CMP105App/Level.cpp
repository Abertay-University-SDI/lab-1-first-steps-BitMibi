#include "Level.h"



Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects

	//Player Object

	m_player.setRadius(10);
	m_player.setFillColor(sf::Color::Magenta);
	m_player.setPosition({ 400.f,300.f });
}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}

}

// Update game objects
void Level::update(float dt)
{
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_player);

	endDraw();
}

