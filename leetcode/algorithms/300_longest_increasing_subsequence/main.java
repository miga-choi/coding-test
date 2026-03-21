import java.util.Arrays;

class LongestIncreasingSubsequence {
    /**
     * DP
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N)
     */
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);

        int result = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }

            }

            result = Math.max(result, dp[i]);
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * DP
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N)
     */
    public int solution1(int[] nums) {
        int[] dp = new int[nums.length];
        int maxLength = 1;

        for (int i = 0; i < nums.length; i++) {
            dp[i] = 1;

            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }

            maxLength = Math.max(maxLength, dp[i]);
        }

        return maxLength;
    }

    /**
     * Solution 2
     *
     * Binary Search
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(N)
     */
    public int solution2(int[] nums) {
        int[] tails = new int[nums.length];
        int size = 0;

        for (int x : nums) {
            int left = 0;
            int right = size;

            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tails[mid] < x) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            tails[left] = x;

            if (left == size) {
                size++;
            }
        }

        return size;
    }
}
