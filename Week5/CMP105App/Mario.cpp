#include "Mario.h"

Mario::Mario()
{
	Walk.addFrame(sf::IntRect(0, 0, 15, 21));
	Walk.addFrame(sf::IntRect(15, 0, 15, 21));
	Walk.addFrame(sf::IntRect(30, 0, 15, 21));
	Walk.addFrame(sf::IntRect(45, 0, 15, 21));
	Walk.setFrameSpeed(1.f / 10.f);
	Idle.addFrame(sf::IntRect(0, 41, 16, 20));
	Idle.addFrame(sf::IntRect(16, 41, 16, 20));
	Idle.setFrameSpeed(1.f / 10.f);
	currentAnimation = &Idle;
	speed = 20;
}

Mario::~Mario()
{
}

void Mario::update(float dt)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

void Mario::handleInput(float dt)
{
	if (inputObject->isKeyDown(sf::Keyboard::D))
	{
		if (currentAnimation != &Walk)
		{
			
			currentAnimation = &Walk;
			currentAnimation->reset();
			setTextureRect(currentAnimation->getCurrentFrame());
		}
		if (currentAnimation->getFlipped())
		{
			currentAnimation->setFlipped(false);
		}
		move(speed * dt,0);
	}
	else if (inputObject->isKeyDown(sf::Keyboard::A))
	{
		if (currentAnimation != &Walk)
		{
			currentAnimation = &Walk;
			currentAnimation->reset();
			setTextureRect(currentAnimation->getCurrentFrame());
		}
		if (!currentAnimation->getFlipped())
		{
			currentAnimation->setFlipped(true);
		}
		move(-speed * dt, 0);
	}
	else
	{
		if (currentAnimation != &Idle)
		{
			
			if (currentAnimation->getFlipped())
			{
				currentAnimation = &Idle;
				currentAnimation->reset();
				currentAnimation->setFlipped(true);
			}
			else {
				currentAnimation = &Idle;
				currentAnimation->reset();
				currentAnimation->setFlipped(false);
			}
			setTextureRect(currentAnimation->getCurrentFrame());
		}
	} 
}

void Mario::setInput(Input* in)
{
	inputObject = in;
}
