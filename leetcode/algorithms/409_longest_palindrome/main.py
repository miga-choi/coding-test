from collections import Counter


class LongestPalindrome:
    """
    # dict
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
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
        length = 0
        has_odd = False

        for cnt in Counter(s).values():
            length += cnt // 2 * 2
            if cnt % 2 == 1:
                has_odd = True

        return length + 1 if has_odd else length

    """
    # Solution 2
    #
    # Count The Odd Numbers
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, s: str) -> int:
        odd = sum(cnt % 2 for cnt in Counter(s).values())

        return len(s) - odd + 1 if odd else len(s)

    """
    # Solution 3
    #
    # Set Toggle
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, s: str) -> int:
        unpaired = set()
        pairs = 0

        for c in s:
            if c in unpaired:
                unpaired.remove(c)
                pairs += 1
            else:
                unpaired.add(c)

        return pairs * 2 + (1 if unpaired else 0)
