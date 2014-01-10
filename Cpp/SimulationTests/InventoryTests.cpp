#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Simulation/headers/Inventory.h"
#include "../Simulation/headers/Item.h"
#include <algorithm>

namespace SimulationTests
{		
	TEST_CLASS(InventoryTests)
	{
	public:
		
		TEST_METHOD(InventoryTests_AddItem)
		{
			Survive::Simulation::Inventory inventory;
			Survive::Simulation::Item testItem("Test Item");
			inventory.AddItem(testItem);

			Assert::IsTrue(inventory.ContainsItem(testItem));
		}

		TEST_METHOD(InventoryTests_AddItem_OperatorPlus)
		{
			Survive::Simulation::Inventory inventory;
			Survive::Simulation::Item testItem("Test Item");
			Survive::Simulation::Inventory inventory2 = inventory + testItem;

			Assert::IsTrue(inventory2.ContainsItem(testItem));
			Assert::IsFalse(inventory.ContainsItem(testItem));
		}

		TEST_METHOD(InventoryTests_AddItem_OperatorPlusEquals)
		{
			Survive::Simulation::Inventory inventory;
			Survive::Simulation::Item testItem("Test Item");
			inventory += testItem;

			Assert::IsTrue(inventory.ContainsItem(testItem));
		}

		TEST_METHOD(InventoryTests_RemoveItem)
		{
			Survive::Simulation::Inventory inventory;
			Survive::Simulation::Item testItem("Test Item");
			inventory += testItem;

			Assert::IsTrue(inventory.ContainsItem(testItem));

			inventory.RemoveItem(testItem);

			Assert::IsFalse(inventory.ContainsItem(testItem));

		}

		TEST_METHOD(InventoryTests_RemoveItem_OperatorMinus)
		{
			Survive::Simulation::Inventory inventory;
			Survive::Simulation::Item testItem("Test Item");
			inventory += testItem;

			Assert::IsTrue(inventory.ContainsItem(testItem));

			Survive::Simulation::Inventory inventory2 = inventory - testItem;
			
			Assert::IsFalse(inventory2.ContainsItem(testItem));
			Assert::IsTrue(inventory.ContainsItem(testItem));
		}

		TEST_METHOD(InventoryTests_RemoveItem_OperatorMinusEquals)
		{
			Survive::Simulation::Inventory inventory;
			Survive::Simulation::Item testItem("Test Item");
			inventory += testItem;

			Assert::IsTrue(inventory.ContainsItem(testItem));

			inventory -= testItem;

			Assert::IsFalse(inventory.ContainsItem(testItem));

		}

		TEST_METHOD(InventoryTests_ListItems)
		{
			Survive::Simulation::Inventory inventory;
			Survive::Simulation::Item testItem("Test Item");
			inventory += testItem;

			Assert::IsTrue(inventory.ContainsItem(testItem));

			InventoryList listOfContents = inventory.Contents();

			Assert::IsFalse(std::find(listOfContents.begin(), listOfContents.end(), testItem.Name()) == listOfContents.end());

		}

	};
}