using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulation
{
	public class Survivor : Actor
	{

		public enum Traits
		{
			// Positive
			Lucky = 1,
			Bullseye = 2,
			Quick = 3,
			Tough = 4,
			Catlike = 5,
			Engineer = 6,

			// Negative
			Clutz = -1,
			OneEye = -2,
			Overweight = -3,
			ThinSkin = -4,
			Sluggish = -5,
			MechanicallyChallenged = -6
		}

		public int Body { get; private set; }
		public int Strength { get; private set; }
		public int Intuition { get; private set; }
		public int Willpower { get; private set; }

		public int Health { get; private set; }
		public int Speed { get; private set; }
		public int Endurance { get; private set; }
		public int Resistance { get; private set; }
		public int Reflex { get; private set; }
		public int Aim { get; private set; }

		public Traits PositiveTrait { get; private set; }
		public Traits NegativeTrait { get; private set; }

		public string Name { get; set; }

		public Survivor(int body, int strength, int intuition, int willpower)
		{
			Body = body;
			Strength = strength;
			Intuition = intuition;
			Willpower = willpower;

			Health = body + willpower;
			Speed = body + strength;
			Endurance = strength + willpower;
			Resistance = body + intuition;
			Reflex = strength + intuition;
			Aim = intuition + willpower;

			int roll = 1, negativeRoll = 1;
			do
			{
				roll = DiceRoller.RollD6();
				negativeRoll = -1 * DiceRoller.RollD6();
				PositiveTrait = (Traits)roll;
				NegativeTrait = (Traits)roll;
			}
			while (roll + negativeRoll == 0);
			
		}

	}
}
