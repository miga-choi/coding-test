#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class LongestSubstringWithoutRepeatingCharacters {
public:
    /**
     * Sliding Window (Using Vector)
     *
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O()
     */
    int lengthOfLongestSubstring(string s) {
        vector<int> charMap(128, -1);
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];

            if (charMap[currentChar] >= left) {
                left = charMap[currentChar] + 1;
            }

            charMap[currentChar] = right;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }


    // Solution
    /**
     * Sliding Window (Using Vector)
     *
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution(string s) {
        vector<int> charIndexMap(128, -1);
        
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            if (charIndexMap[currentChar] >= left) {
                left = charIndexMap[currentChar] + 1;
            }

            charIndexMap[currentChar] = right;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
 