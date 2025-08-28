import sys


class FindTheIndexOfTheFirstOccurrenceInAString:
    ##
    # Brute-Force
    # - Time Complexity: O(N * M)
    # - Space Complexity: O(1)
    #
    def strStr(self, haystack: str, needle: str) -> int:
        haystack_len: int = len(haystack)
        needle_len: int = len(needle)

        if needle_len > haystack_len:
            return -1

        for haystack_idx in range(haystack_len - needle_len + 1):
            isMatch: bool = True

            for needle_idx in range(needle_len):
                if haystack[haystack_idx + needle_idx] != needle[needle_idx]:
                    isMatch = False
                    break

            if isMatch:
                return haystack_idx

        return -1


    # Solution
    ##
    # Solution 1
    #
    # str.find()
    # - Time Complexity: O(N * M)
    # - Space Complexity: O(1)
    #
    def solution1(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

    ##
    # Solution 2
    #
    # str.index()
    # - Time Complexity: O(N * M)
    # - Space Complexity: O(1)
    #
    def solution2(self, haystack: str, needle: str) -> int:
        return haystack.index(needle)

    ##
    # Solution 3
    #
    # Sliding Window
    # - Time Complexity: O(N * M)
    # - Space Complexity: O(1)
    #
    def solution3(self, haystack: str, needle: str) -> int:
        haystack_len, needle_len = len(haystack), len(needle)

        for i in range(haystack_len - needle_len + 1):
            if haystack[i: i + needle_len] == needle:
                return i

        return -1

    ##
    # Solution 4
    #
    # Knuth-Morris-Pratt (KMP)
    # - Time Complexity: O(N + M)
    # - Space Complexity: O(M)
    #
    def solution4(self, haystack: str, needle: str) -> int:
        haystack_len, needle_len = len(haystack), len(needle)

        lps = [0] * needle_len
        prev_lps, i = 0, 1

        while i < needle_len:
            if needle[i] == needle[prev_lps]:
                lps[i] = prev_lps + 1
                prev_lps += 1
                i += 1
            elif prev_lps == 0:
                lps[i] = 0
                i += 1
            else:
                prev_lps = lps[prev_lps - 1]

        haystack_idx = 0
        needle_idx = 0

        while haystack_idx < haystack_len:
            if haystack[haystack_idx] == needle[needle_idx]:
                haystack_idx, needle_idx = haystack_idx + 1, needle_idx + 1
            else:
                if needle_idx == 0:
                    haystack_idx += 1
                else:
                    needle_idx = lps[needle_idx - 1]
            if needle_idx == needle_len:
                return haystack_idx - needle_len

        return -1
