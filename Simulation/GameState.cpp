#include "headers/GameState.h"
#include "headers/DiceRoller.h"

using namespace Survive::Simulation;

GameState GameState::instance;

GameState& GameState::GetInstance()
{
	return instance;
}

GameState::GameState():
	food(0),
	oil(0),
	tools(0),
	wood(0),
	gasoline(0),
	medicalSupplies(0)
{

}

int GameState::MakeTest(int dicePool)
{
	int hitCounter = 0;
	for (int i = 0; i < dicePool; i++)
	{
		if (DiceRoller::RollD6() >= 5)
			hitCounter++;
	}
	return hitCounter;
}

int GameState::MakeRangedAttack(ICombatant* attacker, ICombatant* defender)
{
	
	return 0;
}