using System;

class Program
{
    private static readonly Random rand = new Random();
    
    private static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    private static int Partition(int[] array, int begin, int end)
    {
        // Escolhendo um número aleatório no intervalo [begin, end]
        // Outra opção seria: rand.Next() % (end - begin + 1) + begin
        int indexPivo = rand.Next(begin, end + 1); 
        int pivo = array[indexPivo], i = begin;

        // Trocando o pivô com o valor da posição final do array
        Swap(ref array[indexPivo], ref array[end]);

        for (int j = begin; j < end; j++)
        {
            // Se for menor que o pivô, precisa ir para a esquerda
            if (pivo > array[j])
            {
                (array[i], array[j]) = (array[j], array[i]);  
                i++;
            }
        }
        
        Swap(ref array[end], ref array[i]);
        return i++;
    }

    private static void Quicksort(int[] array, int begin, int end)
    {
        if (begin < end)
        {
            int middle = Partition(array, begin, end);
            Quicksort(array, begin, middle - 1);
            Quicksort(array, middle + 1, end);
        }
    }

    public static void Main(string[] args)
    {
        int[] array = new int[3] { 4, 3, 5 };

        // Ordena o vetor em ordem crescente
        Quicksort(array, 0, 2);

        foreach (var a in array)
        {
            Console.WriteLine(a);
        }
    }
}
