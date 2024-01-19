from collections import OrderedDict
from typing import List


class RemoveDuplicatesFromSortedArray:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums[:] = sorted(list(dict.fromkeys(nums)))
        return len(nums)


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, nums: List[int]) -> int:
        j = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[j] = nums[i]
                j += 1
        return j

    # Best Solution 2: Sort in Place Using
    def bestSolution2(self, nums: List[int]) -> int:
        nums[:] = sorted(set(nums))
        return len(nums)

    # Best Solution 3: Two-pointers
    def bestSolution3(self, nums: List[int]) -> int:
        slow, fast = 0, 1
        while fast in range(len(nums)):
            if nums[slow] == nums[fast]:
                fast += 1
            else:
                nums[slow + 1] = nums[fast]
                fast += 1
                slow += 1

        return slow + 1

    # Best Solution 4: Simplified two-pointers with for loops
    def bestSolution4(self, nums: List[int]) -> int:
        j = 0
        for i in range(1, len(nums)):
            if nums[j] != nums[i]:
                j += 1
                nums[j] = nums[i]
        return j + 1

    # Best Solution 5: Using ".pop()"
    def bestSolution5(self, nums: List[int]) -> int:
        i = 1
        while i < len(nums):
            if nums[i] == nums[i - 1]:
                nums.pop(i)
            else:
                i += 1
        return len(nums)

    # Best Solution 6: Using "OrderedDict.fromkeys()"
    def bestSolution6(self, nums: List[int]) -> int:
        nums[:] = OrderedDict.fromkeys(nums)
        return len(nums)
