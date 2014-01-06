#include "headers\Item.h"

namespace Survive
{
	namespace Simulation 
	{
		Item::Item()
		{
		}

		Item::Item(const Item& copy)
		{
			name = copy.name;
		}

		Item::Item(std::string _name)
		{
			name = _name;
		}

	}
}