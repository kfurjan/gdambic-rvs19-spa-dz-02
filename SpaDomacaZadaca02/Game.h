#pragma once
#include <SFML/Graphics.hpp>
#include "game_of_life.h"
class Game {
private:
	sf::RenderWindow* window;
public:
	Game(sf::RenderWindow* window);
	void draw_rectangle(game_of_life gg);
};

