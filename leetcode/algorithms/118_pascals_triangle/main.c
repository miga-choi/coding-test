/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    *returnSize = numRows;
    int **result = (int **)(malloc(numRows * sizeof(int *)));
    *returnColumnSizes = (int *)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++)
    {
        (*returnColumnSizes)[i] = i + 1;
        result[i] = (int *)malloc(numRows * sizeof(int));
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                result[i][j] = 1;
            }
            else
            {
                result[i][j] = result[(i - 1)][(j - 1)] + result[(i - 1)][j];
            }
        }
    }
    return result;
}

// Best Solution
int **bestSolution(int numRows, int *returnSize, int **returnColumnSizes)
{
    *returnSize = numRows;
    int **output = (int **)malloc(numRows * sizeof(int *));
    *returnColumnSizes = (int *)malloc(numRows * sizeof(int));

    // Allocate memory for the whole triangle
    for (int i = 0; i < numRows; i++)
    {
        (*returnColumnSizes)[i] = i + 1;
        output[i] = (int *)malloc((i + 1) * sizeof(int));
    }

    // The first row will always be 1
    output[0][0] = 1;

    for (int i = 1; i < numRows; i++)
    {
        output[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            output[i][j] = output[i - 1][j - 1] + output[i - 1][j];
        }
        output[i][i] = 1;
    }
    return output;
}