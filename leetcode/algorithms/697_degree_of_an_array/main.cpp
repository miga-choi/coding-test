#include <unordered_map>
#include <vector>
using namespace std;

class DegreeOfAnArray {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> numCountMap;
        unordered_map<int, int> numLeftMap;
        unordered_map<int, int> numRightMap;

        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (numLeftMap.count(nums[i]) == 0) {
                numLeftMap[nums[i]] = i;
            }
            numCountMap[nums[i]]++;
            if (numCountMap[nums[i]] > maxCount) {
                maxCount = numCountMap[nums[i]];
            }
            numRightMap[nums[i]] = i;
        }

        int minSubarrayLength = nums.size();
        for (int num : nums) {
            if (numCountMap[num] == maxCount) {
                int length = numRightMap[num] - numLeftMap[num];
                if (length < minSubarrayLength) {
                    minSubarrayLength = length;
                }
            }
        }

        return minSubarrayLength + 1;
    }


    // Solution
    int findShortestSubArray(vector<int>& A) {
        unordered_map<int, int> count, first;
        int res = 0, degree = 0;

        for (int i = 0; i < A.size(); ++i) {
            if (first.count(A[i]) == 0) {
                first[A[i]] = i;
            }
            if (++count[A[i]] > degree) {
                degree = count[A[i]];
                res = i - first[A[i]] + 1;
            } else if (count[A[i]] == degree) {
                res = min(res, i - first[A[i]] + 1);
            }
        }

        return res;
    }
};
