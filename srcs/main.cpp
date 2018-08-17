/*
** EPITECH PROJECT, 2018
** raycast
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Camera.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), "floating");
	window.setFramerateLimit(60);
	Map map(window);
	Camera cam(window, map);

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					break;
				default:
					break;
			}
		}
		cam.update();
		window.clear();
		cam.draw();
		window.display();
	}
	return 0;
}