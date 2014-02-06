using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace RDG_Tests
{
	[TestClass]
	public class DungeonTests
	{
		decimal ratioThreshold;

		[TestInitialize]
		public void Setup()
		{
			ratioThreshold = 1.61m;
			RDG.Room.MinWidth = 2;
			RDG.Room.MaxWidth = 8;
			RDG.Room.MinHeight = 2;
			RDG.Room.MaxHeight = 8;
			RDG.Room.RatioThreshold = ratioThreshold;
			RDG.Random.RandomSeed = 1;
		}

		[TestMethod]
		public void AddRandomRoom()
		{
			RDG.Dungeon dungeon = new RDG.Dungeon()
			{
				Height = 200,
				Width = 200
			};
			dungeon.AddRandomRoom();
		}

		[TestMethod]
		public void BuildDungeon()
		{
			RDG.Dungeon dungeon = new RDG.Dungeon(80, 80, 80);

			System.IO.StreamWriter fout = new System.IO.StreamWriter("C:\\Test.txt");
			List<RDG.Room> roomList;
			for (int r = 0; r < dungeon.Height; r++)
			{
				for (int c = 0; c < dungeon.Height; c++)
				{
					RDG.Dungeon.Coordinates coords = new RDG.Dungeon.Coordinates(r,c);
					if (dungeon.Map.TryGetValue(coords, out roomList))
					{
						fout.Write(roomList.Count);
					}
					else
					{
						fout.Write("0");
					}
				}
				fout.WriteLine();
			}
			fout.Flush();
			fout.Close();
		}

	}
}
