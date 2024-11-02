using System;

class Program
{
	public static void Main(string[] args)
	{
		int t = int.Parse(Console.ReadLine());

		while (t-- != 0)
		{
			string s = Console.ReadLine();
			int res = 1, discount = 0;

			for (int i = 0; i < s.Length - 1; i++)
			{
				if (s[i] != s[i + 1])
					res++;  

				if (s[i] == '0' && s[i + 1] == '1')
					discount = 1;
				
			}

			Console.WriteLine(res - discount);
		}	
	}
}
