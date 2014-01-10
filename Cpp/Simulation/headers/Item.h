#ifndef Survive_Simulation_Item_h
#define Survive_Simulation_Item_h

#include "Actor.h"
#include <string>

namespace Survive
{
	namespace Simulation 
	{
		class Item : public Actor
		{
		public:
			Item();
			Item(const Item& rhs);
			Item(std::string name);

			std::string Name() const { return name; }

		private:
			std::string name;
		};
	}
}

#endif
