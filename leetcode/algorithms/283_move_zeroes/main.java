class MoveZeroes {
    /**
     * Complexities:
     *   N - The size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public void moveZeroes(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = 1; j < nums.length - i; j++) {
                if (nums[j - 1] == 0) {
                    int temp = nums[j - 1];
                    nums[j - 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }


    // Solution
    /**
     * Solution 1
     *
     * Two Pointers Swap
     *
     * Complexities:
     *   N - The size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public void solution1(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return;
        }

        int lastNonZeroFoundAt = 0;

        for (int cur = 0; cur < nums.length; cur++) {
            if (nums[cur] != 0) {
                if (cur != lastNonZeroFoundAt) {
                    int temp = nums[lastNonZeroFoundAt];
                    nums[lastNonZeroFoundAt] = nums[cur];
                    nums[cur] = temp;
                }

                lastNonZeroFoundAt++;
            }
        }
    }

    /**
     * Solution 2
     *
     * Overwrite & Fill
     *
     * Complexities:
     *   N - The size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public void solution2(int[] nums) {
        int insertPos = 0;

        for (int num : nums) {
            if (num != 0) {
                nums[insertPos++] = num;
            }
        }

        while (insertPos < nums.length) {
            nums[insertPos++] = 0;
        }
    }
}
