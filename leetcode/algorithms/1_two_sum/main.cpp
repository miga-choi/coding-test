#include <unordered_map>
#include <vector>
using namespace std;

class TwoSum {
public:
    /**
     * Brute-Force
     * 
     * Complexities:
     *   N - `nums`'s Size
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    vector<int> twoSum1(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }

    /**
     * unordered_map
     * 
     * Complexities:
     *   N - `nums`'s Size
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {i, map[complement]};
            }
            map[nums[i]] = i;
        }

        return {};
    }


    // Solution
    /**
     * One-pass Hash Table
     * 
     * Complexities:
     *   N - `nums`'s Size
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> solution(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }

            numMap[nums[i]] = i;
        }

        return {};
    }
};
