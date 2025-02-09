#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class ReverseWordsInAStringIII {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp, ans;

        while (ss >> temp) {
            reverse(temp.begin(), temp.end());
            ans += (temp + " ");
        }

        return ans.substr(0, ans.size() - 1);        
    }

    // Solution
    string solution(string s) {
        for (int i = 0; i < s.length(); i++) {
            // when i is a non-space
            if (s[i] != ' ') {
                int j = i;

                // move j to the next space
                for (; j < s.length() && s[j] != ' '; j++) { }

                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }

        return s;
    }
};
