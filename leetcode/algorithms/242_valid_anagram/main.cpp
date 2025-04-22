#include <string>
#include <unordered_map>
using namespace std;

class ValidAnagram {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int alphabetNumArray[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            alphabetNumArray[s.at(i) - 'a']++;
            alphabetNumArray[t.at(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (alphabetNumArray[i] > 0) {
                return false;
            }
        }

        return true;
    }


    // Solution
    // Solution 1: Sorting
    bool solution1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // Solution 2: Hash Table
    bool solution2(string s, string t) {
        unordered_map<char, int> count;

        // Count the frequency of characters in string `s`
        for (auto x : s) {
            count[x]++;
        }

        // Decrement the frequency of characters in string `t`
        for (auto x : t) {
            count[x]--;
        }

        // Check if any character has non-zero frequency
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }

        return true;
    }

    // Solution 3: Hash Table (Using Array)
    bool solution3(string s, string t) {
        int count[26] = {0};

        // Count the frequency of characters in string `s`
        for (char x : s) {
            count[x - 'a']++;
        }

        // Decrement the frequency of characters in string `t`
        for (char x : t) {
            count[x - 'a']--;
        }

        // Check if any character has non-zero frequency
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }
};
