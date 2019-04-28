#include "Game.h"
#include "game_of_life.h"

Game::Game(sf::RenderWindow* window) : window(window){
}

void Game::draw_rectangle(game_of_life gg) {
	sf::RectangleShape rectanlges(sf::Vector2f(40.0f, 15.0f));
	rectanlges.setOutlineThickness(1.0f);
	rectanlges.setOutlineColor(sf::Color::Blue);
	
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 40; j++) {
			
			rectanlges.setPosition(sf::Vector2f(j * 20.0f, i * 30.0f));
			(gg.generacija[i][j]) ? rectanlges.setFillColor(sf::Color::Cyan) :
				                    rectanlges.setFillColor(sf::Color::Black);
			window->draw(rectanlges);
		}
		
	}
}

