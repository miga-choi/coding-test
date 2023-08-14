class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            for j in range(1, len(nums) - i):
                if nums[j - 1] == 0:
                    temp = nums[j - 1]
                    nums[j - 1] = nums[j]
                    nums[j] = temp


    # Best Solution
    def bestSolution(self, nums):
        n = len(nums)
        i = 0
        for j in range(n):
            if nums[j] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
