/**
 * Binary Search
 * 
 * Complexities:
 *   N - Value of `x` 
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }

    long low = 1;
    long high = x;

    while (low <= high) {
        long mid = (low + high) / 2;

        if (mid == x / mid) {
            return (int)mid;
        } else if (mid > x / mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)high;
}


// Solution
/**
 * Solution 1
 * 
 * Binary Search
 * 
 * Complexities:
 *   N - Value of `x` 
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int solution1(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int left = 1;
    int right = x;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

/**
 * Solution 2
 * 
 * Newton-Raphson Method
 * 
 * Complexities:
 *   N - Value of `x` 
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int solution2(int x) {
    if (x == 0) {
        return 0;
    }

    long long r = x;
    
    while (r * r > x) {
        r = (r + x / r) / 2;
    }

    return (int)r;
}
