#include <math.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) {
        return -1;
    }
    if (arg1 > arg2) {
        return 1;
    }
    return 0;
}

int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare_ints);

    int max = 0, leftPin = 0, rightPin = 1;

    while (rightPin < numsSize) {
        int diff = nums[rightPin] - nums[leftPin];
        if (diff == 1) {
            if (rightPin - leftPin + 1 > max) {
                max = rightPin - leftPin + 1;
            }
            rightPin++;
        } else if (diff == 0) {
            rightPin++;
        } else {
            leftPin++;
        }
    }

    return max;
}

// Solution: Sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int solution(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int res = 0, l = 0, r = 1;

    while (r < numsSize) {
        int diff = nums[r] - nums[l];
        if (diff == 1) {
            res = fmax(res, r - l + 1);
            r++;
        } else if (diff < 1) {
            r++;
        } else {
            l++;
        }
    }

    return res;
}
