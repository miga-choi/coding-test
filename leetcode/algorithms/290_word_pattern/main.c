#include <stdbool.h>
#include <string.h>

// Wrong
bool wordPattern(char *pattern, char *s) {
    int patternNum[26] = {0};
    int ifPatternNumNull[26] = {0};
    int wordCount = 0;
    int wordNum = 0;
    int patternLength = strlen(pattern);

    for (int i = 0;; i++) {
        if (wordCount > (patternLength - 1)) {
            return false;
        }
        int alphabetNum = pattern[wordCount] - 97;
        if (s[i] == ' ' || s[i] == '\0') {
            if (!ifPatternNumNull[alphabetNum]) {
                for (int j = 0; j < 26; j++) {
                    if (j != alphabetNum) {
                        if (patternNum[j] == wordNum) {
                            return false;
                        }
                    }
                }
                ifPatternNumNull[alphabetNum] = 1;
                patternNum[alphabetNum] = wordNum;
            } else {
                if (patternNum[alphabetNum] != wordNum) {
                    return false;
                }
            }

            if (s[i] == '\0') {
                if (wordCount != (patternLength - 1)) {
                    return false;
                }
                break;
            }
            wordNum = 0;
            wordCount++;
        } else {
            wordNum += s[i];
        }
    }

    return true;
}

// Best Solution
bool bestSolution(char *pattern, char *s) {
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
