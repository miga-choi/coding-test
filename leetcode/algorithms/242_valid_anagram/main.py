from collections import Counter
from typing import List


class ValidAnagram:
    ##
    # Frequency Counter
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
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
    ##
    # Solution 1
    #
    # Sorting
    # - Time Complexity: O(N * logᴺ)
    # - Space Complexity: O(N)
    #
    def solution1(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        return sorted(s) == sorted(t)

    ##
    # Solution 2
    #
    # Hash Table / Dictionary
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution2(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        char_counts = {}

        for char in s:
            char_counts[char] = char_counts.get(char, 0) + 1

        for char in t:
            if char not in char_counts or char_counts[char] == 0:
                return False
            char_counts[char] -= 1

        return True

    ##
    # Solution 3
    #
    # collections.Counter
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution3(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
