#include <algorithm>
#include <vector>
using namespace std;

class LongestContinuousIncreasingSubsequence {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1, count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i) > nums.at(i - 1)) {
                count++;
                if (count > res) {
                    res = count;
                }
            } else {
                count = 1;
            }
        }
        return res;
    }

    // Solution
    int solution(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i - 1] < nums[i]) {
                res = max(res, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return res;
    }
};
