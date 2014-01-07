#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Simulation/headers/DiceRoller.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SimulationTests
{
	TEST_CLASS(DieRollerTests)
	{
	public:
		
		TEST_METHOD(DiceRoller_D6)
		{
			// TODO: Your test code here

			int result = Survive::Simulation::DiceRoller::RollD6();
			Assert::IsTrue( 1 <= result  && result <= 6);

		}

		TEST_METHOD(DiceRoller_Rand)
		{
			int min = 3, max = 12;
			int result = Survive::Simulation::DiceRoller::Roll(min, max);
			Assert::IsTrue( min <= result && result <= max);
		}

	};
}