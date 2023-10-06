from typing import List


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        result: List[int] = []
        length = len(nums) + 1
        nums = list(set(sorted(nums, reverse=True)))
        count = 0
        for i in range(1, length):
            if count >= len(nums):
                result.append(i)
                continue
            if nums[count] != i:
                result.append(i)
            else:
                count += 1
        return result


    # Best Solution
    def bestSolution(self, nums: List[int]) -> List[int]:
        # For each number i in nums,
        # we mark the number that i points as negative.
        # Then we filter the list, get all the indexes
        # who points to a positive number
        for i in range(len(nums)):
            index = abs(nums[i]) - 1
            nums[index] = -abs(nums[index])

        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
