using System;
using System.Collections.Generic;

class Codeforces
{
    private static bool Solution(int s, List<Tuple<int, int>> intervals, int m)
    {
        int index_a = 0;

        foreach (var pair in intervals)
        {
            if (pair.Item1 - index_a >= s)
                return true;

            index_a = pair.Item2;
        }

        if (m - index_a >= s)
            return true;

        return false;
    }
    public static void Main(string[] args)
    {
        int t = int.Parse(Console.ReadLine());

        while (t-- != 0)
        {
            string[] line = Console.ReadLine().Split(' ');
            int n = int.Parse(line[0]), s = int.Parse(line[1]), m = int.Parse(line[2]);

            List<Tuple<int, int>> intervals = new List<Tuple<int, int>>();
            
            for (int i = 0; i < n; i++)
            {
                string[] newLine = Console.ReadLine().Split(' ');
                Tuple<int, int> interval = Tuple.Create(int.Parse(newLine[0]), int.Parse(newLine[1]));
                intervals.Add(interval);
            }

            string res = (Solution(s, intervals, m) ? "YES" : "NO");
            Console.WriteLine(res);

        }
    }
}