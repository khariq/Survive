//
//  Actor.cpp
//  Survive-Simulation
//
//  Created by Michael Pickens on 1/4/14.
//  Copyright (c) 2014 Michael Pickens. All rights reserved.
//

#include "headers/Actor.h"

using namespace Survive::Simulation;

int Actor::nextActorID = 0;

Actor::Actor()
{
	actorID = CreateActorID();
}

int Actor::CreateActorID()
{
	return nextActorID++;
}