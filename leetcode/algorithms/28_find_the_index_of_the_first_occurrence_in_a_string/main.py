import sys


class FindTheIndexOfTheFirstOccurrenceInAString:
    def strStr(self, haystack: str, needle: str) -> int:
        if haystack == "":
            return -1
        if needle == "":
            return 0
        return haystack.find(needle)


    # Solution
    # Solution 1:
    def solution1(self, haystack, needle):
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i: i + len(needle)] == needle:
                return i
        return -1

    # Solution 2:
    def solution2(self, haystack, needle):
        if needle == "":
            return 0
        for i in range(len(haystack) - len(needle) + 1):
            for j in range(len(needle)):
                if haystack[i + j] != needle[j]:
                    break
                if j == len(needle) - 1:
                    return i
        return -1

    # Solution 3:
    def solution3(self, haystack, needle):
        return haystack.find(needle)

    # Solution 4: Rabin Karp, built-in hash, constant time
    def solution4(self, haystack, needle):
        n, h = len(needle), len(haystack)
        hash_n = hash(needle)
        for i in range(h - n + 1):
            if hash(haystack[i: i + n]) == hash_n:
                return i
        return -1

    # Solution 4:
    # Rabin Karp, numeral base for both uppercase
    # and lowercase letters, constant time
    def solution4(self, haystack, needle):
        def f(c):
            return ord(c) - ord("A")

        n, h, d, m = len(needle), len(haystack), ord(
            "z") - ord("A") + 1, sys.maxint

        if n > h:
            return -1
        nd, hash_n, hash_h = d ** (n - 1), 0, 0
        for i in range(n):
            hash_n = (d * hash_n + f(needle[i])) % m
            hash_h = (d * hash_h + f(haystack[i])) % m
        if hash_n == hash_h:
            return 0
        for i in range(1, h - n + 1):
            # e.g. 10*(1234-1*10**3)+5=2345
            hash_h = (
                d * (hash_h - f(haystack[i - 1]) * nd) + f(haystack[i + n - 1])
            ) % m
            if hash_n == hash_h:
                return i
        return -1

    # Solution 5: KMP
    def solution5(self, haystack, needle):
        n, h = len(needle), len(haystack)
        i, j, nxt = 1, 0, [-1] + [0] * n
        while i < n:
            # calculate next array
            if j == -1 or needle[i] == needle[j]:
                i += 1
                j += 1
                nxt[i] = j
            else:
                j = nxt[j]
        i = j = 0
        while i < h and j < n:
            if j == -1 or haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                j = nxt[j]
        return i - j if j == n else -1
