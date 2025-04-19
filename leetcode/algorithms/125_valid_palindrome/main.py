import re


class ValidPalindrome:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub("[^0-9a-zA-Z]+", "", s).lower()
        for i in range(len(s)):
            if i == len(s) - 1:
                break
            if s[i] != s[len(s) - 1 - i]:
                return False
        return True


    # Solution
    # Solution 1: Two Lines
    def solution1(self, s: str) -> bool:
        s = [i for i in s.lower() if i.isalnum()]
        return s == s[::-1]

    # Solution 2: O(1) space (two-pointer)
    def solution2(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            a, b = s[i].lower(), s[j].lower()
            if a.isalnum() and b.isalnum():
                if a != b:
                    return False
                else:
                    i, j = i + 1, j - 1
                    continue
            i, j = i + (not a.isalnum()), j - (not b.isalnum())
        return True
