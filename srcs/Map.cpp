/*
** EPITECH PROJECT, 2018
** raycast
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(sf::RenderWindow &window) :
	m_window(&window)
{
	int x = 0;
	int y = 0;
	m_map = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	for (auto &line : m_map) {
		x = 0;
		for (auto &c : line) {
			if (c == 1) {
				sf::RectangleShape rect(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
				rect.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				m_boxes.push_back(rect);
			}
			x++;
		}
		y++;
	}
}

Map::~Map()
{}

void Map::draw()
{
	for (auto &rect : m_boxes)
		m_window->draw(rect);
}

void Map::load(std::string fileName)
{}

void Map::update()
{}

bool Map::checkMapCase(int x, int y)
{
	return m_map[y][x] != 0;
}