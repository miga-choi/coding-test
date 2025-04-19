#include <string.h>

int lengthOfLastWord(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }

    int result = 0;
    for (; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '\0') {
            result++;
        } else if (s[i] = ' ' && result > 0) {
            break;
        }
    }

    return result;
}


// Solution
// Solution 1:
int solution1(char* s) {
    int c = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            c++;
        } else {
            break;
        }
    }
    int c1 = 0;
    for (int i = strlen(s) - c - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            c1++;
        } else {
            break;
        }
    }
    return c1;
}

// Solution 2:
int solution2(char* s) {
    int lastSize = 0;
    int i = strlen(s) - 1;

    if (s[i] == ' ') {
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
    }

    while (i >= 0) {
        if (s[i] == ' ') {
            break;
        }
        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90)) {
            lastSize++;
        }
        i--;
    }

    return lastSize;
}

// Solution 2:
int solution2(char* s) {
    int len = 0;
    int i = strlen(s) - 1;

    while (s[i] == ' ' && i >= 0) {
        i--;
    }
    while (i >= 0 && s[i--] != ' ') {
        len++;
    }

    return len;
}
