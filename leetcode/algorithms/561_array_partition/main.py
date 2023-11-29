from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        result = 0
        nums.sort()  ## or nums = sorted(nums)
        for i in range(len(nums)):
            if i % 2 == 0:
                result += nums[i]
        return result


    # Best Solution
    def bestSolution(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])
