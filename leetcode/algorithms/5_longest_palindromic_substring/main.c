#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Expand Around Center
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
int getPalindromeLength(const char* s, const int s_len, int left, int right) {
    while (left >= 0 && right < s_len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    const int s_len = strlen(s);

    if (s_len == 1) {
        return s;
    }

    int start_index = 0;
    int max_len = 0;

    for (int i = 0; i < s_len; i++) {
        const int odd_len = getPalindromeLength(s, s_len, i, i);
        const int even_len = getPalindromeLength(s, s_len, i, i + 1);

        const int curr_max_len = odd_len > even_len ? odd_len : even_len;

        if (curr_max_len > max_len) {
            max_len = curr_max_len;
            start_index = i - (max_len - 1) / 2;
        }
    }

    // s = &s[start_index];
    // s[max_len] = '\0';

    char* result = (char*)malloc(sizeof(char) * (max_len + 1));
    memcpy(result, s + start_index, max_len);
    result[max_len] = '\0';

    return result;
}


// Solution
/**
 * Solution 1
 *
 * Expand Around Center
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
// 중심으로부터 양옆으로 확장하며 회문의 길이를 계산하는 헬퍼 함수
int expandAroundCenter(char* s, int left, int right, int len) {
    // 범위 내에 있고, 문자가 같을 동안 계속 확장
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }

    // while 루프가 끝난 시점의 left와 right는 회문 범위를 벗어난 상태임
    // 따라서 실제 회문의 길이는 (right - 1) - (left + 1) + 1 = right - left - 1
    return right - left - 1;
}

char* solution1(char* s) {
    if (s == NULL || *s == '\0') {
        return "";
    }

    int len = strlen(s);
    int start = 0;
    int maxLen = 0;

    for (int i = 0; i < len; i++) {
        // 1. 홀수 길이 회문 (중심이 s[i])
        int len1 = expandAroundCenter(s, i, i, len);

        // 2. 짝수 길이 회문 (중심이 s[i]와 s[i+1] 사이)
        int len2 = expandAroundCenter(s, i, i + 1, len);

        // 둘 중 더 긴 길이를 선택
        int currentMaxLen = (len1 > len2) ? len1 : len2;

        // 최대 길이 갱신 및 시작 인덱스 재계산
        if (currentMaxLen > maxLen) {
            maxLen = currentMaxLen;
            start = i - (currentMaxLen - 1) / 2;
        }
    }


    // 결과 문자열을 위한 메모리 할당 및 복사
    char* result = (char*)malloc(sizeof(char) * (maxLen + 1));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0'; // 널 문자 추가

    return result;
}

/**
 * Solution 2
 *
 * Dynamic Programming
 * - Time Complexity: O(N²)
 * - Space Complexity: O(N²)
 */
char* solution2(char* s) {
    int n = strlen(s);

    if (n < 2) {
        return s;
    }

    // dp 테이블을 위한 메모리 할당 및 초기화
    bool** dp = (bool**)malloc(sizeof(bool*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (bool*)calloc(n, sizeof(bool));
    }

    int start = 0;
    int maxLen = 1;


    // 길이가 1인 경우는 모두 회문
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // 길이가 2인 경우를 확인
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // 길이가 3 이상인 경우 확인
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // 끝 인덱스

            // 양 끝 문자가 같고, 그 안쪽이 회문이라면
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }
    }

    // 결과 문자열 생성
    char* result = (char*)malloc(sizeof(char) * (maxLen + 1));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    // dp 테이블 메모리 해제
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
