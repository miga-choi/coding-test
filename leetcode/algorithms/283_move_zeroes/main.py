from typing import List


class MoveZeroes:
    """
    # Complexities:
    #   N - The size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
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


    # Solution
    """
    # Two Pointers Swap
    #
    # Complexities:
    #   N - The size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        last_non_zero = 0
        
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[last_non_zero], nums[i] = nums[i], nums[last_non_zero]
                last_non_zero += 1
