#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class LetterCombinationsOfAPhoneNumber {
public:
    /**
     * Recursion: Backtracking (DFS)
     * - Time Complexity: O(4ᴺ)
     * - Space Complexity: O(N)
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

    void backtracking(const string& digits, vector<string>& result, string& row,
                      const int i) {
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
     * - Time Complexity: O(4ᴺ)
     * - Space Complexity: O(N)
     */
    vector<string> result;
    string digits_str;
    unordered_map<char, string> mapping;

    void backtrack(int index, string& current_combination) {
        if (index == digits_str.length()) {
            result.push_back(current_combination);
            return;
        }

        char current_digit = digits_str[index];
        const string& letters = mapping.at(current_digit);

        for (char letter : letters) {
            current_combination.push_back(letter);
            backtrack(index + 1, current_combination);
            current_combination.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        mapping = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                   {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        this->digits_str = digits;
        result.clear();
        string initial_combination = "";

        backtrack(0, initial_combination);

        return result;
    }
};
