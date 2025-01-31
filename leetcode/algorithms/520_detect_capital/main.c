#include <stdbool.h>
#include <string.h>

bool detectCapitalUse(char* word) {
    for (int i = 1; i < word[i] != '\0'; i++) {
        if (i > 1) {
            if (word[i] > 'Z' && word[i - 1] < 'a') {
                return false;
            } else if (word[i] < 'a' && word[i - 1] > 'Z') {
                return false;
            }
        } else {
            if (word[i - 1] > 'Z' && word[i] < 'a') {
                return false;
            }
        }
    }
    return true;
}

// Solution
bool solution(char* word) {
    if (strlen(word) < 2) {
        return true;
    }
    if (word[0] < 'a' && word[1] < 'a') {
        for (int i = 2; i < word[i] != '\0'; i++) {
            if (word[i] > 'Z') {
                return false;
            }
        }
    } else {
        for (int i = 1; i < word[i] != '\0'; i++) {
            if (word[i] < 'a') {
                return false;
            }
        }
    }
    return true;
}
