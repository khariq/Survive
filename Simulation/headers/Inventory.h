#ifndef Survive_Simulation_Inventory_h
#define Survive_Simulation_Inventory_h

#include <map>
#include "item.h"

#define InventoryMap std::map<int, Item*>

namespace Survive
{
	namespace Simulation 
	{
		class Inventory
		{
		public:
			Inventory();
			void AddItem(Item&);
		private:
			InventoryMap inventory;
		};
	}
}

#endif