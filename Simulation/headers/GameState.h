#ifndef Survive_Simulation_GameState_h
#define Survive_Simulation_GameState_h

#include "Resources.h"

namespace Survive {
	namespace Simulation {

		class GameState
		{
		public:

			GameState();

			int GetFood()  const { return food; };
			int GetWood()  const { return wood; };
			int GetOil()   const { return oil; };
			int GetTools() const {return tools; };

		private:
			
			int food;
			int wood;
			int oil;
			int tools;


		};
	}
}

#endif;