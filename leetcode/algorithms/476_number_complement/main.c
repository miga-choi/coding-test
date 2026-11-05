#include <limits.h> // UINT_MAX

/**
 * Double Bit Reversal + Trailing Zero Restoration
 * 
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int findComplement(int num) {
    int startsWithZeroCount = 0;
    int zeroCountDone = 0;

    int reverseNum = 0;
    while (num > 0) {
        if (!zeroCountDone) {
            if (num & 1) {
                startsWithZeroCount++;
            } else {
                zeroCountDone = 1;
            }
        }

        reverseNum = (reverseNum << 1) | (num & 1 ^ 1);
        num >>= 1;
    }

    int result = 0;
    while (reverseNum > 0) {
        result = (result << 1) | (reverseNum & 1);
        reverseNum >>= 1;
    }

    return result << startsWithZeroCount;
}


// Solution
/**
 * Solution 1
 * 
 * Bit-by-bit Flip
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution1(int num) {
    unsigned int n = (unsigned int)num;
    unsigned int res = 0;
    int pos = 0;

    while (n != 0) {
        unsigned int bit = (n & 1) ^ 1;
        res |= bit << pos;
        n >>= 1;
        pos++;
    }

    return (int)res;
}

/**
 * Solution 2
 * 
 * Bit Mask Construction + XOR
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution2(int num) {
    unsigned int mask = 1;

    while (mask < (unsigned int)num) {
        mask = (mask << 1) | 1;
    }

    return (int)(mask ^ (unsigned int)num);
}

/**
 * Solution 3
 * 
 * Bit Smearing + XOR
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution3(int num) {
    unsigned int n = (unsigned int)num;
    unsigned int mask = n;

    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;

    return (int)(mask ^ n);
}

/**
 * Solution 4
 * 
 * Leading Zero Count (Built-in) + XOR
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution4(int num) {
    unsigned int n = (unsigned int)num;
    unsigned int mask = UINT_MAX >> __builtin_clz(n);

    return (int)(mask ^ n);
}