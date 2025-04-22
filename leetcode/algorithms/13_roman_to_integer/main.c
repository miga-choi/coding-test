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
// Solution 1: Hash table
int solution1(char* s) {
    int t['X' + 1] = {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000,
    };
    int res = 0;
    for (int i = 0; s[i]; i++) {
        if (t[s[i]] < t[s[i + 1]]) {
            res -= t[s[i]];
        } else {
            res += t[s[i]];
        }
    }
    return res;
}

// Solution 2: Switch Statement
int getValue(const char* s) {
    switch (*s) {
        case 'I':
            return (s[1] == 'V' || s[1] == 'X') ? -1 : 1;
        case 'X':
            return (s[1] == 'L' || s[1] == 'C') ? -10 : 10;
        case 'C':
            return (s[1] == 'D' || s[1] == 'M') ? -100 : 100;
        case 'V':
            return 5;
        case 'L':
            return 50;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}

int solution2(char* s) {
    int result = 0;

    for (; *s != '\0'; ++s) {
        result += getValue(s);
    }
    return result;
}

// Solution 3: Switch Statement
int decimalNumericalPlace(char roman_np_value) {
    switch (roman_np_value) {
        case 'M':
            return 1000;
            break;
        case 'D':
            return 500;
            break;
        case 'C':
            return 100;
            break;
        case 'L':
            return 50;
            break;
        case 'X':
            return 10;
            break;
        case 'V':
            return 5;
            break;
        case 'I':
            return 1;
            break;
        default:
            return -1;
    }
}

int solution3(char* s) {
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (decimalNumericalPlace(s[i]) < decimalNumericalPlace(s[i + 1])) {
            sum = sum - decimalNumericalPlace(s[i]);
        } else {
            sum += decimalNumericalPlace(s[i]);
        }
    }
    return sum;
}

// Solution 4
int solution4(char* s) {
    int result = 0;

    while (*s) {
        switch (*s) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                return -1;
        }
        if (s[1] != '\0') {
            if (*s == 'I' && (s[1] == 'V' || s[1] == 'X')) {
                result -= 2;
            } else if (*s == 'X' && (s[1] == 'L' || s[1] == 'C')) {
                result -= 20;
            } else if (*s == 'C' && (s[1] == 'D' || s[1] == 'M')) {
                result -= 200;
            }
        }
        s++;
    }

    return result;
}
