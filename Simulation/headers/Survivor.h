#ifndef Survive_Simulation_Survivor_h
#define Survive_Simulation_Survivor_h

#include "actor.h"
#include "Inventory.h"
#include "IDestructible.h"
#include <string>
#include <memory>

namespace Survive
{
	namespace Simulation 
	{
		class Survivor : public Actor, public IDestructible
		{
		public:
			
			Survivor();
			Survivor(const Survivor& rhs);
			Survivor(std::string name, int _body, int _strength, int _willpower, int _aim);

			// Accessors
			std::string GetName()	const {return name;}
			int GetBody()			const {return body;}
			int GetStrength()		const {return strength;}
			int GetWillpower()		const {return willpower;}
			int GetAim()			const {return aim;}
            int GetHealth()         const {return health;}
            
            int TakeDamage(int damageValue);
            
			InventoryPtr GetInventory() const {return inventory;}
			
			// Methods
			void PickupItem(Item& item);
			
		private:
			// Attributes
			int body;
			int strength;
			int willpower;
			int aim;
            int health;

			std::string name;

			std::shared_ptr<Inventory> inventory;

			// Helper methods
			void CreateInventory();

		};
	}
}
#endif