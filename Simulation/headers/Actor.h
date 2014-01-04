//
//  Actor.h
//  Survive-Simulation
//
//  Created by Michael Pickens on 1/4/14.
//  Copyright (c) 2014 Michael Pickens. All rights reserved.
//

#ifndef Survive_Simulation_Actor_h
#define Survive_Simulation_Actor_h

class Actor
{

public:
    Actor();
    
    int GetActorID();
    
private:
    int actorID;
    
    static int CreateActorID();
    
    
    
};


#endif
