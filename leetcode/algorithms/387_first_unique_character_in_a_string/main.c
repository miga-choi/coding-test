#include <string.h>

/**
 * Frequency Counter
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
int firstUniqChar(char* s) {
    int alphabetNumArray[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        alphabetNumArray[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (alphabetNumArray[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}


// Solution
/**
 * Solution 1
 * 
 * Frequency Counter
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
int solution(char* s) {
    int counts[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        counts[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        if (counts[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}
