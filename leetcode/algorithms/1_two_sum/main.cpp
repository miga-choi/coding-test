#include <unordered_map>
#include <vector>
using namespace std;

class TwoSum {
public:
    /**
     * Brute-Force
     * - Time Complexity: O(N²)
     * - Space Complexity: O(1)
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
     * Unordered Map
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
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
    // Solution 1: Brute Force
    vector<int> solution1(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }

    // Solution 2: Two-pass Hash Table
    vector<int> solution2(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }

    // Solution 3: One-pass Hash Table
    vector<int> solution3(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};
