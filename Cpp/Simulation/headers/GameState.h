#ifndef Survive_Simulation_GameState_h
#define Survive_Simulation_GameState_h

#include "Resources.h"
#include "ICombatant.h"
#include "Tile.h"
#include "GameMap.h"

namespace Survive {
	namespace Simulation {

		class GameState
		{
		public:

			int GetFood()  const { return food; };
			int GetWood()  const { return wood; };
			int GetOil()   const { return oil; };
			int GetTools() const {return tools; };
			int GetGasoline() const {return gasoline; };
			int GetMedicalSupplies() const {return medicalSupplies; };

			int MakeTest(int dicePool);
			int MakeRangedAttack(ICombatant* attacker, ICombatant* defender);
			Tile& GetTileInfo(point tileCoords) const;

			static GameState& GetInstance();
			
		private:
			
			GameState();
			
			static GameState instance;

			GameMap strategicMap;

			int food;
			int wood;
			int oil;
			int tools;
			int gasoline;
			int medicalSupplies;

		};
	}
}

#endif;