#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;

    while (i < bitsSize - 1) {
        if (bits[i] == 1) {
            i += 2;
        } else {
            i += 1;
        }
    }

    return i == bitsSize - 1;
}


// Solution
// Solution 1: Increment Pointer
bool solution1(int* bits, int bitsSize) {
    int i = 0;

    while (i < bitsSize - 1) {
        i += bits[i] + 1;
    }

    return i == bitsSize - 1;
}

// Solution 2: Greedy
bool solution2(int* bits, int bitsSize) {
    int i = bitsSize - 2;

    while (i >= 0 && bits[i] > 0) {
        i--;
    }

    return (bitsSize - i) % 2 == 0;
}
