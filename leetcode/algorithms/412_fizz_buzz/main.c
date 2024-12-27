#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * n);

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            result[i - 1] = "FizzBuzz";
        } else if (i % 3 == 0) {
            result[i - 1] = "Fizz";
        } else if (i % 5 == 0) {
            result[i - 1] = "Buzz";
        } else {
            result[i - 1] = (char*)malloc(sizeof(char) * 5);
            sprintf(result[i - 1], "%d", i);
        }
    }

    *returnSize = n;
    return result;
}

// Best Solution
char** bestSolution(int n, int* returnSize) {
    int i;

    // since n = number of elements to be returned
    *returnSize = n;

    // the string of strings where the right elements will be copied
    char** answer;

    // every string contains at most 5 character (max number is 10000 => 5
    // characters)
    char str[5];

    // first number we want to return is 1
    i = 1;

    answer = NULL;

    // our string of strings will have the same number of element than the returning one (n)
    answer = malloc(sizeof(*answer) * n);

    if (!answer) {
        // securizing our malloc => returning NULL if something went wrong
        return (answer);
    }

    while (i <= n) {
        if (i % 15 == 0) {
            // NB we need to start duplicating from position 0 => (i - 1)
            answer[i - 1] = strdup("FizzBuzz");
        } else if (i % 3 == 0) {
            answer[i - 1] = strdup("Fizz");
        } else if (i % 5 == 0) {
            answer[i - 1] = strdup("Buzz");
        } else {
            // converting integer i into char and storing it in str
            sprintf(str, "%d", i);
            answer[i - 1] = strdup(str);
        }
        i++;
    }
    
    return answer;
}
