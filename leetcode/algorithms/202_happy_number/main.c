#include <stdbool.h>

/**
 * Floyd's Cycle-Finding Algorithm
 * 
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int sum(int n) {
    int sum = 0;

    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    int fast = n;
    int slow = n;

    while (true) {
        slow = sum(slow);
        fast = sum(fast);
        fast = sum(fast);
        if (fast == 1) {
            break;
        }
        if (slow == fast) {
            return false;
        }
    }

    return true;
}


// Solution
/**
 * Floyd's Cycle-Finding Algorithm
 * 
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int getNext(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);

    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }

    return fast == 1;
}
