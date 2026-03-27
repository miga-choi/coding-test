#include <algorithm>
#include <vector>
using namespace std;

class HouseRobber {
public:
    /**
     * DP
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> result(n);
        result[0] = nums[0];
        result[1] = nums[1];
        result[2] = result[0] + nums[2];

        for (int i = 3; i < n; i++) {
            result[i] = max(result[i - 2], result[i - 3]) + nums[i];
        }

        return max(result[n - 1], result[n - 2]);
    }


    // Solution
    /**
     * DP
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;

        for (int num : nums) {
            int current = max(prev1, prev2 + num);
            
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
