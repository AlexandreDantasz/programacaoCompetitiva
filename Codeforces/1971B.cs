using System;

class Program
{
	private static bool IsOneLetter(string s)
	{
		char letter = s[0];
		foreach (var c in s)
		{
			if (c != letter)
				return false;
		}

		return true;
	}

	private static string MountString(string s)
	{
		char letter;
		char[] resChar = s.ToCharArray();


		for (int i = 0; i < s.Length; i++)
		{
			letter = s[i];
			for (int j = i + 1; j < s.Length; j++)
			{
				if (letter != s[j])
				{
					resChar[i] = s[j];
					resChar[j] = s[i];
					return new String(resChar);
				}
			}
		}

		return string.Empty;
	}

	public static void Main(string[] args)
	{
		int t = int.Parse(Console.ReadLine());

		while (t-- != 0)
		{
			string s = Console.ReadLine();
			if (IsOneLetter(s))
				Console.WriteLine("NO");
			else
			{
				Console.WriteLine("YES");
				Console.WriteLine(MountString(s));	
			}
		}
	}
}
