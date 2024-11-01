using System;

class Program
{
	public static void Main(string[] args)
	{
		int t = int.Parse(Console.ReadLine());
		while (t-- != 0)
		{
			string[] line = Console.ReadLine().Split(' ');
			int x = int.Parse(line[0]), y = int.Parse(line[1]);
			Console.Write($"{Math.Min(x, y)} {Math.Max(x, y)}\n");
		}	
	}
}
