import collections


class LongestPalindrome:
    def longestPalindrome(self, s: str) -> int:
        result = 0
        sMap: dict = dict()

        for c in s:
            if sMap.get(c) == None:
                sMap.update({c: 1})
            else:
                result += 2
                sMap.pop(c)

        if len(sMap) > 0:
            result += 1

        return result


    # Solution
    # Solution 1
    def solution1(self, s: str) -> int:
        odd_count = 0
        d = {}

        for ch in s:
            if ch in d:
                d[ch] += 1
            else:
                d[ch] = 1

            if d[ch] % 2 == 1:
                odd_count += 1
            else:
                odd_count -= 1

        if odd_count > 1:
            return len(s) - odd_count + 1

        return len(s)

    # Solution 2
    def solution2(self, s: str) -> int:
        odds = sum(v & 1 for v in collections.Counter(s).values())
        return len(s) - odds + bool(odds)
