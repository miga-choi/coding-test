#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    char alphabetRowNum[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        int row = 0;
        for (int j = 0; j < words[i][j] != '\0'; j++) {
            if (row) {
                if (alphabetRowNum[words[i][j] < 'a' ? words[i][j] - 'A' : words[i][j] - 'a'] == row) {
                    if (j == (strlen(words[i]) - 1)) {
                        result[count] = (char*)malloc(sizeof(char) * (strlen(words[i]) + 1));
                        result[count] = words[i];
                        count++;
                    }
                } else {
                    break;
                }
            } else {
                row = alphabetRowNum[words[i][j] < 'a' ? words[i][j] - 'A' : words[i][j] - 'a'];
                j--;
            }
        }
    }
    *returnSize = count;
    return result;
}

// Solution
bool checkWord(char* word) {
    char count[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    for (int i = 1; i < strlen(word); i++) {
        if (count[tolower(word[i - 1]) - 'a'] != count[tolower(word[i]) - 'a']) {
            return false;
        }
    }
    return true;
}

char** solution(char** words, int wordsSize, int* returnSize) {
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (checkWord(words[i])) {
            result[count] = (char*)malloc((strlen(words[i]) + 1) * sizeof(char));
            strcpy(result[count++], words[i]);
        }
    }
    *returnSize = count;
    return result;
}
