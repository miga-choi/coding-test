#include <algorithm>
#include <string>
using namespace std;

class ReverseStringII {
public:
    void swap(string &s, int l, int r) {
        while (l < r) {
            char temp = s[l];
            s[l++] = s[r];
            s[r--] = temp;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i + k - 1 < n - 1 ? i + k - 1 : n - 1;
            swap(s, i, j);
            i += 2 * k;
        }

        return s;
    }

    // Solution
    string solution(string s, int k) {
        int sLength = s.size();
        for (int start = 0; start < sLength; start += 2 * k) {
            int i = start, j = min(start + k - 1, sLength - 1);
            while (i < j) {
                char tmp = s[i];
                s[i++] = s[j];
                s[j--] = tmp;
            }
        }
        return s;
    }
};
