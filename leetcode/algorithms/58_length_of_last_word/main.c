#include <string.h>

/**
 * Reverse Traversal
 * 
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int lengthOfLastWord(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }

    int result = 0;
    for (; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '\0') {
            result++;
        } else if (s[i] = ' ' && result > 0) {
            break;
        }
    }

    return result;
}


// Solution
/**
 * Reverse Traversal
 * 
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(char* s) {
    int len = strlen(s);
    int length = 0;
    int i = len - 1;

    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
