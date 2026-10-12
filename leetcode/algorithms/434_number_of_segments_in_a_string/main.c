#include <stdbool.h> // bool

/**
 * Status flag
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int countSegments(char* s) {
    int count = 0;
    int begin = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            begin = 1;
        }
        if (begin && s[i] == ' ') {
            begin = 0;
            count++;
        }
    }

    return count + begin;
}


// Solution
/**
 * Solution 1
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution1(char* s) {
    int count = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            count++;
        }
    }

    return count;
}

/**
 * Solution 2
 * 
 * Status Flag
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution2(char* s) {
    int count = 0;
    bool inSeg = false;

    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') {
            inSeg = false;
        } else if (!inSeg) {
            inSeg = true;
            count++;
        }
    }

    return count;
}
