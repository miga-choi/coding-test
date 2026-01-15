from typing import List


class Solution:
    """
    # Sorting
    #
    # Complexities:
    #   N - Length of in `intervals`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(N)
    """
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda interval: interval[0])

        result: List[List[int]] = []
        result.append(intervals[0])

        for i in range(1, len(intervals)):
            last: List[int] = result[len(result) - 1]
            curr: List[int] = intervals[i]

            if last[1] >= curr[0]:
                if last[1] < curr[1]:
                    last[1] = curr[1]
            else:
                result.append(intervals[i])

        return result


    # Solution
    """
    # Sorting
    #
    # Complexities:
    #   N - Length of in `intervals`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(N)
    """
    def solution(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])

        merged = []

        for interval in intervals:
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged
