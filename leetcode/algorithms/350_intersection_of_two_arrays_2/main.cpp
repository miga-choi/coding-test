#include <algorithm>     // std::sort, std::set_intersection
#include <array>         // std::array
#include <iterator>      // std::back_inserter
#include <unordered_map> // std::unordered_map
#include <vector>        // std::vector
using namespace std;

class IntersectionOfTwoArraysII {
public:
    /**
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(N + M)
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] != -1 && nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    nums1[i] = -1;
                    nums2[j] = -1;
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Counting Array
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(1)
     */
    vector<int> solution1(vector<int>& nums1, vector<int>& nums2) {
        array<int, 1001> cnt{};

        for (int v : nums1) cnt[v]++;

        vector<int> res;
        for (int v : nums2) {
            if (cnt[v] > 0) {
                res.push_back(v);
                cnt[v]--;
            }
        }

        return res;
    }

    /**
     * Solution 2
     *
     * unordered_map
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(1)
     */
    vector<int> solution2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (int v : nums1) {
            cnt[v]++;
        }

        vector<int> res;
        for (int v : nums2) {
            auto it = cnt.find(v);
            if (it != cnt.end() && it->second > 0) {
                res.push_back(v);
                --it->second;
            }
        }

        return res;
    }

    /**
     * Solution 3
     *
     * Sorting + Two Pointers
     *
     * Complexities:
     *   N - The size of `nums1`
     *   M - The size of `nums2`
     *   - Time Complexity: O(N * logᴺ + M * logᴹ)
     *   - Space Complexity: O(1)
     */
    vector<int> solution3(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        set_intersection(nums1.begin(), nums1.end(),
                         nums2.begin(), nums2.end(),
                         back_inserter(res));

        return res;
    }
};
