#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class WordBreak {
public:
    /**
     * Dynamic Programming
     *
     * Complexities:
     *   N - Size of `s`
     *   - Time Complexity: O(N³)
     *   - Space Complexity: O(N)
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }


    // Solution
    /**
     * Dynamic Programming
     *
     * Complexities:
     *   N - Size of `s`
     *   - Time Complexity: O(N³)
     *   - Space Complexity: O(N)
     */
    bool solution(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        
        vector<bool> dp(n + 1, false);
        
        dp[0] = true;

        int max_word_len = 0;
        for(const string& w : wordDict) {
            max_word_len = max(max_word_len, (int)w.length());
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0 && j >= i - max_word_len; --j) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (dict.count(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};
