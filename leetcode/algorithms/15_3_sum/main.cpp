#include <vector>
using namespace std;

class ThreeSum {
public:
    /**
     * Sort + Two-pointer
     * - Time Complexity: O(N²)
     * - Space Complexity: O(logᴺ)
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int nums_size = nums.size();

        for (int flag = 0; flag < nums_size - 2; flag++) {
            if (flag > 0 && nums[flag] == nums[flag - 1]) {
                continue;
            }

            int left = flag + 1;
            int right = nums_size - 1;

            while (left < right) {
                int sum = nums[flag] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[flag], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Sort + Two-pointer
     * - Time Complexity: O(N²)
     * - Space Complexity: O(logᴺ)
     */
    vector<vector<int>> solution(vector<int>& nums) {
        vector<vector<int>> result;

        int n = nums.size();

        if (n < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};
