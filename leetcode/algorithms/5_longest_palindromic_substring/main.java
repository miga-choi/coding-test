class LongestPalindromicSubstring {
    /**
     * Expand Around Center
     * - Time Complexity: O(N²)
     * - Space Complexity: O(1)
     */
    private int getPalindromeLength(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    public String longestPalindrome(String s) {
        if (s.length() == 1) {
            return s;
        }

        int startIndex = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            int oddLength = getPalindromeLength(s, i, i);
            int evenLength = getPalindromeLength(s, i, i + 1);

            int currMaxLength = Math.max(oddLength, evenLength);

            if (currMaxLength > maxLength) {
                maxLength = currMaxLength;
                startIndex = i - (maxLength - 1) / 2;
            }
        }

        return s.substring(startIndex, startIndex + maxLength);
    }


    // Solution
    /**
     * Solution 1
     * 
     * Expand Around Center
     * - Time Complexity: O(N²)
     * - Space Complexity: O(1)
     */
    // 주어진 중심(left, right)에서부터 밖으로 확장하며 Palindrome의 길이를 찾는 함수
    private int expandAroundCenter(String s, int left, int right) {
        // left과 right이 유효한 범위 내에 있고, 해당 문자가 같을 때까지 확장
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }

        // Palindrome의 길이를 반환 (right - left + 1) - 2
        return right - left - 1;
    }

    public String solution1(String s) {
        if (s == null || s.length() < 1) {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            // 홀수 길이 Palindrome
            int len1 = expandAroundCenter(s, i, i);

            // 짝수 길이 Palindrome
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = Math.max(len1, len2);

            // 더 긴 Palindrome을 찾았다면, 시작과 끝 인덱스를 업데이트
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substring(start, end + 1);
    }

    /**
     * Solution 2
     * 
     * Dynamic Programming
     * - Time Complexity: O(N²)
     * - Space Complexity: O(N²)
     */
    public String solution2(String s) {
        if (s == null || s.length() < 1) {
            return "";
        }

        int n = s.length();
        boolean[][] dp = new boolean[n][n];

        int start = 0;
        int maxLength = 1;

        // 길이가 1인 모든 부분 문자열은 Palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // 길이가 2인 부분 문자열 검사
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // 길이가 3 이상인 부분 문자열 검사
        // len은 부분 문자열의 길이
        for (int len = 3; len <= n; len++) {
            // i는 시작 인덱스
            for (int i = 0; i <= n - len; i++) {
                // j는 끝 인덱스
                int j = i + len - 1;

                // 점화식 적용: 양 끝 문자가 같고, 그 안쪽도 Palindrome인가?
                if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    // 더 긴 Palindrome을 찾았으므로, start와 maxLength 업데이트
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }

        return s.substring(start, start + maxLength);
    }
}
