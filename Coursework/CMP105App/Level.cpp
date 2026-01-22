#include "Level.h"



Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects

	//Player Object

	m_player.setRadius(10);
	m_player.setFillColor(sf::Color::Magenta);
	m_player.setPosition({ m_window.getSize().x / 2.f, m_window.getSize().y / 2.f });

	//Food mmmmm food starts to drool like the yellow funy man

	m_food.setRadius(5);
	m_food.setFillColor(sf::Color::Red);
	spawnFood();

	
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


void Level::spawnFood() {
	
	float x = rand() % m_window.getSize().x;
	float y = rand() % m_window.getSize().y;

	m_food.setPosition({ x, y});
}


// Update game objects
void Level::update(float dt)
{
	if (is_GameOver) {
		return;
		
		
	}
	//Timer 

	 m_timer += dt;

	//Player Input
	switch (m_direction) {
	case RIGHT: m_player.move({ m_player_speed * dt, 0.f }); break;
	case LEFT: m_player.move({ (-m_player_speed * dt), 0.f}); break;
	case UP: m_player.move({0.f, (-m_player_speed * dt)}); break;
	case DOWN: m_player.move({0.f, m_player_speed * dt}); break;
	}


	//Checks x position
	if (m_player.getPosition().x > m_window.getSize().x) {
		
		is_GameOver = true;
		std::cout << "GAME OVER";
		std::cout << "\nFinal Score: " << m_player_score;
		std::cout << "\nTime elapsed: " << m_timer << " seconds\n";
	}
	else if (m_player.getPosition().x < 0.f) {
		
		is_GameOver = true;
		std::cout << "GAME OVER";
		std::cout << "\nFinal Score: " << m_player_score;
		std::cout << "\nTime elapsed: " << m_timer << " seconds\n";
	}

	//Checks y position
	if (m_player.getPosition().y > m_window.getSize().y) {
		
		is_GameOver = true;
		std::cout << "GAME OVER";
		std::cout << "\nFinal Score: " << m_player_score;
		std::cout << "\nTime elapsed: " << m_timer << " seconds\n";
	}
	else if (m_player.getPosition().y < 0.f) {
		
		is_GameOver = true;
		std::cout << "GAME OVER";
		std::cout << "\nFinal Score: " << m_player_score;
		std::cout << "\nTime elapsed: " << m_timer << " seconds\n";
	}


	//Food collision
	float x_dist = (m_player.getPosition().x + m_player.getRadius()) - (m_food.getPosition().x + m_food.getRadius());
	float y_dist = (m_player.getPosition().y + m_player.getRadius()) - (m_food.getPosition().y + m_food.getRadius());

	float squared_distance = (x_dist * x_dist) + (y_dist * y_dist);
	float radii_sum = m_player.getRadius() + m_food.getRadius();

	if (squared_distance < radii_sum * radii_sum) {
		spawnFood();
		m_player_score += 1;
		m_player_speed *= 1.1f;
	}

	
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_player);

	m_window.draw(m_food);

	endDraw();
}
