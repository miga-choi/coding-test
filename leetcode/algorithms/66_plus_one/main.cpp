#include <vector>
using namespace std;

class PlusOne
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result;
        vector<int>::iterator it = result.begin();
        int up = 1;

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int num = digits[i] + up;
            if (num >= 10)
            {
                num -= 10;
                up = 1;
            }
            else
            {
                up = 0;
            }

            it = result.insert(it, num);
        }

        if (up > 0)
        {
            result.insert(it, 1);
        }

        return result;
    }


    // Best Solution
    // Best Solution 1:
    vector<int> bestSolution1(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                digits[i]++;
            }
            if (digits[i] == 10)
            {
                digits[i] = 0;
                if (i != 0)
                {
                    digits[i - 1]++;
                }
                else
                {
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }
        }
        return digits;
    }

    // Best Solution 2:
    vector<int> bestSolution2(vector<int> &digits)
    {
        int n = digits.size() - 1;

        for (int i = n; i >= 0; --i)
        {
            // traverse digits from the last element (least significant)
            // since we begin with the last digit, increasing that digit by one
            // results in overflow.  Therefore, all elements PRIOR to digits[0]
            // need to be considered since there may be additional nines between
            // digits[0], ... , digits[n].
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                // current digit is not 9 so we can safely increment by one
                digits[i] += 1;
                return digits;
            }
        }
        // if the program runs to this point, each 9 is now a 0.
        // to get a correct solution, we need to add one more element with
        // a value of zero AND set digits[0] to 1 (in the most significant position)
        // to account for the carry digit.
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};