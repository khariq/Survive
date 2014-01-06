#ifndef Survive_Simulation_Inventory_h
#define Survive_Simulation_Inventory_h

#include <map>
#include <list>
#include <memory>
#include "item.h"

#define InventoryMap std::map<std::string, std::shared_ptr<Item>>
#define ItemPtr std::shared_ptr<Item>
#define InventoryList std::list<std::string>

namespace Survive
{
	namespace Simulation 
	{
		class Inventory
		{
		public:
			Inventory();
			Inventory(const Inventory& copy);

			bool ContainsItem(const Item&);
			
			InventoryList Contents() const;

			void AddItem(const Item&);
			void RemoveItem(const Item&);
			
			Inventory operator+(const Item& add) const;
			Inventory operator+=(const Item& add);
			Inventory operator-(const Item& remove) const;
			Inventory operator-=(const Item& remove);

		private:
			InventoryMap inventory;
		};
	}
}

#endif