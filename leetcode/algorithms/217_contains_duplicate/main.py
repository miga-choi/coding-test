from typing import List, Set


class ContainsDuplicate:
    """
    # Hash Set
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
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
    """
    # Solution 1
    #
    # Hash Set
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, nums: List[int]) -> bool:
        seen = set()

        for num in nums:
            if num in seen:
                return True
            seen.add(num)

        return False

    """
    # Solution 2
    #
    # Complexities:
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))

    """
    # Solution 3
    #
    # Complexities:
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(1)
    """
    def solution3(self, nums: List[int]) -> bool:
        nums.sort()

        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                return True

        return False
