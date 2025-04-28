#include <stdbool.h>

int longestPalindrome(char* s) {
    int alphabetNumArray[52] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < 97) {
            alphabetNumArray[s[i] - 'A']++;
        } else {
            alphabetNumArray[s[i] - 'a' + 26]++;
        }
    }

    int haveSingle = 0;
    int result = 0;
    for (int i = 0; i < 52; i++) {
        if (alphabetNumArray[i] % 2 > 0) {
            haveSingle = 1;
        }
        result += alphabetNumArray[i] / 2;
    }

    return result * 2 + haveSingle;
}


// Solution
int solution(char* s) {
    long long freq = 0;
    int len = 0;

    for (register int i = 0; s[i] != '\0'; i++) {
        freq ^= (1LL << (s[i] - 'A'));
        len++;
    }

    bool hasOdd = 0;
    for (register int i = 0; i < 58; i++) {
        if ((freq >> i) & 1) {
            len--;
            hasOdd = 1;
        }
    }

    return len + hasOdd;
}
