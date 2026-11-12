#include <algorithm> // std::find, std::max
#include <vector>    // std::vector
using namespace std;

class MaxConsecutiveOnes {
public:
    /**
     * Single Pass + Running Count
     *
     * Complexities:
     *   n - The Size of `nums`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int max = 0;
        int current = 0;

        for (int num : nums) {
            if (num > 0) {
                current++;
                if (current > max) {
                    max = current;
                }
            } else {
                current = 0;
            }
        }

        return max;
    }


    // Solution
    /**
     * Solution 1
     *
     * Single Pass + Running Count
     *
     * Complexities:
     *   n - The Size of `nums`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int>& nums) {
        int cur = 0, best = 0;

        for (int x : nums) {
            if (x == 1) {
                ++cur;
                best = max(best, cur);
            } else {
                cur = 0;
            }
        }

        return best;
    }

    /**
     * Solution 2
     *
     * Single Pass + Last Zero Index
     *
     * Complexities:
     *   n - The Size of `nums`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<int>& nums) {
        int lastZero = -1, best = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] == 0) {
                lastZero = i;
            } else {
                best = max(best, i - lastZero);
            }
        }

        return best;
    }

    /**
     * Solution 3
     *
     * Group Scanning with std::find
     *
     * Complexities:
     *   n - The Size of `nums`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    int solution3(vector<int>& nums) {
        int best = 0;
        auto it = nums.begin();

        while (it != nums.end()) {
            auto start = find(it, nums.end(), 1);
            auto stop  = find(start, nums.end(), 0);
            best = max(best, static_cast<int>(stop - start));
            it = stop;
        }

        return best;
    }
};
