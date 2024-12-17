#include <string.h>

int firstUniqChar(char* s) {
    int alphabetNumArray[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        alphabetNumArray[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (alphabetNumArray[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

// Best Solution
int bestSolution(char* s) {
    int i = 0, map[26], sSize = strlen(s);

    for (i; i < 26; i++) {
        map[i] = 0;
    }

    for (i = 0; i < sSize; i++) {
        map[s[i] - 'a']++;
    }

    for (i = 0; i < sSize; i++) {
        if (map[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}
