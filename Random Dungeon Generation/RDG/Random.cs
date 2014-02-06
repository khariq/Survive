using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RDG
{
	public class Random
	{
		private static System.Random generator = null;
		private static System.Random Generator
		{
			get
			{
				if (generator == null)
					generator = new System.Random(RandomSeed);
				return generator;
			}
		}
		public static int RandomSeed { get; set; }
		
		public static int Next()
		{
			return Generator.Next();
		}

		public static double NextDouble()
		{
			return Generator.NextDouble();
		}

		public static int Next(int min, int max)
		{				
			return Generator.Next(min, max);
		}

		
	}
}
