from functools import reduce
from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums)):
            if nums[i] != i:
                return i
        return len(nums)


    # Best Solution
    def bestSolution1(self, nums: List[int]) -> int:
        return (len(nums) * (len(nums) + 1)) // 2 - sum(nums)

    def bestSolution2(self, nums: List[int]) -> int:
        return reduce(lambda x, y: x ^ y, list(range(len(nums) + 1)) + nums)
