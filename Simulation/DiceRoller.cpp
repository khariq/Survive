#include "headers/DiceRoller.h"
#include <chrono>

using namespace Survive::Simulation;

int DiceRoller::Roll(int min, int max)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> die(min,max);
	return die(generator);
}

int DiceRoller::RollD6()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> d6(1,6);
	return d6(generator);
}
