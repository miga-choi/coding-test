#include <stdlib.h>
char *convertToTitle(int columnNumber)
{
    char *ptr = (char *)malloc(sizeof(char) * 8);
    char *originPtr = ptr; // for free ptr
    ptr += 7;              // move pointer + 7
    *ptr = 0;              // 0 = '\0'

    while (columnNumber > 0)
    {
        ptr--;
        columnNumber -= 1;
        *ptr = columnNumber % 26 + 65;
        columnNumber /= 26;
    }

    return ptr;
    free(originPtr);
}

// Best Solution
char *bestSolution(int columnNumber)
{
    char *ptr;
    ptr = malloc(8 * sizeof(char));
    ptr += 7;
    *ptr = 0;

    while (columnNumber)
    {
        ptr--;
        columnNumber = columnNumber - 1;
        *ptr = (columnNumber % 26) + 65;
        columnNumber = columnNumber / 26;
    }

    return ptr;
}