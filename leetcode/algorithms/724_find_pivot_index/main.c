int sum(int* nums, int numsSize) {
    int num = 0;
    for (int i = 0; i < numsSize; i++) {
        num += nums[i];
    }
    return num;
}

int pivotIndex(int* nums, int numsSize) {
    int leftSum = 0;
    int rightSum = sum(nums, numsSize);

    for (int i = 0; i < numsSize; i++) {
        rightSum -= nums[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}


// Solution
int solution(int* nums, int numsSize) {
    // Initialize rightSum to store the sum of all the numbers
    // strictly to the index's right
    int rightSum = sum(nums, numsSize);

    // Initialize leftSum to store the sum of all the numbers
    // strictly to the index's left
    int leftSum = 0;

    // Traverse all elements through the loop
    for (int idx = 0; idx < numsSize; idx++) {
        // subtract current elements with from rightSum
        rightSum -= nums[idx];

        // If the sum of all the numbers strictly to the left
        // of the index is equal to the sum of all the numbers
        // strictly to the index's right
        if (leftSum == rightSum) {
            // Return the pivot index
            return idx;
        }

        // add current elements with leftSum
        leftSum += nums[idx];
    }

    // If there is no index that satisfies the conditions
    // in the problem statement
    return -1;
}
