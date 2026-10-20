from typing import List


class FindAllNumbersDisappearedInAnArray:
    """
    # Auxiliary Array
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
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


    # Solution
    """
    # Solution 1
    #
    # Set
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution1(self, nums: List[int]) -> List[int]:
        seen = set(nums)
        return [x for x in range(1, len(nums) + 1) if x not in seen]

    """
    # Solution 2
    #
    # Negative Marking
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, nums: List[int]) -> List[int]:
        for x in nums:
            idx = abs(x) - 1
            nums[idx] = -abs(nums[idx])

        return [i + 1 for i, x in enumerate(nums) if x > 0]

    """
    # Solution 3
    #
    # Cyclic Sort
    #
    # Complexities:
    #   N - The Size of `nums`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution3(self, nums: List[int]) -> List[int]:
        for x in nums:
            idx = abs(x) - 1
            nums[idx] = -abs(nums[idx])

        return [i + 1 for i, x in enumerate(nums) if x > 0]
