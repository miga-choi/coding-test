from itertools import pairwise  # Python 3.10+
from typing import List


class TeemoAttacking:
    """
    # Pairwise Gap Summation
    #
    # Complexities:
    #   n - The Size of `timeSeries`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """

    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        result = 0

        for i in range(1, len(timeSeries)):
            if timeSeries[i] - timeSeries[i - 1] >= duration:
                result += duration
            else:
                result += timeSeries[i] - timeSeries[i - 1]

        result += duration

        return result

    # Solution
    """
    # Solution 1
    #
    # Pairwise Gap Summation
    #
    # Complexities:
    #   n - The Size of `timeSeries`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def solution1(self, timeSeries: List[int], duration: int) -> int:
        total = 0

        for i in range(len(timeSeries) - 1):
            gap = timeSeries[i + 1] - timeSeries[i]
            total += min(gap, duration)

        return total + duration

    """
    # Solution 2
    #
    # itertools.pairwise
    #
    # Complexities:
    #   n - The Size of `timeSeries`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def solution2(self, timeSeries: List[int], duration: int) -> int:
        return sum(min(b - a, duration) for a, b in pairwise(timeSeries)) + duration

    """
    # Solution 3
    #
    # Interval Merging
    #
    # Complexities:
    #   n - The Size of `timeSeries`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def solution3(self, timeSeries: List[int], duration: int) -> int:
        total = 0
        end = 0

        for t in timeSeries:
            overlap = max(0, end - t)
            total += duration - overlap
            end = t + duration

        return total
