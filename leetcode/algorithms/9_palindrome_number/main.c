#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long origin = (long)x;
    long sum = 0;

    while (x > 0) {
        long res = (long)x % 10;
        x /= 10;
        sum = sum * 10 + res;
    }

    return sum == origin;
}


// Solution
bool solution(int x) {
    if (x < 0 || x != 0 && x % 10 == 0) {
        return false;
    }
    int check = 0;
    while (x > check) {
        check = check * 10 + x % 10;
        x /= 10;
    }
    return (x == check || x == check / 10);
}
