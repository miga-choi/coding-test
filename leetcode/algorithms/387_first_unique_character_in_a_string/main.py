from collections import Counter
from typing import List


class FirstUniqueCharacterInAString:
    """
    # Counting Array + Two-Pass
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def firstUniqChar(self, s: str) -> int:
        alphabetNumArray: List[int] = [0] * 26

        for c in s:
            alphabetNumArray[ord(c) - 97] += 1

        for i in range(len(s)):
            if alphabetNumArray[ord(s[i]) - 97] == 1:
                return i

        return -1


    # Solution
    """
    # Solution 1
    #
    # collections.Counter
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, s: str) -> int:
        count = Counter(s)

        for i, c in enumerate(s):
            if count[c] == 1:
                return i

        return -1

    """
    # Solution 2
    #
    # Counting Array + Two-Pass
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, s: str) -> int:
        count = [0] * 26
        base = ord('a')

        for c in s:
            count[ord(c) - base] += 1

        for i, c in enumerate(s):
            if count[ord(c) - base] == 1:
                return i

        return -1

    """
    # Solution 3
    #
    # dict + Indexing
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, s: str) -> int:
        seen = {}

        for i, c in enumerate(s):
            seen[c] = i if c not in seen else -1

        candidates = [i for i in seen.values() if i != -1]

        return min(candidates) if candidates else -1
