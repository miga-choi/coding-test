#include <vector>
using namespace std;

class AssignCookies {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;

        for (int j = 0; i < g.size() && j < s.size(); j++) {
            if (g[i] <= s[j]) {
                i++;
            }
        }

        return i;
    }

    // Best Solution
    int bestSolution(vector<int> &g, vector<int> &s) {
        int cookiesNums = s.size();

        if (cookiesNums == 0) {
            return 0;
        }

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0;
        int cookieIndex = cookiesNums - 1;
        int childIndex = g.size() - 1;

        while (cookieIndex >= 0 && childIndex >= 0) {
            if (s[cookieIndex] >= g[childIndex]) {
                maxNum++;
                cookieIndex--;
                childIndex--;
            } else {
                childIndex--;
            }
        }

        return maxNum;
    }
};
