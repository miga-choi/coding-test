#include <stdbool.h>
#include <stdlib.h>

char* reverseVowels(char* s) {
    int sLength = 0;
    int vowelsLength = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
            s[i] == 'O' || s[i] == 'U' || s[i] == 'a' ||
            s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            vowelsLength++;
        }
        sLength++;
    }

    char* vowels = (char*)malloc(sizeof(char) * vowelsLength);

    int count = 0;
    for (int i = 0; i < sLength; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
            s[i] == 'O' || s[i] == 'U' || s[i] == 'a' ||
            s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            vowels[count++] = s[i];
        }
    }

    count = 0;
    for (int i = 0; i < sLength; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
            s[i] == 'O' || s[i] == 'U' || s[i] == 'a' ||
            s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
            s[i] = vowels[vowelsLength - count - 1];
            count++;
        }
    }

    return s;
}


// Solution
bool isVowel(char c) {
    char vowels[] = "aeiouAEIOU";

    for (int i = 0; vowels[i] != '\0'; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }

    return false;
}

char* solution(char* s) {
    int start = 0;
    int end = strlen(s) - 1;

    while (start < end) {
        while (start < end && !isVowel(s[start])) {
            start++;
        }
        while (start < end && !isVowel(s[end])) {
            end--;
        }

        // Swap vowels
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }

    return s;
}
