#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }

    while (n / 2) {
        if (n > 1 && (n % 2)) {
            return false;
        }
        n /= 2;
    }

    return true;
}


// Solution
bool solution(int n) {
    return n > 0 && !(n & n - 1);
}
