/**
 * Single Pass + Running Count
 * 
 * Complexities:
 *   n - `numsSize`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0;
    int current = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            current++;
            if (current > max) {
                max = current;
            }
        } else {
            current = 0;
        }
    }

    return max;
}


// Solution
/**
 * Solution 1
 * 
 * Single Pass + Running Count
 * 
 * Complexities:
 *   n - `numsSize`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
int solution1(int* nums, int numsSize) {
    int cur = 0, best = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            cur++;
            if (cur > best) {
                best = cur;
            }
        } else {
            cur = 0;
        }
    }

    return best;
}

/**
 * Solution 2
 * 
 * Single Pass + Last Zero Index
 * 
 * Complexities:
 *   n - `numsSize`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
int solution2(int* nums, int numsSize) {
    int lastZero = -1, best = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            lastZero = i;
        } else if (i - lastZero > best) {
            best = i - lastZero;
        }
    }

    return best;
}

/**
 * Solution 3
 * 
 * Single Pass + Last Zero Index
 * 
 * Complexities:
 *   n - `numsSize`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
int solution3(int* nums, int numsSize) {
    int cur = 0, best = 0;

    for (int i = 0; i < numsSize; i++) {
        cur = (cur + 1) * nums[i];
        best = cur > best ? cur : best;
    }

    return best;
}
