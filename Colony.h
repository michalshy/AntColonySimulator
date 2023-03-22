#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Ant.h"
#include <iostream>
#include "Walls.h"
import Utils;
class Colony
{
	std::vector<Ant> colonyAnts;
	sf::RectangleShape colonyHeart;
public:
	
	Colony(TextureManager* texM);
	std::vector<Ant> GetColony() { return colonyAnts; }
	void DrawColony(sf::RenderWindow* window);
	sf::RectangleShape GetHeart() { return colonyHeart; }
	void Check(Walls * walls, sf::Time* dt);
	//void Simulation();
	void CreateColony(int amount, TextureManager* texM);

	
	
};

