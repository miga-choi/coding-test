#include <stdlib.h>
#include <string.h>

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
// Solution 1
char* solution1(char* a, char* b) {
    int i, j, k, c = 0;
    char* res;

    i = strlen(a);
    j = strlen(b);
    k = i > j ? i : j;
    k += 2;

    res = (char*)malloc(k * sizeof(char));

    i--;
    j--;
    res[--k] = '\0';

    while (--k >= 0) {
        c += i >= 0 ? a[i--] - '0' : 0;
        c += j >= 0 ? b[j--] - '0' : 0;

        res[k] = c % 2 + '0';
        c /= 2;
    }

    if (res[0] == '0') {
        memmove(res, res + 1, strlen(res) * sizeof(char));
    }

    return res;
}

// Solution 2
char* solution2(char* a, char* b) {
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char* output = (char*)malloc(sizeOutput + 1);
    int sum = 0;

    output[sizeOutput] = '\0';

    while (sizeA > 0 || sizeB > 0 || sum > 0) {
        if (sizeA > 0) {
            sum += a[--sizeA] - '0';
        }
        if (sizeB > 0) {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;
}

// Solution 3
char* solution3(char* a, char* b) {
    int la = strlen(a);
    int lb = strlen(b);
    int lr = la > lb ? la : lb;
    int carry = 0;
    char* res = (char*)calloc(lr + 2, sizeof(char));
    res[lr + 1] = '\0';
    la--;
    lb--;
    while (la >= 0 || lb >= 0) {
        int ba = la >= 0 ? a[la--] - '0' : 0;
        int bb = lb >= 0 ? b[lb--] - '0' : 0;
        int br = ba ^ bb ^ carry;
        carry = (ba & bb) | (carry & (ba ^ bb));
        res[lr--] = br + '0';
    }
    if (!carry) {
        return res + 1;
    }
    res[0] = '1';
    return res;
}
