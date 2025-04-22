#include <stdbool.h>

bool isUgly(int n) {
    while (n > 0) {
        if (n % 5 == 0) {
            n /= 5;
        } else if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            if (n == 0 || n == 1 || n == 2 || n == 3 || n == 5) {
                return true;
            } else {
                break;
            }
        }
    }
    return false;
}


// Solution
bool solution(int n) {
    for (int i = 2; i < 6 && n; i++) {
        while (n % i == 0) {
            n /= i;
        }
    }
    return n == 1;
}
