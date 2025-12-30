#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class RemoveDuplicatesFromSortedArray {
public:
    /**
     * Two Pointers
     * 
     * Complexities:
     *   N - Length of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int removeDuplicates1(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[left] != nums[right]) {
                nums[++left] = nums[right];
            }
        }
        
        return left + 1;
    }

    /**
     * Set
     * 
     * Complexities:
     *   N - Length of `nums`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(N)
     */
    int removeDuplicates2(vector<int>& nums) {
        set<int> set(begin(nums), end(nums));

        int i = 0;
        for (auto p = set.begin(); p != set.end(); p++) {
            int v = *p;
            nums[i++] = v;
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
     *   N - Length of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int>& nums) {
        int index = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[index]) {
                index++;
                nums[index] = nums[i];
            }
        }

        return index + 1;
    }

    /**
     * Solution 2
     * 
     * std::unique
     * 
     * Complexities:
     *   N - Length of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<int>& nums) {
         auto last = unique(nums.begin(), nums.end());

        return distance(nums.begin(), last);
    }
};
