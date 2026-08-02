#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class WordPattern {
public:
    /**
     * Complexities:
     *   N - The size of `pattern`
     *   M - The size of `s`
     *   L - The max size of word
     *   - Time Complexity: O(M + N * L)
     *   - Space Complexity: O(M)
     */
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        
        vector<string> charToWord(26, "");
        unordered_map<string, char> wordToChar;

        string word;
        int i = 0;
        int patternLen = pattern.length();

        while (iss >> word) {
            if (i >= patternLen) {
                return false;
            }

            char c = pattern[i];
            int charIdx = c - 'a';

            if (!charToWord[charIdx].empty() && charToWord[charIdx] != word) {
                return false;
            }

            if (wordToChar.count(word) && wordToChar[word] != c) {
                return false;
            }

            charToWord[charIdx] = word;
            wordToChar[word] = c;

            i++;
        }

        return i == patternLen;
    }


    // Solution
    /**
     * Complexities:
     *   N - The size of `pattern`
     *   M - The size of `s`
     *   L - The max size of word
     *   - Time Complexity: O(M + N * L)
     *   - Space Complexity: O(M)
     */
    bool solution(string pattern, string s) {
        istringstream iss(s);
        
        vector<string> charToWord(26, "");
        unordered_map<string, char> wordToChar;

        string word;
        int i = 0;
        int patternLen = pattern.length();

        while (iss >> word) {
            if (i >= patternLen) {
                return false;
            }

            char c = pattern[i];
            int charIdx = c - 'a';

            if (!charToWord[charIdx].empty() && charToWord[charIdx] != word) {
                return false;
            }

            if (wordToChar.count(word) && wordToChar[word] != c) {
                return false;
            }

            charToWord[charIdx] = word;
            wordToChar[word] = c;

            i++;
        }

        return i == patternLen;
    }
};
