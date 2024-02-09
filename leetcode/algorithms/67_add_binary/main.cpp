#include <stdlib.h>
#include <string>
using namespace std;

class AddBinary
{
public:
    string addBinary(string a, string b)
    {
        int size_a = a.size();
        int size_b = b.size();
        int size = size_a > size_b ? size_a : size_b;
        char *result = (char *)malloc(sizeof(char) * (size + 2));
        int up = 0;
        result[size + 1] = '\0';

        for (int i = 0; i < size; i++)
        {
            int num = up;
            up = 0;

            if (i < size_a)
            {
                num += a[size_a - i - 1] - '0';
            }
            if (i < size_b)
            {
                num += b[size_b - i - 1] - '0';
            }

            if (num > 1)
            {
                num -= 2, up = 1;
            }

            result[size - i] = num + '0';
        }

        if (up > 0)
        {
            result[0] = '1';
            up = -1;
        }

        return result + up + 1;
    }


    // Best Solution
    // Best Solution 1:
    string bestSolution1(string a, string b)
    {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i--] - '0';
            }
            if (j >= 0)
            {
                sum += b[j--] - '0';
            }
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if (carry)
        {
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Best Solution 2:
    string bestSolution2(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
            {
                carry += a[i--] - '0';
            }
            if (j >= 0)
            {
                carry += b[j--] - '0';
            }
            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }

    // Best Solution 3:
    string bestSolution3(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }
};