from collections import Counter
from typing import List


class ValidAnagram:
    """
    # Frequency Counting
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def isAnagram(self, s: str, t: str) -> bool:
        length: int = len(s)

        if length != len(t):
            return False

        alphabetNumArray: List[int] = [0] * 26

        for i in range(length):
            alphabetNumArray[ord(s[i]) - 97] += 1
            alphabetNumArray[ord(t[i]) - 97] -= 1

        for i in range(26):
            if alphabetNumArray[i] != 0:
                return False

        return True


    # Solution
    """
    # Solution 1
    # 
    # Frequency Counting
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        return Counter(s) == Counter(t)

    """
    # Solution 2
    #
    # Sorting
    #
    # Complexities:
    #   N - The size of `s`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(N)
    """
    def solution2(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        return sorted(s) == sorted(t)
