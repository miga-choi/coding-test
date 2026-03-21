from typing import List
import bisect


class LongestIncreasingSubsequence:
    """
    # DP
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N)
    """
    def lengthOfLIS(self, nums: List[int]) -> int:
        n: int = len(nums)
        dp: List[int] = [1] * n

        result: int = 1

        for i in range(1, n):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)

            result = max(result, dp[i])

        return result


    # Solution
    """
    # Solution 1
    #
    # DP
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(N)
    """
    def solution1(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n

        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)

    """
    # Solution 2
    #
    # Binary Search
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(N)
    """
    def solution2(self, nums: List[int]) -> int:
        sub = []

        for num in nums:
            i = bisect.bisect_left(sub, num)

            if i == len(sub):
                sub.append(num)
            else:
                sub[i] = num

        return len(sub)
