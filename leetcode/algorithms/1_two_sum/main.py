from typing import List


class TwoSum:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums), 1):
            for j in range(i + 1, len(nums), 1):
                if i >= len(nums):
                    continue
                if nums[i] + nums[j] == target:
                    return [i, j]


    # Best Solution
    # Best Solution 1: Brute Force
    def bestSolution1(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []  # No solution found

    # Best Solution 2: Two-pass Hash Table
    def bestSolution2(self, nums: List[int], target: int) -> List[int]:
        numMap = {}
        n = len(nums)

        # Build the hash table
        for i in range(n):
            numMap[nums[i]] = i

        # Find the complement
        for i in range(n):
            complement = target - nums[i]
            if complement in numMap and numMap[complement] != i:
                return [i, numMap[complement]]

        return []  # No solution found

    # Best Solution 3: One-pass Hash Table
    def bestSolution3(self, nums: List[int], target: int) -> List[int]:
        numMap = {}
        n = len(nums)

        for i in range(n):
            complement = target - nums[i]
            if complement in numMap:
                return [numMap[complement], i]
            numMap[nums[i]] = i

        return []  # No solution found
