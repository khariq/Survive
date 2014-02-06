using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulation
{
	
	public class Tile
	{
		public enum AttachDirection
		{
			Left,
			Right,
			Top,
			Bottom
		}

		public class AttachPoint
		{
			public int Row { get; set; }
			public int Column { get; set; }
			public AttachDirection Direction { get; set; }
		}

		List<AttachPoint> _attachPoints;

		int rows, columns;

	}
}
