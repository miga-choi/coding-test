#include <set>
#include <vector>
using namespace std;

class RemoveDuplicatesFromSortedArray {
public:
    /**
     * Two Pointers
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
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
     * set
     * - Time Complexity: O(Nlogᴺ)
     * - Space Complexity: O(N)
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
    // Solution 1
    int solution1(vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }

    // Solution 2
    int solution2(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                nums[i - count] = nums[i];
            }
        }
        return nums.size() - count;
    }

    // Solution 3
    int solution3(vector<int>& nums) {
        int i = 0;
        for (int n : nums) {
            if (!i || n > nums[i - 1]) {
                nums[i++] = n;
            }
        }
        return i;
    }

    // Solution 4
    int solution4(vector<int>& nums) {
        int i = !nums.empty();
        for (int n : nums) {
            if (n > nums[i - 1]) {
                nums[i++] = n;
            }
        }
        return i;
    }
};
