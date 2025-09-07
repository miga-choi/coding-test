from typing import List
import collections


class FirstUniqueCharacterInAString:
    ##
    # Frequency Counter
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def firstUniqChar(self, s: str) -> int:
        alphabetNumArray: List[int] = [0] * 26

        for c in s:
            alphabetNumArray[ord(c) - 97] += 1

        for i in range(len(s)):
            if alphabetNumArray[ord(s[i]) - 97] == 1:
                return i

        return -1


    # Solution
    ##
    # Solution 1
    #
    # Frequency Counter
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution1(self, s: str) -> int:
        counts = {}

        for char in s:
            counts[char] = counts.get(char, 0) + 1

        for i in range(len(s)):
            if counts[s[i]] == 1:
                return i

        return -1

    ##
    # Solution 2
    #
    # Frequency Counter & collections.Counter
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution2(self, s: str) -> int:
        counts = collections.Counter(s)

        for index, char in enumerate(s):
            if counts[char] == 1:
                return index

        return -1

    ##
    # Solution 3
    #
    # Hash table
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution3(self, s: str) -> int:
        char_map = {}
        duplicate_flag = len(s)

        for index, char in enumerate(s):
            if char not in char_map:
                char_map[char] = index
            else:
                char_map[char] = duplicate_flag

        min_index = duplicate_flag
        for index_val in char_map.values():
            if index_val != duplicate_flag:
                min_index = min(min_index, index_val)

        return min_index if min_index != duplicate_flag else -1
