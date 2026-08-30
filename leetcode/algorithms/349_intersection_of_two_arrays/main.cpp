#include <algorithm>     // std::set_intersection, std::sort, std::unique
#include <array>         // std::array
#include <iterator>      // std::back_inserter
#include <map>           // std::map
#include <unordered_set> // std::unordered_set
#include <vector>        // std::vector
using namespace std;

class IntersectionOfTwoArrays {
public:
    /**
     * std::map
     *
     * Complexities:
     *   K - The size of `map`
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(K)
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, bool> numsMap;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[i] && !numsMap[nums1[i]]) {
                    result.push_back(nums1[i]);
                    numsMap[nums1[i]] = true;
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Lookup table
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(1)
     */
    vector<int> solution1(vector<int>& nums1, vector<int>& nums2) {
        array<bool, 1001> seen{};

        for (int v : nums1) seen[v] = true;

        vector<int> res;
        for (int v : nums2) {
            if (seen[v]) {
                res.push_back(v);
                seen[v] = false;
            }
        }

        return res;
    }

    /**
     * Solution 2
     *
     * std::unordered_set
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   K - The size of `unordered_set`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(K)
     */
    vector<int> solution2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());

        vector<int> res;
        for (int v : nums2) {
            if (s.erase(v)){
                res.push_back(v);
            }
        }

        return res;
    }

    /**
     * Solution 3
     *
     * std::unordered_set
     *
     * Complexities:
     *   N - The size of `unordered_set`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N * logᴺ + M * logᴹ)
     *   - Space Complexity: O(1)
     */
    vector<int> solution3(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(res));

        res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }
};
