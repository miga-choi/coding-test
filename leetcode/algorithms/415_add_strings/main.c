#include <stdlib.h> // malloc
#include <string.h> // strlen

/**
 * Complexities:
 *   N - The Size of `num1`
 *   M - The Size of `num2`
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(1)
 */
char* addStrings(char* num1, char* num2) {
  int num1Length = 0;
  int num2Length = 0;

  for (int i = 0; num1[i] != '\0'; i++) {
    num1Length++;
  }

  for (int i = 0; num2[i] != '\0'; i++) {
    num2Length++;
  }

  int numLength = num1Length > num2Length ? num1Length : num2Length;

  char* num = (char*)malloc(sizeof(char) * (numLength + 2));

  int num1Ptr = num1Length - 1; // num1 pointer
  int num2Ptr = num2Length - 1; // num2 pointer
  int numPtr = numLength + 1; // num pointer

  num[numPtr--] = '\0';
  int up = 0;

  while (num1Ptr >= 0 || num2Ptr >= 0) {
    int _num1 = num1Ptr >= 0 ? num1[num1Ptr--] - '0' : 0;
    int _num2 = num2Ptr >= 0 ? num2[num2Ptr--] - '0' : 0;
    int _num = _num1 + _num2 + up;
    if (_num > 9) {
      _num -= 10;
      up = 1;
    } else {
      up = 0;
    }
    num[numPtr--] = _num + '0';
  }

  numPtr++;

  if (up > 0) {
    num[--numPtr] = '1';
  }

  return &num[numPtr];
}


// Solution
/**
 * Solution 1
 *
 * Two Pointers
 *
 * Complexities:
 *   N - The Size of `num1`
 *   M - The Size of `num2`
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(1)
 */
char* solution1(char* num1, char* num2) {
    int i = (int)strlen(num1) - 1;
    int j = (int)strlen(num2) - 1;
    int maxLen = (i > j ? i : j) + 1;

    char* res = malloc(maxLen + 2);
    int k = 0, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int d = carry;
        if (i >= 0) {
          d += num1[i--] - '0';
        }
        if (j >= 0) {
          d += num2[j--] - '0';
        }

        res[k++] = (char)('0' + d % 10);
        carry = d / 10;
    }
    res[k] = '\0';

    for (int l = 0, r = k - 1; l < r; l++, r--) {
        char t = res[l];
        res[l] = res[r];
        res[r] = t;
    }

    return res;
}

/**
 * Solution 2
 * 
 * Two Pointers
 * 
 * Complexities:
 *   N - The Size of `num1`
 *   M - The Size of `num2`
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(1)
 */
char* solution2(char* num1, char* num2) {
    int i = (int)strlen(num1) - 1;
    int j = (int)strlen(num2) - 1;
    int len = (i > j ? i : j) + 2;

    char* res = malloc(len + 1);
    res[len] = '\0';
    int k = len - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int d = carry;
        if (i >= 0) {
          d += num1[i--] - '0';
        }
        if (j >= 0) {
          d += num2[j--] - '0';
        }
        res[k--] = (char)('0' + d % 10);
        carry = d / 10;
    }

    int start = k + 1;
    if (start > 0) {
      memmove(res, res + start, len - start + 1);
    }

    return res;
}
