public class Solution {

    private static int Max(int a, int b)
    {
        return a > b ? a : b;
    }

    private static void FillFalse(bool[] array)
    {
        for (int i = 0; i < 255; i++)
            array[i] = false;
    }

    public int LengthOfLongestSubstring(string s) {
        bool[] isVisited = new bool[255];
        FillFalse(isVisited);
        
        int best = 0, pointerA = 0, pointerB = 0;

        while (pointerB < s.Length) {
            int pos = s[pointerB];

            if (!isVisited[pos]) {
                pointerB++;
                isVisited[pos] = true;
            }
            else {
                best = Max(best, pointerB - pointerA);
                pointerA++;
                pointerB = pointerA;
                FillFalse(isVisited);
            }
        }

        best = Max(best, pointerB - pointerA);
        return best;
    }
}