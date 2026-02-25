#include <stdlib.h>

/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
char* intToRoman(int num) {
    int capacity = 8;
    char* result = (char*)malloc(sizeof(char) * capacity);
    int index = 0;

    char charMap[1001];
    charMap[1] = 'I';
    charMap[5] = 'V';
    charMap[10] = 'X';
    charMap[50] = 'L';
    charMap[100] = 'C';
    charMap[500] = 'D';
    charMap[1000] = 'M';

    while (num > 0) {
        if (index >= capacity - 4) {
            capacity += 8;
            result = realloc(result, sizeof(char) * capacity);
        }

        if (num / 1000 > 0) {
            for (int i = 0; i < num / 1000; i++) {
                result[index++] = charMap[1000];
            }
            num %= 1000;
        } else if (num / 100 > 0) {
            if (num >= 900) {
                result[index++] = charMap[100];
                result[index++] = charMap[1000];
            } else if (num >= 500) {
                result[index++] = charMap[500];
                for (int i = 0; i < (num - 500) / 100; i++) {
                    result[index++] = charMap[100];
                }
            } else if (num >= 400) {
                result[index++] = charMap[100];
                result[index++] = charMap[500];
            } else {
                for (int i = 0; i < num / 100; i++) {
                    result[index++] = charMap[100];
                }
            }
            num %= 100;
        } else if (num / 10 > 0) {
            if (num >= 90) {
                result[index++] = charMap[10];
                result[index++] = charMap[100];
            } else if (num >= 50) {
                result[index++] = charMap[50];
                for (int i = 0; i < (num - 50) / 10; i++) {
                    result[index++] = charMap[10];
                }
            } else if (num >= 40) {
                result[index++] = charMap[10];
                result[index++] = charMap[50];
            } else {
                for (int i = 0; i < num / 10; i++) {
                    result[index++] = charMap[10];
                }
            }
            num %= 10;
        } else if (num / 1 > 0) {
            if (num >= 9) {
                result[index++] = charMap[1];
                result[index++] = charMap[10];
            } else if (num >= 5) {
                result[index++] = charMap[5];
                for (int i = 0; i < num - 5; i++) {
                    result[index++] = charMap[1];
                }
            } else if (num >= 4) {
                result[index++] = charMap[1];
                result[index++] = charMap[5];
            } else {
                for (int i = 0; i < num; i++) {
                    result[index++] = charMap[1];
                }
            }
            num = 0;
        }
    }

    result[index] = '\0';
    return result;
}


// Solution
/**
 * Greedy
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
char* intToRoman(int num) {
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char* result = (char*)malloc(sizeof(char) * 20);
    int pos = 0;

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];

            const char* sym = symbols[i];
            while (*sym != '\0') {
                result[pos++] = *sym++;
            }
        }
    }

    result[pos] = '\0';

    return result;
}
