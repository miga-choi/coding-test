#include <numeric>
#include <vector>
using namespace std;

class MissingNumber {
public:
    /**
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
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
    /**
     * Solution 1
     * 
     * std::accumulate
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int> &nums) {
        int n = nums.size();
        
        int expectedSum = n * (n + 1) / 2;
        
        int actualSum = accumulate(nums.begin(), nums.end(), 0);
        
        return expectedSum - actualSum;
    }

    /**
     * Solution 2
     * 
     * XOR
     *
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<int> &nums) {
        int n = nums.size();
        int missing = n;

        for (int i = 0; i < n; ++i) {
            missing ^= i ^ nums[i];
        }

        return missing;
    }
};
