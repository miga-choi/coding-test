#include <stdbool.h>

bool isPowerOfFour(int n) {
    while (n > 1) {
        if (n % 4) {
            return false;
        }
        n /= 4;
    }

    return n == 1;
}

// Solution
bool solution(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
}
