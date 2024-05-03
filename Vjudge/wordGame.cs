public class MyTuples {
    public List<int> players; 
    public int frequency;
    public MyTuples() {
        players = new List<int>();
        frequency = 0;
    }
}

public class Solution {
    static void Main(string[] args) {
        int testCases = int.Parse(Console.ReadLine());
        Dictionary<string, MyTuples> myMap = new Dictionary<string, MyTuples>();
        int [] score = new int[3];
        for (int l = 0; l < testCases; l++) {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < 3; i++) {
                string line = Console.ReadLine();
                string [] words = line.Split(" ");
                for (int j = 0; j < n; j++) {
                    if (myMap.ContainsKey(words[j])) {
                        myMap[words[j]].players.Add(i);
                        myMap[words[j]].frequency++;
                    }
                    else {
                        MyTuples temp = new MyTuples();
                        temp.players.Add(i);
                        temp.frequency = 1;
                        myMap.Add(words[j], temp);
                    }
                }
            }
            score[0] = 0;
            score[1] = 0;
            score[2] = 0;
            foreach (var obj in myMap) {
                if (obj.Value.frequency == 1) score[obj.Value.players[0]] += 3;
                else {
                    if (obj.Value.frequency == 2) {
                        score[obj.Value.players[0]]++;
                        score[obj.Value.players[1]]++;
                    }
                }
            }
            Console.WriteLine("{0} {1} {2}", score[0], score[1], score[2]);
            myMap.Clear();
        }
    }
}