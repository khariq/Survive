using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace RDG_Tests
{
	[TestClass]
	public class RoomTests
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
		public void RoomConstruction()
		{			

			RDG.Room test = new RDG.Room();
			decimal ratio = (decimal)test.Height / (decimal)test.Width;
			Assert.IsTrue(ratio < ratioThreshold);
			Assert.IsTrue(RDG.Room.MinWidth <= test.Width && test.Width <= RDG.Room.MaxWidth);
			Assert.IsTrue(RDG.Room.MinHeight <= test.Height && test.Height <= RDG.Room.MaxHeight);

		}
	}
}
