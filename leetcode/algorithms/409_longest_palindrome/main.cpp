#include <string>
#include <unordered_map>
using namespace std;

class LongestPalindrome {
public:
    int longestPalindrome(string s) {
        int alphabetNumArray[52] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) < 97) {
                alphabetNumArray[s.at(i) - 'A']++;
            } else {
                alphabetNumArray[s.at(i) - 'a' + 26]++;
            }
        }

        int count = 0;
        int hasOdd = 0;

        for (int i = 0; i < 52; i++) {
            if (alphabetNumArray[i] % 2) {
                hasOdd = 1;
            }
            count += alphabetNumArray[i] / 2;
        }

        return count * 2 + hasOdd;
    }

    // Best Solution
    int bestSolution(string s) {
        int oddCount = 0;
        unordered_map<char, int> ump;
        for (char ch : s) {
            ump[ch]++;
            if (ump[ch] % 2 == 1) {
                oddCount++;
            } else {
                oddCount--;
            }
        }
        if (oddCount > 1) {
            return s.length() - oddCount + 1;
        }
        return s.length();
    }
};
