#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool rotateString(char* s, char* goal) {
    int sLen = strlen(s);
    int goalLen = strlen(goal);

    if (sLen != goalLen) {
        return false;
    }

    char* ss = (char*)malloc(sizeof(char) * sLen * 2 + 1);

    strcpy(ss, s);
    strcat(ss, s);

    bool result = strstr(ss, goal) != NULL;

    free(ss);

    return result;
}


// Solution
bool solution(char* s, char* goal) {
    int len_s = strlen(s);
    int len_goal = strlen(goal);

    // Check if lengths are equal
    if (len_s != len_goal) {
        return false;
    }

    // Create a new string by doubling `s`
    char doubled[2 * len_s + 1];
    strcpy(doubled, s);
    strcat(doubled, s);

    // Check if `goal` is a substring of `doubled`
    return strstr(doubled, goal) != NULL;
}
