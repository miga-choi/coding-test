from collections import OrderedDict
from typing import List


class RemoveDuplicatesFromSortedArray:
    """
    # Two Pointers
    #
    # Complexities:
    #   N - Length of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def removeDuplicates1(self, nums: List[int]) -> int:
        left: int = 0
        for right in range(len(nums)):
            if nums[left] != nums[right]:
                left += 1
                nums[left] = nums[right]
            right += 1
        return left + 1
    
    """
    # Set
    #
    # Complexities:
    #   N - Length of `nums`
    #   - Time Complexity: O(N * logᴺ)
    #   - Space Complexity: O(N)
    """
    def removeDuplicates2(self, nums: List[int]) -> int:
        numsSet: List[int] = sorted(list(set(nums)))
        i: int = 0
        for i in range(len(numsSet)):
            nums[i] = numsSet[i]
        return i + 1


    # Solution
    """
    # Two Pointers
    #
    # Complexities:
    #   N - Length of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution(self, nums: List[int]) -> int:
        slow = 0

        for fast in range(1, len(nums)):
            if nums[fast] != nums[slow]:
                slow += 1
                nums[slow] = nums[fast]

        return slow + 1
