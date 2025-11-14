from collections import defaultdict
from typing import List


class GroupAnagrams:
    """
    # Complexities:
    #   N - size of strs
    #   K - max size of strings in strs
    #   - Time Complexity: O(N * K * logᴷ)
    #   - Space Complexity: O(N * K)
    """
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        str_map: dict = {}

        for str in strs:
            sorted_chars = sorted(str)
            sorted_str = "".join(sorted_chars)

            if str_map.get(sorted_str) == None:
                str_map[sorted_str] = []

            str_map[sorted_str].append(str)

        return list(str_map.values())


    # Solution
    """
    # Solution 1
    #
    # Sorted String as Key
    #
    # Complexities:
    #   N - size of strs
    #   K - max size of strings in strs
    #   - Time Complexity: O(N * K * logᴷ)
    #   - Space Complexity: O(N * K)
    """
    def solution1(self, strs: List[str]) -> List[List[str]]:
        anagram_groups = defaultdict(list)

        for s in strs:
            key = "".join(sorted(s))
            anagram_groups[key].append(s)

        return list(anagram_groups.values())

    """
    # Solution 2
    #
    # Character Count as Key
    #
    # Complexities:
    #   N - size of strs
    #   K - max size of strings in strs
    #   - Time Complexity: O(N * K)
    #   - Space Complexity: O(N * K)
    """
    def solution2(self, strs: List[str]) -> List[List[str]]:
        anagram_groups = defaultdict(list)

        for s in strs:
            count = [0] * 26
            for char in s:
                count[ord(char) - ord('a')] += 1

            key = tuple(count)
            anagram_groups[key].append(s)

        return list(anagram_groups.values())
