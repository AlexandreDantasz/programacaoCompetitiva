using System;
using System.Text;

class Program
{

	public static void Main(string[] args)
	{
		int t = int.Parse(Console.ReadLine());
		
		while (t-- != 0)
		{
			string[] line = Console.ReadLine().Split(' ');
			int a = int.Parse(line[0]), b = int.Parse(line[1]), c = int.Parse(line[2]), d = int.Parse(line[3]);

			StringBuilder s = new StringBuilder();
			for (int i = 1; i <= 12; i++)
			{
				if (i == a || i == b)
					s.Append('a');
				else if (i == c || i == d)
					s.Append('b');
			}

			string str = s.ToString();

			Console.WriteLine(((str.Equals("baab") || str.Equals("abba") || str.Equals("aabb") || str.Equals("bbaa")) ? "NO" : "YES"));
		}
	}
}
