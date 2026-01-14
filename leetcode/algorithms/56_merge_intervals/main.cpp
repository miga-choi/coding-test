#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Sorting
     *
     * Complexities:
     *   N - Size of in `intervals`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(N)
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = result[result.size() - 1];
            vector<int>& curr = intervals[i];

            if (last[1] >= curr[0]) {
                if (last[1] < curr[1]) {
                    last[1] = curr[1];
                }
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }


    // Solution
    /**
     * Sorting
     *
     * Complexities:
     *   N - Size of in `intervals`
     *   - Time Complexity: O(N * logᴺ)
     *   - Space Complexity: O(N)
     */
    vector<vector<int>> solution(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (merged.back()[1] >= intervals[i][0]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
