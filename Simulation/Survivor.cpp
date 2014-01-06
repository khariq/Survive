#include "headers/survivor.h"
#include <string>

using namespace std;
using namespace Survive::Simulation;

Survivor::~Survivor()
{
	if (inventory != NULL)
		delete inventory;
}

Survivor::Survivor()
{
	CreateInventory();
}

Survivor::Survivor(const Survivor& rhs) :
	body(rhs.body),
	strength(rhs.strength),
	willpower(rhs.willpower),
	aim(rhs.aim),
	name(rhs.name)
{
	CreateInventory();
}

Survivor::Survivor(string _name, int _body, int _strength, int _willpower, int _aim):
	body(_body),
	strength(_strength),
	willpower(_willpower),
	aim(_aim),
	name(_name)
{
	CreateInventory();
}

void Survivor::CreateInventory()
{
	inventory = new Inventory();
}

void Survivor::PickupItem(Item& item)
{

	inventory->AddItem(item);
}