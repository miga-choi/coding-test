from math import floor


class LongestPalindromicSubstring:
    """
    # Expand Around Center
    # 
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def getPalindromeLength(self, s: str, s_len: int, left: int, right: int):
        while left >= 0 and right < s_len and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1

    def longestPalindrome(self, s: str) -> str:
        s_len: int = len(s)

        if s_len == 1:
            return s

        start_index: int = 0
        max_len: int = 0

        for i in range(0, s_len):
            odd_len: int = self.getPalindromeLength(s, s_len, i, i)
            even_len: int = self.getPalindromeLength(s, s_len, i, i + 1)

            curr_max_len: int = max(odd_len, even_len)

            if curr_max_len > max_len:
                max_len = curr_max_len
                start_index = i - floor((max_len - 1) / 2)

        return s[start_index: start_index + max_len]


    # Solution
    """
    # Solution 1
    #
    # Expand Around Center
    # 
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2 or s == s[::-1]:
            return s

        start, max_len = 0, 1

        def expand(left: int, right: int) -> int:
            # left와 right가 유효한 인덱스이고, 문자가 동일한 동안 확장
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1

            # Palindrome의 길이는 right - left - 1
            return right - left - 1

        for i in range(len(s)):
            # 홀수 길이 Palindrome (중앙이 i)
            len1 = expand(i, i)

            # 짝수 길이 Palindrome (중앙이 i와 i+1 사이)
            len2 = expand(i, i + 1)

            current_len = max(len1, len2)

            if current_len > max_len:
                max_len = current_len

                # 시작점 계산: i - (길이-1)//2
                start = i - (current_len - 1) // 2

        return s[start: start + max_len]

    """
    # Solution 2
    # 
    # Dynamic Programming
    # 
    # Complexities:
    #   N - Length of `s`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N²)
    """
    def solution2(self, s: str) -> str:
        n = len(s)

        if n < 2:
            return s

        dp = [[False] * n for _ in range(n)]
        start, max_len = 0, 1

        # 길이가 1인 모든 부분 문자열은 Palindrome
        for i in range(n):
            dp[i][i] = True

        # 길이가 2인 부분 문자열 검사
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                start = i
                max_len = 2

        # 길이가 3 이상인 부분 문자열 검사
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1

                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True

                    if length > max_len:
                        start = i
                        max_len = length

        return s[start: start + max_len]
