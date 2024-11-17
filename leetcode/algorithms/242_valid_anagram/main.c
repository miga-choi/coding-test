#include <stdbool.h>
#include <string.h>

bool isAnagram(char *s, char *t)
{
    int sNum = 0;
    int tNum = 0;

    int sLength = strlen(s);
    int tLength = strlen(t);

    int charNumArray[26] = {0};

    if (sLength == tLength)
    {
        for (int i = 0; i < sLength; i++)
        {
            charNumArray[s[i] - 'a']++;
            charNumArray[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (charNumArray[i] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

// Best Solution 1
bool bestSolution1(char *s, char *t)
{
    int f[26] = {0};
    register int i;
    for (i = 0; s[i] != '\0' && t[i] != '\0'; i++)
    {
        f[s[i] - 'a']++;
        f[t[i] - 'a']--;
    }
    if (s[i] != '\0' || t[i] != '\0')
        return 0;
    for (register i = 0; i < 26; i++)
        if (f[i] != 0)
            return 0;
    return 1;
}

// Best Solution 2
bool bestSolution2(char *s, char *t)
{

    int chars[26] = {0, 0}, index;
    for (index = 0; s[index]; ++index)
        chars[s[index] - 'a']++;
    for (index = 0; t[index]; ++index)
        chars[t[index] - 'a']--;
    for (index = 0; index < 26; ++index)
        if (chars[index])
            return false;
    return true;
}
