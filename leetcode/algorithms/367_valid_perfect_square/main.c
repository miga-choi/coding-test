#include <stdbool.h>

bool isPerfectSquare(int num) {
    if (num > 1) {
        for (long i = 0; i < num; i++) {
            if (i * i == num) {
                break;
            } else if (i * i > num) {
                return false;
            }
        }
    }
    return true;
}

bool isPerfectSquare(int num) {
    long r = x;
    while (r * r > x) {
        r = (r + x / r) / 2;
    }
    return r * r == x;
}
