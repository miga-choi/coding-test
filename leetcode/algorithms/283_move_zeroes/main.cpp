#include <algorithm> // swap, stable_partition
#include <vector>
using namespace std;

class MoveZeroes {
public:
    /**
     * Complexities:
     *   N - The size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    void moveZeroes(vector<int>& nums) {
        int newNums[nums.size()];
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                newNums[count++] = nums[i];
            }
        }

        for (int i = 0; i < count; i++) {
            nums[i] = newNums[i];
        }

        for (int i = 1; i <= nums.size() - count; i++) {
            nums[nums.size() - i] = 0;
        }
    }


    // Solution
    /**
     * Solution 1
     * 
     * std::swap
     *
     * Complexities:
     *   N - The size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    void solution1(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != lastNonZeroFoundAt) {
                    swap(nums[lastNonZeroFoundAt], nums[i]);
                }
                lastNonZeroFoundAt++;
            }
        }
    }

    /**
     * Solution 2
     * 
     * std::stable_partition
     *
     * Complexities:
     *   N - The size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    void solution2(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int n) {
            return n != 0;
        });
    }
};
