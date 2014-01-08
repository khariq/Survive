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

		TEST_METHOD(DiceRoller_CoverageD6)
		{
			int iteration = 0;
			bool one = false, two = false, three = false, four = false, five = false, six = false;
			bool all = one && two && three && four && five && six;

			while (!all)
			{
				iteration++;
				if (iteration > 1000)
					break;
				int result = Survive::Simulation::DiceRoller::RollD6();
				switch (result)
				{
				case 1:
					one = true;
					break;
				case 2:
					two = true;
					break;
				case 3:
					three = true;
					break;
				case 4:
					four = true;
					break;
				case 5:
					five = true;
					break;
				case 6:
					six = true;
					break;
				}
				all = one && two && three && four && five && six;

			}
			Assert::IsTrue(all);
		}

	};
}