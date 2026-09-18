from collections import Counter
from functools import reduce
from operator import xor


class FindTheDifference:
    """
    # str.replace
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def findTheDifference(self, s: str, t: str) -> str:
        for c in s:
            t = t.replace(c, "", 1)

        return t


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
    def solution1(self, s: str, t: str) -> str:
        diff = Counter(t) - Counter(s)
        return next(iter(diff))

    """
    # Solution 2
    #
    # sum
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, s: str, t: str) -> str:
        return chr(sum(map(ord, t)) - sum(map(ord, s)))

    """
    # Solution 3
    #
    # XOR
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, s: str, t: str) -> str:
        result = 0

        for c in s + t:
            result ^= ord(c)

        return chr(result)

    """
    # Solution 4
    #
    # XOR
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution4(self, s: str, t: str) -> str:
        return chr(reduce(xor, map(ord, s + t)))

    """
    # Solution 5
    #
    # Sorting
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution5(self, s: str, t: str) -> str:
        s, t = sorted(s), sorted(t)

        for i, c in enumerate(s):
            if c != t[i]:
                return t[i]

        return t[-1]
