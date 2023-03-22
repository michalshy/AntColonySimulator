#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "TextureManager.h"
#include "Walls.h"
import Utils;
class Ant
{
	sf::RectangleShape ant;
	float speed = 100.0f;
public:
	Ant(TextureManager * texM);
	float GetRotation() { return ant.getRotation(); }
	float GetSpeed() { return speed; }
	sf::Vector2f GetPos() { return ant.getPosition(); }
	sf::FloatRect GetGlobalBounds() { return ant.getGlobalBounds(); }
	void SetPosition(sf::Vector2f pos);
	void SetRotation(float angle);
	void SetSpeed(float _speed);
	void SetMove(sf::Vector2f mov);
	void Behaviour(sf::Time* dt, Walls * walls);
	
	
	sf::RectangleShape GetAnt() { return ant; }
};

