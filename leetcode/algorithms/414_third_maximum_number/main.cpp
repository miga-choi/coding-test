#include <algorithm>  // std::sort, std::unique
#include <functional> // std::greater
#include <limits>     // std::numeric_limits
#include <optional>   // std::optional
#include <set>        // std::set
#include <vector>     // std::vector
using namespace std;

class ThirdMaximumNumber {
public:
    /**
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int thirdMax(vector<int>& nums) {
        long LONG_MIN = numeric_limits<long>::min();

        int first = nums[0];
        long second = LONG_MIN;
        long thrid = LONG_MIN;

        for (int num : nums) {
            if (num > first) {
                thrid = second;
                second = first;
                first = num;
            } else if (num < first && num > second) {
                thrid = second;
                second = num;
            } else if (num < second && num > thrid) {
                thrid = num;
            }
        }

        return thrid == LONG_MIN ? first : thrid;
    }

    // Solution
    /**
     * Solution 1
     *
     * std::optional
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int>& nums) {
        optional<int> first, second, third;

        for (int x : nums) {
            if (x == first || x == second || x == third) {
                continue;
            }

            if (x > first) {
                third = second;
                second = first;
                first = x;
            } else if (x > second) {
                third = second;
                second = x;
            } else if (x > third) {
                third = x;
            }
        }

        return third ? *third : *first;
    }

    /**
     * Solution 2
     *
     * Set
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<int>& nums) {
        set<int> top;

        for (int x : nums) {
            top.insert(x);
            if (top.size() > 3) {
                top.erase(top.begin());
            }
        }

        return top.size() == 3 ? *top.begin() : *top.rbegin();
    }

    /**
     * Solution 3
     *
     * Sorting + std::unique
     *
     * Complexities:
     *   N - The Size of `nums`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(1)
     */
    int solution3(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        return nums.size() >= 3 ? nums[2] : nums[0];
    }
};
