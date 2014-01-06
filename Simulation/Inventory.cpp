#include "headers\Inventory.h"

using namespace Survive::Simulation;

Inventory::Inventory()
{
}

Inventory::Inventory(const Inventory& copy)
{
	inventory = copy.inventory;
}

void Inventory::AddItem(const Item& item)
{
	ItemPtr storage = std::make_shared<Item>(item);
	inventory[item.Name()] = storage;

}

void Inventory::RemoveItem(const Item& item)
{
	InventoryMap::iterator f = inventory.find(item.Name());
	inventory.erase(f);
}

Inventory Inventory::operator+(const Item& newItem) const
{
	Inventory inv(*(this));
	inv.AddItem(newItem);
	return inv;
}

Inventory Inventory::operator+=(const Item& newItem)
{
	AddItem(newItem);
	return *(this);
}

Inventory Inventory::operator-(const Item& remove) const
{
	Inventory inv(*(this));
	inv.RemoveItem(remove);
	return inv;
}

Inventory Inventory::operator-=(const Item& remove) 
{
	RemoveItem(remove);
	return *(this);
}

bool Inventory::ContainsItem(const Item& test)
{
	InventoryMap::iterator f = inventory.find(test.Name());
	return f != inventory.end();
}