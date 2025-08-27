#include <string>
#include <vector>
using namespace std;

class FindTheIndexOfTheFirstOccurrenceInAString {
public:
    /**
     * Brute-Force
     * - Time Complexity: O(N * M)
     * - Space Complexity: O(1)
     */
    int strStr(string haystack, string needle) {
        int haystack_len = haystack.size();
        int needle_len = needle.size();

        if (needle_len > haystack_len) {
            return -1;
        }

        for (int haystack_idx = 0; haystack_idx < haystack_len; haystack_idx++) {
            bool is_match = true;

            for (int needle_idx = 0; needle_idx < needle_len; needle_idx++) {
                if (haystack[haystack_idx + needle_idx] != needle[needle_idx]) {
                    is_match = false;
                    break;
                }
            }

            if (is_match) {
                return haystack_idx;
            }
        }

        return -1;
    }


    // Solution
    /**
     * Solution 1
     * 
     * std::string::find()
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int solution1(string haystack, string needle) {
        size_t found_pos = haystack.find(needle);

        if (found_pos == string::npos) {
            return -1;
        }

        return static_cast<int>(found_pos);
    }

    /**
     * Solution 2
     * 
     * Brute-Force
     * - Time Complexity: O(N * M)
     * - Space Complexity: O(1)
     */
    int strStr(string haystack, string needle) {
        int haystack_len = haystack.length();
        int needle_len = needle.length();

        if (haystack_len < needle_len) {
            return -1;
        }

        for (int haystack_idx = 0; haystack_idx <= haystack_len - needle_len; ++haystack_idx) {
            int needle_idx = 0;

            for (; needle_idx < needle_len; ++needle_idx) {
                if (haystack[haystack_idx + needle_idx] != needle[needle_idx]) {
                    break;
                }
            }

            if (needle_idx == needle_len) {
                return haystack_idx;
            }
        }

        return -1;
    }

    /**
     * Solution3
     * 
     * Knuth-Morris-Pratt (KMP)
     * - Time Complexity: O(N + M)
     * - Space Complexity: O(M)
     */
    vector<int> compute_lps_array(const string& pattern) {
        int pattern_len = pattern.length();
        vector<int> lps(pattern_len, 0);
        int length = 0;
        int idx = 1;

        while (idx < pattern_len) {
            if (pattern[idx] == pattern[length]) {
                length++;
                lps[idx] = length;
                idx++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[idx] = 0;
                    idx++;
                }
            }
        }

        return lps;
    }

    int solution3(string haystack, string needle) {
        int haystack_len = haystack.size();
        int needle_len = needle.size();

        if (haystack_len < needle_len) {
            return -1;
        }

        vector<int> lps = compute_lps_array(needle);

        for (int haystack_idx = 0, needle_idx = 0; haystack_idx < haystack_len;) {
            if (haystack[haystack_idx] == needle[needle_idx]) {
                haystack_idx++, needle_idx++;
            }

            if (needle_idx == needle_len) {
                return haystack_idx - needle_idx;
            }

            if (haystack_idx < haystack_len && haystack[haystack_idx] != needle[needle_idx]) {
                needle_idx ? needle_idx = lps[needle_idx - 1] : haystack_idx++;
            }
        }

        return -1;
    }
};
