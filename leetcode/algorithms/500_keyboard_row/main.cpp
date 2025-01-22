#include <string>
#include <vector>
using namespace std;

class KeyboardRow {
public:
    vector<string> findWords(vector<string>& words) {
        int alphabetRowNum[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            int row = 0;
            for (int j = 0; j < words[i].size(); j++) {
                if (row) {
                    if (alphabetRowNum[words[i][j] < 'a' ? words[i][j] - 'A' : words[i][j] - 'a'] == row) {
                        if (j == words[i].size() - 1) {
                            result.push_back(words[i]);
                        }
                    } else {
                        break;
                    }
                } else {
                    row = alphabetRowNum[words[i][j] < 'a' ? words[i][j] - 'A' : words[i][j] - 'a'];
                    j--;
                }
            }
        }

        return result;
    }

    // Solution
    vector<string> solution(vector<string>& words) {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (char c : rows[i]) {
                dict[c - 'A'] = 1 << i;
            }
        }
        vector<string> res;
        for (string w : words) {
            int r = 7;
            for (char c : w) {
                r &= dict[toupper(c) - 'A'];
                if (r == 0) {
                    break;
                }
            }
            if (r) {
                res.push_back(w);
            }
        }
        return res;
    }
};
