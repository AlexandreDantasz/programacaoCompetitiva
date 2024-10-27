using System;

public class Solution
{

	private static int Max(int a, int b)
	{
		return a > b ? a : b;
	}

	public string LongestPalindrome(string s)
	{
		int pointerA, pointerB, bestRes = 0;
		string res = string.Empty;

		if (s.Length <= 1)
			return s;

		if (s.Length == 2 && s[0] == s[1])
			return s;

		for (int i = 0; i < s.Length; i++)
		{
			pointerA = i;
		       	pointerB = i;

			// Funciona para números ímpares.

			while (pointerA >= 0 && pointerB < s.Length && s[pointerA] == s[pointerB])
			{

				if (pointerB - pointerA + 1 > bestRes)
				{
					bestRes = pointerB - pointerA + 1;
					res = s.Substring(pointerA, bestRes);
				}

				pointerA--;
				pointerB++;
				
			}

			// Funciona para números pares.
		
			pointerA = i;
			pointerB = i + 1;

			while (pointerA >= 0 && pointerB < s.Length && s[pointerA] == s[pointerB])
			{

				if (pointerB - pointerA + 1 > bestRes)
			       	{
					bestRes = pointerB - pointerA + 1;
					res = s.Substring(pointerA, bestRes);
				}

				pointerA--;
				pointerB++;

			}

		}

		return res;
	}

}
