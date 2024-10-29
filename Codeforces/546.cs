using System; 

class Program
{
	public static void Main(string[] args)
	{
		string[] line = Console.ReadLine().Split(' ');

		int k = int.Parse(line[0]), n = int.Parse(line[1]), w = int.Parse(line[2]);

		int res, i = 1, totalAmount = 0;

		while (w != 0)
		{
			totalAmount += k * i++;
			w--;
		}	

		res = Math.Max(totalAmount - n, 0);

		Console.WriteLine(res);
	}
}
