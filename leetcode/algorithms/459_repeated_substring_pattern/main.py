class RepeatedSubstringPattern:
    """
    # String Concatenation
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N) ~ O(N²)
    #   - Space Complexity: O(N)
    """
    def repeatedSubstringPattern(self, s: str) -> bool:
        if len(s) < 2:
            return False

        return (s[-len(s) + 1:] + s[: len(s) - 1]).find(s) >= 0


    # Solution
    """
    # Solution 1
    #
    # Divisor Enumeration
    #
    # Complexities:
    #   N - The Size of `s`
    #   d(N) - The Number of Divisors of N
    #   - Time Complexity: O(N * d(N))
    #   - Space Complexity: O(1)
    """
    def solution1(self, s: str) -> bool:
        n = len(s)

        for L in range(1, n // 2 + 1):
            if n % L == 0 and s[:L] * (n // L) == s:
                return True

        return False

    """
    # Solution 2
    #
    # String Concatenation
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N) ~ O(N²)
    #   - Space Complexity: O(N)
    """
    def solution2(self, s: str) -> bool:
        return s in (s + s)[1:-1]

    """
    # Solution 3
    #
    # KMP Failure Function
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution3(self, s: str) -> bool:
        n = len(s)
        lps = [0] * n
        length = 0

        for i in range(1, n):
            while length and s[i] != s[length]:
                length = lps[length - 1]
            if s[i] == s[length]:
                length += 1
            lps[i] = length

        l = lps[-1]

        return l > 0 and n % (n - l) == 0
