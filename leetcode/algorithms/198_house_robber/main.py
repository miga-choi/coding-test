from typing import List


class HouseRobber:
    """
    # DP
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def rob(self, nums: List[int]) -> int:
        prev1: int = 0
        prev2: int = 0

        for num in nums:
            currentMax: int = max(prev1, prev2 + num)

            prev2 = prev1
            prev1 = currentMax

        return prev1


    # Solution
    """
    # Solution 1
    #
    # DP
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
            
        dp = [0] * len(nums)
        
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
            
        return dp[-1]

    """
    # Solution 2
    #
    # DP
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, nums: List[int]) -> int:
        prev2, prev1 = 0, 0
        
        for num in nums:
            current = max(prev1, prev2 + num)
            
            prev2 = prev1
            prev1 = current
            
        return prev1
