#include <stdbool.h>
#include <limits.h>

bool find132pattern(int* nums, int numsSize) {

}


// Solution
bool solution(int* nums, int numsSize) {
    int peak = numsSize, min = INT_MIN;

    for (int i = numsSize - 1; i > -1; i--) {
        if (nums[i] < min) {
            return true;
        }
        while (peak < numsSize && nums[i] > nums[peak]) {
            min = nums[peak];
            peak++;
        }
        peak--;
        nums[peak] = nums[i];
    }

    return false;
}
