#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class NextGreaterElementI {
public:
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
    vector<int> solution(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums2) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : nums1) {
            ans.push_back(m.count(n) ? m[n] : -1);
        }
        return ans;
    }
};
