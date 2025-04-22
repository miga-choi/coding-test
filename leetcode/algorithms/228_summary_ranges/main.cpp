#include <string>
#include <vector>
using namespace std;

class SummaryRanges {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> stringVector;

        if (nums.size() > 0) {
            int begin = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                if ((nums[i] - 1) > nums[i - 1]) {
                    if (begin < nums[i - 1]) {
                        stringVector.push_back(to_string(begin) + "->" + to_string(nums[i - 1]));
                    } else {
                        stringVector.push_back(to_string(begin));
                    }
                    begin = nums[i];
                }
            }

            if (begin < nums[nums.size() - 1]) {
                stringVector.push_back(to_string(begin) + "->" + to_string(nums[nums.size() - 1]));
            } else {
                stringVector.push_back(to_string(begin));
            }
        }

        return stringVector;
    }


    // Solution
    // Solution 1
    vector<string> solution1(vector<int>& nums) {
        // extracting size of the array
        int n = nums.size();

        // declaring answer array to store our answer
        vector<string> ans;

        // temproray string that stores all possible answer
        string temp = "";

        // start traversing from the array
        for (int i = 0; i < n; i++) {
            // declare anthor pointer that will move
            int j = i;

            // run that pointer until our range is not break
            while (j + 1 < n && nums[j + 1] == nums[j] + 1) {
                j++;
            }

            // if j > i, that means we got our range more than one element
            if (j > i) {
                // first store starting point
                temp += to_string(nums[i]);

                // then store arrow, as question wants it
                temp += "->";

                // and lastly store the end point
                temp += to_string(nums[j]);
            }
            // we got only one element as range
            else {
                // then store that element in temp
                temp += to_string(nums[i]);
            }

            // push one possible answer string to our answer
            ans.push_back(temp);

            // again reintiliaze temp for new possible answers
            temp = "";

            // and move i to j for a fresh start
            i = j;
        }

        // and at last finally return the answer array
        return ans;
    }

    // Solution 2
    vector<string> solution2(vector<int>& nums) {
        const int size_n = nums.size();
        vector<string> res;
        if (0 == size_n) {
            return res;
        }
        for (int i = 0; i < size_n;) {
            int start = i, end = i;
            while (end + 1 < size_n && nums[end + 1] == nums[end] + 1) {
                end++;
            }
            if (end > start) {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            } else {
                res.push_back(to_string(nums[start]));
            }
            i = end + 1;
        }
        return res;
    }
};
