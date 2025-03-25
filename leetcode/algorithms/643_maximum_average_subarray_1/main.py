from typing import List


class MaximumAverageSubarrayI:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        currSum: float = 0
        maxSum: float = 0

        for i in range(k):
            currSum += nums[i]

        maxSum = currSum

        for i in range(k, len(nums)):
            currSum += nums[i] - nums[i - k]
            maxSum = max(currSum, maxSum)

        return maxSum / k

    # Solution
    def solution(self, nums: List[int], k: int) -> float:
        # Initialize currSum and maxSum to the sum of the initial k elements
        currSum = maxSum = sum(nums[:k])

        # Start the loop from the kth element
        # Iterate until you reach the end
        for i in range(k, len(nums)):
            # Subtract the left element of the window
            # Add the right element of the window
            currSum += nums[i] - nums[i - k]

            # Update the max
            maxSum = max(maxSum, currSum)

        # Since the problem requires average, we return the average
        return maxSum / k
