#include <string.h>
#include <math.h>

/**
 * Complexities:
 *   N - Size of `columnTitle`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
int titleToNumber(char* columnTitle) {
    int length = 0;
    while (1) {
        if (columnTitle[length] == 0) {
            break;
        }
        length++;
    }

    int result = 0;
    for (int i = 0; i < length; i++) {
        result += ((int)columnTitle[length - i - 1] - 64) * pow(26, i);
    }

    return result;
}


// Solution
/**
 * Complexities:
 *   N - Size of `columnTitle`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(char* columnTitle) {
    long long result = 0; 
    
    for (int i = 0; columnTitle[i] != '\0'; i++) {
        int char_value = columnTitle[i] - 'A' + 1;
        
        result = result * 26 + char_value;
    }
    
    return (int)result;
}
