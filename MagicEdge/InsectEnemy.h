#pragma once

#include "Enemy.h"

class InsectEnemy : public Enemy
{
public:
	InsectEnemy(Object* owner) : Enemy(owner) {}
};