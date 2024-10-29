using System;

class Program
{
	public static void Main(string[] args)
	{
		long n = long.Parse(Console.ReadLine());
		long res = n % 2 == 0 ? n / 2 : (long) Math.Floor(n / 2.0 * (-1));
		Console.WriteLine(res);
	}
}
