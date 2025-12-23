#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * LIFO (Last-In, First-Out): Stack
 * 
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
bool isValid(char* s) {
    char stack[strlen(s)];
    int top = -1;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[++top] = ')';
        } else if (s[i] == '[') {
            stack[++top] = ']';
        } else if (s[i] == '{') {
            stack[++top] = '}';
        } else if (s[i] == '\0') {
            break;
        } else {
            if (top == -1 || stack[top] != s[i]) {
                return false;
            }
            stack[top--] = '\0';
        }
    }

    return stack[0] == '\0';
}


// Solution
/**
 * LIFO (Last-In, First-Out): Stack
 * 
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
bool solution(char* s) {
    int len = strlen(s);

    if (len % 2 != 0) {
        return false;
    }

    char* stack = (char*)malloc(sizeof(char) * len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];

        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } else {
            if (top == -1) {
                free(stack);
                return false;
            }

            char open = stack[top--];

            if (current == ')' && open != '(') {
                free(stack);
                return false;
            }
            if (current == '}' && open != '{') {
                free(stack);
                return false;
            }
            if (current == ']' && open != '[') {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1);

    free(stack);
    return result;
}
