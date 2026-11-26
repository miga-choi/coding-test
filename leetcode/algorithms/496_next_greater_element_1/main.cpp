#include <algorithm>     // std::find, std::find_if
#include <unordered_map> // std::unordered_map
#include <vector>        // std::vector
using namespace std;

class NextGreaterElementI {
public:
    /**
     * Brute Force with Found Flag
     *
     * Complexities:
     *   n - The Size of `nums1`
     *   m - The Size of `nums2`
     *   - Time Complexity: O(n * m)
     *   - Space Complexity: O(1)
     */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        vector<bool> numsBool(nums1.size(), false);

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (numsBool[i] && nums2[j] > nums1[i]) {
                    result[i] = nums2[j];
                    numsBool[i] = false;
                } else if (nums1[i] == nums2[j]) {
                    numsBool[i] = true;
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Brute Force with std::find
     *
     * Complexities:
     *   n - The Size of `nums1`
     *   m - The Size of `nums2`
     *   - Time Complexity: O(n * m)
     *   - Space Complexity: O(1)
     */
    vector<int> solution1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        res.reserve(nums1.size());

        for (int x : nums1) {
            auto pos = find(nums2.begin(), nums2.end(), x);
            auto nxt = find_if(pos + 1, nums2.end(), [x](int y) { return y > x; });
            res.push_back(nxt == nums2.end() ? -1 : *nxt);
        }

        return res;
    }

    /**
     * Solution 2
     *
     * Monotonic Stack + Hash Map
     *
     * Complexities:
     *   n - The Size of `nums1`
     *   m - The Size of `nums2`
     *   - Time Complexity: O(n + m)
     *   - Space Complexity: O(m)
     */
    vector<int> solution2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        next.reserve(nums2.size());
        vector<int> st;

        for (int x : nums2) {
            while (!st.empty() && st.back() < x) {
                next[st.back()] = x;
                st.pop_back();
            }
            st.push_back(x);
        }

        vector<int> res;
        res.reserve(nums1.size());
        for (int x : nums1) {
            auto it = next.find(x);
            res.push_back(it == next.end() ? -1 : it->second);
        }

        return res;
    }
};
