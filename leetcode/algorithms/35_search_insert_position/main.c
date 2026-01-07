/**
 * Binary Search
 * 
 * Complexities:
 *   N - numsSize
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (target > nums[mid]) {
            left = mid + 1;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return left;
}


// Solution
/**
 * Binary Search
 * 
 * Complexities:
 *   N - numsSize
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int solution(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
