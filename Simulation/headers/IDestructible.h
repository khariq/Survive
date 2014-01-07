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
        
        class IDestructible
        {
        public:
            virtual int GetHealth() const = 0;
            virtual int TakeDamage(int damageAmount) = 0;
            
        };
        
    }
}

#endif
