#include <algorithm>
#include <string>
using namespace std;

class LongestUncommonSubsequenceI {
public:
    int findLUSlength(string a, string b) {
        if (a != b) {
            return max(a.size(), b.size());
        }
        return -1;
    }

    // Solution
    int solution(string a, string b) {
        if (a == b) {
            return -1;
        }
        return max(a.size(), b.size());
    }
};
