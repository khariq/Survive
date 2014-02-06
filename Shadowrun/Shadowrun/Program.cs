using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shadowrun
{
	class Program
	{
		static int lineLength = 60;
		static void Main(string[] args)
		{


			Console.WriteLine("".PadLeft(80, '*'));
			Console.WriteLine(CenterAlign("This system is the property of Evo and is provided solely for use by its"));
			Console.WriteLine(CenterAlign("authorized employees in accordance with policies available for viewing on"));
			Console.WriteLine(CenterAlign("our website and in the Office of Human Resources. "));
			Console.WriteLine("".PadLeft(lineLength));
			Console.WriteLine(CenterAlign("WARNING: Criminal and coprorate penalties may be imposed for obtaining"));
			Console.WriteLine(CenterAlign("unauthorized access to this system or for causing intentional, unauthorized"));
			Console.WriteLine(CenterAlign("damage, deletion, alteration, or insertion of data. Any information stored,"));
			Console.WriteLine(CenterAlign("processed, or transmitted to this system may be monitored, used, or disclosed"));
			Console.WriteLine(CenterAlign("by authorized personnel, including law enforcement."));
			Console.WriteLine("".PadLeft(80, '*'));

			Console.WriteLine("295");
			Console.WriteLine("audit(936DA01F-9ABD-4d9d-80C7-02AF85C822A8)");
			Console.WriteLine("INIT: Talisman clone version 2.86 booting");
			WriteOkMessage("Initializing Talisman OS");
			WriteOkMessage("Setting up loopback interface");
			WriteOkMessage("Configuring kernal parameters");
			WriteOkMessage("Setting clock (utc): Tue Apr 30 2075 05:20:22 PST");
			WriteOkMessage("Activating swap partitions");
			Console.WriteLine();
			WriteMessage("Checking filesystems"); Console.WriteLine();
			WriteMessage("/: clean, 4871/26323 files, 720321/263056 blocks"); Console.WriteLine();
			WriteMessage("/home: clean, 117/130560 files, 27384/522080 blocks"); Console.WriteLine();
			WriteMessage("/var: clean, 1165/130560 files, 65117/522080 blocks"); Console.WriteLine();
			WriteMessage("/dev/md0: clean, 12/883872 files, 45604/883456 blocks"); Console.WriteLine();
			WriteMessage("/usr: clean, 81733/524288 files, 427747/524120 blocks"); Console.WriteLine();
			WriteMessage("/bot: clean, 33/66264 files, 24068/265040 blocks"); Console.WriteLine();
			Console.WriteLine();
			WriteOkMessage("Remounting root filesystem in read-write mode");
			WriteOkMessage("Mounting local filesystems");
			WriteOkMessage("Enabling local filesystem quotas");
			Console.WriteLine();

			WriteOkMessage("Sampling DNA pattern from buffer");
			
			Console.WriteLine("Preparing boot volumes".PadRight(lineLength));
			WriteOkMessage("/motor".PadLeft(15));
			WriteOkMessage("/fine-motor".PadLeft(15));
			WriteOkMessage("/speech".PadLeft(15));
			WriteFailedMessage("/persona".PadLeft(15));
			MessageInColor("Failed to load persona.  No persona found matching host body.  Please enter", ConsoleColor.Red);
			string armitageLoading_1 = "persona to load.  Default persona downloading from matrix.";
			string armitageLoading_2 = "Persona: Armitage, Jake";
			string armitageLoading_3 = "Status: e-Ghost, experiment #1";
			string armitageLoading_4 = "Progress";

			WriteMessageInRandomColors(armitageLoading_1);
			WriteMessageInRandomColors(armitageLoading_2);
			WriteMessageInRandomColors(armitageLoading_3);
			WriteMessageInRandomColors(armitageLoading_4);

		}

		private static void WriteMessageInRandomColors(string armitageLoading_1)
		{
			String[] colorNames = { "Red", "Black", "Blue" };
			System.Random rand = new Random();
			foreach (char c in armitageLoading_1.ToCharArray())
			{
				int i = rand.Next(0, colorNames.Length);
				string colorName = colorNames[i];
				ConsoleColor color = (ConsoleColor)Enum.Parse(typeof(ConsoleColor), colorName);

				if (color == ConsoleColor.Black) 
					System.Console.Write(" ");
				else
					MessageInColor(c.ToString(), color);
			}
			Console.WriteLine();
		}

		private static void WriteMessage(string msg)
		{
			Console.Write(msg.PadRight(lineLength)); 
		}

		private static void WriteOkMessage(string msg)
		{
			WriteMessage(msg);
			WriteOK();
		}

		private static void WriteFailedMessage(string msg)
		{
			WriteMessage(msg);
			WriteFail();
		}

		private static void WriteOK()
		{
			Console.Write("[  "); MessageInColor("OK", ConsoleColor.Green); Console.WriteLine("  ] ");
		}

		private static void WriteFail()
		{
			Console.Write("[ "); MessageInColor("FAIL", ConsoleColor.Red); Console.WriteLine(" ] ");
		}

		static void MessageInColor(string msg, ConsoleColor color)
		{
			ConsoleColor current = Console.ForegroundColor;
			Console.ForegroundColor = color;
			System.Console.Write(msg);
			Console.ForegroundColor = current;

		}

		

		static string CenterAlign(string msg)
		{
			int leftPad = 38 - (msg.Length / 2);
			return msg.PadLeft(leftPad, ' ');
		}

	}
}
