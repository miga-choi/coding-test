#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
char** readBinaryWatch(int turnedOn, int *returnSize) {
    // Hour + Minute
    char** result = (char**)malloc(sizeof(char*) * 720);
    int count = 0;

    // Hour
    for (int h = 0; h < 12; h++) {
        int H = 0;
        int hTemp = h;

        while (hTemp > 0) {
            if (hTemp % 2 > 0) {
                H++;
            }
            hTemp >>= 1;
        }

        // Minute
        for (int m = 0; m < 60; m++) {
            int M = 0;
            int mTemp = m;
            while (mTemp > 0) {
                if (mTemp % 2 > 0) {
                    M++;
                }
                mTemp >>= 1;
            }

            if (H + M == turnedOn) {
                result[count] = (char*)malloc(sizeof(char) * 8);
                snprintf(result[count], 8, "%d:%02d", h, m);
                count++;
            }
        }
    }

    *returnSize = count;
    return result;
}


// Solution
/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
char** solution(int turnedOn, int* returnSize) {
    char** res = malloc(720 * sizeof(char*));
    int cnt = 0;

    for (int h = 0; h < 12; h++) {
        int hb = bitCount(h);
        if (hb > turnedOn) {
            continue;
        }

        for (int m = 0; m < 60; m++) {
            if (hb + bitCount(m) == turnedOn) {
                res[cnt] = malloc(6);
                snprintf(res[cnt], 6, "%d:%02d", h, m);
                cnt++;
            }
        }
    }

    *returnSize = cnt;
    return res;
}
