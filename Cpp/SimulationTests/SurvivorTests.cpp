#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Simulation/headers/Survivor.h"
#include "../Simulation/headers/Inventory.h"
#include "../Simulation/headers/Item.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Survive::Simulation;

#define SurvivorTest TEST_METHOD_ATTRIBUTE(L"Category", L"Survivor")

namespace SimulationTests
{
	TEST_CLASS(SurvivorTests)
	{
	public:
		
		BEGIN_TEST_METHOD_ATTRIBUTE(SurvivorTests_CreateSurvivor_Default)
			TEST_METHOD_ATTRIBUTE(L"Category", L"Survivor")
			TEST_OWNER(L"Survivor")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(SurvivorTests_CreateSurvivor_Default)
		{
			// TODO: Your test code here
			Survivor test;
			Assert::IsTrue(test.GetName().length() == 0);
			Assert::IsTrue(test.GetBody() == 0);
			Assert::IsTrue(test.GetStrength() == 0);
			Assert::IsTrue(test.GetWillpower() == 0);
			Assert::IsTrue(test.GetIntuition() == 0);
			Assert::IsTrue(test.GetHealth() == 0);
			Assert::IsTrue(test.GetEndurance() == 0);
			Assert::IsTrue(test.GetResistance() == 0);
			Assert::IsTrue(test.GetReflex() == 0);
			Assert::IsTrue(test.GetAim() == 0);

		}

		TEST_METHOD(SurvivorTests_CreateSurivor_Basic)
		{
			int min = 1;
			Survivor test("Joe", min, min, min, min);
			
			Assert::IsTrue(test.GetBody() == min);
			Assert::IsTrue(test.GetStrength() == min);
			Assert::IsTrue(test.GetWillpower() == min);
			Assert::IsTrue(test.GetIntuition() == min);

			Assert::IsTrue(test.GetHealth() == min + min);
			Assert::IsTrue(test.GetSpeed() == min + min);
			Assert::IsTrue(test.GetEndurance() == min + min);
			Assert::IsTrue(test.GetResistance() == min + min);
			Assert::IsTrue(test.GetReflex() == min + min);
			Assert::IsTrue(test.GetAim() == min + min);
		}

		TEST_METHOD(SurvivorTests_CreateSurvivor_Random)
		{
			Survivor test = Survive::Simulation::Survivor::CreateRandomSurvivor();
			Assert::IsTrue(test.GetName() == "Random");

			int min = 1, max = 6;
			// TEST Basic stats
			Assert::IsTrue(min <= test.GetBody()	  && test.GetBody() <= max);
			Assert::IsTrue(min <= test.GetStrength()  && test.GetStrength() <= max);
			Assert::IsTrue(min <= test.GetWillpower() && test.GetWillpower() <= max);
			Assert::IsTrue(min <= test.GetIntuition() && test.GetIntuition() <= max);

			// TEST derived stats
			min = 2, max = 12;
			Assert::IsTrue(min <= test.GetHealth()	  && test.GetHealth() <= max);
			Assert::IsTrue(min <= test.GetSpeed()  && test.GetSpeed() <= max);
			Assert::IsTrue(min <= test.GetEndurance() && test.GetEndurance() <= max);
			Assert::IsTrue(min <= test.GetResistance() && test.GetResistance() <= max);
			Assert::IsTrue(min <= test.GetReflex() && test.GetReflex() <= max);
			Assert::IsTrue(min <= test.GetAim() && test.GetAim() <= max);

		}

		TEST_METHOD(SurvivorTests_CreateSurvivor_DerivedStats_Health)
		{
			Survivor test("Joe", 1, 0, 1, 0);
			Assert::AreEqual(test.GetHealth(), 2);
		}

		TEST_METHOD(SurvivorTests_CreateSurvivor_DerivedStats_Speed)
		{
			Survivor test("Joe", 1, 1, 0, 0);
			Assert::AreEqual(test.GetSpeed(), 2);
		}

		TEST_METHOD(SurvivorTests_CreateSurvivor_DerivedStats_Endurance)
		{
			Survivor test("Joe", 0, 1, 1, 0);
			Assert::AreEqual(test.GetEndurance(), 2);
		}

		TEST_METHOD(SurvivorTests_CreateSurvivor_DerivedStats_Resistance)
		{
			Survivor test("Joe", 1, 0, 0, 1);
			Assert::AreEqual(test.GetResistance(), 2);
		}

		TEST_METHOD(SurvivorTests_CreateSurvivor_DerivedStats_Reflex)
		{
			Survivor test("Joe", 0, 1, 0, 1);
			Assert::AreEqual(test.GetReflex(), 2);
		}

		TEST_METHOD(SurvivorTests_CreateSurvivor_DerivedStats_Aim)
		{
			Survivor test("Joe", 0, 0, 1, 1);
			Assert::AreEqual(test.GetAim(), 2);
		}


		TEST_METHOD(SurvivorTests_AccessorTest_Intuition)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetIntuition(), 1);
		}

		TEST_METHOD(SurvivorTests_AccessorTest_Body)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetBody(), 1);
		}

		TEST_METHOD(SurvivorTests_AccessorTest_Inventory)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::IsNotNull(test.GetInventory().get());
		}

		TEST_METHOD(SurvivorTests_AccessorTest_Name)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetName(), std::string("Joe"));
		}

		TEST_METHOD(SurvivorTests_AccessorTest_Strength)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetStrength(), 1);
		}

		TEST_METHOD(SurvivorTests_AccessorTest_Willpower)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetWillpower(), 1);
		}

		TEST_METHOD(SurvivorTests_ActionTest_PickupItem)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			
			Item testItem("Test Item");
			test.PickupItem(testItem);

			Assert::IsTrue(test.GetInventory()->ContainsItem(testItem));

		}


	};
}