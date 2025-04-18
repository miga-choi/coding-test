class ValidPalindromeII:
    def validPalindrome(self, s: str) -> bool:
        left: int = 0
        right: int = len(s) - 1

        while left < right and s[left] == s[right]:
            left += 1
            right -= 1

        left1: int = left + 1
        right1: int = right

        left2: int = left
        right2: int = right - 1

        while left1 < right1 and s[left1] == s[right1]:
            left1 += 1
            right1 -= 1

        while left2 < right2 and s[left2] == s[right2]:
            left2 += 1
            right2 -= 1

        return left1 >= right1 or left2 >= right2


    # Solution
    def solution(self, s):
        i, j = 0, len(s) - 1

        while i < j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                return self.validPalindromeUtil(s, i + 1, j) or self.validPalindromeUtil(s, i, j - 1)
        return True

    def validPalindromeUtil(self, s, i, j):
        while i < j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                return False

        return True
