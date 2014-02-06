using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulation
{
	public class GameMap
	{

		List<Tile> _map;
		List<Tile> _openEdges;

		void AddTile(Tile newTile)
		{
			// select tile from list of open edges
			
			// select attach point from the selected edge => "pinned"

			// select attach point from newTile => "attach"

			// Rotate attached tile to orient attach points
			#region Rotation
			// all rotations about the y-axis

			// if attach.point.direction == pinned.point.direction (i.e. both "top")
			// then rotate attach 180 degrees

			// if attach.point.direction == left 
			//		if pinned.point.direction == right
			//			then return
			//		if pinned.point.direction == bottom
			//			then rotate attach 90 degrees
			//		if pinned.point.direction == top
			//			then rotate attach -90 degrees
			
			// if attach.point.direction == right
			//		if pinned.point.direction == left
			//			then return
			//		if pinned.point.direction == top
			//			then rotate attach 90 degrees
			//		if pinned.point.direction == bottom
			//			then rotate attach -90 degrees
			
			// if attach.point.direction == top
			//		if pinned.point.direction == bottom
			//			then return
			//		if pinned.point.direction == left
			//			then rotate attach 90 degrees
			//		if pinned.point.direction == right
			//			then rotate attach -90 degrees

			// if attach.point.direction == bottom 
			//		if pinned.point.direction == top
			//			then return
			//		if pinned.point.direction == right
			//			then rotate attach 90 degrees
			//		if pinned.point.direction == left
			//			then rotate attach -90 degrees
			#endregion

			// translate attached tile to align attach points
			#region Translate
			
			// translate attach to pinned origin
			// translate attach
			//		x = x + pinned.attach.row
			//		z = z + pinned.attach.col
			// if pinned.attach.direction == top
			//		translate attach.z = pinned.attach.z - tile.height (constant?)
			// if pinned.attach.direction == bottom
			//		translate pinned.attach.z + tile.height
			// if pinned.attach.direction == left
			//		translate pinned.attach.x - tile.height
			// if pinned.attach.direction == right
			//		translate pinned.attaxh.x + tile.height
			#endregion
		
			// add tile to world graph
		
		}

	}
}
