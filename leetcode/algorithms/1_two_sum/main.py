from typing import List


class TwoSum:
    """
    # Brute-Force
    # 
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def twoSum1(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

        return []

    """
    # Dictionary
    # 
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        map: dict[int, int] = {}

        for i in range(len(nums)):
            complement: int = target - nums[i]
            if complement in map:
                return [i, map[complement]]
            map[nums[i]] = i

        return []


    # Solution
    """
    # Solution 1
    # 
    # Brute Force
    # 
    # Complexities:
    #   N - `nums`'s Size
    #   - Time Complexity: O(N²)
    #   - Space Complexity: O(1)
    """
    def solution1(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]

        return []

    """
    # Solution 2
    # 
    # Hash Map
    # 
    # Complexities:
    #   N - `nums`'s Size
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, nums: List[int], target: int) -> List[int]:
        num_map = {}

        for i, num in enumerate(nums):
            complement = target - num

            if complement in num_map:
                return [num_map[complement], i]

            num_map[num] = i

        return []
