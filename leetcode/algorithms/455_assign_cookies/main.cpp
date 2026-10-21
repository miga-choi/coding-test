#include <algorithm> // std::sort
#include <cstddef>   // std::size_t
#include <vector>    // std::vector
using namespace std;

class AssignCookies {
public:
    /**
     * Sorting + Greedy
     *
     * Complexities:
     *   N - The Size of `g`
     *   M - The Size of `s`
     *   - Time Complexity: O(N * logᴺ + M * logᴹ)
     *   - Space Complexity: O(1)
     */
    int findContentChildren(vector<int>& g, vector<int>& s) {
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


    // Solution
    /**
     * Solution 1
     * 
     * Sorting + Greedy
     *
     * Complexities:
     *   N - The Size of `g`
     *   M - The Size of `s`
     *   - Time Complexity: O(N * logᴺ + M * logᴹ)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        size_t i = 0;
        for (int cookie : s) {
            if (i == g.size()) {
                break;
            }
            if (cookie >= g[i]) {
                ++i;
            }
        }

        return static_cast<int>(i);
    }

    /**
     * Solution 2
     * 
     * Sorting + Greedy
     *
     * Complexities:
     *   N - The Size of `g`
     *   M - The Size of `s`
     *   - Time Complexity: O(N * logᴺ + M * logᴹ)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = static_cast<int>(s.size()) - 1;
        int count = 0;
        for (int i = static_cast<int>(g.size()) - 1; i >= 0 && j >= 0; --i) {
            if (s[j] >= g[i]) {
                ++count;
                --j;
            }
        }

        return count;
    }
};
