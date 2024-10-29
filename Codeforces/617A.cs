using System;

class Program
{
	public static void Main(string[] args)
	{
		int x = int.Parse(Console.ReadLine());
		int steps = 0;

		steps = x / 5;
		x = x % 5;
		steps += x / 4;
		x = x % 4;
		steps += x / 3;
		x = x % 3;
		steps += x / 2;
		x = x % 2;
		steps += x;

		Console.WriteLine(steps);
	}
}
