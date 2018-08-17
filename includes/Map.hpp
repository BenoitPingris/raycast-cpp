/*
** EPITECH PROJECT, 2018
** raycast
** File description:
** Map
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "Macro.hpp"
#include "StringTools.hpp"

class Map {
public:
	Map(sf::RenderWindow &);
	~Map();
	void draw();
	void update();
	void load(std::string);
	bool checkMapCase(int x, int y);

private:
	sf::RenderWindow *m_window;
	std::vector<std::vector<int>> m_map;
	std::vector<sf::RectangleShape> m_boxes;
};
