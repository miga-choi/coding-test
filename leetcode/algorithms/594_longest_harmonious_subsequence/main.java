import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int LongestHarmoniousSubsequence(int[] nums) {
        int result = 0;
        Map<Integer, Integer> numsMap = new HashMap<Integer, Integer>();

        for (int num : nums) {
            numsMap.put(num, numsMap.get(num) == null ? 1 : numsMap.get(num) + 1);
        }

        if (numsMap.size() > 1) {
            for (int k : numsMap.keySet()) {
                if (numsMap.get(k - 1) != null) {
                    result = Math.max(result, numsMap.get(k) + numsMap.get(k - 1));
                }
                if (numsMap.get(k + 1) != null) {
                    result = Math.max(result, numsMap.get(k) + numsMap.get(k + 1));
                }
            }
        }

        return result;
    }


    // Best Solution
    // Best Solution 1: Hash table / Hash map
    public int bestSolution1(int[] nums) {
        Map<Long, Integer> map = new HashMap<>();
        for (long num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int result = 0;
        for (long key : map.keySet()) {
            if (map.containsKey(key + 1)) {
                result = Math.max(result, map.get(key + 1) + map.get(key));
            }
        }
        return result;
    }

    // Best Solution 2: Sorting
    public int bestSolution2(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        Arrays.sort(nums);
        int left = 0, right = 1;
        int ArrayLen = 0;
        while (right < nums.length) {
            int diff = nums[right] - nums[left];
            if (diff == 1) {
                ArrayLen = Math.max(ArrayLen, right - left + 1);
            }
            if (diff <= 1) {
                right++;
            } else {
                left++;
            }
        }
        return ArrayLen;
    }
}
