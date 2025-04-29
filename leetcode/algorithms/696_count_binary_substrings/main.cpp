#include <algorithm>
#include <string>
using namespace std;

class CountBinarySubstrings {
public:
    int countBinarySubstrings(string s) {
        int count = 1;
        int prevCount = 0;
        int result = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s.at(i) == s.at(i - 1)) {
                count++;
            } else {
                if (count < prevCount) {
                    result += count;
                } else {
                    result += prevCount;
                }
                prevCount = count;
                count = 1;
            }
        }

        if (count < prevCount) {
            result += count;
        } else {
            result += prevCount;
        }

        return result;
    }


    // Solution
    int solution(string s) {
        int cur = 1, pre = 0, res = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }

        return res + min(cur, pre);
    }
};
