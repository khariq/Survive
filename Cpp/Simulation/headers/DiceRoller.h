#ifndef Survive_Simulation_DiceRoller_h
#define Survive_Simulation_DiceRoller_h

#include <random>

namespace Survive
{
	namespace Simulation 
	{
		class DiceRoller
		{
		public:
			static int Roll(int min, int max);
			static int RollD6();
		private:
			static std::default_random_engine generator;
			static std::uniform_int_distribution<int> d6;
		};
	}
}

#endif