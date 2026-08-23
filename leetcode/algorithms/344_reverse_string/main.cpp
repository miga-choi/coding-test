#include <algorithm> // std::reverse
#include <utility>   // std::swap
#include <vector>    // std::vector
using namespace std;

class ReverseString {
public:
    /**
     * Two pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
    }


    // Solution
    /**
     * Solution 1
     *
     * Two pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    void solution1(vector<char>& s) {
        for (int left = 0, right = s.size() - 1; left < right; ++left, --right) {
            swap(s[left], s[right]);
        }
    }

    /**
     * Solution 2
     *
     * std::reverse
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    void solution2(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
