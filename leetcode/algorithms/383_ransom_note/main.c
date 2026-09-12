#include <stdbool.h> // bool
#include <string.h>  // strlen

/**
 * Counting Array
 * 
 * Complexities:
 *   N - The Size of `ransomNote`
 *   M - The Size of `magazine`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
bool canConstruct(char* ransomNote, char* magazine) {
    int alphabetMap[26] = {0};

    for (int i = 0; magazine[i] != '\0'; i++) {
        alphabetMap[magazine[i] - 'a']++;
    }

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (alphabetMap[ransomNote[i] - 'a'] > 0) {
            alphabetMap[ransomNote[i] - 'a']--;
        } else {
            return false;
        }
    }

    return true;
}


// Solution
/**
 * Solution 1
 * 
 * Counting Array
 * 
 * Complexities:
 *   N - The Size of `ransomNote`
 *   M - The Size of `magazine`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
bool solution1(char* ransomNote, char* magazine) {
    if (strlen(ransomNote) > strlen(magazine)) {
        return false;
    }

    int cnt[26] = {0};

    for (int i = 0; magazine[i]; i++) {
        cnt[magazine[i] - 'a']++;
    }

    for (int i = 0; ransomNote[i]; i++) {
        if (--cnt[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }

    return true;
}


/**
 * Solution 2
 * 
 * Complexities:
 *   N - The Size of `ransomNote`
 *   M - The Size of `magazine`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
bool solution2(char* ransomNote, char* magazine) {
    if (strlen(ransomNote) > strlen(magazine)) {
        return false;
    }

    int cnt[26] = {0};

    for (int i = 0; magazine[i]; i++) {
        cnt[magazine[i] - 'a']++;
    }
    for (int i = 0; ransomNote[i]; i++) {
        cnt[ransomNote[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] < 0) {
            return false;
        }
    }

    return true;
}
