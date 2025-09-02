#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Frequency Counter
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
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
 * Solution 1
 * 
 * Frequency Counter
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
bool solution1(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t) {
        return false;
    }

    int char_counts[26] = {0};

    for (int i = 0; i < len_s; i++) {
        char_counts[s[i] - 'a']++;
    }

    for (int i = 0; i < len_t; i++) {
        char_counts[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (char_counts[i] != 0) {
            return false;
        }
    }

    return true;
}

/**
 * Solution 2
 * 
 * Sort
 * - Time Complexity: O(N * logᴺ)
 * - Space Complexity: O(1) or O(logᴺ)
 */
int compare_chars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

bool solution2(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t) {
        return false;
    }

    qsort(s, len_s, sizeof(char), compare_chars);
    qsort(t, len_t, sizeof(char), compare_chars);

    if (strcmp(s, t) == 0) {
        return true;
    } else {
        return false;
    }
}
