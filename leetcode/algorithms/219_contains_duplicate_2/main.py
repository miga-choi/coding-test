from typing import List


class ContainsDuplicateII:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        numsMap = {}

        for i in range(len(nums)):
            if numsMap.get(nums[i]) != None:
                if abs(i - numsMap[nums[i]]) <= k:
                    return True
            numsMap.update({nums[i]: i})

        return False


    # Solution
    def solution(self, nums: List[int], k: int) -> bool:
        # Create hset for storing previous of k elements...
        hset = {}

        # Traverse for all elements of the given array in a for loop...
        for idx in range(len(nums)):
            # If duplicate element is present at distance less than equal to k, return true...
            if nums[idx] in hset and abs(idx - hset[nums[idx]]) <= k:
                return True
            hset[nums[idx]] = idx

        # If no duplicate element is found then return false...
        return False
