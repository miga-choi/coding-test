#include <string>
#include <vector>
using namespace std;

class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0;; i++) {
            if (strs[0][i] == '\0') {
                return strs[0];
            }
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
    }


    // Solution
    // Solution 1
    string solution1(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }

    // Solution 2
    string solution2(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        }

        string ans = "";
        sort(begin(strs), end(strs));
        string a = strs[0];
        string b = strs[n - 1];

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) {
                ans = ans + a[i];
            } else {
                break;
            }
        }

        return ans;
    }
};
