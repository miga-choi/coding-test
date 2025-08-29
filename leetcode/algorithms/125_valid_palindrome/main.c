#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/**
 * Two-Pointer
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
bool isPalindrome(char* s) {
    int prefix = 0;
    int suffix = strlen(s) - 1;

    while (prefix < suffix) {
        char prefix_char = s[prefix];
        char suffix_char = s[suffix];

        if (!((prefix_char >= '0' && prefix_char <= '9') ||
              (prefix_char >= 'A' && prefix_char <= 'Z') ||
              (prefix_char >= 'a' && prefix_char <= 'z'))) {
            prefix++;
            continue;
        }
        if (!((suffix_char >= '0' && suffix_char <= '9') ||
              (suffix_char >= 'A' && suffix_char <= 'Z') ||
              (suffix_char >= 'a' && suffix_char <= 'z'))) {
            suffix--;
            continue;
        }

        if (tolower(prefix_char) != tolower(suffix_char)) {
            return false;
        }

        prefix++;
        suffix--;
    }

    return true;
}


// Solution
/**
 * Two-Pointer
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
bool solution(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        while (left < right && !isalnum(s[right])) {
            right--;
        }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
