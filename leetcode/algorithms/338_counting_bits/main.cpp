#include <vector>
using namespace std;

class CountingBits {
public:
    vector<int> countBits(int n) {
        vector<int> result;

        for (int i = 0; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num != 0) {
                sum += num % 2;
                num /= 2;
            }
            result.push_back(sum);
        }

        return result;
    }


    // Solution
    // Solution 1
    vector<int> solution1(int n) {
        vector<int> ans;

        // iterating fromt 0 to n
        for (int i = 0; i <= n; i++) {
            // sum is initialised as 0
            int sum = 0;
            int num = i;
            // while num not equals zero
            while (num != 0) {
                // we have to count 1's in binary representation of i, therefore % 2
                sum += num % 2;
                num = num / 2;
            }
            // add sum to ans vector
            ans.push_back(sum);
        }
        // return
        return ans;
    }

    // Solution 2
    vector<int> solution2(int n) {
        // n+1 as we are going to count from 0 to n
        vector<int> t(n + 1);

        // t[0] will be 0 beacuse 0 has count of set bit is 0;
        t[0] = 0;

        // we can compute current set bit count using previous count
        // as x/2 in O(1) time

        // i%2 will be 0 for even number ans 1 for odd number

        for (int i = 1; i <= n; ++i) {
            t[i] = t[i / 2] + i % 2;
        }

        return t;
    }
};
