import 'dart:math';

class MaximumAverageSubarrayI {
  double findMaxAverage(List<int> nums, int k) {
    double currSum = 0, maxSum = 0;

    for (int i = 0; i < k; i++) {
      currSum += nums[i];
    }
    maxSum = currSum;

    for (int i = k; i < nums.length; i++) {
      currSum += nums[i] - nums[i - k];
      maxSum = max(currSum, maxSum);
    }

    return maxSum / k;
  }
}
