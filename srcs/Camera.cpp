/*
** EPITECH PROJECT, 2018
** raycast
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(sf::RenderWindow &win, Map &map) :
	m_window(&win), m_map(&map)
{
	m_radius = 5;
	m_camera.setRadius(m_radius);
	m_camera.setFillColor(sf::Color(255, 255, 0));
	m_camera.setOrigin(sf::Vector2f(m_radius, m_radius));

	m_speedMove = 200.0f;
	m_speedAngle = 100.0f;
	m_pos = {128, 128};
	m_fov = 60;
	m_rayLength = 500;

	for (int i = 0; i < WIDTH; i++) {
		sf::VertexArray ray(sf::Lines, 2);
		ray[0].color = sf::Color::Red;
		ray[1].color = sf::Color(100, 0, 0);
		m_rays.push_back(ray);
	}
}

Camera::~Camera()
{}

void Camera::draw()
{
	for (auto &ray : m_rays)
		m_window->draw(ray);
	m_window->draw(m_camera);
	m_map->draw();
}

void Camera::update()
{
	sf::Time dt = m_clock.restart();
	keyboardManager(dt);
	projection();
}

int Camera::distance()
{
	const double x_diff = m_pos.x - m_intersection.x;
	const double y_diff = m_pos.y - m_intersection.y;

	return std::sqrt(x_diff * x_diff + y_diff * y_diff);
}

void Camera::projection()
{
	int i = 0;
	int dist = 0;

	for (auto &ray : m_rays) {
		ray[0].position = m_pos;
		if (intersect(i))
			ray[1].position = m_intersection;
		else
			ray[1].position = {m_pos.x + m_rayLength * dCos((m_angle+m_fov / 2) - i * (m_fov / WIDTH)),
		 		   m_pos.y + m_rayLength * dSin((m_angle+m_fov / 2) - i * (m_fov / WIDTH))};
		dist = distance();
		if (dist != 0) {
			sf::RectangleShape a(sf::Vector2f(1, HEIGHT / dist));
			a.setPosition(sf::Vector2f(i, i));
			m_window->draw(a);
		}
		i++;
	}
}

void Camera::keyboardManager(sf::Time &t)
{
	sf::Vector2f tmp;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		tmp.x = m_pos.x + dCos(m_angle) * m_speedMove * t.asSeconds();
		tmp.y = m_pos.y + dSin(m_angle) * m_speedMove * t.asSeconds();
		if (!m_map->checkMapCase(tmp.x/BLOCK_SIZE, tmp.y/BLOCK_SIZE))
			m_pos = tmp;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		tmp.x = m_pos.x - dCos(m_angle) * m_speedMove * t.asSeconds();
		tmp.y = m_pos.y - dSin(m_angle) * m_speedMove * t.asSeconds();
		if (!m_map->checkMapCase(tmp.x / BLOCK_SIZE,tmp.y / BLOCK_SIZE))
			m_pos = tmp;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_angle -= m_speedAngle * t.asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_angle += m_speedAngle * t.asSeconds();
	m_angle = m_angle > 360 ? 0 : m_angle;
	m_angle = m_angle < 0 ? 360 : m_angle;

	m_camera.setPosition(m_pos);
	m_camera.setRotation(m_angle);
}

bool Camera::intersect(int i)
{
	float angle = (m_angle + m_fov / 2 - i * m_fov / WIDTH);
	sf::Vector2f dir(dCos(angle), dSin(angle));

	for (int i = 0; i < m_rayLength; i++) {
		float x = m_pos.x + i * dir.x;
		float y = m_pos.y + i * dir.y;

		if (m_map->checkMapCase(x / BLOCK_SIZE, y / BLOCK_SIZE)) {
			m_intersection = {x, y};
			return true;
		}
	}
	return false;
}