from typing import List


class MissingNumber:
    """
    # Solution 1
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums)):
            if nums[i] != i:
                return i
        return len(nums)


    # Solution
    """
    # Solution 1
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution1(self, nums: List[int]) -> int:
        n = len(nums)
        
        expected_sum = n * (n + 1) // 2
        
        actual_sum = sum(nums)
        
        return expected_sum - actual_sum

    """
    # Solution 2
    #
    # XOR
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums: List[int]) -> int:
        n = len(nums)
        missing = n
        
        for i in range(n):
            missing ^= i ^ nums[i]
            
        return missing
