#include <algorithm>
#include <vector>
using namespace std;

class RemoveElement {
public:
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }

        return i;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Two Pointers
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }

    /**
     * Solution 2
     * 
     * Swap with Last
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
            } else {
                i++;
            }
        }

        return n;
    }

    /**
     * Solution 3
     * 
     * algorithm - std::remove
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution3(vector<int>& nums, int val) {
        auto newEnd = remove(nums.begin(), nums.end(), val);

        return distance(nums.begin(), newEnd);
    }
};
