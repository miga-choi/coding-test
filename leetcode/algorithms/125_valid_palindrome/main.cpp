#include <cctype>
#include <string>
using namespace std;

class ValidPalindrome {
public:
    /**
     * Two-Pointer
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    bool isPalindrome(string s) {
        int prefix = 0;
        int suffix = s.size() - 1;

        while (prefix < suffix) {
            char prefix_char = s[prefix];
            char suffix_char = s[suffix];

            if (!isalnum(prefix_char)) {
                prefix++;
                continue;
            }
            if (!isalnum(suffix_char)) {
                suffix--;
                continue;
            }

            if (tolower(prefix_char) != tolower(suffix_char)) {
                return false;
            }

            prefix++;
            suffix--;
        }

        return true;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Two-Pointer
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    bool solution1(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    /**
     * Solution 2
     * 
     * Compare two strings
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    bool solution2(string s) {
        string filtered_s;

        for (char c : s) {
            if (isalnum(c)) {
                filtered_s += tolower(c);
            }
        }

        return equal(filtered_s.begin(),
                     filtered_s.begin() + filtered_s.size() / 2,
                     filtered_s.rbegin());
    }
};
