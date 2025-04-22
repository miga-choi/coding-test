#include <vector>
using namespace std;

class RemoveDuplicatesFromSortedArray {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
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
