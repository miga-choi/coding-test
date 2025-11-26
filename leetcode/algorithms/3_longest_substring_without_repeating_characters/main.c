#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Sliding Window (Using Array)
 * 
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int lengthOfLongestSubstring(char* s) {
    int charMap[128];
    memset(charMap, -1, sizeof(charMap));

    int left = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char currentChar = s[right];

        if (charMap[currentChar] > -1 && charMap[currentChar] >= left) {
            left = charMap[currentChar] + 1;
        }

        charMap[currentChar] = right;

        int length = right - left + 1;

        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}


// Solution
/**
 * Sliding Window (Using Array)
 * 
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(char* s) {
    int last_index[128];
    memset(last_index, -1, sizeof(last_index));

    int left = 0;
    int max_len = 0;
    int right = 0;

    while (s[right] != '\0') {
        char current_char = s[right];

        if (last_index[current_char] >= left) {
            left = last_index[current_char] + 1;
        }

        last_index[current_char] = right;

        max_len = MAX(max_len, right - left + 1);

        right++;
    }

    return max_len;
}
