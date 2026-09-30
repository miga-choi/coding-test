#include <array>   // std::array
#include <bit>     // std::popcount (C++20)
#include <cstdint> // std::uint64_t
#include <string>  // std::string
using namespace std;

class LongestPalindrome {
public:
    /**
     * Counting Array
     * 
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int longestPalindrome(string s) {
        int alphabetNumArray[52] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) < 97) {
                alphabetNumArray[s.at(i) - 'A']++;
            } else {
                alphabetNumArray[s.at(i) - 'a' + 26]++;
            }
        }

        int count = 0;
        int hasOdd = 0;
        for (int i = 0; i < 52; i++) {
            if (alphabetNumArray[i] % 2) {
                hasOdd = 1;
            }
            count += alphabetNumArray[i] / 2;
        }

        return count * 2 + hasOdd;
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
    int solution1(string s) {
        array<int, 128> cnt{};
        for (char c : s) {
            cnt[static_cast<unsigned char>(c)]++;
        }

        int len = 0;
        bool hasOdd = false;

        for (int x : cnt) {
            len += x / 2 * 2;

            if (x % 2 == 1) {
                hasOdd = true;
            }
        }

        return len + (hasOdd ? 1 : 0);
    }

    /**
     * Solution 2
     *
     * Count The Odd Numbers
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution2(string s) {
        std::array<bool, 128> odd{};
        int oddCnt = 0;

        for (char ch : s) {
            auto c = static_cast<unsigned char>(ch);
            odd[c] = !odd[c];
            oddCnt += odd[c] ? 1 : -1;
        }

        int n = static_cast<int>(s.size());
        return oddCnt > 0 ? n - oddCnt + 1 : n;
    }

    /**
     * Solution 3
     *
     * 64-bit Mask
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution3(string s) {
        uint64_t mask = 0;
        for (char c : s) {
            mask ^= uint64_t{1} << (c - 'A');
        }

        int oddCnt = popcount(mask);
        int n = static_cast<int>(s.size());

        return oddCnt > 0 ? n - oddCnt + 1 : n;
    }
};
