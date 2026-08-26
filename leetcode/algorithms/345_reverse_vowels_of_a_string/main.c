#include <stdbool.h>
#include <stdlib.h>

/**
 * Two Pointers 
 * 
 * Complexities: 
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
char* reverseVowels(char* s) {
    int sLength = 0;
    int vowelsLength = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
            s[i] == 'O' || s[i] == 'U' || s[i] == 'a' ||
            s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            vowelsLength++;
        }
        sLength++;
    }

    char* vowels = (char*)malloc(sizeof(char) * vowelsLength);

    int count = 0;
    for (int i = 0; i < sLength; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
            s[i] == 'O' || s[i] == 'U' || s[i] == 'a' ||
            s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            vowels[count++] = s[i];
        }
    }

    count = 0;
    for (int i = 0; i < sLength; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
            s[i] == 'O' || s[i] == 'U' || s[i] == 'a' ||
            s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            s[i] = vowels[vowelsLength - count - 1];
            count++;
        }
    }

    return s;
}


// Solution
/**
 * Solution 1
 * 
 * Two Pointers 
 * 
 * Complexities: 
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
static inline bool isVowel(char c) {
    switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
        default:
            return false;
    }
}

char* solution1(char* s) {
    int left = 0, right = (int)strlen(s) - 1;

    while (left < right) {
        while (left < right && !isVowel(s[left])) {
            left++;
        }
        while (left < right && !isVowel(s[right])) {
            right--;
        }

        if (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

    return s;
}

/**
 * Solution 2
 * 
 * Two Pointers 
 * 
 * Complexities: 
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
static const bool VOWEL[256] = {
    ['a'] = true, ['e'] = true, ['i'] = true, ['o'] = true, ['u'] = true,
    ['A'] = true, ['E'] = true, ['I'] = true, ['O'] = true, ['U'] = true,
};

char* solution2(char* s) {
    int left = 0, right = (int)strlen(s) - 1;

    while (left < right) {
        while (left < right && !VOWEL[(unsigned char)s[left]]) {
            left++;
        }
        while (left < right && !VOWEL[(unsigned char)s[right]]) {
            right--;
        }

        if (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

    return s;
}
