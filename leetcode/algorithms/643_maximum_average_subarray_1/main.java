class MaximumAverageSubarrayI {
    public double findMaxAverage(int[] nums, int k) {
        double currSum = 0, maxSum = 0;

        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        maxSum = currSum;

        for (int i = k; i < nums.length; i++) {
            currSum += nums[i] - nums[i - k];
            maxSum = Math.max(currSum, maxSum);
        }

        return maxSum / k;
    }

    // Solution
    public double solution(int[] nums, int k) {
        long sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        long max = sum;

        for (int i = k; i < nums.length; i++) {
            sum += nums[i] - nums[i - k];
            max = Math.max(max, sum);
        }

        return max / 1.0 / k;
    }
}
