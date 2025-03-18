import heapq
from typing import List


class MaximumProductOfThreeNumbers:
    def maximumProduct(self, nums: List[int]) -> int:
        max1: int = -1000
        max2: int = -1000
        max3: int = -1000
        min1: int = 1000
        min2: int = 1000

        for num in nums:
            if num > max1:
                max3 = max2
                max2 = max1
                max1 = num
            elif num > max2:
                max3 = max2
                max2 = num
            elif num > max3:
                max3 = num

            if num < min1:
                min2 = min1
                min1 = num
            elif num < min2:
                min2 = num

        return max(max1 * max2 * max3, min1 * min2 * max1)


    # Solution 1: Using sort
    def maximumProduct(self, nums):
        nums.sort()
        return max(nums[-1] * nums[-2] * nums[-3], nums[0] * nums[1] * nums[-1])


    # Solution 2: Using sort
    def maximumProduct(self, nums):
        a, b = heapq.nlargest(3, nums), heapq.nsmallest(2, nums)
        return max(a[0] * a[1] * a[2], b[0] * b[1] * a[0])
