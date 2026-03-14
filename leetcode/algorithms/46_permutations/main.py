import itertools
from typing import List


class Permutations:
    """
    # Backtracking
    # 
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N * N!)
    #   - Space Complexity: O(N)
    """
    def permute(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]] = []
        visited: List[bool] = [False] * len(nums)

        def backtracking(current: List[int]) -> None:
            if len(current) == len(nums):
                result.append(current[:])
                return

            for i in range(len(nums)):
                if visited[i]:
                    continue

                current.append(nums[i])
                visited[i] = True

                backtracking(current)

                current.pop()
                visited[i] = False

        backtracking([])

        return result


    # Solution
    """
    # Solution 1
    #
    # Backtracking
    # 
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N * N!)
    #   - Space Complexity: O(N)
    """
    def solution1(self, nums: List[int]) -> List[List[int]]:
        result = []
        visited = [False] * len(nums)

        def backtrack(path: List[int]):
            if len(path) == len(nums):
                result.append(path[:])
                return

            for i in range(len(nums)):
                if not visited[i]:
                    visited[i] = True
                    path.append(nums[i])

                    backtrack(path)

                    path.pop()
                    visited[i] = False

        backtrack([])

        return result

    """
    # Solution 2
    #
    # itertools.permutations
    # 
    # Complexities:
    #   N - Size of `nums`
    #   - Time Complexity: O(N * N!)
    #   - Space Complexity: O(N)
    """
    def solution2(self, nums: List[int]) -> List[List[int]]:
        return [list(p) for p in itertools.permutations(nums)]
