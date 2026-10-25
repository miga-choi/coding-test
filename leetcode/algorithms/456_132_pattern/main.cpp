#include <algorithm> // std::min
#include <climits>   // std::INT_MIN
#include <limits>    // std::numeric_limits
#include <vector>    // std::vector
using namespace std;

class OneThreeTwoPattern {
public:
    /**
     * Monotonic Stack (In-place)
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    bool find132pattern(vector<int>& nums) {
        int peak = nums.size();
        int min = INT_MIN;

        for (int i = nums.size() - 1; i > -1; i--) {
            if (nums[i] < min) {
                return true;
            }

            while (peak < nums.size() && nums[i] > nums[peak]) {
                min = nums[peak];
                peak++;
            }

            peak--;
            nums[peak] = nums[i];
        }

        return false;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Monotonic Stack
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool solution1(vector<int>& nums) {
        vector<int> st;
        st.reserve(nums.size());
        int third = numeric_limits<int>::min();

        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
            if (nums[i] < third) {
                return true;
            }

            while (!st.empty() && st.back() < nums[i]) {
                third = st.back();
                st.pop_back();
            }

            st.push_back(nums[i]);
        }

        return false;
    }

    /**
     * Solution 2
     * 
     * Monotonic Stack (In-place)
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    bool solution2(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int k = n;
        int third = numeric_limits<int>::min();

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < third) {
                return true;
            }

            while (k < n && nums[k] < nums[i]) {
                third = nums[k++];
            }

            nums[--k] = nums[i];
        }

        return false;
    }

    /**
     * Solution 3
     * 
     * Prefix Minimum + Brute Force
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    bool solution3(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int minLeft = nums[0];

        for (int j = 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (minLeft < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }

            minLeft = min(minLeft, nums[j]);
        }

        return false;
    }
};
