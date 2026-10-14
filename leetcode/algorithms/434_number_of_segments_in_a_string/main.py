class NumberOfSegmentsInAString:
    """
    # Built-in Function
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def countSegments(self, s: str) -> int:
        return len(list(filter(lambda x: x != "", s.split(" "))))


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, s: str) -> int:
        count = 0

        for i in range(len(s)):
            if s[i] != ' ' and (i == 0 or s[i - 1] == ' '):
                count += 1

        return count

    """
    # Solution 2
    #
    # Status flag
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, s: str) -> int:
        count = 0
        in_segment = False

        for c in s:
            if c != ' ':
                if not in_segment:
                    count += 1
                    in_segment = True
            else:
                in_segment = False

        return count

    """
    # Solution 3
    #
    # Built-in Function
    #
    # Complexities:
    #   N - The Size of `s`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, s: str) -> int:
        return len(s.split())
