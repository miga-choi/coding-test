#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char* s) {}


// Solution
bool solution(char* s) {
    int len = strlen(s);
    int j;

    for (int i = 1; i <= len / 2; i++) {
        if (len % i == 0) {
            int isRepeated = 1;
            for (int j = i; j < len; j++) {
                if (s[j] != s[j - i]) {
                    isRepeated = 0;
                    break;
                }
            }
            if (isRepeated) {
                return true;
            }
        }
    }

    // No repeated substring found
    return false;
}
