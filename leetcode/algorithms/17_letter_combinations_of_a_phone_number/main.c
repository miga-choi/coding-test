#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Recursion: Backtracking (DFS)
 * 
 * Complexities:
 *   - Time Complexity: O(4ᴺ)
 *   - Space Complexity: O(N)
 */
int getLettersLength(char digit) {
    switch (digit) {
        case '2':
            return 3;
        case '3':
            return 3;
        case '4':
            return 3;
        case '5':
            return 3;
        case '6':
            return 3;
        case '7':
            return 4;
        case '8':
            return 3;
        case '9':
            return 4;
        default:
            return 0;
    }
}

char* getLetters(char digit) {
    switch (digit) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
    }
}

void backtracking(const char* digits, const int digits_size, char*** result,
                  char* row, int i, int* returnSize) {
    if (i == digits_size) {
        (*result)[(*returnSize)++] = strdup(row);
        return;
    }

    char* letters = getLetters(digits[i]);
    int letters_length = getLettersLength(digits[i]);

    for (int j = 0; j < letters_length; j++) {
        row[i] = letters[j];
        backtracking(digits, digits_size, result, row, i + 1, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int digits_size = 0;
    int array_size = 1;

    for (int i = 0; digits[i] != '\0'; i++) {
        digits_size++;
        array_size *= getLettersLength(digits[i]);
    }

    char** result = (char**)malloc(sizeof(char*) * array_size);
    char* row = (char*)malloc(sizeof(char) * (digits_size + 1));
    row[digits_size] = '\0';

    backtracking(digits, digits_size, &result, row, 0, returnSize);

    return result;
}


// Solution
/**
 * Recursion: Backtracking (DFS)
 * 
 * Complexities:
 *   - Time Complexity: O(4ᴺ)
 *   - Space Complexity: O(N)
 */
const char* KEYPAD[10] = {
  "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(const char* digits, int index, char* path, char** result, int* count) {
    if (digits[index] == '\0') {
        path[index] = '\0';
        result[*count] = (char*)malloc(sizeof(char) * (strlen(path) + 1));
        strcpy(result[*count], path);
        (*count)++;
        return;
    }

    int digit = digits[index] - '0';
    const char* letters = KEYPAD[digit];

    for (int i = 0; i < strlen(letters); i++) {
        path[index] = letters[i];
        backtrack(digits, index + 1, path, result, count);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || *digits == '\0') {
        *returnSize = 0;
        return NULL;
    }

    int len = strlen(digits);
    int total_combinations = 1;

    for (int i = 0; i < len; i++) {
        int digit = digits[i] - '0';
        total_combinations *= strlen(KEYPAD[digit]);
    }

    char** result = (char**)malloc(sizeof(char*) * total_combinations);

    char* path = (char*)malloc(sizeof(char) * (len + 1));

    int count = 0;
    backtrack(digits, 0, path, result, &count);

    free(path);
    *returnSize = count;

    return result;
}