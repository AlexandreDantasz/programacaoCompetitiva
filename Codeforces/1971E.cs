using System;

class Program
{
    public static void Main(string[] args)
    {
        int t = int.Parse(Console.ReadLine());

        while (t-- != 0)
        {
            string[] line = Console.ReadLine().Split(' ');
            int n = int.Parse(line[0]);
            int k = int.Parse(line[1]);
            int q = int.Parse(line[2]);

            long[] signs = new long[k + 1], minutes = new long[k + 1];

            signs[0] = 0;
            minutes[0] = 0;

            line = Console.ReadLine().Split(' ');
            for (int i = 1; i <= k; i++)
                signs[i] = long.Parse(line[i - 1]);

            line = Console.ReadLine().Split(' ');
            for (int i = 1; i <= k; i++)
                minutes[i] = long.Parse(line[i - 1]); 
            
            while (q-- != 0)
            {
                long d = long.Parse(Console.ReadLine());
                int left = 0, right = k;

                while (left <= right)
                {
                    int mid = left + (right - left) / 2;

                    if (signs[mid] > d)
                        right = mid - 1;
                    else 
                        left = mid + 1;
                }

                if (signs[right] == d)
                    Console.Write(minutes[right] + " ");
                else 
                {
                    // using linear interpolation
                    long res = minutes[right] + ((d - signs[right]) * (minutes[right + 1] - minutes[right])) / (signs[right + 1] - signs[right]);
                    Console.Write(res + " ");
                }

            }

            Console.WriteLine();
        }
    }
}