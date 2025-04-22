from collections import defaultdict
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        numsMap = {}
        length = len(nums) / 2

        while len(nums) > 0:
            num = nums.pop()
            if numsMap.get(num) is not None and numsMap.get(num) > 0:
                numsMap[num] = numsMap[num] + 1
            else:
                numsMap[num] = 1

            if numsMap[num] > length:
                return num


    # Solution
    # Solution 1: Sorting
    def solution1(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        return nums[n//2]

    # Solution 2: Hash Map
    def solution2(self, nums: List[int]) -> int:
        n = len(nums)
        m = defaultdict(int)
        
        for num in nums:
            m[num] += 1
        
        n = n // 2
        for key, value in m.items():
            if value > n:
                return key
        
        return 0

    # Solution 3: Moore Voting Algorithm
    def solution3(self, nums: List[int]) -> int:
        count = 0
        candidate = 0
        
        for num in nums:
            if count == 0:
                candidate = num
            
            if num == candidate:
                count += 1
            else:
                count -= 1
        
        return candidate