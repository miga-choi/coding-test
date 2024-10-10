/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int *getRow(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int **result = (int **)malloc(sizeof(int *) * (rowIndex + 1));

    for (int i = 0; i < rowIndex + 1; i++)
    {
        result[i] = (int *)malloc(sizeof(int) * (i + 1));
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
    return result[rowIndex];
}

// Best Solution
int *bestSolution(int rowIndex, int *returnSize)
{
    int *ans = calloc(rowIndex + 1, sizeof(int));
    long temp = 1;
    ans[0] = 1;
    for (int i = 1, up = rowIndex; i <= rowIndex; i++, up--)
    {
        temp = temp * up / i;
        ans[i] = temp;
    }
    *returnSize = rowIndex + 1;
    return ans;
}