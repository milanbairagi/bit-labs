/*
Lab 1: Define polymorphism. Write a program to achieve the run time polymorphism.
*/

class Character
{
	public virtual void Describe()
	{
		Console.WriteLine("This is a character.");
	}
}

class Player : Character
{
	public override void Describe()
	{
		Console.WriteLine("This is a player.");
	}
}

class EnemyPlayer : Character
{
	public override void Describe()
	{
		Console.WriteLine("This is an enemy player.");
	}
}

class Program
{
	static void Main()
	{
		Character player = new Player();
		Character enemy = new EnemyPlayer();

		player.Describe();
		enemy.Describe();
	}
}

