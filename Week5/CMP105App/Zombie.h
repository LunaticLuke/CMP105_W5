#include "Framework/Animation.h"
#include "Framework/GameObject.h"

#pragma once
class Zombie : public GameObject
{
public:
	Zombie();
	~Zombie();

	void update(float dt) override;
	int getSpeed();
	void handleInput(float dt) override;
	void setInput(Input* in);
protected:
	Animation walk;
	int speed;
	Input* inputObject;
};

