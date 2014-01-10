#ifndef Survive_Simulation_Survivor_h
#define Survive_Simulation_Survivor_h

#include "actor.h"
#include "Inventory.h"
#include "Destructible.h"
#include "ICombatant.h"
#include "Weapon.h"
#include "point.h"
#include <string>
#include <memory>

namespace Survive
{
	namespace Simulation 
	{
		class Survivor : public Actor, public Destructible, public ICombatant
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
			// Health is a derived stat, but it's value is tracked by the Destructible base class
			int GetSpeed()			const {return speed;}
			int GetEndurance()      const {return endurance;}
			int GetResistance()     const {return resistance;}
			int GetReflex()         const {return reflex;}
			int GetAim()			const {return aim;}

			InventoryPtr GetInventory() const {return inventory;}
			
			// Methods
			void PickupItem(Item& item);
			void SetLocation(point moveTo);
			void SetLocation(int x, int y);

			//ICombatant methods
			virtual int CalculateRangedAttackPool() const;
			virtual int CalculateMeleeAttackPool() const;
			virtual int CalculateRangedDefensePool() const;
			virtual int CalculateMeleeDefensePool() const;
			virtual Weapon& GetEquippedWeapon() const;
			virtual point GetLocation() const;

		private:
			// Attributes
			int body;
			int strength;
			int willpower;
			int intuition;
			            
			int speed;
			int endurance;
			int resistance;
			int reflex;
			int aim;

			std::string name;

			std::shared_ptr<Inventory> inventory;

			point location;

			// Helper methods
			void CreateInventory();

		};
	}
}
#endif