#include <cstdlib> // std::abs
#include <vector>  // std::vector
using namespace std;

class FindAllNumbersDisappearedInAnArray {
public:
    /**
     * Auxiliary Array
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> numArray(nums.size(), 0);

        for (int num : nums) {
            numArray[num - 1] = 1;
        }

        vector<int> result;

        for (int i = 1; i <= nums.size(); i++) {
            if (!numArray[i] - 1) {
                result.push_back(i);
            }
        }

        return result;
    }

    // Solution
    /**
     * Solution 1
     *
     * Auxiliary Array
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> solution1(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<bool> seen(n + 1, false);

        for (int x : nums) {
            seen[x] = true;
        }

        vector<int> res;
        for (int v = 1; v <= n; ++v) {
            if (!seen[v]) {
                res.push_back(v);
            }
        }

        return res;
    }

    /**
     * Solution 2
     *
     * Negative Marking
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    vector<int> solution2(vector<int>& nums) {
        for (int x : nums) {
            int idx = abs(x) - 1;
            nums[idx] = -abs(nums[idx]);
        }

        vector<int> res;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            } else {
                nums[i] = -nums[i];
            }
        }

        return res;
    }

    /**
     * Solution 3
     *
     * Cyclic Sort
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    vector<int> solution3(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};
