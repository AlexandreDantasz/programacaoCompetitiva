public class Solution {
    public int MaximumLengthSubstring(string str) {
        SortedDictionary<char, int> myMap = new SortedDictionary<char, int>();
        int end = 0, start = 0, resp = 0;
        while (end < str.Length) {
            if (myMap.ContainsKey(str[end])) { // contains the letter
                if (myMap[str[end]] < 2) {
                    myMap[str[end]]++;
                    end++;
                }
                else {
                    resp = (end - start) > resp ? (end - start) : resp;
                    myMap[str[start]]--;
                    start++;
                }
            }
            else {
                myMap.Add(str[end], 1);
                end++;
            }
        }
        resp = (end - start) > resp ? (end - start) : resp;
        return resp;
    }
}
