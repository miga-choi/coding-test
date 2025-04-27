#include <string.h>

char findTheDifference(char* s, char* t) {
    int alphabetNumArray[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        alphabetNumArray[s[i] - 'a']++;
    }

    for (int i = 0; t[i] != '\0'; i++) {
        if (alphabetNumArray[t[i] - 'a'] == 0) {
            return t[i];
        } else {
            alphabetNumArray[t[i] - 'a']--;
        }
    }

    return ' ';
}


// Solution
char solution(char* s, char* t) {
    // Passing the diff: (t[i]-s[i]) to t[i+1]
    for (int i = 0; i < strlen(s); i++) {
        t[i + 1] += t[i] - s[i];
    }

    // The diff will be carried over to the last element eventually
    return t[strlen(t) - 1];
}
