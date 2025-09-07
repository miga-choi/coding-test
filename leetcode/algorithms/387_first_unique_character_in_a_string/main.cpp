#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class FirstUniqueCharacterInAString {
public:
    /**
     * Frequency Counter
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int firstUniqChar(string s) {
        int alphabetNumArray[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            alphabetNumArray[s.at(i) - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (alphabetNumArray[s.at(i) - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    // Solution
    /**
     * Solution 1
     * 
     * Frequency Counter
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int solution1(string s) {
        vector<int> counts(26, 0);

        for (char c : s) {
            counts[c - 'a']++;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (counts[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Solution 2
     * 
     * Hash table
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    int solution2(string s) {
        unordered_map<char, int> counts;

        for (char c : s) {
            counts[c]++;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (counts[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
