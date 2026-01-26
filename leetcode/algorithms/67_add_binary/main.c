#include <stdlib.h>
#include <string.h>

/**
 * Reverse Iteration
 * 
 * Complexities:
 *   N - Length of `a` 
 *   M - Length of `b` 
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(max(N, M))
 */
char* addbinary(char* a, char* b) {
    int size_a = strlen(a);
    int size_b = strlen(b);
    int size = size_a > size_b ? size_a : size_b;
    char* result = (char*)malloc(sizeof(char) * (size + 2));
    int up = 0;
    result[size + 1] = '\0';

    for (int i = 0; i < size; i++) {
        int num = up;
        up = 0;

        if (i < size_a) {
            num += a[size_a - i - 1] - '0';
        }
        if (i < size_b) {
            num += b[size_b - i - 1] - '0';
        }

        if (num > 1) {
            num -= 2, up = 1;
        }

        result[size - i] = num + '0';
    }

    if (up > 0) {
        result[0] = '1';
        up = -1;
    }

    return result + up + 1;
}


// Solution
/**
 * Reverse Iteration
 * 
 * Complexities:
 *   N - Length of `a` 
 *   M - Length of `b` 
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(max(N, M))
 */
char* solution(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0;

    int max_len = (i > j ? i : j) + 2; 
    
    char* result = (char*)malloc(sizeof(char) * (max_len + 1));
    
    result[max_len] = '\0';
    int k = max_len - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        
        if (j >= 0) sum += b[j--] - '0';

        result[k--] = (sum % 2) + '0';
        
        carry = sum / 2;
    }

    if (k == 0) {
        return result + 1;
    }

    return result;
}
