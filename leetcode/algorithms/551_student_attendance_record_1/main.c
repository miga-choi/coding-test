#include <stdbool.h>

bool checkRecord(char* s) {
    int absent = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            absent++;
            if (absent > 1) {
                return false;
            }
        } else if (i > 1 && s[i - 2] == 'L' && s[i - 1] == 'L' && s[i] == 'L') {
            return false;
        }
    }
    return true;
}

// Solution
bool checkRecord(char* s) {
    int a = 0, l = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            a++;
        }
        if (s[i] == 'L') {
            l++;
        } else {
            l = 0;
        }
        if (a >= 2 || l > 2) {
            return false;
        }
    }
    return true;
}
