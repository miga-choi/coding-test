from collections import Counter


class RansomNote:
    """
    # dict
    #
    # Complexities:
    #   N - The Size of `ransomNote`
    #   M - The Size of `magazine`
    #   K - The Size of Characters in `magazine`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(K)
    """
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazineMap: dict = {}

        for c in magazine:
            if magazineMap.get(c) != None:
                magazineMap.update({c: magazineMap.get(c) + 1})
            else:
                magazineMap.update({c: 1})

        for c in ransomNote:
            if magazineMap.get(c) != None and magazineMap.get(c) > 0:
                magazineMap.update({c: magazineMap.get(c) - 1})
            else:
                return False

        return True


    # Solution
    """
    # Solution 1
    #
    # collections.Counter
    #
    # Complexities:
    #   N - The Size of `ransomNote`
    #   M - The Size of `magazine`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(1)
    """
    def solution1(self, ransomNote, magazine):
        return Counter(ransomNote) <= Counter(magazine)

    """
    # Solution 2
    #
    # Counting Array
    #
    # Complexities:
    #   N - The Size of `ransomNote`
    #   M - The Size of `magazine`
    #   - Time Complexity: O(N + M)
    #   - Space Complexity: O(1)
    """
    def solution2(self, ransomNote, magazine):
        if len(ransomNote) > len(magazine):
            return False

        count = [0] * 26
        base = ord('a')

        for c in magazine:
            count[ord(c) - base] += 1

        for c in ransomNote:
            idx = ord(c) - base
            count[idx] -= 1
            if count[idx] < 0:
                return False

        return True
