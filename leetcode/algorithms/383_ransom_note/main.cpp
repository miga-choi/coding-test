#include <string>
#include <unordered_map>
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
    // Solution 1: Map
    bool solution1(string ransomNote, string magazine) {
        unordered_map<char, int> dictionary;

        // Iterate through the magazine and count characters
        for (char c : magazine) {
            if (dictionary.find(c) == dictionary.end()) {
                dictionary[c] = 1;
            } else {
                dictionary[c]++;
            }
        }

        // Iterate through the ransom note and check character counts
        for (char c : ransomNote) {
            if (dictionary.find(c) != dictionary.end() && dictionary[c] > 0) {
                dictionary[c]--;
            } else {
                return false;
            }
        }

        return true;
    }

    // Solution 2
    bool solution2(string ransomNote, string magazine) {
        // Initialize an array of count with the size 26...
        int counter[26] = {0};

        // Traverse a loop through the entire String of magazine where char ch stores the char at the index of magazine...
        for (char ch : magazine) {
            counter[ch - 'a']++;
        }

        // Run another for loop for ransomNote...
        for (char ch : ransomNote) {
            // If the charachter doesn't exists in magazine for ransomNote, we return false...
            if (counter[ch - 'a']-- <= 0) {
                return false;
            }
        }

        // If nothing goes wrong, return true...
        return true;
    }
};
