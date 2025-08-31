import re


class ValidPalindrome:
    ##
    # Two-Pointer
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    def isPalindrome(self, s: str) -> bool:
        left: int = 0
        right: int = len(s) - 1

        while left < right:
            if not s[left].isalnum():
                left += 1
                continue

            if not s[right].isalnum():
                right -= 1
                continue

            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True


    # Solution
    ##
    # Solution 1
    #
    # Compare strings
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    #
    def solution1(self, s: str) -> bool:
        filtered_chars = []

        for char in s:
            if char.isalnum():
                filtered_chars.append(char.lower())

        processed_s = "".join(filtered_chars)

        return processed_s == processed_s[::-1]

    ##
    # Solution 2
    #
    # Two-Pointer
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution2(self, s: str) -> bool:
        left, right = 0, len(s) - 1

        while left < right:
            while left < right and not s[left].isalnum():
                left += 1

            while left < right and not s[right].isalnum():
                right -= 1

            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True

    ##
    # Solution 3
    #
    # Regular Expressions
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    #
    def solution3(self, s: str) -> bool:
        s = re.sub(r'[^a-zA-Z0-9]', '', s).lower()
        return s == s[::-1]
