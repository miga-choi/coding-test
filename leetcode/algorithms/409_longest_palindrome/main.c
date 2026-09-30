#include <stdbool.h> // bool

/**
 * Counting Array
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int longestPalindrome(char* s) {
    int alphabetNumArray[52] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < 97) {
            alphabetNumArray[s[i] - 'A']++;
        } else {
            alphabetNumArray[s[i] - 'a' + 26]++;
        }
    }

    int haveSingle = 0;
    int result = 0;
    for (int i = 0; i < 52; i++) {
        if (alphabetNumArray[i] % 2 > 0) {
            haveSingle = 1;
        }
        result += alphabetNumArray[i] / 2;
    }

    return result * 2 + haveSingle;
}


// Solution
/**
 * Solution 1
 * 
 * Counting Array
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution1(char* s) {
    int cnt[128] = {0};

    for (int i = 0; s[i]; i++) {
        cnt[(unsigned char)s[i]]++;
    }

    int len = 0, hasOdd = 0;
    for (int c = 0; c < 128; c++) {
        len += cnt[c] / 2 * 2;

        if (cnt[c] % 2 == 1) {
            hasOdd = 1;
        }
    }

    return len + hasOdd;
}

/**
 * Solution 2
 * 
 * Count The Odd Numbers
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution2(char* s) {
    bool odd[128] = {false};
    int oddCnt = 0, n = 0;

    for (; s[n]; n++) {
        unsigned char c = (unsigned char)s[n];
        odd[c] = !odd[c];
        oddCnt += odd[c] ? 1 : -1;
    }

    return oddCnt > 0 ? n - oddCnt + 1 : n;
}

/**
 * Solution 3
 * 
 * 64-bit Mask
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution3(char* s) {
    unsigned long long mask = 0;
    int n = 0;

    for (; s[n]; n++) {
        mask ^= 1ULL << (s[n] - 'A');
    }

    int oddCnt = 0;
    while (mask) {
        mask &= mask - 1;
        oddCnt++;
    }

    return oddCnt > 0 ? n - oddCnt + 1 : n;
}
