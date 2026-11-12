class MaxConsecutiveOnes {
    /**
     * Single Pass (Running Counter)
     *
     * Complexities:
     *   n - The Size of `nums`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    public int findMaxConsecutiveOnes(int[] nums) {
        int result = 0;
        int curr = 0;

        for (int num : nums) {
            if (num == 1) {
                curr++;
            } else {
                if (curr > result) {
                    result = curr;
                }
                curr = 0;
            }
        }

        return Math.max(result, curr);
    }


    // Solution
    /**
     * Solution 1
     *
     * Single Pass (Running Counter)
     *
     * Complexities:
     *   n - The Size of `nums`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    public int solution1(int[] nums) {
        int max = 0, current = 0;

        for (int n : nums) {
            if (n == 1) {
                max = Math.max(max, ++current);
            } else {
                current = 0;
            }
        }

        return max;
    }

    /**
     * Solution 2
     *
     * Two Pointers (Sliding Window)
     *
     * Complexities:
     *   n - The Size of `nums`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    public int solution2(int[] nums) {
        int max = 0, left = 0;

        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) {
                left = right + 1;
            } else {
                max = Math.max(max, right - left + 1);
            }
        }

        return max;
    }
}
