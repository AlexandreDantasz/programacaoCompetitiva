public class MyTuples {
    public int Item1, Item2;
}

public class Solution {
    static int binarySearch(int key, MyTuples [] arr, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            if (key >= arr[mid].Item1 && key <= arr[mid].Item2) return mid;
            else if (key > arr[mid].Item2) return binarySearch(key, arr, mid + 1, high);
            return binarySearch(key, arr, low, mid - 1);
        }
        return low;
    }
    static void Main(string[] args)
    {
        // data structure: arr[resp] = (a, b)
        int n = int.Parse(Console.ReadLine());
        MyTuples [] arr = new MyTuples[n + 1];
        string line = Console.ReadLine();
        string [] worms = line.Split(" ");
        int begin = 1, end = int.Parse(worms[0]);
        arr[1] = new MyTuples();
        arr[1].Item1 = begin;
        arr[1].Item2 = end;
        begin = end + 1;
        for (int i = 2; i <= n; i++) {
            end += int.Parse(worms[i - 1]);
            arr[i] = new MyTuples();
            arr[i].Item1 = begin;
            arr[i].Item2 = end;
            begin = end + 1;
        }
        int q = int.Parse(Console.ReadLine());
        line = Console.ReadLine();
        worms = line.Split(" ");
        foreach (var i in worms) Console.WriteLine(binarySearch(int.Parse(i), arr, 1, n));
    }
}