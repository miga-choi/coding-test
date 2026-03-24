from typing import List


class CombinationSum:
    """
    # Backtracking
    # 
    # Complexities:
    #   N - Size of `candidates`
    #   T - Value of `target`
    #   M - Minimum value of `candidates`
    #   - Time Complexity: O(Nᵀ/ᴹ)
    #   - Space Complexity: O(T/M)
    """
    def backtracking(self, candidates: List[int], target: int, start: int, current: List[int], result: List[List[int]]) -> None:
        if target == 0:
            result.append(current[:])
            return

        if target < 0:
            return

        for i in range(start, len(candidates)):
            current.append(candidates[i])

            self.backtracking(candidates, target -
                              candidates[i], i, current, result)

            current.pop()

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result: List[List[int]] = []
        current: List[int] = []

        self.backtracking(candidates, target, 0, current, result)

        return result


    # Solution
    """
    # Backtracking
    # 
    # Complexities:
    #   N - Size of `candidates`
    #   T - Value of `target`
    #   M - Minimum value of `candidates`
    #   - Time Complexity: O(Nᵀ/ᴹ)
    #   - Space Complexity: O(T/M)
    """
    def solution(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        candidates.sort()

        def backtrack(remain: int, curr_path: List[int], start: int):
            if remain == 0:
                result.append(curr_path[:])
                return

            for i in range(start, len(candidates)):
                if remain - candidates[i] < 0:
                    break

                curr_path.append(candidates[i])

                backtrack(remain - candidates[i], curr_path, i)

                curr_path.pop()

        backtrack(target, [], 0)

        return result
