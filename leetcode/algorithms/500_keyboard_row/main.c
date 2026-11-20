#include <ctype.h>   // tolower
#include <stdbool.h> // bool
#include <stddef.h>  // size_t
#include <stdlib.h>  // malloc
#include <string.h>  // strlen, memcpy

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Row Lookup Table + First-Letter Row Check
 * 
 * Complexities:
 *   i - Length of iᵗʰ Word in `words`
 *   - Time Complexity: O(Σ lenᵢ²)
 *   - Space Complexity: O(1)
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    char alphabetRowNum[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        int row = 0;

        for (int j = 0; j < words[i][j] != '\0'; j++) {
            if (row) {
                if (alphabetRowNum[words[i][j] < 'a' ? words[i][j] - 'A' : words[i][j] - 'a'] == row) {
                    if (j == (strlen(words[i]) - 1)) {
                        result[count] = (char*)malloc(sizeof(char) * (strlen(words[i]) + 1));
                        result[count] = words[i];
                        count++;
                    }
                } else {
                    break;
                }
            } else {
                row = alphabetRowNum[words[i][j] < 'a' ? words[i][j] - 'A' : words[i][j] - 'a'];
                j--;
            }
        }
    }

    *returnSize = count;
    return result;
}


// Solution
/**
 * Solution 1
 * 
 * Row Lookup Table
 * 
 * Complexities:
 *   n - Sum of The Number of Characters in `words`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
static const char* ROWS1[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

static bool inOneRow(const char* w, const int* row) {
    int r = row[tolower((unsigned char)w[0]) - 'a'];

    for (int i = 1; w[i]; i++) {
        if (row[tolower((unsigned char)w[i]) - 'a'] != r) {
            return false;
        }
    }

    return true;
}

char** solution1(char** words, int wordsSize, int* returnSize) {
    int row[26];

    for (int r = 0; r < 3; r++) {
        for (const char* p = ROWS1[r]; *p; p++) {
            row[*p - 'a'] = r;
        }
    }

    char** res = malloc(wordsSize * sizeof(char*));
    int k = 0;

    for (int i = 0; i < wordsSize; i++) {
        if (!inOneRow(words[i], row)) {
            continue;
        }

        size_t len = strlen(words[i]);
        res[k] = malloc(len + 1);
        memcpy(res[k], words[i], len + 1);
        k++;
    }

    *returnSize = k;
    return res;
}

/**
 * Solution 2
 * 
 * Row Bitmask
 * 
 * Complexities:
 *   n - Sum of The Number of Characters in `words`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
static const char* ROWS2[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

static unsigned int toMask(const char* s) {
    unsigned int m = 0;

    for (; *s; s++) {
        m |= 1u << (tolower((unsigned char)*s) - 'a');
    }

    return m;
}

char** solution2(char** words, int wordsSize, int* returnSize) {
    unsigned int rowMask[3];
    for (int r = 0; r < 3; r++) {
        rowMask[r] = toMask(ROWS2[r]);
    }

    char** res = malloc(wordsSize * sizeof(char*));
    int k = 0;

    for (int i = 0; i < wordsSize; i++) {
        unsigned int w = toMask(words[i]);
        for (int r = 0; r < 3; r++) {
            if ((w & ~rowMask[r]) == 0) {
                size_t len = strlen(words[i]);
                res[k] = malloc(len + 1);
                memcpy(res[k], words[i], len + 1);
                k++;
                break;
            }
        }
    }

    *returnSize = k;
    return res;
}
