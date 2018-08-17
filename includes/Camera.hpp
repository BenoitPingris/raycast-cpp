/*
** EPITECH PROJECT, 2018
** raycast
** File description:
** Camera
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Macro.hpp"
#include "Map.hpp"

class Camera {
public:
	Camera(sf::RenderWindow &, Map &);
	~Camera();
	void draw();
	void update();
	void projection();
	void keyboardManager(sf::Time &);
	bool intersect(int);
	int distance();

	float toRadian(float deg) { return (PI / 180) * deg; }
	float dCos(float deg) { return cos(toRadian(deg)); }
	float dSin(float deg) { return sin(toRadian(deg)); }

private:
	sf::RenderWindow *m_window;
	Map *m_map;
	sf::CircleShape m_camera;
	sf::Vector2f m_pos;
	sf::Vector2f m_intersection;
	sf::Clock m_clock;

	float m_angle;
	float m_fov;
	float m_rayLength;
	float m_radius;
	float m_speedMove;
	float m_speedAngle;
	std::vector<sf::VertexArray> m_rays;
};
