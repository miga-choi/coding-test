#include <array>      // std::array
#include <functional> // std::bit_xor
#include <numeric>    // std::accumulate
#include <string>     // std::string
using namespace std;

class FindTheDifference {
public:
    /**
     * Counting Array
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    char findTheDifference(string s, string t) {
        int alphabetNumArray[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            alphabetNumArray[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            if (alphabetNumArray[t[i] - 'a'] == 0) {
                return t[i];
            } else {
                alphabetNumArray[t[i] - 'a']--;
            }
        }

        return ' ';
    }


    // Solution
    /**
     * Solution 1
     *
     * Counting Array
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    char solution1(string s, string t) {
        array<int, 26> cnt{};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (char c : t) {
            if (--cnt[c - 'a'] < 0) {
                return c;
            }
        }

        return 0;
    }

    /**
     * Solution 2
     *
     * XOR
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    char solution2(string s, string t) {
        char x = 0;

        for (char c : s) {
            x ^= c;
        }
        for (char c : t) {
            x ^= c;
        }

        return x;
    }

    /**
     * Solution 3
     *
     * std::accumulate
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    char solution3(string s, string t) {
        int sum = std::accumulate(t.begin(), t.end(), 0) - accumulate(s.begin(), s.end(), 0);
        return static_cast<char>(sum);
    }

    /**
     * Solution 4
     *
     * std::accumulate + std::bit_xor
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    char solution4(string s, string t) {
        return accumulate(
            s.begin(),
            s.end(),
            accumulate(t.begin(), t.end(), char{0}, bit_xor<char>{}),
            bit_xor<char>{}
        );
    }
};
