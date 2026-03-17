from typing import List


class Subsets:
    """
    # Backtracking
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N * 2ᴺ)
    #   - Space Complexity: O(N)
    """
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]] = []

        def backtracking(start: int, nums: List[int], current: List[int], result: List[List[int]]) -> None:
            result.append(current[:])

            for i in range(start, len(nums)):
                current.append(nums[i])

                backtracking(i + 1, nums, current, result)

                current.pop()

        backtracking(0, nums, [], result)

        return result


    # Solution
    """
    # Solution 1
    #
    # Backtracking
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N * 2ᴺ)
    #   - Space Complexity: O(N)
    """
    def solution1(self, nums: List[int]) -> List[List[int]]:
        result = []

        def backtrack(start: int, path: List[int]):
            result.append(path[:])

            for i in range(start, len(nums)):
                path.append(nums[i])

                backtrack(i + 1, path)

                path.pop()

        backtrack(0, [])

        return result

    """
    # Solution 2
    #
    # Cascading
    #
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N * 2ᴺ)
    #   - Space Complexity: O(N)
    """
    def solution2(self, nums: List[int]) -> List[List[int]]:
        result = [[]]

        for num in nums:
            result += [curr + [num] for curr in result]

        return result
