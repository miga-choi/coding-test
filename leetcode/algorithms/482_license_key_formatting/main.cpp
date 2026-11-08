#include <algorithm> // std::count, std::reverse
#include <cctype>    // std::toupper
#include <string>    // std::string
using namespace std;

class LicenseKeyFormatting {
public:
    /**
     * Reverse Traversal + Positional Dash Insertion + Reverse
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
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
    /**
     * Solution 1
     *
     * Reverse Traversal + Reverse
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    string solution1(string s, int k) {
        string res;
        int group = 0;

        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
            if (s[i] == '-') {
                continue;
            }

            if (group == k) {
                res.push_back('-');
                group = 0;
            }

            res.push_back(static_cast<char>(toupper(static_cast<unsigned char>(s[i]))));
            ++group;
        }

        reverse(res.begin(), res.end());

        return res;
    }

    /**
     * Solution 2
     *
     * Two-Pass + Backward Fill
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    string solution2(string s, int k) {
        int cnt = static_cast<int>(s.size() - count(s.begin(), s.end(), '-'));
        if (cnt == 0) {
            return "";
        }

        string res(cnt + (cnt - 1) / k, '-');
        int pos = static_cast<int>(res.size()) - 1, group = 0;

        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
            if (s[i] == '-') {
                continue;
            }

            if (group == k) {
                --pos;
                group = 0;
            }

            res[pos--] = static_cast<char>(toupper(static_cast<unsigned char>(s[i])));
            ++group;
        }

        return res;
    }

    /**
     * Solution 3
     *
     * Two-Pass + Forward Fill with First Group Size
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    string solution3(string s, int k) {
        int cnt = static_cast<int>(s.size() - count(s.begin(), s.end(), '-'));

        string res;
        res.reserve(cnt + (cnt > 0 ? (cnt - 1) / k : 0));

        int limit = cnt % k;
        if (limit == 0) {
            limit = k;
        }

        int group = 0;

        for (char c : s) {
            if (c == '-') {
                continue;
            }

            if (group == limit) {
                res.push_back('-');
                group = 0;
                limit = k;
            }

            res.push_back(static_cast<char>(toupper(static_cast<unsigned char>(c))));
            ++group;
        }

        return res;
    }
};
