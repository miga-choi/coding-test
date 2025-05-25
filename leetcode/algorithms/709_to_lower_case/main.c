char* toLowerCase(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] > 64 && s[i] < 91) {
            s[i] = s[i] + 32;
        }
    }
    return s;
}


// Solution
char* solution(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    return s;
}
