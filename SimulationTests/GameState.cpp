#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Simulation/headers/GameState.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Survive::Simulation;


namespace SimulationTests
{
	TEST_CLASS(GameStateTests)
	{
	public:
		
		TEST_METHOD(GameStateTests_MakeTest)
		{
			// TODO: Your test code here
			int dicePool = 5;
			int hits = GameState::GetInstance().MakeTest(dicePool);
			
			Assert::IsTrue(hits <= dicePool);

		}

	};
}