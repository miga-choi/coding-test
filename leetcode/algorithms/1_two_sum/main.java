import java.util.HashMap;
import java.util.Map;

class TwoSum {
    /**
     * Brute-Force
     * - Time Complexity: O(N²)
     * - Space Complexity: O(1)
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
     * HashMap
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    public int[] twoSum(int[] nums, int target) {
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
    // Solution 1: Brute Force
    public int[] solution1(int[] nums, int target) {
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] { i, j };
                }
            }
        }
        return new int[] {}; // No solution found
    }

    // Solution 2: Two-pass Hash Table
    public int[] solution2(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        int n = nums.length;

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap.put(nums[i], i);
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement) && numMap.get(complement) != i) {
                return new int[] { i, numMap.get(complement) };
            }
        }

        return new int[] {}; // No solution found
    }

    // Solution 3: One-pass Hash Table
    public int[] solution3(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement)) {
                return new int[] { numMap.get(complement), i };
            }
            numMap.put(nums[i], i);
        }

        return new int[] {}; // No solution found
    }
}
