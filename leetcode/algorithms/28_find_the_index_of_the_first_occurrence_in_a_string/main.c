#include <string.h>

/**
 * Brute Force, Sliding Window
 * 
 * Complexities:
 *   N - Length of `haystack`
 *   M - Length of `needle`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(1)
 */
int strStr(char* haystack, char* needle) {
    int start_idx = -1;
    int haystack_idx = 0;
    int needle_idx = 0;

    while (1) {
        if (needle[needle_idx] == '\0') {
            return haystack_idx - needle_idx;
        }

        if (haystack[haystack_idx] == '\0') {
            return -1;
        }

        if (haystack[haystack_idx] == needle[needle_idx]) {
            if (start_idx == -1) {
                start_idx = haystack_idx;
            }
            needle_idx++;
            haystack_idx++;
        } else {
            if (start_idx > -1) {
                haystack_idx = start_idx + 1;
                start_idx = -1;
            } else {
                haystack_idx++;
            }
            needle_idx = 0;
        }
    }

    return -1;
}


// Solution
/**
 * Solution 1
 * 
 * Brute Force, Sliding Window
 * 
 * Complexities:
 *   N - Length of `haystack`
 *   M - Length of `needle`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(1)
 */
int solution1(char* haystack, char* needle) {
    int h_len = strlen(haystack);
    int n_len = strlen(needle);

    if (h_len < n_len) {
        return -1;
    }

    for (int i = 0; i <= h_len - n_len; i++) {
        int j;
        for (j = 0; j < n_len; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        if (j == n_len) {
            return i;
        }
    }

    return -1;
}

/**
 * Solution 2
 * 
 * <string.h> -> strstr
 * 
 * Complexities:
 *   N - Length of `haystack`
 *   M - Length of `needle`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(1)
 */
int solution2(char* haystack, char* needle) {
    char* pos = strstr(haystack, needle);

    if (pos != NULL) {
        return pos - haystack;
    }

    return -1;
}
