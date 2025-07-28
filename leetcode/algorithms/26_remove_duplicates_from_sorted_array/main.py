from collections import OrderedDict
from typing import List


class RemoveDuplicatesFromSortedArray:
    ##
    # Two Pointers
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def removeDuplicates1(self, nums: List[int]) -> int:
        left: int = 0
        for right in range(len(nums)):
            if nums[left] != nums[right]:
                left += 1
                nums[left] = nums[right]
            right += 1
        return left + 1
    
    ##
    # Set
    # - Time Complexity: O(?)
    # - Space Complexity: O(?)
    #
    def removeDuplicates2(self, nums: List[int]) -> int:
        numsSet: List[int] = sorted(list(set(nums)))
        i: int = 0
        for i in range(len(numsSet)):
            nums[i] = numsSet[i]
        return i + 1


    # Solution
    # Solution 1:

    def solution1(self, nums: List[int]) -> int:
        j = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[j] = nums[i]
                j += 1
        return j

    # Solution 2: Sort in Place Using
    def solution2(self, nums: List[int]) -> int:
        nums[:] = sorted(set(nums))
        return len(nums)

    # Solution 3: Two-pointers
    def solution3(self, nums: List[int]) -> int:
        slow, fast = 0, 1
        while fast in range(len(nums)):
            if nums[slow] == nums[fast]:
                fast += 1
            else:
                nums[slow + 1] = nums[fast]
                fast += 1
                slow += 1

        return slow + 1

    # Solution 4: Simplified two-pointers with for loops
    def solution4(self, nums: List[int]) -> int:
        j = 0
        for i in range(1, len(nums)):
            if nums[j] != nums[i]:
                j += 1
                nums[j] = nums[i]
        return j + 1

    # Solution 5: Using ".pop()"
    def solution5(self, nums: List[int]) -> int:
        i = 1
        while i < len(nums):
            if nums[i] == nums[i - 1]:
                nums.pop(i)
            else:
                i += 1
        return len(nums)

    # Solution 6: Using "OrderedDict.fromkeys()"
    def solution6(self, nums: List[int]) -> int:
        nums[:] = OrderedDict.fromkeys(nums)
        return len(nums)
