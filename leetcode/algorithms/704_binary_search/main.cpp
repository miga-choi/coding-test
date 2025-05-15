#include <vector>
using namespace std;

class BinarySearch {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }


    // Solution
    int solution(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;

            if (target < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }

        return nums[lo] == target ? lo : -1;
    }
};
