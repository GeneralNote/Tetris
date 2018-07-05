#include <SFML/Graphics.hpp>
#include "Game.h"

// Block types
enum class Block
{
	I,
	O,
	T,
	S,
	Z,
	J,
	L,
	Count
};

int main()
{
	srand(time(NULL));


	

	sf::RenderWindow wnd(sf::VideoMode(600, 760), "Tetris", sf::Style::Titlebar | sf::Style::Close);
	sf::Event e;

	te::Game game(wnd.getSize().x, wnd.getSize().y);

	while (wnd.isOpen()) {
		while (wnd.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				wnd.close();
			game.OnEvent(e);
		}

		game.OnUpdate();

		wnd.clear();
		game.Render(wnd);
		wnd.display();
	}


	return 0;
}

