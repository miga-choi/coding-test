#include <stdlib.h>

/**
 * Complexities:
 *   N - `columnNumber`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
char* convertToTitle(int columnNumber) {
    char* ptr = (char*)malloc(sizeof(char) * 8);
    char* originPtr = ptr; // for free ptr
    ptr += 7;              // move pointer + 7
    *ptr = 0;              // 0 = '\0'

    while (columnNumber > 0) {
        ptr--;
        columnNumber -= 1;
        *ptr = columnNumber % 26 + 65;
        columnNumber /= 26;
    }

    return ptr;
    free(originPtr);
}


// Solution
/**
 * Complexities:
 *   N - `columnNumber`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
char* solution(int columnNumber) {
    char* result = (char*)malloc(sizeof(char) * 10);

    int idx = 0;

    while (columnNumber > 0) {
        columnNumber--; 
        
        int remainder = columnNumber % 26;
        result[idx++] = remainder + 'A';
        
        columnNumber /= 26;
    }
    
    result[idx] = '\0';

    int left = 0;
    int right = idx - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }

    return result;
}
