from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums[:] = sorted(filter(lambda num: num != val, nums))
        return len(nums)


    # Best Solution
    def bestSolution(self, nums: List[int], val: int) -> int:
        while val in nums:
            nums.remove(val)
