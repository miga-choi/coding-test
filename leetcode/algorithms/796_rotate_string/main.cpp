#include <string>
#include <vector>
using namespace std;

class RotateString {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        return (s + s).find(goal) != string::npos;
    }


    // Solution
    // Solution 1: Brute Force
    bool solution1(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        int length = s.length();

        // Try all possible rotations of the string
        for (int rotationCount = 0; rotationCount < length; ++rotationCount) {
            // Perform one rotation
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) {
                return true;
            }
        }

        return false;
    }

    // Solution 2: Concatenation Check
    bool solution2(string s, string goal) {
        // Check if the lengths are different
        if (s.length() != goal.length()) {
            return false;
        }

        // Create a new string by concatenating 's' with itself
        string doubledString = s + s;

        // Use find to search for 'goal' in 'doubledString'
        // If find returns an index that is less than the
        // length of doubledString, 'goal' is a substring
        return doubledString.find(goal) < doubledString.length();
    }

    // Solution 3: KMP Algorithm
    bool solution3(string s, string goal) {
        // Check if the lengths of both strings are different; if so, they can't
        // be rotations
        if (s.length() != goal.length()) {
            return false;
        }

        // Concatenate 's' with itself to create a new string containing all
        // possible rotations
        string doubledString = s + s;

        // Perform KMP substring search to check if 'goal' is a substring of
        // 'doubledString'
        return kmpSearch(doubledString, goal);
    }

private:
    bool kmpSearch(string& text, string& pattern) {
        // Precompute the LPS (Longest Prefix Suffix) array for the pattern
        vector<int> lps = computeLPS(pattern);
        int textIndex = 0, patternIndex = 0;
        int textLength = text.size(), patternLength = pattern.size();

        // Loop through the text to find the pattern
        while (textIndex < textLength) {
            // If characters match, move both indices forward
            if (text[textIndex] == pattern[patternIndex]) {
                textIndex++;
                patternIndex++;
                // If we've matched the entire pattern, return true
                if (patternIndex == patternLength)
                    return true;
            }
            // If there's a mismatch after some matches, use the LPS array to
            // skip unnecessary comparisons
            else if (patternIndex > 0) {
                patternIndex = lps[patternIndex - 1];
            }
            // If no matches, move to the next character in text
            else {
                textIndex++;
            }
        }

        // Pattern not found in text
        return false;
    }

    vector<int> computeLPS(string& pattern) {
        int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);
        int length = 0, index = 1;

        // Build the LPS array
        while (index < patternLength) {
            // If characters match, increment length and set lps value
            if (pattern[index] == pattern[length]) {
                length++;
                lps[index++] = length;
            }
            // If there's a mismatch, update length using the previous LPS value
            else if (length > 0) {
                length = lps[length - 1];
            }
            // No match and length is zero
            else {
                lps[index++] = 0;
            }
        }

        return lps;
    }
};
