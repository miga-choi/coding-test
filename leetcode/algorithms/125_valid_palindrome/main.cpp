#include <cctype>
#include <string>
using namespace std;

class ValidPalindrome {
public:
    bool isPalindrome(string s) {
        int prefix = 0;
        int suffix = s.size() - 1;

        while (prefix < suffix) {
            char prefixChar = s[prefix];
            char suffixChar = s[suffix];

            if (!((prefixChar >= '0' && prefixChar <= '9') ||
                  (prefixChar >= 'A' && prefixChar <= 'Z') ||
                  (prefixChar >= 'a' && prefixChar <= 'z'))) {
                prefix++;
                continue;
            }
            if (!((suffixChar >= '0' && suffixChar <= '9') ||
                  (suffixChar >= 'A' && suffixChar <= 'Z') ||
                  (suffixChar >= 'a' && suffixChar <= 'z'))) {
                suffix--;
                continue;
            }

            if (tolower(prefixChar) != tolower(suffixChar)) {
                return false;
            }

            prefix++;
            suffix--;
        }

        return true;
    }


    // Solution
    bool solution(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }
};
