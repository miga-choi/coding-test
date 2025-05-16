import math
from typing import List


class BinarySearch:
    def search(self, nums: List[int], target: int) -> int:
        left: int = 0
        right: int = len(nums) - 1

        while left <= right:
            mid: int = left + math.floor((right - left) / 2)

            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                return mid

        return -1


    # Solution
    def solution(self, nums: List[int], target: int) -> int:
        lo: int = 0
        hi: int = len(nums) - 1

        while lo < hi:
            mid: int = lo + math.floor((hi - lo + 1) / 2)

            if target < nums[mid]:
                hi = mid - 1
            else:
                lo = mid

        return lo if nums[lo] == target else -1
