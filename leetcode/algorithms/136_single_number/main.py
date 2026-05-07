from collections import Counter
from typing import List
import functools
import operator


class SingleNumber:
    """
    # Bit Manipulation
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def singleNumber(self, nums: List[int]) -> int:
        result = 0

        for num in nums:
            result = result ^ num

        return result


    # Solution
    """
    # Solution 1
    #
    # XOR
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, nums: List[int]) -> int:
        result = 0

        for num in nums:
            result ^= num

        return result

    """
    # Solution 2
    #
    # functools.reduce + operator.xor
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums: List[int]) -> int:
        return functools.reduce(operator.xor, nums)

    """
    # Solution 3
    #
    # HashMap
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, nums: List[int]) -> int:
        counts = Counter(nums)

        for num, count in counts.items():
            if count == 1:
                return num

    """
    # Solution 4
    #
    # Set
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution4(self, nums: List[int]) -> int:
        return 2 * sum(set(nums)) - sum(nums)
