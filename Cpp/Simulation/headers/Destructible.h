//
//  IDestructible.h
//  Survive-Simulation
//
//  Created by Michael PIckens on 1/6/14.
//  Copyright (c) 2014 Michael PIckens. All rights reserved.
//

#ifndef Survive_Simulation_IDestructible_h
#define Survive_Simulation_IDestructible_h

namespace Survive
{
    namespace Simulation
    {
        
        class Destructible
        {
        public:
			Destructible(int maximumHealth, int currentHealth);
			
			virtual int GetHealth() const { return health; };
			virtual int TakeDamage(int damageAmount);
			virtual int HealDamage(int healAmount);

		protected:
			int health;
			int maximumHealth;

			// Pointers to a destructible should not be able to delete the derived instance
			~Destructible(){};
        };
        
    }
}

#endif
