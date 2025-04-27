import collections


class FirstUniqueCharacterInAString:
    def firstUniqChar(self, s: str) -> int:
        for c in s:
            if s.index(c) == s.rindex(c):
                return s.index(c)
        return -1


    # solution
    def solution(self, s: str) -> int:
        hset = collections.Counter(s)

        # Traverse the string from the beginning...
        for idx in range(len(s)):
            # If the count is equal to 1, it is the first distinct character in the list.
            if hset[s[idx]] == 1:
                return idx

        # If no character appeared exactly once...
        return -1
