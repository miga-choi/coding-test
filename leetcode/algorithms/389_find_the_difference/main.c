#include <string.h>

/**
 * Counting Array
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
char findTheDifference(char* s, char* t) {
    int alphabetNumArray[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        alphabetNumArray[s[i] - 'a']++;
    }

    for (int i = 0; t[i] != '\0'; i++) {
        if (alphabetNumArray[t[i] - 'a'] == 0) {
            return t[i];
        } else {
            alphabetNumArray[t[i] - 'a']--;
        }
    }

    return ' ';
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
char solution1(char* s, char* t) {
    int cnt[26] = {0};

    for (int i = 0; s[i]; i++) {
        cnt[s[i] - 'a']++;
    }

    for (int i = 0; t[i]; i++) {
        if (--cnt[t[i] - 'a'] < 0) {
            return t[i];
        }
    }

    return 0;
}

/**
 * Solution 2
 * 
 * XOR
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
char solution2(char* s, char* t) {
    char x = 0;

    for (int i = 0; s[i]; i++) {
        x ^= s[i];
    }
    for (int i = 0; t[i]; i++) {
        x ^= t[i];
    }

    return x;
}

/**
 * Solution 3
 * 
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
char solution3(char* s, char* t) {
    int sum = 0;

    for (int i = 0; s[i]; i++) {
        sum -= s[i];
    }
    for (int i = 0; t[i]; i++) {
        sum += t[i];
    }

    return (char)sum;
}
