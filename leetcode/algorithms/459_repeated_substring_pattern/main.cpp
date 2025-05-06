#include <string>
using namespace std;

class RepeatedSubstringPattern {
public:
    bool repeatedSubstringPattern(string s) {}


    // Solution
    // Solution 1: Check All Possible Substrings
    bool solution1(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                string substring = s.substr(0, i);
                string repeated = "";
                for (int j = 0; j < n / i; ++j) {
                    repeated += substring;
                }
                if (repeated == s) {
                    return true;
                }
            }
        }
        return false;
    }

    // Solution 2: Clever String Manipulation
    bool solution2(string s) {
        string doubled = s + s;
        string sub = doubled.substr(1, doubled.size() - 2);
        return sub.find(s) != string::npos;
    }
};
