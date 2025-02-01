#include <string.h>

int findLUSlength(char* a, char* b) {
    int aLength = strlen(a);
    int bLength = strlen(b);

    if (aLength == bLength) {
        for (int i = 0; i < aLength; i++) {
            if (a[i] != b[i]) {
                break;
            }
            if (i == aLength - 1) {
                return -1;
            }
        }
    }

    return aLength > bLength ? aLength : bLength;
}

// Solution
int solution(char* a, char* b) {
    return (!strcmp(a, b)) ? -1 : fmax(strlen(a), strlen(b));
}
