class HouseRobber {
    /**
     * DP
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int rob(int[] nums) {
        int prev1 = 0;
        int prev2 = 0;

        for (int num : nums) {
            int max = Math.max(prev1, prev2 + num);

            prev2 = prev1;
            prev1 = max;
        }

        return prev1;
    }


    // Solution
    /**
     * DP
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution(int[] nums) {
        int prev1 = 0;
        int prev2 = 0;

        for (int num : nums) {
            int currentMax = Math.max(prev1, prev2 + num);

            prev2 = prev1;
            prev1 = currentMax;
        }

        return prev1;
    }
}
