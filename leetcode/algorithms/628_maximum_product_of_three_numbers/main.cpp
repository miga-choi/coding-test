#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class MaximumProductOfThreeNumbers {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1000, max2 = -1000, max3 = -1000;
        int min1 = 1000, min2 = 1000;

        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }

            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }

    // Solution 1: Sorting
    int solution1(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                   nums[0] * nums[1] * nums[n - 1]);
    }

    // Solution 2
    int solution2(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] <= min2) {
                min2 = nums[i];
            }
            if (nums[i] >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] >= max2) {
                max3 = max2;
                max2 = nums[i];
            } else if (nums[i] >= max3) {
                max3 = nums[i];
            }
        }

        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
