#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Simulation/headers/Survivor.h"
#include "../Simulation/headers/Inventory.h"
#include "../Simulation/headers/Item.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Survive::Simulation;

namespace SimulationTests
{
	TEST_CLASS(SurvivorTests)
	{
	public:
		
		TEST_METHOD(CreateSurvivor_Default)
		{
			// TODO: Your test code here
			Survivor test;
			Assert::IsTrue(true);
		}

		TEST_METHOD(CreateSurivor_Basic)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::IsTrue(true);
		}

		TEST_METHOD(CreateSurvivor_DerivedStats_Health)
		{
			Survivor test("Joe", 1, 0, 1, 0);
			Assert::AreEqual(test.GetHealth(), 2);
		}

		TEST_METHOD(CreateSurvivor_DerivedStats_Speed)
		{
			Survivor test("Joe", 1, 1, 0, 0);
			Assert::AreEqual(test.GetSpeed(), 2);
		}

		TEST_METHOD(CreateSurvivor_DerivedStats_Endurance)
		{
			Survivor test("Joe", 0, 1, 1, 0);
			Assert::AreEqual(test.GetEndurance(), 2);
		}

		TEST_METHOD(CreateSurvivor_DerivedStats_Resistance)
		{
			Survivor test("Joe", 1, 0, 0, 1);
			Assert::AreEqual(test.GetResistance(), 2);
		}

		TEST_METHOD(CreateSurvivor_DerivedStats_Reflex)
		{
			Survivor test("Joe", 0, 1, 0, 1);
			Assert::AreEqual(test.GetReflex(), 2);
		}

		TEST_METHOD(CreateSurvivor_DerivedStats_Aim)
		{
			Survivor test("Joe", 0, 0, 1, 1);
			Assert::AreEqual(test.GetAim(), 2);
		}


		TEST_METHOD(AccessorTest_Intuition)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetIntuition(), 1);
		}

		TEST_METHOD(AccessorTest_Body)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetBody(), 1);
		}

		TEST_METHOD(AccessorTest_Inventory)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::IsNotNull(test.GetInventory().get());
		}

		TEST_METHOD(AccessorTest_Name)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetName(), std::string("Joe"));
		}

		TEST_METHOD(AccessorTest_Strength)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetStrength(), 1);
		}

		TEST_METHOD(AccessorTest_Willpower)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			Assert::AreEqual(test.GetWillpower(), 1);
		}

		TEST_METHOD(ActionTest_PickupItem)
		{
			Survivor test("Joe", 1, 1, 1, 1);
			
			Item testItem("Test Item");
			test.PickupItem(testItem);

			Assert::IsTrue(test.GetInventory()->ContainsItem(testItem));

		}


	};
}