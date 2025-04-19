#include <string>
using namespace std;

class LengthOfLastWord {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        for (int i = s.size(); i >= 0; i--) {
            if (s[i] != ' ' && s[i] != '\0') {
                result++;
            } else if (s[i] = ' ' && result > 0) {
                break;
            }
        }

        return result;
    }


    // Solution
    // Solution 1:
    int solution1(string s) {
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') {
            tail--;
        }
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }

    // Solution 2:
    int solution2(string s) {
        int siz = s.size(), kount = 0, flag = 0;
        for (int i = siz - 1; i >= 0; i--) {
            if (s[i] == ' ' && flag) {
                break;
            }
            if (s[i] != ' ') {
                flag = 1;
                kount++;
            }
        }
        return kount;
    }

    // Solution 3:
    int solution3(string s) {
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ' && ans > 0) {
                return ans;
            }
            if (s[i] != ' ') {
                ans++;
            }
        }
        return ans;
    }
};
