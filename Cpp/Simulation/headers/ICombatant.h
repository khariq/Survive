#include "Weapon.h"
#include "point.h"

namespace Survive 
{
	namespace Simulation 
	{
		class ICombatant
		{
		public:
			virtual int CalculateRangedAttackPool() const = 0;
			virtual int CalculateMeleeAttackPool() const = 0;

			virtual int CalculateRangedDefensePool() const = 0;
			virtual int CalculateMeleeDefensePool() const = 0;

			virtual Weapon& GetEquippedWeapon() const = 0;

			virtual point GetLocation() const = 0;

		protected:
			// attackers cannot be destroyed
			~ICombatant(){};
		};
	}
}
