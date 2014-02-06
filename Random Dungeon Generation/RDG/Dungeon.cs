using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RDG
{
	public class Dungeon
	{

		public class Coordinates : IEquatable<Coordinates>
		{
			int row;
			int column;
			public Coordinates(int r, int c)
			{
				row = r;
				column = c;
			}

			public override bool Equals(object obj)
			{
				if (obj == null) return false;
				if (obj is Coordinates)
				{
					return Equals((Coordinates)obj);
				}
				return false;
			}

			public override int GetHashCode()
			{
				return row ^ column;
			}


			public bool Equals(Coordinates other)
			{
				return row == other.row && column == other.column;
			}
		}

		public int Height { get; set; }
		public int Width { get; set; }
		
		Dictionary<Coordinates, List<Room>> map;

		public Dictionary<Coordinates, List<Room>> Map
		{
			get { return map; }
		}

		public Dungeon()
		{
			map = new Dictionary<Coordinates, List<Room>>();
		}

		public Dungeon(int rooms, int height, int width)
		{
			Height = height;
			Width = width;
			map = new Dictionary<Coordinates, List<Room>>();
			for (int i = 0; i < rooms; i++)
			{
				AddRandomRoom();
			}
		}

		public void AddRandomRoom()
		{
			int row = Random.Next(0, Height);
			int column = Random.Next(0, Width);
			
			Room room = new Room();

			for (int r = row - room.Height / 2; r < row + room.Height / 2; r++)
			{
				for (int c = column - room.Width / 2; c < column + room.Width / 2; c++)
				{
					Coordinates coord = new Coordinates(r, c);
					if (!map.Keys.Contains(coord))
					{
						map.Add(coord, new List<Room>());
					}
					map[coord].Add(room);
					
				}
			}

		}

		

	}
}
