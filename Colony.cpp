#include "Colony.h"


void Colony::CreateColony(int amount, TextureManager* texM)
{
	for (int i = 0; i < amount; i++)
	{
		Ant ant(texM);
		ant.SetPosition(colonyHeart.getPosition());
		colonyAnts.push_back(ant);
	}
}

Colony::Colony(TextureManager* texM)
{
	colonyHeart.setSize(sf::Vector2f(100.0f,100.0f));
	colonyHeart.setOrigin(colonyHeart.getSize().x / 2,colonyHeart.getSize().y/2);
	colonyHeart.setPosition(sf::Vector2f(950.0f, 500.0f));
	colonyHeart.setFillColor(sf::Color::Cyan);	

	CreateColony(250, texM);
}

void Colony::DrawColony(sf::RenderWindow* window)
{
	window->draw(colonyHeart);
	for (auto& ant : colonyAnts)
	{
		window->draw(ant.GetAnt());
	}
}

//void Colony::Simulation()
//{
//	for (auto& ant : colonyAnts)
//	{
//		ant.Behaviour();
//	}
//}

void Colony::Check(Walls * walls, sf::Time * dt)
{

	
	for (auto& ant : colonyAnts)
	{
		ant.Behaviour(dt, walls);
	}
}



