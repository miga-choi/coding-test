#include <algorithm>
#include <vector>
using namespace std;

class MaxConsecutiveOnes {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int max = 0;
        int current = 0;

        for (int num : nums) {
            if (num > 0) {
                current++;
                if (current > max) {
                    max = current;
                }
            } else {
                current = 0;
            }
        }

        return max;
    }


    // Solution
    int solution(vector<int> &nums) {
        int max_cnt = 0, cnt = 0;

        for (int n : nums) {
            if (n == 1) {
                max_cnt = max(++cnt, max_cnt);
            } else {
                cnt = 0;
            }
        }

        return max_cnt;
    }
};
