#include <string>
#include <vector>
using namespace std;

class SummaryRanges {
public:
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> stringVector;

        if (nums.size() > 0) {
            int begin = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                if ((nums[i] - 1) > nums[i - 1]) {
                    if (begin < nums[i - 1]) {
                        stringVector.push_back(to_string(begin) + "->" + to_string(nums[i - 1]));
                    } else {
                        stringVector.push_back(to_string(begin));
                    }
                    begin = nums[i];
                }
            }

            if (begin < nums[nums.size() - 1]) {
                stringVector.push_back(to_string(begin) + "->" + to_string(nums[nums.size() - 1]));
            } else {
                stringVector.push_back(to_string(begin));
            }
        }

        return stringVector;
    }


    // Solution
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - Size of `nums`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    vector<string> solution(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        
        if (n == 0) {
            return result;
        }

        int i = 0;
        while (i < n) {
            int start = i;

            while (i + 1 < n && (long long)nums[i + 1] - nums[i] == 1) {
                i++;
            }
            int end = i;

            if (start == end) {
                result.push_back(to_string(nums[start]));
            } else {
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }

            i++;
        }

        return result;
    }
};
