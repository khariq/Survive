#include "headers/survivor.h"
#include <string>
#include <random>

using namespace std;
using namespace Survive::Simulation;

Survivor::Survivor()
{
	CreateInventory();
}

Survivor::Survivor(const Survivor& rhs) :
	body(rhs.body),
	strength(rhs.strength),
	willpower(rhs.willpower),
	intuition(rhs.intuition),
	name(rhs.name),
	health(rhs.health),
	speed(rhs.speed),
	endurance(rhs.endurance),
	resistance(rhs.resistance),
	reflex(rhs.reflex),
	aim(rhs.aim)
{
	CreateInventory();
}

Survivor::Survivor(string _name, int _body, int _strength, int _willpower, int _intuition):
	body(_body),
	strength(_strength),
	willpower(_willpower),
	intuition(_intuition),
	name(_name),
	health(_body + _willpower),
	speed(_body + _strength),
	endurance(_strength + _willpower),
	resistance(_body + _intuition),
	reflex(_strength + _intuition),
	aim(_intuition + _willpower)
{
	CreateInventory();
}

void Survivor::CreateInventory()
{
	inventory = std::make_shared<Inventory>();
}

void Survivor::PickupItem(Item& item)
{
	inventory->AddItem(item);
}

int Survivor::TakeDamage(int damageValue)
{
    health -= damageValue;
    return health;
}

Survivor Survivor::CreateRandomSurvivor()
{

	return Survivor();

}