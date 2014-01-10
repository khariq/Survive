#include "headers/Destructible.h"

using namespace Survive::Simulation;

Destructible::Destructible(int max, int current):
	maximumHealth(max),
	health(current)
{
}

int Destructible::TakeDamage(int value)
{
	health -= value;
	if (health < 0)
		health = 0;
	return health;

}

int Destructible::HealDamage(int value)
{
	health += value;
	if (health > maximumHealth)
		health = maximumHealth;
	return health;

}