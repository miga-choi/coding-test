import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

class DegreeOfAnArray {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> numsCountMap = new HashMap<Integer, Integer>();
        Map<Integer, Integer> numsFirstIndexMap = new HashMap<Integer, Integer>();
        int maxCount = 0;
        int minSubarrayLength = nums.length;

        for (int i = 0; i < nums.length; i++) {
            if (numsCountMap.get(nums[i]) == null) {
                numsCountMap.put(nums[i], 0);
                numsFirstIndexMap.put(nums[i], i);
            }

            int count = numsCountMap.get(nums[i]) + 1;
            numsCountMap.put(nums[i], count);
            if (count > maxCount) {
                maxCount = count;
                minSubarrayLength = i - numsFirstIndexMap.get(nums[i]) + 1;
            } else if (count == maxCount) {
                int subarrayLength = i - numsFirstIndexMap.get(nums[i]) + 1;
                if (subarrayLength < minSubarrayLength) {
                    minSubarrayLength = subarrayLength;
                }
            }
        }

        return minSubarrayLength;
    }


    // Solution: Left and Right Index
    public int solution1(int[] nums) {
        Map<Integer, Integer> left = new HashMap<Integer, Integer>();
        Map<Integer, Integer> right = new HashMap<Integer, Integer>();
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            if (left.get(x) == null) {
                left.put(x, i);
            }
            right.put(x, i);
            count.put(x, count.getOrDefault(x, 0) + 1);
        }

        int ans = nums.length;
        int degree = Collections.max(count.values());
        for (int x : count.keySet()) {
            if (count.get(x) == degree) {
                ans = Math.min(ans, right.get(x) - left.get(x) + 1);
            }
        }

        return ans;
    }
}
