#include <string>
using namespace std;

class LicenseKeyFormatting {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int j = 1;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if ((j % (k + 1)) == 0) {
                    result += "-";
                    i++;
                } else {
                    result += toupper(s[i]);
                }
                j++;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }


    // Solution
    string solution(string s, int k) {
        string res;

        for (auto i = s.rbegin(); i < s.rend(); i++) {
            // ignore '-' in original string
            if (*i != '-') {
                if (res.size() % (k + 1) == k) {
                    // every (K+1)th char is '-' from tail
                    res += '-';
                }
                res += toupper(*i);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
