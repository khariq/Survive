
namespace Survive 
{
	namespace Simulation 
	{
		class IDefender
		{
		public:
			virtual int CalculateRangedDefensePool() const = 0;
			virtual int CalculateMeleeDefensePool() const = 0;

			virtual Weapon& GetEquippedWeapon() const = 0;

		protected:
			~IDefender(){};
		};
	}
}
