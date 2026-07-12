#include <stdbool.h>
#include <string.h>

/**
 * Frequency Counting
 * 
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
bool isAnagram(char* s, char* t) {
    int len = strlen(s);

    if (len != strlen(t)) {
        return false;
    }

    int charNumArray[26] = {0};

    for (int i = 0; i < len; i++) {
        charNumArray[s[i] - 'a']++;
        charNumArray[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (charNumArray[i] != 0) {
            return false;
        }
    }

    return true;
}


// Solution
/**
 * Frequency Counting
 * 
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
bool solution(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t) {
        return false;
    }

    int counts[26] = {0};

    for (int i = 0; i < len_s; i++) {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) {
            return false;
        }
    }

    return true;
}
