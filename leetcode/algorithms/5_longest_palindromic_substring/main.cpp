#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class LongestPalindromicSubstring {
public:
    /**
     * Expand Around Center
     *
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    int getPalindromeLength(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int start_index = 0;
        int max_len = 0;

        for (int i = 0; i < s.size(); i++) {
            const int odd_len = getPalindromeLength(s, i, i);
            const int even_len = getPalindromeLength(s, i, i + 1);

            const int curr_max_len = odd_len > even_len ? odd_len : even_len;

            if (curr_max_len > max_len) {
                max_len = curr_max_len;
                start_index = i - (max_len - 1) / 2;
            }
        }

        return s.substr(start_index, max_len);
    }


    // Solution
    /**
     * Solution 1
     * 
     * Expand Around Center
     * 
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    // 중심으로부터 양옆으로 확장하며 회문의 길이를 계산하는 헬퍼 함수
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // while 루프가 끝난 시점의 left와 right는 회문 범위를 벗어난 상태
        // 실제 회문의 길이는 (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }

    string solution1(string s) {
        if (s.length() < 1) {
            return "";
        }

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            // 1. 홀수 길이 회문 (중심이 s[i])
            int len1 = expandAroundCenter(s, i, i);

            // 2. 짝수 길이 회문 (중심이 s[i]와 s[i+1] 사이)
            int len2 = expandAroundCenter(s, i, i + 1);

            int currentMaxLen = max(len1, len2);

            // 최대 길이 갱신 및 시작 인덱스 재계산
            if (currentMaxLen > maxLen) {
                maxLen = currentMaxLen;
                start = i - (maxLen - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

    /**
     * Solution 2
     *
     * Dynamic Programming
     * 
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N²)
     */
    string solution2(string s) {
        int n = s.length();

        if (n < 2) {
            return s;
        }

        // dp 테이블 생성 및 false로 초기화
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        // 길이가 1인 경우는 모두 회문
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // 길이가 2 이상인 경우를 확인
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                // 양 끝 문자가 다르면 절대 회문이 아님
                if (s[i] != s[j]) {
                    continue;
                }

                // 양 끝 문자가 같을 때
                // 길이가 2이거나 (j-i=1), 안쪽이 회문이면 현재 부분 문자열도 회문
                if (j - i < 2 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
