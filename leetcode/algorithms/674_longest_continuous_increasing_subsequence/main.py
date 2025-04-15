from typing import List


class LongestContinuousIncreasingSubsequence:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        res: int = 1
        count: int = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                count += 1
                if count > res:
                    res = count
            else:
                count = 1
        return res

    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [1] * len(nums)
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                dp[i] = dp[i - 1] + 1
        return max(dp)
