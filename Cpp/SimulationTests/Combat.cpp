#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Simulation/headers/Survivor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Survive::Simulation;

namespace SimulationTests
{
	TEST_CLASS(CombatTests)
	{
	public:
		
		static Survive::Simulation::Survivor MakeTestSurvivor()
		{
			int body = 1, strength = 1, intuition = 1, willpower = 1;
			return Survive::Simulation::Survivor("Test", body, strength, intuition, willpower);
		}

		TEST_METHOD(CombatTests_Survivor_CalculateRangedAttackPool)
		{
			Survivor test = MakeTestSurvivor();
			int rangedAttackPool = test.CalculateRangedAttackPool();
			Assert::AreEqual(rangedAttackPool, test.GetAim());
			
		}

		TEST_METHOD(CombatTests_Survivor_CalculateMeleeAttackPool)
		{
			Survivor test = MakeTestSurvivor();
			int attackPool = test.CalculateMeleeAttackPool();
			Assert::AreEqual(attackPool, test.GetReflex() + test.GetSpeed());
			
		}

		TEST_METHOD(CombatTests_Survivor_CalculateRangedDefensePool)
		{
			Survivor test = MakeTestSurvivor();
			int attackPool = test.CalculateRangedDefensePool();
			Assert::AreEqual(attackPool, test.GetReflex());
			
		}

		TEST_METHOD(CombatTests_Survivor_CalculateMeleeDefensePool)
		{
			Survivor test = MakeTestSurvivor();
			int attackPool = test.CalculateMeleeDefensePool();
			Assert::AreEqual(attackPool, test.GetReflex() + test.GetSpeed());
			
		}

	};
}