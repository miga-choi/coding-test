import re


class ValidPalindrome:
    """
    # Two-Pointers
    #
    # Complexities:
    #   N - Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
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
    """
    # Solution 1
    #
    # Pythonic Way
    #
    # Complexities:
    #   N - Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, s: str) -> bool:
        filtered_chars = [char.lower() for char in s if char.isalnum()]

        return filtered_chars == filtered_chars[::-1]

    """
    # Solution 2
    #
    # Two-Pointers
    #
    # Complexities:
    #   N - Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
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
