#include "Level.h"



Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects

	//Player Object

	m_player.setRadius(10);
	m_player.setFillColor(sf::Color::Magenta);
	m_player.setPosition({ m_window.getSize().x / 2.f, m_window.getSize().y / 2.f });

	//Food mmm food starts to drool like the yellow funy man

	m_food.setRadius(5);
}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}

	if (m_input.isKeyDown(sf::Keyboard::Scancode::D)) {

		m_direction = RIGHT;
		                                
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A)) {

		m_direction = LEFT;

	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::W)) {

		m_direction = UP;

	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S)) {

		m_direction = DOWN;

	}

}

// Update game objects
void Level::update(float dt)
{
	switch (m_direction) {
	case RIGHT: m_player.move({ m_player_speed * dt, 0.f }); break;
	case LEFT: m_player.move({ (-m_player_speed * dt), 0.f}); break;
	case UP: m_player.move({0.f, (-m_player_speed * dt)}); break;
	case DOWN: m_player.move({0.f, m_player_speed * dt}); break;
	}


	//Checks x position
	if (m_player.getPosition().x > m_window.getSize().x) {
		m_player.setPosition({ m_window.getSize().x / 2.f, m_window.getSize().y / 2.f });
	}
	else if (m_player.getPosition().x < 0.f) {
		m_player.setPosition({ m_window.getSize().x / 2.f, m_window.getSize().y / 2.f });
	}

	//Checks y position
	if (m_player.getPosition().y > m_window.getSize().y) {
		m_player.setPosition({ m_window.getSize().x / 2.f, m_window.getSize().y / 2.f });
	}
	else if (m_player.getPosition().y < 0.f) {
		m_player.setPosition({ m_window.getSize().x / 2.f, m_window.getSize().y / 2.f });
	}
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_player);

	endDraw();
}
