#include <vector>
using namespace std;

class ThreeSumClosest {
public:
    /**
     * Sorting + Two Pointers
     *
     * Complexities:
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int flag = 0;
        int sum = nums[0] + nums[1] + nums[2];

        for (int flag = 0; flag < n - 2; flag++) {
            int left = flag + 1;
            int right = n - 1;

            while (left < right) {
                int currSum = nums[flag] + nums[left] + nums[right];

                if (abs(currSum - target) < abs(sum - target)) {
                    sum = currSum;
                }

                if (currSum < target) {
                    left++;
                } else if (currSum > target) {
                    right--;
                } else {
                    return currSum;
                }
            }
        }

        return sum;
    }


    // Solution
    /**
     * Sorting + Two Pointers
     *
     * Complexities:
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    int solution(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == target) {
                    return currentSum;
                }

                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};
