from typing import List


class TwoSum:
    # Brute-Force
    # - Time Complexity: O(N²)
    # - Space Complexity: O(1)
    def twoSum1(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        
        return []

    # Dictionary
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        map: dict[int, int] = {}

        for i in range(len(nums)):
            complement: int = target - nums[i]
            if complement in map:
                return [i, map[complement]]
            map[nums[i]] = i

        return []



    # Solution
    # Solution 1: Brute Force
    def solution1(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []  # No solution found

    # Solution 2: Two-pass Hash Table
    def solution2(self, nums: List[int], target: int) -> List[int]:
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

    # Solution 3: One-pass Hash Table
    def solution3(self, nums: List[int], target: int) -> List[int]:
        numMap = {}
        n = len(nums)

        for i in range(n):
            complement = target - nums[i]
            if complement in numMap:
                return [numMap[complement], i]
            numMap[nums[i]] = i

        return []  # No solution found
