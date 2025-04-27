#include <map>
#include <vector>
using namespace std;

class IntersectionOfTwoArraysII {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
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
    // Solution 1: Using map without sort
    vector<int> solution1(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> freq;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            freq[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (freq[nums2[i]] > 0) {
                freq[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }

    // Solution2: Two pointer with sort
    vector<int> solution2(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> res;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            }
        }

        return res;
    }
};
