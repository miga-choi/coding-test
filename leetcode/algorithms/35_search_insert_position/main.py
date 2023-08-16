import math
import bisect
from typing import List


class Solution:
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
    # Linear Search
    def linearSearch(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0

        for i, num in enumerate(nums):
            if num >= target:
                return i

        return len(nums)

    # Using bisect module
    def bisectModule(self, nums: List[int], target: int) -> int:
        return bisect.bisect_left(nums, target)

    # Binary Search By Hand
    def binarySearch(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums)
        while low < high:
            mid = (low + high) // 2
            if target > nums[mid]:
                low = mid + 1
            else:
                high = mid
        return low
