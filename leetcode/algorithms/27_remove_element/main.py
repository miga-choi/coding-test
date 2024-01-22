from typing import List


class RemoveElement:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums[:] = sorted(filter(lambda num: num != val, nums))
        return len(nums)


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, nums: List[int], val: int) -> int:
        index = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[index] = nums[i]
                index += 1
        return index

    # Best Solution 2:
    def bestSolution2(self, nums: List[int], val: int) -> int:
        while val in nums:
            nums.remove(val)

    # Best Solution 3:
    def bestSolution3(self, nums: List[int], val: int) -> int:
        start, end = 0, len(nums) - 1
        while start <= end:
            if nums[start] == val:
                nums[start], nums[end], end = nums[end], nums[start], end - 1
            else:
                start += 1
        return start
