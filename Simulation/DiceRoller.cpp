#include "headers/DiceRoller.h"

using namespace Survive::Simulation;


int DiceRoller::Roll(int min, int max)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> die(min,max);
	return die(generator);
}

int DiceRoller::RollD6()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> d6(1,6);
	return d6(generator);
}
