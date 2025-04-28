#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
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
char** solution(int turnedOn, int *returnSize) {
    char** final_arr = (char**)malloc(190 * sizeof(char*));
    int count = 0;

    // 720 minutes a day
    for (int k = 0; k < 720; k++) {
        // unsigned char from 0 to 255
        unsigned char h = k / 60;
        unsigned char m = k % 60;

        int count_bit = 0;

        while (h > 0) {
            if (h % 2 == 1) {
                count_bit++;
            }
            h >>= 1;
        }

        while (m > 0) {
            if (m % 2 == 1) {
                count_bit++;
            }
            m >>= 1;
        }

        if (count_bit == turnedOn) {
            final_arr[count] = (char*)malloc(8 * sizeof(char));
            snprintf(final_arr[count], 8, "%d:%02d", k / 60, k % 60);
            count++;
        }
    }

    *returnSize = count;
    return final_arr;
}
