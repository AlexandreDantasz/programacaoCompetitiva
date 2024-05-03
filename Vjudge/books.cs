int n, t; // t -> time | n -> number of books
int i, j;
string line = Console.ReadLine();
string[] numbers = line.Split(" ");
n = int.Parse(numbers[0]);
t = int.Parse(numbers[1]);
line = Console.ReadLine();
numbers = line.Split(" ");
int resp = 0, sum = 0;
int [] timeforBooks = new int[n];
for (i = 0; i < n; i++) timeforBooks[i] = int.Parse(numbers[i]);
// two pointers
i = 0;
j = 1;
int cont = 0;
// searching the first book possible
while (i < n && resp == 0) {
    if ((sum = timeforBooks[i]) <= t) {
        resp = 1;
        cont = 1;
    }
    else {
        i++;
        j++;
    }
}
while (j < n) {
    sum += timeforBooks[j];
    if (sum <= t) cont++;
    else 
    {
        sum -= timeforBooks[i];
        i++;
    }
    j++;
    resp = resp < cont ? cont : resp;
}
Console.WriteLine(resp);
