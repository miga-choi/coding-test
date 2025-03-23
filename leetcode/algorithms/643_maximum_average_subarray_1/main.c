double findMaxAverage(int* nums, int numsSize, int k) {
    double currSum = 0, maxSum = 0;

    for (int i = 0; i < k; i++) {
        currSum += nums[i];
    }
    maxSum = currSum;

    for (int i = k; i < numsSize; i++) {
        currSum += nums[i] - nums[i - k];
        if (currSum > maxSum) {
            maxSum = currSum;
        }
    }

    return maxSum / k;
}
