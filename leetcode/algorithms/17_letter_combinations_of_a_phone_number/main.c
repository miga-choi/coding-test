#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Recursion: Backtracking (DFS)
 * - Time Complexity: O(4ᴺ)
 * - Space Complexity: O(N)
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
 * - Time Complexity: O(4ᴺ)
 * - Space Complexity: O(N)
 */
const char* mapping[] = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};

void backtrack(const char* digits, int index, char* current_combination,
               char*** result, int* returnSize, int* capacity) {
    if (index == strlen(digits)) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = (char**)realloc(*result, sizeof(char*) * (*capacity));
        }

        (*result)[*returnSize] = strdup(current_combination);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    const char* letters = mapping[digit];

    for (int i = 0; i < strlen(letters); i++) {
        current_combination[index] = letters[i];
        backtrack(digits, index + 1, current_combination, result, returnSize, capacity);
    }
}

char** solution(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);

    if (len == 0) {
        return NULL;
    }

    int capacity = 8;
    char** result = (char**)malloc(sizeof(char*) * capacity);

    char* current_combination = (char*)malloc(sizeof(char) * (len + 1));
    current_combination[len] = '\0';

    backtrack(digits, 0, current_combination, &result, returnSize, &capacity);

    free(current_combination);
    return result;
}
