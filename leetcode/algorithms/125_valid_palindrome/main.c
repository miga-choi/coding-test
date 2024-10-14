#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s)
{
    int prefix = 0;
    int suffix = strlen(s) - 1;

    while (prefix < suffix)
    {
        char prefixChar = s[prefix];
        char suffixChar = s[suffix];

        if (!((prefixChar >= '0' && prefixChar <= '9') ||
              (prefixChar >= 'A' && prefixChar <= 'Z') ||
              (prefixChar >= 'a' && prefixChar <= 'z')))
        {
            prefix++;
            continue;
        }
        if (!((suffixChar >= '0' && suffixChar <= '9') ||
              (suffixChar >= 'A' && suffixChar <= 'Z') ||
              (suffixChar >= 'a' && suffixChar <= 'z')))
        {
            suffix--;
            continue;
        }

        if (tolower(prefixChar) != tolower(suffixChar))
        {
            return false;
        }

        prefix++;
        suffix--;
    }

    return true;
}

// Best Solution
int isAlphanum(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int convertAlphaLower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

bool bestSolution(char *s)
{
    int l, r;

    r = strlen(s) - 1;

    l = 0;
    while (l < r)
    {
        if (isAlphanum(s[l]))
        {
            if (isAlphanum(s[r]))
            {
                if (convertAlphaLower(s[l]) != convertAlphaLower(s[r]))
                {
                    return 0;
                }

                l++;
                r--;
            }
            else
                r--;
        }
        else
            l++;
    }

    return (1);
}