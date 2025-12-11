#include <string.h>

int getNumber(char s) {
    switch (s) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

/**
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int romanToInt(char* s) {
    int result = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (getNumber(s[i]) < getNumber(s[i + 1])) {
            result -= getNumber(s[i]);
        } else {
            result += getNumber(s[i]);
        }
    }

    return result;
}



// Solution
/**
 * Array
 * 
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(char* s) {
    int map[256] = {0};

    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int total = 0;
    int i = 0;

    while (s[i] != '\0') {
        int currentVal = map[s[i]];
        int nextVal = map[s[i + 1]];

        if (currentVal < nextVal) {
            total -= currentVal;
        } else {
            total += currentVal;
        }

        i++;
    }

    return total;
}
