using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulation
{
	public class Actor
	{

		public string Tag 
		{ 
			get; 
			set; 
		}



		protected Actor() 
		{ 
			Tag = "";
		}

		protected Actor(string _tag)
		{
			Tag = _tag;
		}

	}
}
