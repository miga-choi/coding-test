#include <stdlib.h>
#include <string.h>

/**
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
char* convert(char* s, int numRows) {
    int sLen = strlen(s);

    if (numRows == 1 || numRows >= sLen) {
        char* result = (char*)malloc(sizeof(char) * (sLen + 1));
        strcpy(result, s);
        return result;
    }

    char* result = (char*)malloc(sizeof(char) * (sLen + 1));

    int cycleLen = numRows * 2 - 2;
    int result_idx = 0;
    for (int row = 0; row < numRows; row++) {
        for (int cycle = 0; row + cycle < sLen; cycle += cycleLen) {
            result[result_idx++] = s[row + cycle];

            if (row > 0 && row < numRows - 1) {
                int diag_idx = cycle + cycleLen - row;
                if (diag_idx < sLen) {
                    result[result_idx++] = s[diag_idx];
                }
            }
        }
    }

    result[result_idx] = '\0';

    return (char*)result;
}


// Solution
/**
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        char* result = (char*)malloc(sizeof(char) * (len + 1));
        strcpy(result, s);
        return result;
    }

    char* result = (char*)malloc(sizeof(char) * (len + 1));

    int cycleLen = 2 * numRows - 2;
    int result_idx = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            result[result_idx++] = s[j + i];

            if (i != 0 && i != numRows - 1) {
                int diag_idx = j + cycleLen - i;
                
                if (diag_idx < len) {
                    result[result_idx++] = s[diag_idx];
                }
            }
        }
    }

    result[result_idx] = '\0';
    
    return result;
}
