#include <functional> // std::bit_xor
#include <numeric>    // std::accumulate
#include <vector>
using namespace std;

class SingleNumber {
public:
    /**
     * Bit Manipulation
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Bit Manipulation
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int solution1(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            result ^= num;
        }

        return result;
    }

    /**
     * Solution 2
     * 
     * accumulate
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int solution2(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};
