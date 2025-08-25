from typing import List, Set


class ContainsDuplicate:
    ##
    # Set
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    #
    def containsDuplicate(self, nums: List[int]) -> bool:
        if len(nums) < 2:
            return False

        numsSet: Set = set()

        for num in nums:
            if num in numsSet:
                return True
            else:
                numsSet.add(num)

        return False


    # Solution
    ##
    # Set
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    #
    def solution(self, nums: List[int]) -> bool:
        hset: Set = set(nums)
        return len(nums) != len(hset)
