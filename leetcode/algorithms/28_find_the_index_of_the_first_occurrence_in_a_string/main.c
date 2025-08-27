#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/**
 * Brute-Force
 * - Time Complexity: O(N * M)
 * - Space Complexity: O(1)
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
 * strstr() in <string.h>
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
int solution1(char* haystack, char* needle) {
    if (*needle == '\0') {
        return 0;
    }

    char* foundPos = strstr(haystack, needle);

    if (foundPos == NULL) {
        return -1;
    }

    return (int)(foundPos - haystack);
}

/**
 * Solution 2
 * 
 * Brute-Force
 * - Time Complexity: O(N * M)
 * - Space Complexity: O(1)
 */
int solution2(char* haystack, char* needle) {
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (haystack_len < needle_len) {
        return -1;
    }

    for (int haystack_idx = 0; haystack_idx <= haystack_len - needle_len; haystack_idx++) {
        bool match = true;

        for (int needle_idx = 0; needle_idx < needle_len; needle_idx++) {
            if (haystack[haystack_idx + needle_idx] != needle[needle_idx]) {
                match = false;
                break;
            }
        }

        if (match) {
            return haystack_idx;
        }
    }

    return -1;
}

/**
 * Solution 3
 * 
 * Knuth-Morris-Pratt (KMP) + Longest Prefix Suffix (LPS)
 * - Time Complexity: O(N + M)
 * - Space Complexity: O(M)
 */
 void compute_lps_array(char* pattern, int pattern_len, int* lps) {
    int length = 0;
    lps[0] = 0;
    int idx = 1;

    while (idx < pattern_len) {
        if (pattern[idx] == pattern[length]) {
            length++;
            lps[idx] = length;
            idx++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[idx] = 0;
                idx++;
            }
        }
    }
}

int solution3(char* haystack, char* needle) {
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (haystack_len < needle_len) {
        return -1;
    }

    int* lps = (int*)malloc(sizeof(int) * needle_len);

    compute_lps_array(needle, needle_len, lps);

    int haystack_idx = 0;
    int needle_idx = 0;

    while (haystack_idx < haystack_len) {
        if (needle[needle_idx] == haystack[haystack_idx]) {
            haystack_idx++;
            needle_idx++;
        }

        if (needle_idx == needle_len) {
            return haystack_idx - needle_idx;
        } else if (haystack_idx < haystack_len && needle[needle_idx] != haystack[haystack_idx]) {
            if (needle_idx != 0) {
                needle_idx = lps[needle_idx - 1];
            } else {
                haystack_idx++;
            }
        }
    }

    return -1;
}
