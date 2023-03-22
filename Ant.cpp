#include "Ant.h"

Ant::Ant(TextureManager * texM)
{
	
	ant.setSize(sf::Vector2f(10.0f, 10.0f));
	ant.setTexture((texM->GetAntTex()));
	ant.setFillColor(sf::Color::Red);
	ant.setOrigin(sf::Vector2f(5.0f, 5.0f));
	ant.setRotation(RandomFloat(0,360));
}

void Ant::SetPosition(sf::Vector2f pos)
{
	ant.setPosition(pos);
}

void Ant::SetRotation(float angle)
{
	ant.setRotation(angle);
}

void Ant::Behaviour(sf::Time* dt, Walls * walls)
{
	sf::FloatRect nextPos;
	sf::FloatRect antBox;
	sf::FloatRect wallBox;
	sf::Vector2f velo;
	sf::Vector2f pos;
	int collisions = 0;
	bool out = true;
	antBox = ant.getGlobalBounds();
	velo = sf::Vector2(speed * cos(DegreesToRadians(ant.getRotation())), speed * -sin(DegreesToRadians(ant.getRotation())));
	nextPos = antBox;
	nextPos.left += 2 * velo.x;
	nextPos.top += 2 * velo.y;
	for (auto& wall : walls->GetWalls())
	{
		wallBox = wall.GetWall().getGlobalBounds();
		if (wallBox.intersects(antBox))
		{
			pos = sf::Vector2f((ant.getPosition().x - wall.GetPos().x) / 100, (ant.getPosition().y - wall.GetPos().y) / 100);

			collisions++;
		}
	}
	if (collisions != 0)
	{
		ant.setRotation(ant.getRotation() + RandomFloat(150, 210));
		ant.move(pos);

	}
	if (collisions == 0)
	{
		ant.setRotation(ant.getRotation() + RandomFloat(-10, 10));
		ant.move(sf::Vector2(speed * sin(DegreesToRadians(ant.getRotation())), speed * -cos(DegreesToRadians(ant.getRotation()))) * dt->asSeconds());
	}

	
}
void Ant::SetSpeed(float _speed)
{
	speed = _speed;
}

void Ant::SetMove(sf::Vector2f mov)
{
	ant.move(mov);
}


