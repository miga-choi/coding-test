#include <algorithm> // std::find_if, std::min
#include <array>     // std::array
#include <limits>    // std::numeric_limits
#include <string>    // std::string
using namespace std;

class FirstUniqueCharacterInAString {
public:
    /**
     * Counting Array + Two-Pass
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int firstUniqChar(string s) {
        int alphabetNumArray[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            alphabetNumArray[s.at(i) - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (alphabetNumArray[s.at(i) - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }


    // Solution
    /**
     * Solution 1
     *
     * Counting Array + Two-Pass
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution1(string s) {
        array<int, 26> cnt{};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Solution 2
     * 
     * Counting Array +  std::find_if
     * 
     * Hash table
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int solution2(string s) {
        array<int, 26> cnt{};

        for (char c : s) {
            cnt[c - 'a']++;
        }
 
        auto it = find_if(s.begin(), s.end(), [&cnt](char c) { return cnt[c - 'a'] == 1; });

        return it == s.end() ? -1 : static_cast<int>(it - s.begin());
    }

    /**
     * Solution 3
     *
     * Counting Array + Indexing + 1.5-Pass
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution3(string s) {
        array<int, 26> first;
        array<int, 26> cnt{};
        first.fill(-1);

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            int c = s[i] - 'a';

            if (cnt[c] == 0) {
                first[c] = i;
            }

            cnt[c]++;
        }

        int ans = numeric_limits<int>::max();
        for (int c = 0; c < 26; ++c) {
            if (cnt[c] == 1) {
                ans = min(ans, first[c]);
            }
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};
