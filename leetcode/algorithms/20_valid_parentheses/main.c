#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    char stack[strlen(s)];
    int count = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[count] = ')';
            count++;
        } else if (s[i] == '[') {
            stack[count] = ']';
            count++;
        } else if (s[i] == '{') {
            stack[count] = '}';
            count++;
        } else if (s[i] == '\0') {
            break;
        } else {
            count--;
            if (count < 0 || stack[count] != s[i])
            {
                return false;
            }
            stack[count] = '\0';
        }
    }

    return stack[0] == '\0';
}


// Solution
// Solution 1
bool solution1(char* s) {
    char* q = s;

    for (char* p = s; *p; p++) {
        switch (*p) {
            case '(':
                *q++ = ')';
                continue;
            case '{':
                *q++ = '}';
                continue;
            case '[':
                *q++ = ']';
                continue;
            default:
                if (q == s || *p != *--q) {
                    return false;
                }
        }
    }

    return q == s;
}

// Solution 2: Stack
bool solution2(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) {
                return false;
            }
            if ((s[i] == ')' && stack[top] == '(') ||
                (s[i] == '}' && stack[top] == '{') ||
                (s[i] == ']' && stack[top] == '[')) {
                top--;
            } else {
                return false;
            }
        }
    }
    return top == -1;
}
