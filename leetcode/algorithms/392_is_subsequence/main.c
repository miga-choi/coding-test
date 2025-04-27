#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int i = 0;

    for (int j = 0; t[j] != '\0'; j++) {
        if (s[i] == t[j]) {
            i++;
        }
    }

    return s[i] == '\0';
}


// Solution
// Solution 1
bool solution1(char* s, char* t) {
    while (*t) {
        s += *s == *t++;
    }
    return !*s;
}

// Solution 2
bool solution2(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);

    // For index of s (or subsequence)
    int j = 0;

    // Traverse s and t,
    // and compare current character of s with first unmatched char of t,
    // if matched then move ahead in s
    for (int i = 0; i < m && j < n; i++) {
        if (s[j] == t[i]) {
            j++;
        }
    }

    // If all characters of s were found in t
    return (j == n);
}

// Solution 3
int isSubSequence(char* s1, char* s2, int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }

    if (s1[i - 1] == s2[j - 1]) {
        return 1 + isSubSequence(s1, s2, i - 1, j - 1);
    } else {
        return isSubSequence(s1, s2, i, j - 1);
    }
}

bool solution3(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    if (m > n) {
        return false;
    }

    if (isSubSequence(s, t, m, n) == m) {
        return true;
    } else {
        return false;
    }
}
