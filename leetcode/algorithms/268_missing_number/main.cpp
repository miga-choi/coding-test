#include <numeric>
#include <vector>
using namespace std;

class MissingNumber {
public:
    int missingNumber(vector<int> &nums) {
        int originSum = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            originSum += (i + 1);
            sum = nums[i];
        }
        return originSum - sum;
    }


    // Solution
    // Solution 1: Using Vectors
    int solution1(vector<int> &nums) {
        int n = nums.size();
        vector<int> v(n + 1, -1);
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]] = nums[i];
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1)
                return i;
        }
        return 0;
    }

    // Solution 2: XOR Operation
    int solution2(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = ans ^ i;
        }
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }

    // Solution 3: Sum of all elememnts
    int solution3(vector<int> &nums) {
        int n = nums.size();
        int Tsum = (n * (n + 1)) / 2;
        return Tsum - accumulate(nums.begin(), nums.end(), 0);
    }

    // Solution 4: Sorting
    int solution4(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // case 1
        if (nums[0] != 0)
            return 0;
        // case 2
        if (nums[n - 1] != n)
            return n;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                // case 3
                return i;
            }
        }
        return 0;
    }
};
