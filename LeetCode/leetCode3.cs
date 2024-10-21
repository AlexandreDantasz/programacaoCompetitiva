public class Solution {

    /*
        To solve this problem, I used sliding window technique!
        slinding window info: https://www.geeksforgeeks.org/window-sliding-technique/
    */

    private static int Max(int a, int b)
    {
        return a > b ? a : b;
    }

    public int LengthOfLongestSubstring(string s) {
        
        HashSet<char> charSet = new HashSet<char>();
        
        int best = 0, pointerA = 0, pointerB = 0;

        while (pointerB < s.Length) {
            if (!charSet.Contains(s[pointerB])) {
                charSet.Add(s[pointerB]);
                pointerB++;
                best = Max(best, charSet.Count);
            }
            else {
                while (s[pointerA] != s[pointerB]) {
                    charSet.Remove(s[pointerA++]);
                }

                charSet.Remove(s[pointerA++]);
            }
        }

        best = Max(best, charSet.Count);

        return best;
    }
}