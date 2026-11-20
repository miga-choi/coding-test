#include <algorithm>   // std::all_of, std::any_of
#include <array>       // std::array
#include <cctype>      // std::tolower
#include <string>      // std::string
#include <string_view> // std::string_view
#include <vector>      // std::vector
using namespace std;

class KeyboardRow {
public:
    /**
     * Row Lookup Table + First-Letter Row Check
     *
     * Complexities:
     *   i - Length of iᵗʰ Word in `words`
     *   - Time Complexity: O(Σ lenᵢ²)
     *   - Space Complexity: O(1)
     */
    vector<string> findWords(vector<string>& words) {
        int alphabetRowNum[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            int row = 0;

            for (int j = 0; j < words[i].size(); j++) {
                if (row) {
                    if (alphabetRowNum[words[i][j] < 'a' ? words[i][j] - 'A' : words[i][j] - 'a'] == row) {
                        if (j == words[i].size() - 1) {
                            result.push_back(words[i]);
                        }
                    } else {
                        break;
                    }
                } else {
                    row = alphabetRowNum[words[i][j] < 'a' ? words[i][j] - 'A' : words[i][j] - 'a'];
                    j--;
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Row Lookup Table
     *
     * Complexities:
     *   n - Sum of The Number of Characters in `words`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    static int idx(char c) {
        return tolower(static_cast<unsigned char>(c)) - 'a';
    }

    vector<string> solution1(vector<string>& words) {
        static const char* ROWS[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        array<int, 26> row{};
        for (int r = 0; r < 3; ++r) {
            for (const char* p = ROWS[r]; *p; ++p) {
                row[*p - 'a'] = r;
            }
        }

        vector<string> res;
        for (const auto& w : words) {
            int r = row[idx(w[0])];
            if (all_of(w.begin(), w.end(), [&](char c) { return row[idx(c)] == r; })) {
                res.push_back(w);
            }
        }

        return res;
    }

    /**
     * Solution 2
     *
     * Row Bitmask
     *
     * Complexities:
     *   n - Sum of The Number of Characters in `words`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    static unsigned int toMask(string_view s) {
        unsigned int m = 0;

        for (char c : s) {
            m |= 1u << (tolower(static_cast<unsigned char>(c)) - 'a');
        }

        return m;
    }

    vector<string> solution2(vector<string>& words) {
        const array<unsigned int, 3> rowMask = { toMask("qwertyuiop"), toMask("asdfghjkl"), toMask("zxcvbnm")};

        vector<string> res;
        for (const auto& w : words) {
            unsigned int m = toMask(w);
            if (any_of(rowMask.begin(), rowMask.end(), [m](unsigned int r) { return (m & ~r) == 0; })) {
                res.push_back(w);
            }
        }

        return res;
    }
};
