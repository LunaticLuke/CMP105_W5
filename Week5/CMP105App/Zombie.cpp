#include "Zombie.h"
#include "Framework/Input.h"

Zombie::Zombie()
{
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);
	speed = 20;
}

Zombie::~Zombie()
{
}

void Zombie::setInput(Input* in)
{
	inputObject = in;
}

void Zombie::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt)
{
	if (inputObject->isKeyDown(sf::Keyboard::Right))
	{
		if (!walk.getPlaying())
		{
			walk.play(true);
		}
		move(sf::Vector2f(speed * dt, 0));

		if (walk.getFlipped())
		{
			walk.setFlipped(false);
		}
	}
	else if (inputObject->isKeyDown(sf::Keyboard::Left))
	{
		if (!walk.getPlaying())
		{
			walk.play(true);
		}
		move(sf::Vector2f(-speed * dt, 0));
		if (!walk.getFlipped())
		{
			walk.setFlipped(true);
		}
	}
	else
	{
		walk.stop();
	}
}

int Zombie::getSpeed()
{
	return speed;
}

