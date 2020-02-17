#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include "Framework/Input.h"

#pragma once
class Mario : public GameObject
{
public:
	Mario();
	~Mario();
	void update(float dt) override;
	void handleInput(float dt) override;
	void setInput(Input* in);
protected:
	Animation Walk;
	Animation Idle;
	Animation* currentAnimation;
	Input* inputObject;
	int speed;
};

