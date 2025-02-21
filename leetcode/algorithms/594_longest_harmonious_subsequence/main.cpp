#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class LongestHarmoniousSubsequence {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int result = 0, leftPin = 0, rightPin = 1;

        while (rightPin < nums.size()) {
            int diff = nums.at(rightPin) - nums.at(leftPin);
            if (diff == 1) {
                result = max(rightPin - leftPin + 1, result);
                rightPin++;
            } else if (diff == 0) {
                rightPin++;
            } else {
                leftPin++;
            }
        }

        return result;
    }

    // Solution 1: Using Map
    int solution1(vector<int>& nums) {
        unordered_map<int, int> m;

        for (int i : nums) {
            m[i]++;
        }

        int res = 0;

        for (pair<int, int> it : m) {
            if (m.count(it.first - 1) > 0) {
                res = max(res, it.second + m[it.first - 1]);
            }
        }

        return res;
    }

    // Solution 2: Using Map
    int solution2(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;

        for (int i : nums) {
            m[i]++;
            if (m.count(i + 1)) {
                res = max(res, m[i] + m[i + 1]);
            }
            if (m.count(i - 1)) {
                res = max(res, m[i] + m[i - 1]);
            }
        }

        return res;
    }

    // Solution 3: Sorting
    int solution3(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = 0;

        for (int i = 1, start = 0, new_start = 0; i < nums.size(); i++) {
            if (nums[i] - nums[start] > 1) {
                start = new_start;
            }
            if (nums[i] != nums[i - 1]) {
                new_start = i;
            }
            if (nums[i] - nums[start] == 1) {
                len = max(len, i - start + 1);
            }
        }

        return len;
    }
};
