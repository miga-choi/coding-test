#include <string.h>
#include <math.h>

int titleToNumber(char *columnTitle)
{
    int length = 0;
    while (1)
    {
        if (columnTitle[length] == 0)
        {
            break;
        }
        length++;
    }

    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result += ((int)columnTitle[length - i - 1] - 64) * pow(26, i);
    }

    return result;
}

// Best Solution
int bestSolution(char *columnTitle)
{
    int output = 0;
    for (int i = 0; i < strlen(columnTitle); i++)
    {
        output *= 26;
        output += (columnTitle[i] - 'A' + 1);
    }
    return output;
}
