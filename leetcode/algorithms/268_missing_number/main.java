import java.util.Arrays;

class MissingNumber {
    /**
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return nums.length;
    }


    // Solution
    /**
     * Solution 1
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution1(int[] nums) {
        int n = nums.length;
        
        int expectedSum = n * (n + 1) / 2;
        
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }

    /**
     * Solution 2
     *
     * XOR
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution2(int[] nums) {
        int n = nums.length;

        int xor = n;

        for (int i = 0; i < n; i++) {
            xor ^= i ^ nums[i];
        }

        return xor;
    }
}
