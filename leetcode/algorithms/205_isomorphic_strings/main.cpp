#include <string>
#include <vector>
using namespace std;

class RemoveLinkedListElements {
public:
    /**
     * Complexities:
     *   N - Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    bool isIsomorphic(string s, string t) {
        char sCharArray[256] = {0};
        char tCharArray[256] = {0};

        for (int i = 0; s[i] != '\0' && t[i] != '\0'; i++) {
            if (sCharArray[s[i]] == 0 && tCharArray[t[i]] == 0) {
                sCharArray[s[i]] = t[i];
                tCharArray[t[i]] = s[i];
            } else if (sCharArray[s[i]] != t[i] || tCharArray[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Complexities:
     *   N - Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    bool solution1(string s, string t) {
        vector<int> posS(256, 0);
        vector<int> posT(256, 0);

        for (int i = 0; i < s.length(); ++i) {
            unsigned char charS = s[i];
            unsigned char charT = t[i];

            if (posS[charS] != posT[charT]) {
                return false;
            }

            posS[charS] = i + 1;
            posT[charT] = i + 1;
        }

        return true;
    }

    /**
     * Solution 2
     * 
     * Complexities:
     *   N - Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    bool solution2(string s, string t) {
        char mapS[256] = {0};
        char mapT[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            unsigned char charS = s[i];
            unsigned char charT = t[i];

            if (mapS[charS] == 0 && mapT[charT] == 0) {
                mapS[charS] = charT;
                mapT[charT] = charS;
            } else if (mapS[charS] != charT || mapT[charT] != charS) {
                return false;
            }
        }

        return true;
    }
};
