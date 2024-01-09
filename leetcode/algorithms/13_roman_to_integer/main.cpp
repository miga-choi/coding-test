#include <string>
using namespace std;

class RomanToInteger
{
public:
    int romanToInt(string s)
    {
        int result = 0;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (getNumber(s[i]) < getNumber(s[i + 1]))
            {
                result -= getNumber(s[i]);
            }
            else
            {
                result += getNumber(s[i]);
            }
        }

        return result;
    }

    int getNumber(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
        }
    }


    // Best Solution
    // Best Solution 1: Hash table
    int bestSolution1(string s)
    {
        unordered_map<char, int> m{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        // unordered_map<char, int> m;
        // m['I'] = 1;
        // m['V'] = 5;
        // m['X'] = 10;
        // m['L'] = 50;
        // m['C'] = 100;
        // m['D'] = 500;
        // m['M'] = 1000;

        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (m[s[i]] < m[s[i + 1]])
            {
                ans -= m[s[i]];
            }
            else
            {
                ans += m[s[i]];
            }
        }

        return ans;
    }

    // Best Solution 2: Switch
    int bestSolution1(string s)
    {
        int ret = 0;  // to store the return value
        int temp = 0; // to store the previous value

        for (size_t i = 0; i < s.size(); i++)
        {
            char curr = s[i];
            int pos = 0; // to store the current value

            switch (curr)
            {
            case 'I':
                pos = 1;
                break;
            case 'V':
                pos = 5;
                break;
            case 'X':
                pos = 10;
                break;
            case 'L':
                pos = 50;
                break;
            case 'C':
                pos = 100;
                break;
            case 'D':
                pos = 500;
                break;
            case 'M':
                pos = 1000;
                break;
            default:
                return 0;
            }

            ret += pos;
            if (temp < pos)
                ret -= temp * 2; // ex: IV, ret = 1 + 5 - 1*2 = 4
            temp = pos;
        }

        return ret;
    }
};
