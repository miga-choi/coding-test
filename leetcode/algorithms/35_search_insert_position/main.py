import math
import bisect
from typing import List


class SearchInsertPosition:
    def searchInsert(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums)
        while lo < hi:
            mid = lo + math.floor((hi - lo) / 2)
            if target > nums[mid]:
                lo = mid + 1
            else:
                hi = mid
        return lo


    # Best Solution
    # Best Solution 1: Linear Search
    def bestSolution1(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0

        for i, num in enumerate(nums):
            if num >= target:
                return i

        return len(nums)

    # Best Solution 2: Using bisect module
    def bestSolution2(self, nums: List[int], target: int) -> int:
        return bisect.bisect_left(nums, target)

    # Best Solution 3: Binary Search By Hand
    def bestSolution3(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums)
        while low < high:
            mid = (low + high) // 2
            if target > nums[mid]:
                low = mid + 1
            else:
                high = mid
        return low
