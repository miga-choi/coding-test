#include <stdlib.h>

/**
 * Sorting + Two Pointers
 * 
 * Complexities:
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
int compare(const void* prev, const void* next) {
    return (*(int*)prev - *(int*)next);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);

    int sum = nums[0] + nums[1] + nums[2];

    for (int flag = 0; flag < numsSize - 2; flag++) {
        int left = flag + 1;
        int right = numsSize - 1;

        while (left < right) {
            int currSum = nums[flag] + nums[left] + nums[right];

            if (abs(currSum - target) < abs(sum - target)) {
                sum = currSum;
            }

            if (currSum < target) {
                left++;
            } else if (currSum > target) {
                right--;
            } else {
                return currSum;
            }
        }
    }

    return sum;
}


// Solution
/**
 * Sorting + Two Pointers
 * 
 * Complexities:
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int solution(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            if (abs(target - currentSum) < abs(target - closestSum)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return currentSum;
            }
        }
    }

    return closestSum;
}
