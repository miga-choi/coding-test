import math
from typing import List


class ConstructTheRectangle:
    """
    # Downward Search from Square Root
    #
    # Complexities:
    #   n - `area`
    #   - Time Complexity: O(√n)
    #   - Space Complexity: O(1)
    """
    def constructRectangle(self, area: int) -> List[int]:
        w = math.floor(math.sqrt(area))

        while area % w != 0:
            w -= 1

        return [int(area / w), w]


    # Solution
    """
    # Solution 1
    #
    # Downward Search from Square Root
    #
    # Complexities:
    #   n - `area`
    #   - Time Complexity: O(√n)
    #   - Space Complexity: O(1)
    """
    def solution1(self, area: int) -> List[int]:
        w = math.isqrt(area)

        while area % w != 0:
            w -= 1

        return [area // w, w]

    """
    # Solution 2
    #
    # Divisor Enumeration
    #
    # Complexities:
    #   n - `area`
    #   - Time Complexity: O(√n)
    #   - Space Complexity: O(1)
    """
    def solution2(self, area: int) -> List[int]:
        best = 1

        for w in range(1, math.isqrt(area) + 1):
            if area % w == 0:
                best = w

        return [area // best, best]
