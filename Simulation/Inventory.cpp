#include "headers\Inventory.h"

using namespace Survive::Simulation;

Inventory::Inventory()
{
}

void Inventory::AddItem(Item& item)
{
	Item* storage = new Item(item);
	inventory[storage->GetActorID()] = storage;

}