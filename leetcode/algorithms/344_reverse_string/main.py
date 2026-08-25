from math import floor
from typing import List


class ReverseString:
    """
    # Two pointers
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexities: O(N)
    #   - Space Complexities: O(1)
    """
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(floor(len(s) / 2)):
            temp = s[i]
            s[i] = s[len(s) - 1 - i]
            s[len(s) - 1 - i] = temp


    # Solution
    """
    # Solution 1
    #
    # Two pointers
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexities: O(N)
    #   - Space Complexities: O(1)
    """
    def solution1(self, s: List[str]) -> None:
        left, right = 0, len(s) - 1

        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

    """
    # Solution 2
    #
    # Built-in function
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexities: O(N)
    #   - Space Complexities: O(1)
    """
    def solution2(self, s: List[str]) -> None:
        s.reverse()
    