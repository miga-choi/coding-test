#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    for (int i = 0;; i++)
    {
        if (strs[0][i] == '\0')
        {
            return strs[0];
        }
        for (int j = 1; j < strsSize; j++)
        {
            if (strs[j][i] != strs[0][i])
            {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
}


// Best Solution
// Best Solution 1:
char *bestSolution1(char **strs, int strsSize)
{
    for (int c = 0;; ++c)
    {
        if (strs[0][c] == '\0') // the longest common prefix is the first string
        {
            return strs[0];
        }
        for (int s = 1; s < strsSize; ++s)
        {
            if (strs[s][c] != strs[0][c]) // compare all strings character to the first one
            {
                strs[0][c] = '\0'; // replace the current character with '\0'
                return strs[0];
            }
        }
    }
}

// Best Solution 2:
char *bestSolution2(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        return "";
    }
    if (strsSize == 1)
    {
        return strs[0];
    }

    int len = 0, min = strlen(strs[0]);
    for (int i = 1; i < strsSize; ++i)
    {
        min = strlen(strs[i]) < min ? strlen(strs[i]) : min;
    }

    for (int c = 0; c < min; ++c)
    {
        for (int s = 0; s < strsSize - 1; ++s)
        {
            if (strs[s][c] == strs[s + 1][c])
            {
                if (s == strsSize - 2)
                {
                    ++len;
                }
            }
            else
            {
                goto br;
            }
        }
    }
br:
    if (len > 0)
    {
        char *ret = malloc(len * sizeof(int));
        strs[0][len] = '\0';
        strcpy(ret, strs[0]);
        return ret;
    }

    return "";
}

// Best Solution 3:
char *bestSolution3(char **strs, int strsSize)
{
    if (strsSize == 1)
    {
        return strs[0];
    }

    for (int i = 1, j = 0; i < strsSize; i++)
    {
        while (strs[i][j] == strs[i - 1][j] && strs[i][j] != '\0' && strs[i - 1][j] != '\0')
        {
            j++;
        }
        strs[i][j] = '\0';
        j = 0;
    }

    return strs[strsSize - 1];
}