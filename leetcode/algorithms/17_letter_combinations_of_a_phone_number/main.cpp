#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class LetterCombinationsOfAPhoneNumber {
public:
    /**
     * Recursion: Backtracking (DFS)
     *
     * Complexities:
     *   - Time Complexity: O(4ᴺ)
     *   - Space Complexity: O(N)
     */
    int getLettersLength(char digit) {
        switch (digit) {
        case '2':
            return 3;
        case '3':
            return 3;
        case '4':
            return 3;
        case '5':
            return 3;
        case '6':
            return 3;
        case '7':
            return 4;
        case '8':
            return 3;
        case '9':
            return 4;
        default:
            return 0;
        }
    }

    string getLetters(char digit) {
        switch (digit) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
        }
    }

    void backtracking(const string& digits, vector<string>& result, string& row, const int i) {
        if (i == digits.length()) {
            result.push_back(row);
            return;
        }

        const string letters = getLetters(digits[i]);
        const int letters_length = getLettersLength(digits[i]);

        for (char letter : letters) {
            row.push_back(letter);
            backtracking(digits, result, row, i + 1);
            row.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string row;

        backtracking(digits, result, row, 0);

        return result;
    }


    // Solution
    /**
     * Recursion: Backtracking (DFS)
     *
     * Complexities:
     *   - Time Complexity: O(4ᴺ)
     *   - Space Complexity: O(N)
     */
    const vector<string> KEYPAD = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        const string& letters = KEYPAD[digit];

        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, result);
            current.pop_back();
        }
    }

    vector<string> solution(string digits) {
        vector<string> result;
        
        if (digits.empty()) {
            return result;
        }

        string current;
        backtrack(digits, 0, current, result);
        
        return result;
    }
};
