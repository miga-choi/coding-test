#include <stdbool.h>

bool hasAlternatingBits(int n) {
    int prev = -1;

    while (n > 0) {
        if (n % 2 == prev) {
            return false;
        }
        prev = n % 2;
        n /= 2;
    }

    return true;
}


// Solution
bool solution(int n) {
    int d = n & 1;

    while ((n & 1) == d) {
        d = 1 - d;
        n >>= 1;
    }

    return n == 0;
}
