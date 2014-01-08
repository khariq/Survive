#ifndef Survive_Simulation_Point_h
#define Survive_Simulation_Point_h

namespace Survive 
{
	namespace Simulation 
	{
		struct point {
			int x;
			int y;

			point(int _x, int _y) : x(_x), y(_y){};
		};
	}

}

#endif