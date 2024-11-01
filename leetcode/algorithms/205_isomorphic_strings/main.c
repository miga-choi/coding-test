#include <stdbool.h>

bool isIsomorphic(char *s, char *t)
{
    char sCharArray[256] = {0};
    char tCharArray[256] = {0};

    for (int i = 0; s[i] != '\0' && t[i] != '\0'; i++)
    {
        if (sCharArray[s[i]] == 0 && tCharArray[t[i]] == 0)
        {
            sCharArray[s[i]] = t[i];
            tCharArray[t[i]] = s[i];
        }
        else if (sCharArray[s[i]] != t[i] || tCharArray[t[i]] != s[i])
        {
            return false;
        }
    }

    return true;
}

// Best Solution
bool bestSolution(char *s, char *t)
{
    char charArrS[256] = {0};
    char charArrT[256] = {0};
    int i = 0;
    while (s[i] != 0)
    {
        if (charArrS[s[i]] == 0 && charArrT[t[i]] == 0)
        {
            charArrS[s[i]] = t[i];
            charArrT[t[i]] = s[i];
        }
        else if (charArrS[s[i]] != t[i] || charArrT[t[i]] != s[i])
            return false;
        i++;
    }

    return true;
}