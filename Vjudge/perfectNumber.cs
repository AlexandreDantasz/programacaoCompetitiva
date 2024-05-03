int [] perfect = new int [10001];
perfect[1] = 19;
for (int i = 2; i <= 10000; i++) perfect[i] = perfect[i - 1] + 9;
int pos = int.Parse(Console.ReadLine());
Console.WriteLine(perfect[pos]);