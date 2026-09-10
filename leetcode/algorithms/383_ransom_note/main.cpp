#include <algorithm>     // std::none_of
#include <array>         // std::array
#include <string>        // std::string
#include <unordered_map> // std::unordered_map
using namespace std;

class RansomNote {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alphabet[26] = {0};

        for (char c : magazine) {
            alphabet[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (alphabet[c - 'a'] > 0) {
                alphabet[c - 'a']--;
            } else {
                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Solution 1
     *
     * Counting Array
     *
     * Complexities:
     *   N - The size of `ransomNote`
     *   M - The size of `magazine`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(1)
     */
    bool solution1(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        array<int, 26> cnt{};

        for (char c : magazine) {
            cnt[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (--cnt[c - 'a'] < 0) return false;
        }

        return true;
    }

    /**
     * Solution 2
     *
     * unordered_map
     *
     * Complexities:
     *   N - The size of `ransomNote`
     *   M - The size of `magazine`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(1)
     */
    bool solution2(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        unordered_map<char, int> cnt;

        for (char c : magazine) {
            cnt[c]++;
        }

        for (char c : ransomNote) {
            auto it = cnt.find(c);

            if (it == cnt.end() || it->second == 0) {
                return false;
            }

            --it->second;
        }

        return true;
    }

    /**
     * Solution 3
     *
     * Complexities:
     *   N - The size of `ransomNote`
     *   M - The size of `magazine`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(1)
     */
    bool solution3(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        array<int, 26> cnt{};

        for (char c : magazine) {
            cnt[c - 'a']++;
        }
        for (char c : ransomNote) {
            cnt[c - 'a']--;
        }

        return none_of(cnt.begin(), cnt.end(), [](int x) { return x < 0; });
    }
};
