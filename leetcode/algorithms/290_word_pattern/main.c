#include <stdbool.h>
#include <string.h>

bool wordPattern(char *pattern, char *s) {
}

// Best Solution 1
bool bestSolution1(char *pattern, char *s) {
    int patternLen = strlen(pattern);
    int sLen = strlen(s);

    if (patternLen == 0 || sLen == 0)
        return false;

    char *hashMap[26];
    memset(hashMap, 0, sizeof(char *) * 26);

    char *word;
    char *token = strtok(s, " ");
    int i = 0;

    while (token != NULL) {
        if (i >= patternLen) {
            return false;
        }

        word = token;

        int index = pattern[i] - 'a';
        if (hashMap[index] == NULL) {
            // Check if the word is already mapped to another pattern character
            for (int j = 0; j < 26; j++) {
                if (hashMap[j] != NULL && strcmp(hashMap[j], word) == 0) {
                    return false;
                }
            }
            hashMap[index] = word;
        } else {
            if (strcmp(hashMap[index], word) != 0) {
                return false;
            }
        }

        token = strtok(NULL, " ");
        i++;
    }

    return i == patternLen;
}
