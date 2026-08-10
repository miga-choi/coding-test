from itertools import accumulate
from typing import List


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)

"""
# Complexities:
#   - Time Complexity: O(N)
#   - Space Complexity: O(1)
"""
class NumArray:
    def __init__(self, nums: List[int]):
        self.nums = nums

    def sumRange(self, left: int, right: int) -> int:
        sum = 0

        for i in range(left, right + 1):
            sum += self.nums[i]

        return sum


# Solution
"""
# Solution 1
#
# Complexities:
#   - Time Complexity: O(N)
#   - Space Complexity: O(1)
"""
class Solution1:
    def __init__(self, nums: List[int]):
        self.prefix = [0] * (len(nums) + 1)

        for i, x in enumerate(nums):
            self.prefix[i + 1] = self.prefix[i] + x

    def sumRange(self, left: int, right: int) -> int:
        return self.prefix[right + 1] - self.prefix[left]

"""
# Solution 2
#
# Complexities:
#   - Time Complexity: O(N)
#   - Space Complexity: O(1)
"""
class Solution2:
    def __init__(self, nums: List[int]):
        self.prefix = list(accumulate(nums, initial=0))

    def sumRange(self, left: int, right: int) -> int:
        return self.prefix[right + 1] - self.prefix[left]
