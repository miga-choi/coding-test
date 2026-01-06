class FindTheIndexOfTheFirstOccurrenceInAString:
    """
    # Brute Force, Sliding Window
    #
    # Complexities:
    #   N - Length of `haystack`
    #   M - Length of `needle`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(1)
    """
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
    """
    # Solution 1
    #
    # Brute Force, Sliding Window
    #
    # Complexities:
    #   N - Length of `haystack`
    #   M - Length of `needle`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(1)
    """
    def solution1(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)

        if m > n:
            return -1

        for i in range(n - m + 1):
            if haystack[i: i + m] == needle:
                return i

        return -1

    """
    # Solution 2
    #
    # built-in: find()
    #
    # Complexities:
    #   N - Length of `haystack`
    #   M - Length of `needle`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(1)
    """
    def solution2(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
