#include "headers/survivor.h"
#include "headers/DiceRoller.h"
#include <string>
#include <random>

using namespace std;
using namespace Survive::Simulation;

Survivor::Survivor():
	body(0),
	strength(0),
	willpower(0),
	intuition(0),
	name(""),
	speed(0),
	endurance(0),
	resistance(0),
	reflex(0),
	aim(0),
	Destructible(0, 0),
	location(0,0)
{
	CreateInventory();
}

Survivor::Survivor(const Survivor& rhs) :
	body(rhs.body),
	strength(rhs.strength),
	willpower(rhs.willpower),
	intuition(rhs.intuition),
	name(rhs.name),
	speed(rhs.speed),
	endurance(rhs.endurance),
	resistance(rhs.resistance),
	reflex(rhs.reflex),
	aim(rhs.aim),
	Destructible(rhs.body + rhs.willpower, rhs.body + rhs.willpower),
	location(rhs.location.x, rhs.location.y)
{
	CreateInventory();
}

Survivor::Survivor(string _name, int _body, int _strength, int _willpower, int _intuition):
	body(_body),
	strength(_strength),
	willpower(_willpower),
	intuition(_intuition),
	name(_name),
	speed(_body + _strength),
	endurance(_strength + _willpower),
	resistance(_body + _intuition),
	reflex(_strength + _intuition),
	aim(_intuition + _willpower),
	Destructible(_body + _willpower ,_body + _willpower),
	location(0,0)
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

Survivor Survivor::CreateRandomSurvivor()
{
	return Survivor("Random", DiceRoller::RollD6(), DiceRoller::RollD6(),DiceRoller::RollD6(),DiceRoller::RollD6());
	
}

//IAttacker methods
int Survivor::CalculateRangedAttackPool() const
{
	return aim;
}
int Survivor::CalculateMeleeAttackPool() const
{
	return speed + reflex;
}

// IDefender methods
int Survivor::CalculateRangedDefensePool() const
{
	return reflex;
}
int Survivor::CalculateMeleeDefensePool() const
{
	return reflex + speed;
}

Weapon& Survivor::GetEquippedWeapon() const
{
	return Weapon();
}


void Survivor::SetLocation(int x, int y)
{
	location.x = x;
	location.y = y;
}

void Survivor::SetLocation(point moveTo)
{
	location.x = moveTo.x;
	location.y = moveTo.y;
}

point Survivor::GetLocation() const
{
	return location;
}