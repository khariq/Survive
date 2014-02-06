using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DiscoveryLogic.PDE.MgmtConsole.Entity;
using System.Reflection;

namespace Reflection
{
	class Program
	{
		static void Main(string[] args)
		{

			using (PDEMgmtConsoleConnection context = new PDEMgmtConsoleConnection())
			{

				var profiles = from profile in context.MatchProfiles
							   where profile.JobID == 8
							   select profile;

				foreach (MatchProfile m in profiles)
				{

					foreach (PropertyInfo property in m.GetType().GetProperties())
					{
						System.Console.WriteLine("{0} = {1}", property.Name, property.GetValue(m));
					}
					break;
				}

			}

		}
	}
}
