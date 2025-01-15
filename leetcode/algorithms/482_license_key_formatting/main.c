#include <string.h>
#include <stdlib.h>

char* licenseKeyFormatting(char* s, int k) {
    int length = strlen(s);
    int p = length - 1;

    char* result = (char*)malloc(sizeof(char) * (length * 2));
    result[length * 2 - 1] = '\0';
    int i = 1;

    while (1) {
        if (p < 0) {
            break;
        }
        if (s[p] == '-') {
            p--;
            continue;
        }

        if (!(i % (k + 1))) {
            result[length * 2 - 1 - i] = '-';
        } else {
            result[length * 2 - 1 - i] = s[p] >= 'a' ? s[p] - 'a' + 'A' : s[p];
            p--;
        }

        i++;
    }

    return &result[length * 2 - i];
}

// Best Solution
char* bestSolution(char* s, int k) {
    int len = strlen(s);
    int size = len + len / k + 1;
    int counter = 0;

    char* ans = (char*)calloc(size, sizeof(char));
    ans[--size] = '\0';

    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '-') {
            continue;
        }
        ans[--size] = s[i] >= 'a' ? s[i] - 'a' + 'A' : s[i];
        counter++;
        if (counter == k && i != 0) {
            ans[--size] = '-';
            counter = 0;
        }
    }

    /* no leading '-' */
    if (ans[size] == '-') {
        size++;
    }

    return ans + size;
}
