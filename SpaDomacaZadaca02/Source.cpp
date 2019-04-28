#include <SFML/Graphics.hpp>
#include "Game.h";
#include "game_of_life.h"
#include <ctime>
#include <windows.h>
#include <chrono>
#include <thread>

int main() {
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of life!");
	window.setFramerateLimit(60);
	Game game(&window);
	game_of_life gg;

	std::chrono::duration<int, std::milli> timespan(125);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		gg.sljedeca_generacija();
		std::this_thread::sleep_for(timespan);
		game.draw_rectangle(gg);

		window.display();
	}

	return 0;
}