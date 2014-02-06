using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RDG
{
    public class Room
    {
		public static decimal RatioThreshold { get; set; }

		public static int MinHeight { get; set; }
		public static int MinWidth { get; set; }
		public static int MaxHeight { get; set; }
		public static int MaxWidth { get; set; }

		int height, width;

		public int Height { get { return height; } }
		public int Width { get { return width; } }

		public Room()
		{
			decimal ratio = 0;
			do
			{
				height = Random.Next(MinHeight, MaxHeight);
				width = Random.Next(MinWidth, MaxWidth);

				ratio = (decimal)height / (decimal)width;

			} while (ratio > RatioThreshold);

		}

    }
}
