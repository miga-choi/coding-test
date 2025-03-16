#include <limits.h>
#include <math.h>

int maximumProduct(int* nums, int numsSize) {
    int max1 = -1000, max2 = -1000, max3 = -1000;
    int min1 = 1000, min2 = 1000;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        } else if (nums[i] > max3) {
            max3 = nums[i];
        }

        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] < min2) {
            min2 = nums[i];
        }
    }

    return max1 * max2 * max3 > min1 * min2 * max1 ? 
            max1 * max2 * max3 : 
            min1 * min2 * max1;
}

// Solution
int maximumProduct(int* nums, int numsSize) {
    int first_max = INT_MIN;
    int second_max = first_max;
    int third_max = first_max;

    int first_min = INT_MAX;
    int second_min = first_min;

    for (int i = 0; i < numsSize; i++) {
        // Calculating first_max, second_max, and third_max
        if (first_max <= nums[i]) {
            third_max = second_max;
            second_max = first_max;
            first_max = nums[i];
        } else if (second_max <= nums[i]) {
            third_max = second_max;
            second_max = nums[i];
        } else if (third_max <= nums[i])
            third_max = nums[i];

        // Calculating the first_min, second_min
        if (first_min >= nums[i]) {
            second_min = first_min;
            first_min = nums[i];
        } else if (second_min >= nums[i])
            second_min = nums[i];
    }

    int maxi = fmax(first_max * second_max * third_max, 
        first_min * second_min * first_max);

    return maxi;
}
