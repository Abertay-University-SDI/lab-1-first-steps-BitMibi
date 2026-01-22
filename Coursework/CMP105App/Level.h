#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();
	void spawnFood();

private:
	// Default functions for rendering to the screen.

	// Default variables for level class.
	

	//Player

	sf::CircleShape m_player;

	float m_player_speed = 200;

	//Keys Pressed

	enum Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	Direction m_direction;

	//Food mmmm yummy food drools like homer simpson

	sf::CircleShape m_food;


	//Game Over and points
	bool is_GameOver = false;
	int m_player_score = 0;
	float m_timer = 0.f;

};