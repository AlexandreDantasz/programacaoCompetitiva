using System;
using System.Collections.Generic;

class URI
{
    static int Max(int a, int b)
    {
        return a > b ? a : b;
    }

    static int Solution(int[,] pd, int index, List<Tuple<int, int>> list, int l)
    {
        if (index < 0)
            return 0;

        if (pd[index, l] != -1)
            return pd[index, l];

        if (list[index].Item2 > l)
        {
            pd[index, l] = Solution(pd, index - 1, list, l);
            return pd[index, l];
        }

        pd[index, l] = Max(list[index].Item1 + Solution(pd, index - 1, list, l - list[index].Item2), Solution(pd, index - 1, list, l));
        return pd[index, l];
    }

    static void Main(string[] args)
    {
        int t = int.Parse(Console.ReadLine());

        while (t-- != 0)
        {
            int n = int.Parse(Console.ReadLine());

            List<Tuple<int, int>> list = new List<Tuple<int, int>>();
            for (int i = 0; i < n; i++)
            {
                string[] line = Console.ReadLine().Split(' ');
                list.Add(new Tuple<int, int>(int.Parse(line[0]), int.Parse(line[1])));
            }

            int l = int.Parse(Console.ReadLine()), r = int.Parse(Console.ReadLine());

            int[,] pd = new int[n + 1, l + 1];

            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= l; j++)
                    pd[i, j] = -1;

            if (Solution(pd, n - 1, list, l) >= r)
                Console.WriteLine("Missao completada com sucesso");
            else
                Console.WriteLine("Falha na missao");

        }

    }

}