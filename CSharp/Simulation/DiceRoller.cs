using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulation
{
	public class DiceRoller
	{
		private static Random rand;
		public static int RollD6()
		{
			if (rand == null)
				rand = new Random();
			return rand.Next(1, 6);
		}

	}
}
