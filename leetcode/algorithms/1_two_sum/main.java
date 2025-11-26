import java.util.HashMap;
import java.util.Map;

class TwoSum {
    /**
     * Brute-Force
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    public int[] twoSum1(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] { i, j };
                }
            }
        }

        return new int[] {};
    }

    /**
     * Hash Map
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public int[] twoSum2(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { i, map.get(complement) };
            }
            map.put(nums[i], i);
        }

        return new int[] {};
    }


    // Solution
    /**
     * One-Pass Hash Table)
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public int[] solution(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }

            map.put(nums[i], i);
        }

        throw new IllegalArgumentException("No two sum solution");
    }
}
