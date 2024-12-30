#include <stdlib.h>
#include <string.h>

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

// Best Solution
char* bestSolution(char* num1, char* num2) {
  int sizeNum1 = strlen(num1);
  int sizeNum2 = strlen(num2);
  int sizeOutput = (sizeNum1 > sizeNum2 ? sizeNum1 : sizeNum2) + 1;
  char* output = (char*)malloc(sizeOutput + 1);
  int sum = 0;

  output[sizeOutput] = '\0';

  while (sizeNum1 > 0 || sizeNum2 > 0 || sum > 0) {
    if (sizeNum1 > 0) {
      sum += num1[--sizeNum1] - '0';
    }
    if (sizeNum2 > 0) {
      sum += num2[--sizeNum2] - '0';
    }
    output[--sizeOutput] = sum % 10 + '0';
    sum /= 10;
  }

  return output + sizeOutput;
}
