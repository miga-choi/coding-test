#include <string>
#include <vector>
using namespace std;

class FindTheIndexOfTheFirstOccurrenceInAString {
public:
    /**
     * Brute Force, Sliding Window
     *
     * Complexities:
     *   N - Length of `haystack`
     *   M - Length of `needle`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(1)
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
     * Brute Force, Sliding Window 
     *
     * Complexities:
     *   N - Length of `haystack`
     *   M - Length of `needle`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(1)
     */
    int solution1(string haystack, string needle) {
        int h_len = haystack.length();
        int n_len = needle.length();

        if (h_len < n_len) {
            return -1;
        }

        for (int i = 0; i <= h_len - n_len; ++i) {
            int j = 0;
            
            for (; j < n_len; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }

            if (j == n_len) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Solution 2
     * 
     * string::find
     *
     * Complexities:
     *   N - Length of `haystack`
     *   M - Length of `needle`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(1)
     */
    int solution2(string haystack, string needle) {
        size_t found = haystack.find(needle);
        
        if (found != string::npos) {
            return (int)found;
        }
        
        return -1;
    }
};
