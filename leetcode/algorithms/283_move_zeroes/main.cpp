#include <vector>
using namespace std;

class MoveZeroes {
public:
    void moveZeroes(vector<int> &nums) {
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

    // Best Solution 1
    void bestSolution1(vector<int> &nums) {
        int j = 0;

        // move all the non-zero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }

    // Best Solution 2
    void bestSolution2(vector<int> &nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};
