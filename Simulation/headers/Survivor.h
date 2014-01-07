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
			
			static Survivor CreateRandomSurvivor();

			Survivor();
			Survivor(const Survivor& rhs);
			Survivor(std::string name, int _body, int _strength, int _willpower, int _aim);

			// Accessors
			std::string GetName()	const {return name;}
			
			// Base Stats
			int GetBody()			const {return body;}
			int GetStrength()		const {return strength;}
			int GetWillpower()		const {return willpower;}
			int GetIntuition()		const {return intuition;}
            
			// Derived Stats
			int GetHealth()         const {return health;}
			int GetSpeed()			const {return speed;}
			int GetEndurance()      const {return endurance;}
			int GetResistance()     const {return resistance;}
			int GetReflex()         const {return reflex;}
			int GetAim()			const {return aim;}

            int TakeDamage(int damageValue);
            
			InventoryPtr GetInventory() const {return inventory;}
			
			// Methods
			void PickupItem(Item& item);
			
		private:
			// Attributes
			int body;
			int strength;
			int willpower;
			int intuition;

            int health;
			int speed;
			int endurance;
			int resistance;
			int reflex;
			int aim;

			std::string name;

			std::shared_ptr<Inventory> inventory;

			// Helper methods
			void CreateInventory();

		};
	}
}
#endif