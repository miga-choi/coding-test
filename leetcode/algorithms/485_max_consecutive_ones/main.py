from itertools import groupby
from typing import List


class MaxConsecutiveOnes:
    """
    # Running Counter
    #
    # Complexities:
    #   n - The Size of `nums`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        result = 0
        curr = 0

        for num in nums:
            if num == 1:
                curr += 1
            else:
                if curr > result:
                    result = curr
                curr = 0

        return max(result, curr)


    # Solution
    """
    # Solution 1
    #
    # Running Counter
    #
    # Complexities:
    #   n - The Size of `nums`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def solution1(self, nums: List[int]) -> int:
        count = best = 0

        for x in nums:
            if x == 1:
                count += 1
                best = max(best, count)
            else:
                count = 0

        return best

    """
    # Solution 2
    #
    # Run-Length Grouping
    #
    # Complexities:
    #   n - The Size of `nums`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums: List[int]) -> int:
        return max((sum(1 for _ in group) for key, group in groupby(nums) if key == 1), default=0)

    """
    # Solution 3
    #
    # String Splitting
    #
    # Complexities:
    #   n - The Size of `nums`
    #   - Time Complexity: O(n)
    #   - Space Complexity: O(n)
    """
    def solution3(self, nums: List[int]) -> int:
        return max(map(len, ''.join(map(str, nums)).split('0')))
