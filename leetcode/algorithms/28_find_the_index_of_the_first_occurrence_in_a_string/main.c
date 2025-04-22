#include <string.h>;

int strStr(char* haystack, char* needle) {
    int needleSize = 0;
    for (int i = 0; needle[i] != '\0'; i++) {
        needleSize++;
    }

    if (needleSize == 0) {
        return 0;
    }

    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            for (int j = 0; needle[j] != '\0'; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                } else if (needle[j + 1] == '\0') {
                    return i;
                }
            }
        }
    }

    return -1;
}


// Solution
// Solution 1
int solution1(char* haystack, char* needle) {
    if (strlen(needle) > strlen(haystack)) {
        return -1;
    }

    for (int i = 0; i < strlen(haystack); i++) {
        if (!strncmp(haystack + i, needle, strlen(needle))) {
            return i;
        }
    }

    return -1;
}

// Solution 2
int solution2(char* haystack, char* needle) {
    if (strlen(needle) > strlen(haystack)) {
        return -1;
    }

    for (int i = 0; i < strlen(haystack); i++) {
        if (!strncmp(haystack + i, needle, strlen(needle))) {
            return i;
        }
    }

    return -1;
}
