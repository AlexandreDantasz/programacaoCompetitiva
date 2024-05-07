public class Solution {
    public int MaximumLengthSubstring(string str) {
        SortedDictionary<char, int> myMap = new SortedDictionary<char, int>();
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
