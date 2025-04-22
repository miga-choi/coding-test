#include <stdbool.h>

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
// Solution 1
int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool solution1(int n) {
    int slow, fast;
    slow = fast = n;

    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while (slow != fast);

    if (slow == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Solution 2
bool solution2(int n) {
    int total = 0;

    while (true) {
        while (n > 0) {
            total += (n % 10) * (n % 10);
            n /= 10;
        }
        if (total == 1) {
            return true;
        } else if (total == 4) {
            return false;
        }
        n = total;
        total = 0;
    }
}
