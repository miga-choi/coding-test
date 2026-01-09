import bisect
import math
from typing import List


class SearchInsertPosition:
    """
    # Binary Search
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def searchInsert(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums)
        while lo < hi:
            mid = lo + math.floor((hi - lo) / 2)
            if target > nums[mid]:
                lo = mid + 1
            else:
                hi = mid
        return lo


    # Solution
    """
    # Solution 1
    #
    # Binary Search
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution1(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left

    """
    # Solution 2
    #
    # bisect
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums: List[int], target: int) -> int:
        return bisect.bisect_left(nums, target)
