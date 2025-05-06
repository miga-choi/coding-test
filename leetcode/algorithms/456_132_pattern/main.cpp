#include <limits>
#include <stack>
#include <vector>
using namespace std;

class OneThreeTwoPattern {
public:
    bool find132pattern(vector<int> &nums) {
        int peak = nums.size();
        int min = INT_MIN;

        for (int i = nums.size() - 1; i > -1; i--) {
            if (nums[i] < min) {
                return true;
            }
            while (peak < nums.size() && nums[i] > nums[peak]) {
                min = nums[peak];
                peak++;
            }
            peak--;
            nums[peak] = nums[i];
        }

        return false;
    }


    // Solution
    bool solution(vector<int> &nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < s3) {
                return true;
            } else {
                while (!st.empty() && nums[i] > st.top()) {
                    s3 = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};
