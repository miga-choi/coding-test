#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

class IntersectionOfTwoArrays {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
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
    vector<int> solution(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;

        for (auto a : nums2) {
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        }

        return res;
    }
};
