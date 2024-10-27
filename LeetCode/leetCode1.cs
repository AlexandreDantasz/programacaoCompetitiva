public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> map = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            int x = nums[i];
            if (map.ContainsKey(x)) {
                int[] res = [map[x], i];
                return res;
            }
            else {
                if (!map.ContainsKey(target - x)) 
                    map.Add(target - x, i);
            }
        }

        return null;
    }
}