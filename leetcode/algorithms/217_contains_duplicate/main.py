from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        numsMap: dict = {}
        for i in range(len(nums)):
            if numsMap.get(nums[i]) != None:
                return True
            numsMap.update({nums[i]: True})
        return False

    
    # Best Solution
    def containsDuplicate(self, nums: List[int]) -> bool:
        hset = set()
        for idx in nums:
            if idx in hset:
                return True
            else:
                hset.add(idx)
