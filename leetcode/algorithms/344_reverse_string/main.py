import math
from typing import List


class ReverseString:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(math.floor(len(s) / 2)):
            temp = s[i]
            s[i] = s[len(s) - 1 - i]
            s[len(s) - 1 - i] = temp


    # Solution
    def solution(self, s: List[str]) -> None:
        s[:] = s[::-1]
