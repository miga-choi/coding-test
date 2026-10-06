#include <limits.h> // LLONG_MIN
#include <stddef.h> // NULL
#include <stdlib.h> // qsort

/**
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int thirdMax(int* nums, int numsSize) {
    int first = nums[0];
    int second = INT_MIN;
    int initSecond = 0;
    int third = INT_MIN;
    int initThird = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= first) {
            if (nums[i] == first) {
                continue;
            }
            if (!initSecond) {
                second = first;
                first = nums[i];
                initSecond = 1;
            } else {
                third = second;
                second = first;
                first = nums[i];
                initThird = 1;
            }
        } else if (nums[i] >= second) {
            if (!initSecond) {
                second = nums[i];
                initSecond = 1;
            } else {
                if (nums[i] == second) {
                    continue;
                }
                third = second;
                second = nums[i];
                initThird = 1;
            }
        } else if (nums[i] >= third) {
            third = nums[i];
            initThird = 1;
        }
    }

    if (!initThird) {
        return first;
    }

    return third;
}


// Solution
/**
 * Solution 1
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution1(int* nums, int numsSize) {
    long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        long long x = nums[i];

        if (x == first || x == second || x == third) {
            continue;
        }

        if (x > first) {
            third = second;
            second = first;
            first = x;
        } else if (x > second) {
            third = second;
            second = x;
        } else if (x > third) {
            third = x;
        }
    }

    return third == LLONG_MIN ? (int)first : (int)third;
}

/**
 * Solution 2
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution2(int* nums, int numsSize) {
    int *a = NULL, *b = NULL, *c = NULL;

    for (int i = 0; i < numsSize; i++) {
        int* p = &nums[i];

        if ((a && *p == *a) || (b && *p == *b) || (c && *p == *c)) {
            continue;
        }

        if (!a || *p > *a) {
          c = b;
          b = a;
          a = p;
        } else if (!b || *p > *b) {
          c = b;
          b = p;
        } else if (!c || *p > *c) {
          c = p;
        }
    }

    return c ? *c : *a;
}

/**
 * Solution 3
 * 
 * Sorting
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(1)
 */
static int cmpDesc(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x < y) - (x > y);
}

int solution3(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpDesc);

    int distinct = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1] && ++distinct == 3) {
            return nums[i];
        }
    }

    return nums[0];
}
